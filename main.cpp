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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No Turing Machine given." << endl;
        exit(1);
    }
    std::vector<State> states = parseMachine(argv[1]);
    for (std::vector<State>::iterator i = states.begin(); i != states.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}