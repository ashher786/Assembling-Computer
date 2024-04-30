/*Syed Ashher Majid
  23i-007
  CS(A)
  Dr.Ali Zeeshan
  Mohammad Abdul Rafay
*/



#include <iostream>
#include <string>
#include<cstring>
#include "i23-0007_A.h" // Include necessary headers for ComputerAssembly, AppleComputerAssembly, and PCComputerAssembly


using namespace std;

int main() {
    string userChoice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Welcome! Are you building a Mac or a PC? (Type 'Mac' or 'PC'): ";
        cin >> userChoice;

        if (userChoice == "Mac") {
            AppleComputerAssembly* appleassembly = new AppleComputerAssembly();
            appleassembly->insert();
            appleassembly->display();
            delete appleassembly; // Delete the allocated memory for appleassembly
            validChoice = true;
        }
        else if (userChoice == "PC") {
            PCComputerAssembly* pcassembly = new PCComputerAssembly();
            pcassembly->insert();
            pcassembly->display();
            delete pcassembly; // Delete the allocated memory for pcassembly
            validChoice = true;
        }
        else {
            cout << "Invalid choice. Please enter 'Mac' or 'PC'." << endl;
        }
    }

    return 0; // Exit program successfully
}