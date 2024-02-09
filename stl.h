#ifndef stl_h
#define stl_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Train {
private:
    string number;
    string departureTime;
    string destinationStation;

public:
    Train(const string& num, const string& depTime, const string& destStation)
        : number(num), departureTime(depTime), destinationStation(destStation) {}

    void display() const {
        cout << "Train number: " << number << ", Departure time: " << departureTime
            << ", Destination station: " << destinationStation << endl;
    }

    const string& getNumber() const {
        return number;
    }
};

class TrainStation {
private:
    vector<Train> trains;

public:
    void addTrain(const string& num, const string& depTime, const string& destStation) {
        trains.push_back(Train(num, depTime, destStation));
    }

    void displayAllTrains() const {
        cout << "All trains at the station:" << endl;
        for (const auto& train : trains) {
            train.display();
        }
    }

    void searchTrain(const string& trainNumber) const {
        bool found = false;
        for (const auto& train : trains) {
            if (train.getNumber() == trainNumber) {
                found = true;
                train.display();
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << trainNumber << " not found." << endl;
        }
    }
};
#endif
