#include "StateMachine.h"
#include "State.h"

StateMachine::StateMachine():_state(nullptr){}
StateMachine::StateMachine(std::shared_ptr<State> state):_state(state) {}

void StateMachine::update(const Map & map) {
    _state = _state->update(map);
}

void StateMachine::place(const Map & map) {
    _state->place(map);
}

void StateMachine::move(const Map & map) {
    _state->move(map);
}
