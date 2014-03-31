#ifndef STATEMACHINE__H_
#define STATEMACHINE__H_

#include <memory>

#include "Map.h"

class State;
class Bot;

class StateMachine {
 private:
    std::shared_ptr<State> _state;
 public:
    StateMachine();
    StateMachine(std::shared_ptr<State> state);
    void update(const Map & map);
    void place(const Map & map);
    void move(const Map & map);
};

#endif // STATEMACHINE__H_
