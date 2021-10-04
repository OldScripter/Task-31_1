#include <iostream>
#include "include/SharedToyPtr.h"

#include "include/Dog.h"

int main()
{
    Dog* dogA = new Dog("A", SharedToyPtr::makeShared("Ball"));
    std::cout << "Dog A toy (" << dogA->getFavouriteToy().get()->getName() << "): " << dogA->getFavouriteToy().getUseCount() << "\n";

    Toy* toy = new Toy("Bone");
    std::cout << "Separately created Bone toy with the address: " << toy << "\n";
    Dog* dogB = new Dog("B", SharedToyPtr::makeShared(toy));
    Dog* dogC = new Dog("C", SharedToyPtr::makeShared(toy));
    Dog* dogD = new Dog("D", SharedToyPtr::makeShared(toy));
    std::cout << "---------------------\n";
    std::cout << "Dog A has a toy: " << dogA->getFavouriteToy().get()->getName() << " with address " << dogA->getFavouriteToy().get() << "\n";
    std::cout << "Dog B has a toy: " << dogB->getFavouriteToy().get()->getName() << " with address " << dogB->getFavouriteToy().get() << "\n";
    std::cout << "Dog C has a toy: " << dogC->getFavouriteToy().get()->getName() << " with address " << dogC->getFavouriteToy().get() << "\n";
    std::cout << "---------------------\n";
    std::cout << "Toys share pointers refs:\n";
    std::cout << "Dog A toy (" << dogA->getFavouriteToy().get()->getName() << "): " << dogA->getFavouriteToy().getUseCount() << "\n";
    std::cout << "Dog B toy (" << dogB->getFavouriteToy().get()->getName() << "): " << dogB->getFavouriteToy().getUseCount() << "\n";
    std::cout << "Dog C toy (" << dogC->getFavouriteToy().get()->getName() << "): " << dogC->getFavouriteToy().getUseCount() << "\n";
    delete dogA;
    delete dogB;
    std::cout << "---------------------\n";
    std::cout << "Dog A and B are deleted.\n";
    std::cout << "Dog C toy (" << dogC->getFavouriteToy().get()->getName() << "): " << dogC->getFavouriteToy().getUseCount();


    delete dogC;
    dogA = nullptr;
    dogB = nullptr;
    dogC = nullptr;
    return 0;
}
