#include <iostream>

using namespace std;

const int NAME_SIZE = 50;

void addStop(char* names[], int* arrivalTimes, int& numStops, char* name, int arrivalTime) {
    if (numStops == 0) {
        names[numStops] = new char[NAME_SIZE];
        int i = 0;
        while (name[i] != '\0' && i < NAME_SIZE - 1) {
            names[numStops][i] = name[i];
            i++;
        }
        names[numStops][i] = '\0';
        arrivalTimes[numStops] = arrivalTime;
        numStops++;
    }
    else {
        int i = numStops - 1;
        while (i >= 0 && arrivalTime < arrivalTimes[i]) {
            names[i + 1] = names[i];
            arrivalTimes[i + 1] = arrivalTimes[i];
            i--;
        }
        i++;
        names[i] = new char[NAME_SIZE];
        int j = 0;
        while (name[j] != '\0' && j < NAME_SIZE - 1) {
            names[i][j] = name[j];
            j++;
        }
        names[i][j] = '\0';
        arrivalTimes[i] = arrivalTime;
        numStops++;
    }
}

void printRoute(char* names[], int* arrivalTimes, int numStops) {
    cout << "run: ";
    if (arrivalTimes[0] < arrivalTimes[numStops - 1]) {
        cout << names[0] << " -> " << names[numStops - 1] << endl;
    }
    else {
        cout << names[numStops - 1] << " -> " << names[0] << endl;
    }
}

int main() {
    const int MAX_STOPS = 10;
    char* names[MAX_STOPS];
    int arrivalTimes[MAX_STOPS];
    int numStops = 0;
    const char* stop1 = "stop 1  ";
    const char* stop2 = "stop 2 ";
    const char* stop3 = "stop 3 ";
    addStop(names, arrivalTimes, numStops, (char*)stop1, 100);
    addStop(names, arrivalTimes, numStops, (char*)stop2, 900);
    addStop(names, arrivalTimes, numStops, (char*)stop3, 30);
    printRoute(names, arrivalTimes, numStops);
    for (int i = 0; i < numStops; i++) {
        delete[] names[i];
    }
    return 0;
}
