#ifndef TASK_31_1_TOY_H
#define TASK_31_1_TOY_H

#include <iostream>

class Toy {

private:
    std::string name;

public:
    Toy(std::string name) : name(name){};
    Toy() : Toy("NoName") {};
    std::string getName() const;
};

#endif //TASK_31_1_TOY_H