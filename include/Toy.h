#ifndef TASK_31_1_TOY_H
#define TASK_31_1_TOY_H

#include <iostream>

class Toy {

private:
    std::string name;

public:
    Toy() : name ("noName"){std::cout << "Toy is created: " << name << ", " << this << "\n";};
    Toy(std::string name) : name (name){std::cout << "Toy is created: " << name << ", " << this << "\n";};
    ~Toy();
};

#endif //TASK_31_1_TOY_H