//
// Created by Diamond Martin on 4/19/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>
#include "Patient.h"
#include "Mode.h"
void patientIDLookup(vector<Patient> patients);
void printUntreatedPatients(priority_queue<Patient, vector<Patient>, greater<Patient>> untreatedPatients);
using namespace std;
using namespace std::chrono;

int main() {
    vector<Patient> allPatients;
    priority_queue<Patient, vector<Patient>, greater<Patient>> untreatedPatients;
    vector<Patient> treatedPatients;
    Mode mode;
    int patientID;
    string firstName;
    string middleName;
    string lastName;
    string suffix;
    string ailment;
    vector<string> ailments;
    string doctor;
    int treated;
    int priority;
    bool isFinished = false;
    bool isValidTreat;
    bool isValidPriority;
    bool isValidInteger;
    bool isValidID;
    bool isNotEntering;
    bool doctorFound;
    char input[100];
    int waitTime;
    srand(time(0));
    int integerSelected;

    while (!isFinished) {
        isValidTreat = false;
        isValidPriority = false;
        isValidInteger = false;
        isValidID = false;
        isNotEntering = false;
        doctorFound = false;
        waitTime = (rand() % 3) + 1;

        cout << "\nEnter an number between 1 and 14 to select an option.\n"
                "Enter 1: Add a patient to the system\n"
                "Enter 2: Patient's ID lookup\n"
                "Enter 3: Treat a patient\n"
                "Enter 4: Print out a patient's information as a report\n"
                "Enter 5: Print out a report of all treated patients\n"
                "Enter 6: Know the next patient to be treated\n"
                "Enter 7: Print out a report of all the patients in triage\n"
                "Enter 8: Treat all patients\n"
                "Enter 9: Print out of all patients by doctor\n"
                "Enter 10: Add patients into the system from a file\n"
                "Enter 11: Turn debug mode on\n"
                "Enter 12: Turn debug mode off\n"
                "Enter 13: Quit\n"
                "Enter 14: Help\n";

        while (!isValidInteger) {
            cout << "Option selected: ";
            cin >> integerSelected;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You must enter a Number" << endl;
            }
            else {
                isValidInteger = true;
            }
        }

        switch (integerSelected) {
            case 1: { //New patient added to system
                cin.ignore(INT_MAX, '\n');
                cout << "\nEnter the patient's first name: ";
                cin.getline(input, sizeof(input));
                firstName = input;
                cout << "Enter the patient's middle name: ";
                cin.getline(input, sizeof(input));
                middleName = input;
                cout << "Enter the patient's last name: ";
                cin.getline(input, sizeof(input));
                lastName = input;
                cout << "Enter the patient's suffix: ";
                cin.getline(input, sizeof(input));
                suffix = input;
                while (!isNotEntering) {
                    cout << "Enter the patient's ailments one at a time (enter a dash when done): ";
                    cin.getline(input, sizeof(input));
                    ailment = input;
                    if (ailment != "-") {
                        ailments.emplace_back(ailment);
                    }
                    else {
                        isNotEntering = true;
                    }
                }
                cout << "Enter the patient's doctor name: ";
                cin.getline(input, sizeof(input));
                doctor = input;
                //check to make sure 0 or 1 is entered
                while (!isValidTreat) {
                    cout << "Enter the patient's treated number: ";
                    cin >> treated;
                    if (cin.fail() || treated < 0 || treated > 1) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nNumber must be a 0 or 1." << endl;
                    }
                    else {
                        isValidTreat = true;
                    }
                }
                //check that a number greater than 0 is entered
                string priorityNum;
                while (!isValidPriority) {
                    cout << "Enter the patient's priority number: ";
                    cin >> priority;
                    if (cin.fail() || priority < 1) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nNumber must be equal to or greater than 1." << endl;
                    }
                    else {
                        isValidPriority = true;
                    }
                }
                Patient addedPatient = Patient(firstName, middleName, lastName, suffix, ailments, doctor, treated, priority);
                allPatients.emplace_back(addedPatient);

                if (treated == 0) {
                    untreatedPatients.push(addedPatient);
                }
                else {
                    treatedPatients.emplace_back(addedPatient);
                }
                ailments.clear();
                cout << '\n' + addedPatient.getFullName() + " has been added to the system.\n";
                mode.modeLog("A nurse has added a new patient to the system.");
                break;
            }
            case 2: { //patient's ID look up
                patientIDLookup(allPatients);
                break;
            }
            case 3: { //treat a patient
                if (!untreatedPatients.empty()) {
                    Patient patient = untreatedPatients.top();
                    this_thread::sleep_for(seconds(waitTime));
                    for (vector<Patient>:: iterator itr = allPatients.begin(); itr != allPatients.end(); ++itr) {
                        if (patient.getCurrentId() == itr->getCurrentId()) {
                            itr->setTreated(1);
                            break;
                        }
                    }
                    patient.setTreated(1);
                    cout << "\n" + patient.getFullName() + " has been treated.\n";
                    treatedPatients.emplace_back(patient);
                    untreatedPatients.pop();
                }
                else {
                    cout << "\nThere are no patients left to be treated.\n";
                }
                mode.modeLog("A doctor has attepted to treat a patient in triage.");
                break;
            }
            case 4: { //print a patient's report
                while (!isValidID) {
                    cout << "\nIf the patient's ID is unknown, enter a 0 to do a patient's ID lookup by name.\n"
                            "Enter the patient's ID: ";
                    cin >> patientID;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nYou must enter a number" << endl;
                    } else if (patientID == 0) {
                        patientIDLookup(allPatients);
                    } else {
                        isValidID = true;
                    }
                }
                for (Patient patient : allPatients) {
                    if (patientID == patient.getCurrentId()) {
                        patient.printReport();
                    }
                }
                mode.modeLog("A doctor has printed a patient's report.");
                break;
                case 5: //print out all the treated patient's report
                    for (vector<Patient>::iterator itr = treatedPatients.begin(); itr != treatedPatients.end(); ++itr) {
                        itr->printReport();
                    }
                mode.modeLog("A doctor has printed all treated patients' reports.");
                break;
            }
            case 6: {//know the next patient to treat
                if (!untreatedPatients.empty()) {
                    Patient patient = untreatedPatients.top();
                    cout << "\nThe next patient to be treated is " + patient.getFullName() + ".\n";
                } else {
                    cout << "\nThere are no patients left to be treated.\n";
                }
                mode.modeLog("A doctor knows who the next patient to be treated.");
                break;
            }
            case 7: {//print out all the untreated patient's report
                printUntreatedPatients(untreatedPatients);
                mode.modeLog("A hospital administrator has printed out all the patients' reports that are in triage.");
                break;
            }
            case 8: {//treat all patients
                if (untreatedPatients.empty()) {
                    cout << "\nThere are no patients left to be treated.\n";
                }
                cout << '\n';
                while (!untreatedPatients.empty()) {
                    Patient patient = untreatedPatients.top();
                    this_thread::sleep_for(seconds(waitTime));
                    cout << patient.getFullName() + " has been treated." << endl;
                            patient.setTreated(1);
                    for (vector<Patient>::iterator itr = allPatients.begin(); itr != allPatients.end(); ++itr) {
                        if (itr->getCurrentId() == patient.getCurrentId()) {
                            itr->setTreated(1);
                        }
                    }
                    treatedPatients.emplace_back(patient);
                    untreatedPatients.pop();
                }
                mode.modeLog("A hospital administrator has treated all patients.");
                break;
            }
            case 9: {//print all patients by doctor
                cin.ignore(INT_MAX, '\n');
                cout << "\nEnter the patient's doctor name: ";
                cin.getline(input, sizeof(input));
                doctor = input;
                for (Patient patient: allPatients) {
                    if (doctor == patient.getDoctor()) {
                        doctorFound = true;
                    }
                }
                if (doctorFound) {
                cout << "\n" + doctor + "'s patients list:" << endl;
                for (Patient patient: allPatients) {
                    if (doctor == patient.getDoctor()) {
                        cout << patient.getFullName() << endl;
                    }
                }
                }
                else {
                    cout << "There is no doctor by the name of " + doctor << endl;
                }
                mode.modeLog("A hospital administrator has printed out all patients by doctor.");
                break;
            }
            case 10: { //Add patients into the system from a file
                string fileName;
                char delimiter = ':';
                string treatNum;
                string priorityNum;
                string information;
                string header;
                ifstream inFile;
                cout << "\nEnter the file name that you would like to add patients from: ";
                cin >> fileName;
                inFile.open(fileName);
                if (inFile.fail()) {
                    cout << "Unable to open input file." << endl;
                    exit(1);
                }
                while (!inFile.eof()) {
                    getline(inFile, information, delimiter);
                    if (information == "firstName") {
                        getline(inFile, firstName);
                    } else if (information == "middleName") {
                        getline(inFile, middleName);
                    } else if (information == "lastName") {
                        getline(inFile, lastName);
                    } else if (information == "suffix") {
                        getline(inFile, suffix);
                    } else if (information == "ailment") {
                        getline(inFile, ailment);
                        ailments.push_back(ailment);
                    } else if (information == "doctor") {
                        getline(inFile, doctor);
                    } else if (information == "treated") {
                        getline(inFile, treatNum);
                    }
                    else if (information == "priority") {
                        getline(inFile, priorityNum);
                        inFile.ignore();
                        try {
                            treated = stoi(treatNum);
                            priority = stoi(priorityNum);
                        } catch (const invalid_argument &e) {
                        }
                        Patient filePatient = Patient(firstName, middleName, lastName, suffix, ailments, doctor, treated, priority);
                        allPatients.emplace_back(filePatient);
                        cout << filePatient.getFullName() + " has been added to the system from a file.\n";
                        if (treated == 0) {
                            untreatedPatients.push(filePatient);
                        } else {
                            treatedPatients.emplace_back(filePatient);
                        }
                        ailments.clear();
                    }
                }
                inFile.close();
                mode.modeLog("A system administrator has added patients into the system from a file.");
                break;
            }
            case 11: { //set debug mode on
                mode.setDebugMode(true);
                mode.modeLog("A system administrator has turned debug mode on.");
                break;
            }
            case 12: {//set debug mode off
                mode.setDebugMode(false);
                mode.modeLog("A system administrator has turned debug mode off.");
                break;
            }
            case 13: {//quit
                isFinished = true;
                cout << "\nYou've exited out of the application. Have a Great Day!" << endl;
                mode.modeLog("The user has exit the application.");
                mode.closeOutFile();
                break;
            }
            case 14: {//help guide
                cout
                        << "\n1: Add a patient to the system - if there is a new patient that is not in the system, then the patient needs to be added to the system."
                           "\n\tThe patient's first name, middle name, last name, suffix, ailment, doctor's name, if they have been treated, and their priority is entered.\n"
                           "2: Patient's ID lookup - If the patient's ID is unknown, then entering their full name will list the patients that have that name.\n"
                           "3: Treat a patient - If a patient needs to be treated, then this option is selected to treat the patient.\n"
                           "4: Print out a patient's information as a report - If a certain patient's report needs to be printed, then the patient's ID must be entered to access their report.\n"
                           "5: Print out a report of all treated patients - If a report is needed of all treated patients, then this option is selected to print out the reports.\n"
                           "6: Know the next patient to be treated - The patients that still needs to be treated has a priority depending on the number they're given then"
                           "\n\tit's first come, first serve. This tells which patient is top priority.\n"
                           "7: Print out a report of all the patients in triage - All the patients' reports that are untreated are printed out.\n"
                           "8: Treat all patients - Treats all patients that are currently untreated.\n"
                           "9: Print out of all patients by doctor - All the patients' names with a certain doctor is printed out.\n"
                           "10: Add patients into the system from a file - With a formatted file, patients can be added in bulk.\n"
                           "\tThe patient's information should be formatted like this including the headers with a space between each new patient.\n"
                           "\tIf there are multiple ailments, then list each one at a time with its own ailment header.\n"
                           "\tfirstName:John\n"
                           "\tmiddleName:A\n"
                           "\tlastName:Doe\n"
                           "\tsuffix:\n"
                           "\tailment:broken toe\n"
                           "\tailment:bleeding\n"
                           "\tdoctor:Smith\n"
                           "\ttreated:1\n"
                           "\tpriority:1\n"
                           "11: Turn debug mode on - Turns debug mode on and all operations of the system by each user is logged to the console in debug mode.\n"
                           "12: Turn debug mode off - If debug mode is off, the system is in normal mode. All operations of the system by each user is logged into a file in normal mode.\n"
                           "13: Quit - To exit the application.\n";
                mode.modeLog("A user has accessed the help guide.");
                break;
            }
            default: {
                cout << "\nYou've enter an invalid number that is not an option. Please enter a valid number.\n";
                break;
            }
        }
    }
    return 0;
}

