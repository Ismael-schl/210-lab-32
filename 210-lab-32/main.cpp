//Lab 33 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Car.h"
#include <deque>

using namespace std;

const int SIZE = 2;
const int LANESIZE = 4;

const int PROPTOT = 100;
const int PROBPAID = 46;
const int PROBJOIN = 39;
const int PERIODS  = 20;

void simulate(deque<Car> lanes[LANESIZE]);
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
    print_lanes(lanes);

    simulate(lanes);
    /*
    cout << "Test operations on queue:  " << endl;
    cout << "After taking one car away from every lane: " << endl;
    for (int i = 0; i < LANESIZE; i++) {
        lanes[i].pop_front();
    }
    
    print_lanes(lanes);
    */
    return 0;
}

//This function takes the array of deques and outputs every car. It also considers the empty case.
void print_lanes(deque<Car> lanes[LANESIZE]) {
    for (int j = 0; j < LANESIZE; j++) {
        cout << "Lane " << j+1 << " Queue:" << endl;
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
    cout << endl;
}

//This function distributes the probabilbity of either a car paying and leaving or a car joining as 
void simulate(deque<Car> lanes[LANESIZE]) {
    for (int i = 0; i < PERIODS; i++) {
        int count = i+1;
        cout << endl << "Time: " << count << endl;
        for (int j = 0; j < LANESIZE; j++) {
            int r = rand() % PROPTOT;
            cout << "Lane: " << j+1;
            if (lanes[j].empty()) {
                if (r < 50) {
                    cout << " Joined: ";
                    lanes[j].push_back(Car());
                    lanes[j].back().print();
                }
                else {
                    cout << "   Unaffected";
                }
            }
            else {
                if (r < PROBPAID) {
                cout << " Paid: ";
                lanes[j].front().print();
                lanes[j].pop_front();
                }
                else if (r < PROBJOIN + PROBPAID) {
                    cout << " Joined: ";
                    lanes[j].push_back(Car());
                    lanes[j].back().print();
                }
                else {
                    cout << " Switched: ";

                } 
            }
        }
           
        print_lanes(lanes);
    } 
}
