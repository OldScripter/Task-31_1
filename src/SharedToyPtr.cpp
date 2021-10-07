#include "../include/SharedToyPtr.h"

SharedToyPtr makeSharedToy(std::string name)
{
    return {name};
}

SharedToyPtr makeSharedToy(Toy* toy)
{
    if (toy == nullptr)
        return SharedToyPtr();
    else
        return {toy};
}

unsigned long SharedToyPtr::getUseCount() const {
    if (controlBlock == nullptr)
    {
        return 0;
    }
    else
    {
        return controlBlock->getUseCount();
    }
}

void SharedToyPtr::reset()
{
    if (controlBlock == nullptr)
        return;
    else
    {
        controlBlock->decrementUseCount();
        controlBlock = nullptr;
    }
}

SharedToyPtr::SharedToyPtr(const SharedToyPtr &other)
{
    if (other.controlBlock != nullptr)
    {
        this->controlBlock = other.controlBlock;
        this->controlBlock->incrementUseCount();
    }
}

SharedToyPtr &SharedToyPtr::operator=(const SharedToyPtr &other){

    if (this->controlBlock == other.controlBlock)
        return *this;
    else if (this->controlBlock != nullptr)
        this->controlBlock->decrementUseCount();

    this->controlBlock = other.controlBlock;

    if (this->controlBlock != nullptr)
        this->controlBlock->incrementUseCount();
    return *this;
}

Toy *SharedToyPtr::get() {
    if (controlBlock == nullptr)
    {
        return nullptr;
    }
    else
    {
        return controlBlock->getToy();
    }
}

ControlBlock *SharedToyPtr::getControlBlock() {
    return controlBlock;
}

SharedToyPtr::~SharedToyPtr()
{
    std::cout << "SharedPtr is deleted " << this << "\n";
    if (controlBlock != nullptr)
    {
        controlBlock->decrementUseCount();
    }
}