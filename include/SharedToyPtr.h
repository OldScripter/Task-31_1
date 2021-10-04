#ifndef TASK_31_1_SHAREDTOYPTR_H
#define TASK_31_1_SHAREDTOYPTR_H

#include <iostream>
#include "Toy.h"

class SharedToyPtr {

private:
    Toy* object;
    int* useCount;
public:
    //Конструктор
    SharedToyPtr() : object(nullptr), useCount(nullptr){};
    SharedToyPtr(Toy* toy);
    SharedToyPtr(std::string name);
    //Конструктор копирования
    SharedToyPtr(const SharedToyPtr& other);
    //Конструктор присваивания
    SharedToyPtr& operator= (const SharedToyPtr& other);
    //Деструктор
    ~SharedToyPtr();
    //Make shared
    static SharedToyPtr makeShared(std::string name);
    static SharedToyPtr makeShared(Toy* toy);
    int getUseCount();
    //Get
    Toy* get();

};


#endif //TASK_31_1_SHAREDTOYPTR_H