void patientIDLookup (vector<Patient> patients) {
    char input[50];
    Mode mode;
    bool isFound = false;
    string firstName;
    string middleName;
    string lastName;
    cin.ignore(INT_MAX, '\n');
    cout << "\nEnter the patient's first name: ";
    cin.getline(input, sizeof(input));
    firstName = input;
    cout << "Enter the patient's middle name: ";
    cin.getline(input, sizeof(input));
    middleName = input;
    cout << "Enter the patient's last name: ";
    cin.getline(input, sizeof(input));
    lastName = input;
    printf("\n%-10s%-15s%-15s%-15s%-15s%-50s%-20s%-10s%-10s\n", "ID", "First Name", "Middle Name", "Last Name", "Suffix", "Ailment", "Doctor", "Treated", "Priority");
    for (Patient patient: patients) {
        if (patient.getFirstName() == firstName && patient.getMiddleName() == middleName &&
            patient.getLastName() == lastName) {
            isFound = true;
            printf("%-10d%-15s%-15s%-15s%-15s%-50s%-20s%-10d%-10d\n", patient.getCurrentId(), patient.getFirstName().c_str(), patient.getMiddleName().c_str(),
                   patient.getLastName().c_str(), patient.getSuffix().c_str(),
                   patient.printAilments().c_str(), patient.getDoctor().c_str(), patient.getTreated(), patient.getPriority());
        }
    }
    if (!isFound) {
        cout << "No patients were found with the name " + firstName + " " + middleName + " " + lastName + ".\n";
    }
    mode.modeLog("An user has performed a patient's ID lookup.");
}

void printUntreatedPatients(priority_queue<Patient, vector<Patient>, greater<Patient>> untreatedPatients) {
    while (!untreatedPatients.empty()) {
        Patient patient = untreatedPatients.top();
        patient.printReport();
        untreatedPatients.pop();
    }
}