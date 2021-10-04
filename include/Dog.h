#ifndef TASK_31_1_DOG_H
#define TASK_31_1_DOG_H

#include "SharedToyPtr.h"

class Dog {

private:
    std::string name;
    SharedToyPtr favouriteToy;

public:
    Dog() : Dog("NoName", nullptr) {};
    Dog(std::string name) :  Dog(name, nullptr) {};
    Dog(SharedToyPtr favouriteToy) : Dog("NoName", favouriteToy) {};
    Dog(std::string name, SharedToyPtr favouriteToy) : name (name), favouriteToy(favouriteToy) {};
    SharedToyPtr getFavouriteToy() const;
};

#endif //TASK_31_1_DOG_H