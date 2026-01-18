#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// ===== SECTION A: CONSTANTS & GLOBAL ARRAYS =====
// Lakin will work here

// ===== END SECTION A =====

int main()
{
    // ===== SECTION B: WELCOME MESSAGE =====
    // (kept for structure clarity)

    // ===== SECTION C: BOOKING LOGIC =====
    // Kidist will work here

    // ===== SECTION D: DISPLAY RESERVED ROOMS =====
    // Koket will work here

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
