#include "../include/ControlBlock.h"

unsigned long ControlBlock::getUseCount() const
{
    return useCount;
}

void ControlBlock::incrementUseCount()
{
    ++useCount;
}

void ControlBlock::decrementUseCount()
{
    if (useCount > 1)
    {
        --useCount;
    }
    else
    {
        delete this;
    }
}

Toy *ControlBlock::getToy()
{
    return toy;
}

ControlBlock::~ControlBlock()
{
    std::cout << "ControlBlock is deleted " << this << "\n";
    if (useCount > 0 && toy != nullptr)
        delete toy;
}