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
