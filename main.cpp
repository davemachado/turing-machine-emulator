#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "State.h"

using std::cout;
using std::endl;
using std::string;

std::vector<State> parseMachine(char* filename) {
    std::ifstream file(filename);
    string str;
    std::vector<State> states;
    while (std::getline(file, str)) {
        if (str.find(';', 0) == 0 || str.length() == 0) {
            continue;
        } else {
            char *tokString = new char[str.length() + 1];
            std::strcpy(tokString, str.c_str());
            char *p = strtok(tokString, " ");
            State tempState;
            int indexCnt = 0;
            while (p && indexCnt < 5) {
                if (p[0] == ';') break;
                switch (indexCnt) {
                    case 0:
                        tempState.setName(p);
                        break;
                    case 1:
                        tempState.setCurrentSymbol(p[0]);
                        break;
                    case 2:
                        tempState.setNewSymbol(p[0]);
                        break;
                    case 3:
                        tempState.setDirection(p[0]);
                        break;
                    case 4:
                        tempState.setNewState(p);
                        break;
                    default:
                        break;
                }
                indexCnt++;
                p = strtok(NULL, " ");
            }
            states.push_back(tempState);
        }
    }
    return states;
}

bool runMachine(std::vector<State> states, string input) {
    string currentStateName = "0";
    State *curStatePtr = NULL;
    int headPos = 0, endOfTape = (int) input.size();

    char tape[256];
    for (int i = 0; i < 256; ++i) {
        if (i < input.size())
            tape[i] = input.at(i);
        else
            tape[i] = '_';
    }

    while (true) {
        for (int i = 0; i < endOfTape; ++i)
            cout << tape[i];
        cout << endl;
        for (int i = 0; i < headPos; ++i)
            cout << ' ';
        cout << '^' << endl;
        cout << headPos << "/" << endOfTape << endl;
        cout << "Current State: " << currentStateName << "\tCurrent Symbol: " << tape[headPos] << endl;
        for (int i = 0; i < states.size(); ++i) {
            cout << "Looking at state: " << states.at(i).getName() << endl;
            if (states.at(i).getName() == currentStateName) {
                cout << "\tLooking at symbol: " << states.at(i).getCurrentSymbol() << endl;
                if (states.at(i).getCurrentSymbol() == tape[headPos] || states.at(i).getCurrentSymbol() == '*') {
                    curStatePtr = &states.at(i);
                    cout << "Matched this state: " << *curStatePtr << endl;
                    break;
                }
            }
        }
        if (curStatePtr == NULL) {
            cout << "No matching state!" << endl;
            exit(2);
        }
        currentStateName = curStatePtr->getNewState();
        tape[headPos] = curStatePtr->getNewSymbol();
        if (currentStateName == "halt-accept")
            return true;
        if (currentStateName == "halt-reject")
            return false;

        if (curStatePtr->getDirection() == 'r') {
            headPos += 1;
        } else if (curStatePtr->getDirection() == 'l') {
            if (headPos == 0)
                headPos = 0;
            else
                headPos -= 1;
        } else {}
        if (headPos >= endOfTape)
            endOfTape++;
        curStatePtr = NULL;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No Turing Machine given." << endl;
        exit(1);
    }
    std::vector<State> states = parseMachine(argv[1]);
    bool rslt = runMachine(states, "1001001");

    if (rslt) {
        cout << "ACCEPT!" << endl;
    } else {
        cout << "REJECT!" << endl;
    }
    return 0;
}
