//Lab 32 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Car.h"
#include <deque>

using namespace std;

const int SIZE = 2;

void simulate(deque<Car> &deq);

int main() {
    srand(time(0));
    deque<Car> myDeque(SIZE);

    for (int i = 0; i < SIZE; i++) {
        myDeque.push_back(Car());
    }

    simulate(myDeque);
    
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
            deq.pop_front();
            cout << endl << "Queue: " << endl;
            for (int i = 0; i < deq.size(); i++) {
                cout << "    ";
                deq[i].print();
                cout << endl;
            }

        }
        //45% case
        else {
            cout << "Time: " << count << " Operation: Joined lane: ";
            deq.push_back(Car());
            deq.back().print();
            cout << endl << "Queue: " << endl;
            for (int i = 0; i < deq.size(); i++) {
                cout << "    ";
                deq[i].print();
                cout << endl;
            }
        }
    count++;
    }
    cout << "    " << "Empty" << endl;
}