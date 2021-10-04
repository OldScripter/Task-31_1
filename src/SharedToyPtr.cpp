#include "../include/SharedToyPtr.h"

SharedToyPtr::SharedToyPtr(Toy *toy)
{
    object = toy;
    if (object == nullptr)
        return;

    try
    {
        useCount = new int(1);
    }
    catch(...)
    {
        delete object;
        std::cerr << "Bad counter allocation.\n";
    }
}

SharedToyPtr::SharedToyPtr(std::string name)
{
    try
    {
        object = new Toy(name);
    }
    catch (...)
    {
        std::cerr << "Bad counter allocation.\n";
        return;
    }

    try
    {
        useCount = new int(1);
    }
    catch(...)
    {
        delete object;
        std::cerr << "Bad counter allocation.\n";
    }
}

SharedToyPtr::SharedToyPtr(const SharedToyPtr & other)
{
    object = other.object;
    useCount = other.useCount;

    if (object == nullptr)
        return;

    ++*useCount;
}

SharedToyPtr::~SharedToyPtr()
{
    if (object == nullptr)
        return;
    else
    {
        --*useCount;
        if (*useCount <= 0)
        {
            delete object;
            delete useCount;
            object = nullptr;
            useCount = nullptr;
        }
    }
}

SharedToyPtr & SharedToyPtr::operator=(const SharedToyPtr & other)
{
    if (this == &other || other.object == nullptr || other.useCount == nullptr)
    {
        return *this;
    }

    if (object == nullptr && useCount == nullptr)
    {
        object = other.object;
        useCount = other.useCount;
        ++*useCount;
    }
    return *this;
}

SharedToyPtr SharedToyPtr::makeShared(std::string name)
{
    Toy *toy = new Toy(name);
    return SharedToyPtr(toy);
}

SharedToyPtr SharedToyPtr::makeShared(Toy *toy) {
    return SharedToyPtr(toy);
}

Toy *SharedToyPtr::get() {
    return object;
}

int SharedToyPtr::getUseCount() {
    return *useCount;
}





