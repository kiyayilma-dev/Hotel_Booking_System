/*
===============================================================================
Project : Hotel Management Dashboard (v3.0)
Repo    : Hotel_Booking_System
Purpose : Professional Hotel Room Reservation & Management System (C++)
Author  : Group Project — Section C, Group 10
Team Members    :      id                 — Responsibilities
 - LAKIN AWEL          ETS0876/17        — Constants & Global Variables
 - KIDIST  TESFAYE     ETS0837/17        — Booking Logic
 - KOKET DESALEGN      ETS0872/17        — Display Reserved Rooms
 - KIYA YILMA          ETS0869/17        — Guest Search & Integration
 - LEULSEGED DEGU      ETS0896/17        — Booking Logic Integration & Testing

 
Date    : 2026-01-19

Description:
This program implements a robust, menu-driven Hotel Management System designed 
to handle the full lifecycle of a reservation. Unlike the previous version, 
this system allows staff to not only book rooms but also update guest details, 
cancel reservations, and view real-time occupancy in a formatted dashboard. 
It features professional input handling (fixing buffer overflows) and 
tabular data display.

Core Features:
 - Interactive Main Menu: Continuous operation without restarting the program.
 - Full Reservation Management:
   1. Book New Room (Create)
   2. View All Reservations (Read - Formatted Table)
   3. Update Guest Details (Update)
   4. Cancel/Delete Reservation (Delete)
 - Advanced Input Handling: Supports full names with spaces using getline/cin.ignore.
 - Data Visualization: Uses <iomanip> for aligned, professional status reports.
 - Search Functionality: Locate guests instantly by name.
 - Error Handling: Prevents double-booking, invalid inputs, and buffer errors.

Guidelines:
 - Use the Main Menu to navigate between tasks.
 - All room arrays are 0-indexed internally but displayed 1-based for users.
 - Compile with: g++ hotel_booking.cpp -o hotel && ./hotel

Usage :
 1. Run the executable to open the Dashboard.
 2. Select an option (1-6) from the menu.
 3. Follow prompts to manage reservations.
 4. Use the 'Show All' feature to generate a status report for screenshots.
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;


// ===== CONSTANTS & GLOBAL ARRAYS =====
const int rooms = 150;
const int oceanStart = 1, poolStart = 61, gardenStart = 111;

int roomStatus[rooms] = {0};
string guestNames[rooms], guestGender[rooms], reservationCodes[rooms];
int guestAge[rooms] = {0};

// Helper function to clean the input buffer
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;

    while (true) {
        cout << "\n=========================================================" << endl;
        cout << "           AASTU HOTEL MANAGEMENT DASHBOARD" << endl;
        cout << "=========================================================" << endl;
        cout << "1. Book a New Room" << endl;
        cout << "2. Show All Reserved Rooms" << endl;
        cout << "3. Update Reservation Details" << endl;
        cout << "4. Delete/Cancel Reservation" << endl;
        cout << "5. Search Guest by Name" << endl;
        cout << "6. Exit System" << endl;
        cout << "Select Option: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid Input. Numbers only!" << endl;
            clearBuffer();
            continue;
        }

        if (choice == 6) break;

        switch (choice) {
            case 1: { // BOOKING LOGIC
                int roomNum;
                cout << "Enter Room Number to Book (1-150): ";
                cin >> roomNum;
                int idx = roomNum - 1;

                if (idx < 0 || idx >= rooms) {
                    cout << "Error: Invalid Room Number." << endl;
                } else if (roomStatus[idx] == 1) {
                    cout << "Error: Room already occupied!" << endl;
                } else {
                    clearBuffer();
                    cout << "Full Name: "; getline(cin, guestNames[idx]);
                    cout << "Gender: "; getline(cin, guestGender[idx]);
                    cout << "Age: "; cin >> guestAge[idx];
                    clearBuffer();
                    cout << "Code: "; getline(cin, reservationCodes[idx]);
                    roomStatus[idx] = 1;
                    cout << ">> SUCCESS: Room " << roomNum << " Reserved." << endl;
                }
                break;
            }

            case 2: { // SHOW ALL RESERVED
                cout << "\n" << left << setw(8) << "ROOM" << setw(25) << "GUEST NAME" << "RESERVATION CODE" << endl;
                cout << string(50, '-') << endl;
                bool empty = true;
                for (int i = 0; i < rooms; i++) {
                    if (roomStatus[i] == 1) {
                        cout << left << setw(8) << i + 1 << setw(25) << guestNames[i] << reservationCodes[i] << endl;
                        empty = false;
                    }
                }
                if (empty) cout << "No rooms are currently reserved." << endl;
                break;
            }

            case 3: { // UPDATE LOGIC
                int roomNum;
                cout << "Enter Room Number to Update: ";
                cin >> roomNum;
                int idx = roomNum - 1;

                if (roomStatus[idx] == 0) {
                    cout << "Error: This room is empty. Nothing to update." << endl;
                } else {
                    clearBuffer();
                    cout << "Enter NEW Name (Current: " << guestNames[idx] << "): ";
                    getline(cin, guestNames[idx]);
                    cout << ">> Reservation Updated." << endl;
                }
                break;
            }

            case 4: { // DELETE/UNDO LOGIC
                int roomNum;
                cout << "Enter Room Number to Cancel: ";
                cin >> roomNum;
                int idx = roomNum - 1;

                if (roomStatus[idx] == 1) {
                    roomStatus[idx] = 0; // Resetting status to empty
                    guestNames[idx] = ""; // Clearing data
                    cout << ">> SUCCESS: Reservation for Room " << roomNum << " has been deleted." << endl;
                } else {
                    cout << "Error: Room is already empty." << endl;
                }
                break;
            }

            case 5: { // SEARCH LOGIC
                clearBuffer();
                string sName;
                cout << "Search Name: ";
                getline(cin, sName);
                bool found = false;
                for (int i = 0; i < rooms; i++) {
                    if (roomStatus[i] == 1 && guestNames[i] == sName) {
                        cout << ">> Found in Room " << i + 1 << " [Code: " << reservationCodes[i] << "]" << endl;
                        found = true;
                    }
                }
                if (!found) cout << "Guest not found." << endl;
                break;
            }

            default:
                cout << "Invalid choice." << endl;
        }
    }

    cout << "System shutting down... Goodbye!" << endl;
    return 0;
}