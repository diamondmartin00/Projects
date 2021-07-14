//
// Created by Diamond Martin on 4/20/21.
//

#ifndef CLASS_MODE_H
#define CLASS_MODE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Mode {
public:
    Mode();

    void modeLog(const string message);

    void closeOutFile();

    bool isDebugMode() const;

    void setDebugMode(bool debugMode);

private:
    bool debugMode;
    ofstream outFile;
};


#endif //CLASS_MODE_H
