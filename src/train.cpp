// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), current(nullptr) {}

Train::~Train() {
    if (!first) return;
    Car* carriage = first->next;
    while (carriage != first) {
        Car* tmp = carriage->next;
        delete carriage;
        carriage = tmp;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
        current = first;
    } else {
        Car* tail = first->prev;
        tail->next = newCar;
        newCar->prev = tail;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    resetOps();
    current = first;

    if (!current->light) {
        current->light = true;
    }

    int length = 0;
    bool done = false;

    while (!done) {
        while (true) {
            current = current->next;
            countOp++;
            length++;
            if (current->light) {
                current->light = false;
                break;
            }
        }
        int back = 0;
        while (back < length) {
            current = current->prev;
            countOp++;
            back++;
        }
        if (!current->light) {
            done = true;
        } else {
            length = 0;
        }
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}

void Train::resetOps() {
    countOp = 0;
}
