/*
Diamond Martin
Class: CSC 362-001, Programming Assignment 2
October 1, 2020
A program that calculates city ratings based on many factors. The information of ethe cities are in a text file that is received and inputed. Once the information 
is inputed, the city's population density is calculated; then the city's pollution rating, traffic rating, crime per capita, expense per capita are calculated 
with use of the city's population density that was calculated beofre. Based on the numbers for the city's pollution rating, traffic rating, crime per capita, 
expense per capita, the city's livability is computed. Then, the number of cities, total livability of all the cities, the city with the best livability, 
and the city’s name with the best livability are updated as the program goes through the files' rows of city information. Each city's name, population density, 
and livability are outputed on their own row. Also a summary is outputed of how many cities there are, the average livability of all the cities, city’s name with 
the best livability, the best livability of the city.     
*/
//file containing the header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//Constants
#define POLLUTIONNUM 1112.2         //A constant used in the formula to calculate a city's pollution
#define TRAFFICNUM 2.13             //A constant used in the formula to calculate a city's traffic rating
#define CRIMENUM 924.6              //A constant used in the formula to calculate a city's crime per capita
#define EXPENSENUM 1217.1           //A constant used in the formula to calculate a city's expense per capita
#define LIVABILITYNUM 13.81         //A constant used in the formula to calculate a city's livability
//Function prototypes
int input(FILE*, char*, int*, int*, int*, int*, int*, int*);				      //get input of one city from file
double computePopulationDensity(int, int);									      //compute the city's population density based on population and mileage
void compute(double, int, int, int, int, double*, double*, double*, double*);	  //compute the city’s pollution rating, traffic rating, crime per capita, expense per capita
void computeLivability(double, double, double, double, double*);   //compute the city's livability based on the city’s pollution rating, traffic rating, crime per capita, expense per capita           
void update(int*, char*, double, double*, double*, char*);        //determine the number of cities, total livability of all the cities, best livability of a and the city’s name with the best livability 
void output(char*, double, double);					              //output of the one city's name, population density, and livability
void summary(int, double, char*, double);                         //outputs a summary of the city’s name with best livability, the best livability of the city, the number of cities, and the average livability of the cities
//file containg main function
#include "cityratings.h" //contains constants and function prototypes 

