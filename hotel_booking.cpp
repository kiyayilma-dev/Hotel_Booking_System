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

    return 0;
}
