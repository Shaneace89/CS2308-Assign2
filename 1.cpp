/*File Name: assign1_s_f88.cpp
 
 Author: Shane Fleming
 Date: 02/09/16
 Assignment Number: 2
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Small Store Inventory*/

#include <iostream>

using namespace std;

void menuF()
{
    cout << "Manage Inventory Menu" << endl << endl
    << "1. Add product" << endl
    << "2. Remove product" << endl
    << "3. Adjust quantity of a product" << endl
    << "4. Display a product" << endl
    << "5. Display inventory sorted by product name" << endl
    << "6. Quit the Program" << endl << endl
    << "Enter your choice: ";
}

int main()
{
    int choice = 0;
    
    while (choice != 6)
    {
        menuF();
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "case1" << endl;
                break;
            case 2:
                cout << "case2" << endl;
                break;
            case 3:
                cout << "case3" << endl;
                break;
            case 4:
                cout << "case4" << endl;
                break;
            case 5:
                cout << "case5" << endl;
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Please Enter Valid Choice" << endl;
        }
    }
    
    return 0;
}