void main() {
    char cityName[20], bestCityName[20];            //city name and city with best livability name
    int population, squareMileage, pollutionValue, crimeValue, expenseValue, numHighways, numCities = 0;    //city rating data and number of cities
    double populationDensity, pollutionRating, trafficRating, crimePerCapita, expensePerCapita, livability; //data used to calculate livability 
    double bestLivability, totalLivability = 0; //bestLivability is for best livability of a city, and totalLivability is the total livability of all the cities
    FILE* fp1;                          //file pointer for input file
    fp1 = fopen("cities2.txt", "r");    //open the file as read-only
    printf("City\t\t\t Population dens.\tLivability\n"); // To label what the columns represent for the output
    while (input(fp1, cityName, &population, &squareMileage, &pollutionValue, &crimeValue, &expenseValue, &numHighways) != EOF) { //iterate for each city and get the city's input from fp1
        populationDensity = computePopulationDensity(population, squareMileage); //compute the population density
        compute(populationDensity, pollutionValue, numHighways, crimeValue, expenseValue, &pollutionRating, &trafficRating, &crimePerCapita, &expensePerCapita);                      //compute pollutionRating, trafficRating, crimePerCapita, expensePerCapita
        computeLivability(pollutionRating, trafficRating, crimePerCapita, expensePerCapita, &livability); //compute the city's livability
        update(&numCities, cityName, livability, &totalLivability, &bestLivability, bestCityName); //counts the number of cities and updates total livability, best livability, and best city name based on the city's livability
        output(cityName, populationDensity, livability); //output name, population density and livability for each city
    }
    fclose(fp1);        //closes the file
    summary(numCities, totalLivability, bestCityName, bestLivability); //compute the average livability and output the number of cities, average livability, and best city name and its livability
}
//file containing input, output and summary functions
#include "cityratings.h" //contains constants and function prototypes
//this function gets one line of input about the current city
int input(FILE* fp1, char* city, int* pop, int* mileage, int* pollution, int* crime, int* expense, int* highways) {
    return fscanf(fp1, "%s %d %d %d %d %d %d", city, pop, mileage, pollution, crime, expense, highways);
}
//this function outputs a city's name, population density and livability
void output(char* cityName, double popDensity, double livability) {
    printf("%-30s %.3f %17.3f\n", cityName, popDensity, livability);
}
//this function calculates the average livability of the cities and outputs the number of cities, average livability and best city name and its livability
void summary(int numCities, double totalLivability, char* bestCityName, double bestLivability) {
    double averageLivability = totalLivability / numCities; //average livability is calcuated by dividing the total livability of the cities by the number of cities
    printf("\nBest city: %s, with a livability of %.3f\nThe %d cities have an average livability of %.3f", bestCityName, bestLivability, numCities, averageLivability);
}
//file containing compute population density, compute, compute livability, and update functions
#include "cityratings.h"        //contains constants and function prototypes
//this function computes the population density of a city
double computePopulationDensity(int pop, int m) {
	double popDensity; //population density can be a decimal number, so the variable is declared as a double
	double population = (double)pop;       //casted pop as double to do division
	double mileage = (double)m;            //casted m as double to do division
	popDensity = population / mileage;     //population density is calcuated by dividing the city's population by the square mileage
	return popDensity;                     // the population sensty is returned as a double
}
//This function computes the city’s pollution rating, traffic rating, crime per capita, expense per capita
void compute(double popDensity, int pol, int h, int c, int e, double* polRating, double* trafRating, double* crimeCapita, double* expenseCapita) {
	double pollution = (double)pol;    //casted pol as double to do division
	double highways = (double)h;       //casted h as double to do division
	double crime = (double)c;          //casted c as double to do division
	double expense = (double)e;        //casted e as double to do division
	*polRating = pollution * popDensity / POLLUTIONNUM;    //calculates pollution rating of a city
	*trafRating = popDensity * TRAFFICNUM / highways;      //calculates traffic rating of a city
	*crimeCapita = crime * popDensity / CRIMENUM;          //calculates crime per capita of a city
	*expenseCapita = expense * popDensity / EXPENSENUM;    //calculates expense per capita of a city
}
//this function computes a city's livability
void computeLivability(double pollution, double traffic, double crime, double expense, double* livability) {
	*livability = 100 - (pollution + traffic + crime + expense) / LIVABILITYNUM;
}
//this function counts the number of cities, and updates the total livability of all the cities, which city has the best livability, and best city name based on the city's livability
void update(int* numCities, char* cityName, double livability, double* totalLivability, double* bestLivability, char* bestCityName) {
	*numCities = *numCities + 1;                           //counts the number of cities by adding 1 for each city
	*totalLivability = *totalLivability + livability;      //each city's livability is added to thetotal livability
	if (livability > *bestLivability) {                    //determines which city has the best livability by comparing
		*bestLivability = livability;                      //updates the best livability of the cities
		strcpy(bestCityName, cityName);                   //updates the city's name that has the best livability
	}
}

/*
City                     Population dens.       Livability
Atlanta                        451.209            52.363
Boston                         517.143            36.146
Cincinnati                     298.633            72.542
Dallas                         251.294            77.090
Las_Vegas                      158.677            83.462
Los_Angeles                    576.611            16.672
Minneapolis                    303.487            72.202
New_York_City                  730.751             6.360
Seattle                        370.022            64.140
Washington_DC                  493.871            41.381

Best city: Las_Vegas, with a livability of 83.462
The 10 cities have an average livability of 52.236
*/
