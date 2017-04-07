//
// Created by Dave on 4/6/17.
//

#include "State.h"

State::State() {}

State::State(const std::string &name, char currentSymbol,
             char newSymbol, char direction,
             const std::string &newState) : name(name),
                    currentSymbol(currentSymbol), newSymbol(newSymbol),
                        direction(direction), newState(newState) {}

const std::string &State::getName() const {
    return name;
}

void State::setName(const std::string &name) {
    State::name = name;
}

char State::getCurrentSymbol() const {
    return currentSymbol;
}

void State::setCurrentSymbol(char currentSymbol) {
    State::currentSymbol = currentSymbol;
}

char State::getNewSymbol() const {
    return newSymbol;
}

void State::setNewSymbol(char newSymbol) {
    State::newSymbol = newSymbol;
}

char State::getDirection() const {
    return direction;
}

void State::setDirection(char direction) {
    State::direction = direction;
}

const std::string &State::getNewState() const {
    return newState;
}

void State::setNewState(const std::string &newState) {
    State::newState = newState;
}

std::ostream &operator<<(std::ostream &os, const State &state1) {
    os << "name: " << state1.name << " currentSymbol: "
       << state1.currentSymbol << " newSymbol: " << state1.newSymbol
       << " direction: " << state1.direction << " newState: "
       << state1.newState;
    return os;
}
