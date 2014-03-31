#ifndef STATE__H_
#define STATE__H_
#include <memory>

class Bot;

class State {
 private:
    Bot & _bot;
 public:
    State(Bot & bot): _bot(bot) {}
    virtual void enter() = 0;
    virtual std::shared_ptr<State> update(const Map & map) = 0;
    virtual void place(const Map & map) = 0;
    virtual void move(const Map & map) = 0;
    virtual void exit() = 0;    
};

#endif // STATE__H_
