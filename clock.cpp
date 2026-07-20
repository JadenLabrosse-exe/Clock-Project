/***************************************************************
Developer: Jaden
Date: 07/15/2026
Purpose: Display 12-hour and 24-hour clocks simultaneously and allow the user to add hours, minutes, or seconds.
****************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Add one hour and wrap around
    void addHour(bool is24) {
        hours++;
        if (is24) {
            if (hours > 23) hours = 0;   // 24-hour wrap around
        }
        else {
            if (hours > 12) hours = 1;   // 12-hour wrap around
        }
    }

    // Add one minute and wrap around
    void addMinute(bool is24) {
        minutes++;
        if (minutes > 59) {
            minutes = 0;
            addHour(is24);
        }
    }

    // Add one second and wrap correctly
    void addSecond(bool is24) {
        seconds++;
        if (seconds > 59) {
            seconds = 0;
            addMinute(is24);
        }
    }

    // Display formatted time
    void display(bool is24) {
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds;
        if (!is24) {
            cout << (hours >= 12 ? " PM" : " AM");
        }
    }
};

void printMenu() { // Menu
    cout << "\n**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
    cout << "Enter your choice: ";
}

int main() {

    // Initial time input
    int h, m, s;
    cout << "Enter starting hour: ";
    cin >> h;
    while (h < 0 || h > 23) { // Catches bad hour input
        cout << "Invalid hour. Enter a value between 1 and 23. \nRe-enter: ";
        cin >> h;
    }
    cout << "Enter starting minute: ";
    cin >> m;
    while (m < 0 || m > 59) { // Catches bad minute input
        cout << "Invalid minute. Enter a value between 0 and 59. \nRe-enter: ";
        cin >> m;
    }
    cout << "Enter starting second: ";
    cin >> s;
    while (s < 0 || s > 59) { // Catches bad second input
        cout << "Invalid second. Enter a value between 0 and 59 \nRe-enter: ";
        cin >> s;
    }

    // Create 12 and 24 hour clocks
    Clock clock12(h, m, s);
    Clock clock24(h, m, s);

    int choice = 0;

    // Loops until user exits program
    while (choice != 4) {

        // Display 12-hour clock
        cout << "**************************\n";
        cout << "*     12-Hour Clock      *\n";
        cout << "*     ";
        clock12.display(false);
        cout << "        *\n";
        cout << "**************************\n\n";

        // Display 24-hour clock
        cout << "**************************\n";
        cout << "*     24-Hour Clock      *\n";
        cout << "*     ";
        clock24.display(true);
        cout << "           *\n";
        cout << "**************************\n\n";

        // Display menu
        printMenu();
        cin >> choice;

        // Process user choice
        if (choice == 1) {
            clock12.addHour(false);
            clock24.addHour(true);
        }
        else if (choice == 2) {
            clock12.addMinute(false);
            clock24.addMinute(true);
        }
        else if (choice == 3) {
            clock12.addSecond(false);
            clock24.addSecond(true);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}