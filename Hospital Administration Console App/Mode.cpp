//
// Created by Diamond Martin on 4/20/21.
//

#include "Mode.h"
Mode::Mode() {
    debugMode = false;
    outFile.open("/Users/diamondmartin/CLionProjects/Class/OperationsLog.txt");
    if (outFile.fail()) {
        cout << "Unable to open output file" << endl;
        exit(1);
    }
}

bool Mode::isDebugMode() const {
    return debugMode;
}

void Mode::setDebugMode(bool debugMode) {
    Mode::debugMode = debugMode;
}

void Mode::modeLog(string message) {
    if (debugMode) { //true means it's on debug mode
        cout << "\n" + message << endl;
    } else { //otherwise, it's on normal mode
        outFile << message << endl;
    }
}
void Mode::closeOutFile() {
    outFile.close();
}