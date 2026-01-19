/*
===============================================================================
Project : Hotel Booking System
Repo    : Hotel_Booking_System
Purpose : Hotel Room Reservation System (C++)
Author  : Group Project — Section C, Group 10 (5 members)
Date    : [2026-01-18]
===============================================================================

Description:
This program implements a straightforward Hotel Room Reservation System where
guests can book rooms from three categories (Ocean View Suite, Poolside Villa,
Garden View Room). The system tracks room availability, stores guest details,
prevents double-booking, lists current reservations, and allows searching for
guests by name.

Core Features:
 - Menu-driven room selection (3 categories).
 - Input validation for room type and room number.
 - Stores guest data: name, gender, age, reservation code.
 - Prevents assigning an occupied room to a new guest.
 - Displays all reserved rooms (for staff review).
 - Search function to find a guest and show their reservation code.

Team Members    :      id                 — Responsibilities
 - LAKIN AWEL          ETS0876/17        — Constants & Global Variables
 - KIDIST  TESFAYE     ETS0837/17        — Booking Logic
 - KOKET DESALEGN      ETS0872/17        — Display Reserved Rooms
 - KIYA YILMA          ETS0869/17        — Guest Search & Integration
 - LEULSEGED DEGU      ETS0896/17        — Booking Logic Integration & Testing
Guidelines:
 - Keep logic unchanged unless team agrees.
 - If you modify this header, update the Date and Authors section.
 - Compile with: g++ hotel_booking.cpp -o hotel && ./hotel

Usage :
 1. Compile the program.
 2. Run executable and follow on-screen prompts to book rooms.
 3. After booking, view the list of reserved rooms and search by name.

===============================================================================
*/


#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// ===== SECTION A: CONSTANTS & GLOBAL ARRAYS =====
//lakin will work here

    // Koket will work here
const int rooms = 150;
const int roomCategory = 10;
const int oceanStart = 1;
const int poolStart = 61;
const int gardenStart = 111;

int roomStatus[rooms] = {};
string guestNames[rooms];
string guestGender[rooms];
int guestAge[rooms];
string reservationCodes[rooms];


int main()
{
    // ===== SECTION B: WELCOME MESSAGE =====
    // (kept for structure clarity)
    cout << "===============================================================================" << endl;
    cout << "              Welcome to AASTU's Hotel Room Reservation System" << endl;
    cout << "===============================================================================" << endl;

    char answer;
    do
    {
        int roomType, roomNumber;
        cout << "Please select the room type you want to book" << endl;
        cout << "1. Ocean View Suite" << endl;
        cout << "2. Poolside Villa" << endl;
        cout << "3. Garden View Room" << endl;
        cin >> roomType;

        if (roomType < 1 || roomType > 3)
        {
            cout << "Invalid input. Please select a valid room type." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int roomCategoryStart = (roomType == 1) ? oceanStart : (roomType == 2) ? poolStart
                                                                               : gardenStart;

        cout << "You have selected ";
        switch (roomType)
        {
        case 1:
            cout << "Ocean View Suite";
            break;
        case 2:
            cout << "Poolside Villa";
            break;
        case 3:
            cout << "Garden View Room";
            break;
        }
        cout << endl;

        cout << "Please select the room number you want to book" << endl;
        for (int i = 0; i < roomCategory; ++i)
        {
            cout << i + 1 << ". " << roomCategoryStart + i << endl;
        }

        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > roomCategory)
        {
            cout << "Invalid input. Please select a valid room number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int roomIndex = roomCategoryStart + roomNumber - 1;

        if (roomStatus[roomIndex] == 0)
        {
            cout << "Please enter your name: ";
            cin >> guestNames[roomIndex];
            cout << "Please enter your gender: ";
            cin >> guestGender[roomIndex];
            cout << "Please enter your age: ";
            cin >> guestAge[roomIndex];
            cout << "Please enter a unique reservation code: ";
            cin >> reservationCodes[roomIndex];

            roomStatus[roomIndex] = 1;
            cout << "You have successfully booked room " << roomCategoryStart + roomNumber << endl;
        }
        else
        {
            cout << "Room " << roomCategoryStart + roomNumber << " is not available." << endl;
        }

        cout << "Do you want to book another room? (Y/N)" << endl;
        cin >> answer;

    } while (answer == 'Y' || answer == 'y');

    cout << "Current Reserved Room Status:" << endl;

for (int i = 0; i < rooms; ++i)
{
    if (roomStatus[i] == 1)
    {
        cout << "Room " << i + 1
             << " is booked by " << guestNames[i] << endl;
    }
}


    // ===== SECTION E: SEARCH GUEST =====
    // Kiya will work here
    string searchName;
cout << "Enter a name to search for patrons: ";
cin >> searchName;

bool found = false;
for (int i = 0; i < rooms; ++i)
{
    if (guestNames[i] == searchName)
    {
        cout << "Guest found in room " << i + 1
             << ". Reservation code: " << reservationCodes[i] << endl;
        found = true;
        break;
    }
}

if (!found)
{
    cout << "No guest found with the given name." << endl;
}


    return 0;
}
