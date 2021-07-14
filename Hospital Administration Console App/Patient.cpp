//
// Created by Diamond Martin on 4/19/21.
//

#include "Patient.h"
Patient::Patient(string fName, string mName, string lName, string suf, vector<string> ail, string doc, int tre, int pri)
    : firstName(fName), middleName(mName), lastName(lName), suffix(suf), ailments(ail), doctor(doc), treated(tre), priority(pri)
    {
    currentID = id++;
    }
int Patient:: id = 1;
void Patient::printReport() {
    cout << "\n" + firstName + "'s Report" +
            "\nID: " + to_string(currentID) +
            "\nFirst name: " + firstName +
            "\nMiddle name: " + middleName +
            "\nLast name: " + lastName +
            "\nSuffix: " + suffix +
            "\nAilment: " + printAilments() +
            "\nDoctor: " + doctor +
            "\nTreated: " + to_string(treated) +
            "\nPriority: " + to_string(priority) + "\n";
}

string Patient::printAilments() {
    string elem;
    string ailmentList;
    for (int i = 0; i < ailments.size(); ++i) {
        elem = ailments[i];
        if (i != ailments.size() - 1) {
            ailmentList += elem + ", ";
        }
        else {
            ailmentList += elem;
        }

    }
    return ailmentList;
}

string Patient::getFullName() const {
    return firstName + " " + middleName + " " + lastName;
}

string Patient::getFirstName() const {
    return firstName;
}

void Patient::setFirstName(string firstName) {
    Patient::firstName = firstName;
}

string Patient::getMiddleName() const {
    return middleName;
}

void Patient::setMiddleName(string middleName) {
    Patient::middleName = middleName;
}

string Patient::getLastName() const {
    return lastName;
}

void Patient::setLastName(string lastName) {
    Patient::lastName = lastName;
}

string Patient::getSuffix() const {
    return suffix;
}

void Patient::setSuffix(string suffix) {
    Patient::suffix = suffix;
}

vector<string> Patient::getAilment() const {
    return ailments;
}

void Patient::setAilment(vector<string> ailments) {
    Patient::ailments = ailments;
}

string Patient::getDoctor() const {
    return doctor;
}

void Patient::setDoctor(string doctor) {
    Patient::doctor = doctor;
}

int Patient::getTreated() const {
    return treated;
}

void Patient::setTreated(int treated) {
    Patient::treated = treated;
}

int Patient::getPriority() const {
    return priority;
}

void Patient::setPriority(int priority) {
    Patient::priority = priority;
}

int Patient::getCurrentId() const {
    return currentID;
}

void Patient::setCurrentId(int currentId) {
    currentID = currentId;
}

bool Patient::operator>(const Patient &rhs) const {
    return priority > rhs.priority;
}