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

    // ===== SECTION C: BOOKING LOGIC =====
    // Kidist will work here

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
