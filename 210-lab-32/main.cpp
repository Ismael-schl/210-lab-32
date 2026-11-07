//Lab 32 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Car.h"
#include <deque>

using namespace std;

const int SIZE = 2;

int main() {
    deque<Car> myDeque;

    for (int i = 0; i < SIZE; i++) {
        myDeque.push_back(Car());
    }

    myDeque.back().print();
    myDeque.front().print();
    
    return 0;
}
