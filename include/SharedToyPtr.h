#ifndef TASK_31_1_SHAREDTOYPTR_H
#define TASK_31_1_SHAREDTOYPTR_H

#include <iostream>
#include "ControlBlock.h"

class SharedToyPtr {

private:
    ControlBlock* controlBlock;
public:
    SharedToyPtr() : controlBlock(nullptr){};
    SharedToyPtr(Toy* toy) : controlBlock(new ControlBlock(toy)){};
    SharedToyPtr(std::string toyName) : controlBlock(new ControlBlock(toyName)){};
    ~SharedToyPtr();
    SharedToyPtr(const SharedToyPtr& other);
    SharedToyPtr& operator=(const SharedToyPtr& other);
    unsigned long getUseCount() const;
    void reset();
    Toy* get();
    ControlBlock* getControlBlock();
};

SharedToyPtr makeSharedToy(std::string name);
SharedToyPtr makeSharedToy(Toy* toy);

#endif //TASK_31_1_SHAREDTOYPTR_H