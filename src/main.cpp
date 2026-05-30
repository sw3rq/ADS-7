// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << "n\tfalse\t\ttrue\t\trandom\n";

    for (int n = 2; n <= 100; n++) {
        int opsFalse, opsTrue, opsRandom;

        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(false);
            train.getLength();
            opsFalse = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(true);
            train.getLength();
            opsTrue = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(std::rand() % 2);
            train.getLength();
            opsRandom = train.getOpCount();
        }

        std::cout << n << "\t"
                  << opsFalse << "\t\t"
                  << opsTrue  << "\t\t"
                  << opsRandom << "\n";
    }
    return 0;
}
