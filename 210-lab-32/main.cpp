//Lab 32 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Car.h"
#include <deque>

using namespace std;

const int SIZE = 2;

void simulate(deque<int> &deq);

int main() {
    srand(time(0));
    deque<Car> myDeque;

    for (int i = 0; i < SIZE; i++) {
        myDeque.push_back(Car());
    }

    myDeque.back().print();
    myDeque.front().print();
    
    return 0;
}

void simulate(deque<Car> &deq) {
    int count = 1;
    while (!deq.empty()) {
        int r = rand() % 100;
        //55% case
        if (r < 55) {
            cout << "Time: " << count << " Operation: Car paid: ";
            deq.front().print();
            cout << endl << "Queue: "
        }
        //45% case
        else {

        }
    count++;
    }
}