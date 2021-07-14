//
// Created by Diamond Martin on 4/19/21.
//

#ifndef CLASS_PATIENT_H
#define CLASS_PATIENT_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Patient {
public:
    Patient(string fName, string mName, string lName, string suf,
            vector<string> ail, string doc, int tre, int pri);
    void printReport();

    string printAilments();

    string getFullName() const;

    string getFirstName() const;

    void setFirstName(string firstName);

    string getMiddleName() const;

    void setMiddleName(string middleName);

    string getLastName() const;

    void setLastName(string lastName);

    string getSuffix() const;

    void setSuffix(string suffix);

    vector<string> getAilment() const;

    void setAilment(vector<string> ailments);

    string getDoctor() const;

    void setDoctor(string doctor);

    int getTreated() const;

    void setTreated(int treated);

    int getPriority() const;

    void setPriority(int priority);

    bool operator<(const Patient &rhs) const;

    bool operator>(const Patient &rhs) const;

    bool operator<=(const Patient &rhs) const;

    bool operator>=(const Patient &rhs) const;

    bool operator==(const Patient &rhs) const;

    bool operator!=(const Patient &rhs) const;

    int getCurrentId() const;

    void setCurrentId(int currentId);


private:
    int currentID;
    static int id;
    string firstName;
    string middleName;
    string lastName;
    string suffix;
    vector<string> ailments;
    string doctor;
    int treated;
    int priority;
};

#endif //CLASS_PATIENT_H
