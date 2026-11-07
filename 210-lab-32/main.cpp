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
    deque<Car> myDeque;

    //Populates the que initially
    for (int i = 0; i < SIZE; i++) {
        myDeque.push_back(Car());
    }
    
    //Outputs the initial que
    cout << "Initial que: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "    ";
        myDeque[i].print();
    }

    simulate(myDeque);
    
    return 0;
}

//This function distributes the probabilbity of either a car paying and leaving or a car joining as 55% and 45% respectively. It accomplishes this via a while loop and two branched possibilities.
void simulate(deque<Car> &deq) {
    int count = 1;
    while (!deq.empty()) {
        int r = rand() % 100;
        //55% case
        if (r < 55) {
            cout << endl << "Time: " << count << " Operation: Car paid: ";
            deq.front().print();
            deq.pop_front();
            cout << "Queue: " << endl;
            for (int i = 0; i < deq.size(); i++) {
                cout << "    ";
                deq[i].print();
            }

        }
        //45% case
        else {
            cout << endl << "Time: " << count << " Operation: Joined lane: ";
            deq.push_back(Car());
            deq.back().print();
            cout << "Queue: " << endl;
            for (int i = 0; i < deq.size(); i++) {
                cout << "    ";
                deq[i].print();
            }
        }
    count++;
    }
    cout << "    " << "Empty" << endl;
}