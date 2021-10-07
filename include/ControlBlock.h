#ifndef TASK_31_1_CONTROLBLOCK_H
#define TASK_31_1_CONTROLBLOCK_H

#include "Toy.h"

class ControlBlock {

private:
    unsigned long useCount;
    Toy* toy;

public:
    ControlBlock(Toy* toy) : useCount(1), toy(new Toy(*toy)){};
    ControlBlock(std::string toyName) : useCount(1), toy(new Toy(toyName)){};
    ~ControlBlock();
    unsigned long getUseCount() const;
    void incrementUseCount();
    void decrementUseCount();
    Toy* getToy();
};

#endif //TASK_31_1_CONTROLBLOCK_H