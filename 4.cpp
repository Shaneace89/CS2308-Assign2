/*File Name: assign1_s_f88.cpp
 
 Author: Shane Fleming
 Date: 02/09/16
 Assignment Number: 2
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Small Store Inventory*/

#include <iostream>
#include <iomanip>

using namespace std;

int x = 0;
const int nameWidth = 19;
const char separator = ' ';

template<typename T> void print(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}

struct
{
    string name;
    string location;
    int quantity;
    double price;
}     product[101];

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

void addF()
{
    cout << "Enter the new product name:" << endl;
    cin >> ws;
    getline(cin, product[x].name);
    cout << "Enter the locator (no spaces):" << endl;
    cin >> product[x].location;
    cout << "Enter the quantity (0 or more):" << endl;
    cin >> product[x].quantity;
    cout << "Enter the price (greater than 0):" << endl;
    cin >> product[x].price;
    x++;
}

void displayF()
{
    int k = 0;
    
    print("Product", nameWidth); print("Location", nameWidth);
    print("Quantity", nameWidth); print("Price", nameWidth);
    cout <<  endl
    << "_________________________________________________________________" << endl;
    
    while (product[k].price > 0 && product[k].quantity > -1)
    {
        print(product[k].name, nameWidth);
        print(product[k].location, nameWidth);
        print(product[k].quantity, nameWidth); cout << "$";
        cout << setprecision(2) << fixed;
        print(product[k].price, nameWidth); cout <<endl;
        k++;
    }
}

int main()
{
    int choice = 0, count = 0;
    
    while (choice != 6)
    {
        menuF();
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                if (count < 100)
                { addF();
                    count++;}
                else
                {
                    cout << "ERROR Storage is full! Please "
                    << "remove an item to contiune." << endl;
                }
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
                displayF();
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
