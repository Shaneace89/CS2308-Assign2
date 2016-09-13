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

void headerF()
{
    cout << endl;
    print("Product", nameWidth); print("Location", nameWidth);
    print("Quantity", nameWidth); print("Price", nameWidth);
    cout <<  endl
    << "_________________________________________________________________" << endl;
}

void displayF()
{
    int k = 0;
    
    headerF();
    
    while (product[k].price > 0 && product[k].quantity > -1)
    {
        print(product[k].name, nameWidth);
        print(product[k].location, nameWidth);
        print(product[k].quantity, nameWidth); cout << "$";
        cout << setprecision(2) << fixed;
        print(product[k].price, nameWidth); cout << endl;
        k++;
    }
    cout << endl;
}

void sortF(int size)
{
    bool swap;
    
    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (product[count].name > product[count + 1].name)
            {
                product[101] = product[count];
                product[count] = product[count + 1];
                product[count + 1] = product[101];
                swap = true;
            }
        }
    } while (swap);
}

int searchF(int size, string find)
{
    int first = 0,                // First array element
    last = size - 1,       // Last array element
    middle,                // Mid point of search
    position = -1;         // Position of search value
    bool found = false;        // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (product[middle].name == find)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (product[middle].name > find)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}

int main()
{
    int choice = 0, count = 0, found = 0;
    string findPro;
    
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
                cout << "Enter product name of product to find: ";
                cin >> findPro;
                sortF(count);
                found = searchF(count, findPro);
                headerF();
                print(product[found].name, nameWidth);
                print(product[found].location, nameWidth);
                print(product[found].quantity, nameWidth); cout << "$";
                cout << setprecision(2) << fixed;
                print(product[found].price, nameWidth); cout << endl << endl;
                break;
            case 5:
                sortF(count);
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
