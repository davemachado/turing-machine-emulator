//
// Created by Dave on 4/6/17.
//

#ifndef TURINGMACHINE_STATE_H
#define TURINGMACHINE_STATE_H

#include <string>
#include <ostream>

class State {
public:

private:
    std::string name;
    char currentSymbol;
    char newSymbol;
    char direction;
    std::string newState;
public:

    State();

    State(const std::string &name, char currentSymbol, char newSymbol,
          char direction, const std::string &newState);

    const std::string &getName() const;

    void setName(const std::string &name);

    char getCurrentSymbol() const;

    void setCurrentSymbol(char currentSymbol);

    char getNewSymbol() const;

    void setNewSymbol(char newSymbol);

    char getDirection() const;

    void setDirection(char direction);

    const std::string &getNewState() const;

    void setNewState(const std::string &newState);

    friend std::ostream &operator<<(std::ostream &os, const State &state1);

};

#endif //TURINGMACHINE_STATE_H
