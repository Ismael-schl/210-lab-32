//Lab 33 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Car.h"
#include <deque>

using namespace std;

const int SIZE = 2;
const int LANESIZE = 4;

void simulate(deque<Car> &deq);
void print_lanes(deque<Car> lanes[LANESIZE]);

int main() {
    srand(time(0));
    deque<Car> lanes[LANESIZE];

    //Populates the que initially
    for (int j = 0; j < LANESIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
        lanes[j].push_back(Car());
        }
    }
    
    //Outputs the initial que
    cout << "Initial queue: " << endl;
    for (int j = 0; j < LANESIZE; j++) {
        cout << "Lane " << j+1 << ":" << endl;
        for (int i = 0; i < lanes[j].size(); i++) {
            cout << "    ";
            lanes[j][i].print();
        }
    }
    /*
    for (int i = 0; i < SIZE; i++) {
        cout << "    ";
        myDeque[i].print();
    }

    simulate(myDeque);
    */
    return 0;
}

void print_lanes(deque<Car> lanes[LANESIZE]) {
    for (int j = 0; j < LANESIZE; j++) {
        cout << "Lane " << j+1 << ":" << endl;
        if (lanes[j].empty()) {
            cout << "empty" << endl;
        }
        else {
        for (int i = 0; i < lanes[j].size(); i++) {
            cout << "    ";
            lanes[j][i].print();
            }
        }
    }
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