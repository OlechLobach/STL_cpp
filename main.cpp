#include"stl.h"

int main() {
    TrainStation station;

    char addAnother;
    do {
        string number, depTime, destStation;
        cout << "Enter train number: ";
        cin >> number;
        cout << "Enter departure time: ";
        cin >> depTime;
        cout << "Enter destination station: ";
        cin >> destStation;

        station.addTrain(number, depTime, destStation);

        cout << "Do you want to add another train? (y/n): ";
        cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    station.displayAllTrains();

    string searchNumber;
    cout << "Enter the train number to search: ";
    cin >> searchNumber;
    station.searchTrain(searchNumber);

    return 0;
}