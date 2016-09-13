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

struct
{
    string name;
    string location;
    int quantity;
    double price;
}     product[101];

/******************************************************************
 print: Sets up a void function for formatting
 sets width, and setfill
 ******************************************************************/

template<typename T> void print(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}

/******************************************************************
 menuF: Displays the main Menu
 couts the main menu to be called from other functions
 ******************************************************************/

void menuF()
{
    cout << endl << "Manage Inventory Menu" << endl << endl
    << "1. Add product" << endl
    << "2. Remove product" << endl
    << "3. Adjust quantity of a product" << endl
    << "4. Display a product" << endl
    << "5. Display inventory sorted by product name" << endl
    << "6. Quit the Program" << endl << endl
    << "Enter your choice: ";
}

/******************************************************************
 addF: Allows user to input products with stipulations
 Allows new product to be added to struct "product"
 ******************************************************************/

void addF()
{
    cout << endl << "Enter the new product name:" << endl;
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

/******************************************************************
 headerF:  Displays a header for the store inventory
 Simple header function, wanted to clean up main()
 Uses fucntion void print, to reduce redundancy
 ******************************************************************/

void headerF()
{
    cout << endl;
    print("Product", nameWidth); print("Location", nameWidth);
    print("Quantity", nameWidth); print("Price", nameWidth);
    cout <<  endl
    << "_________________________________________________________________"
    << endl;
}

/******************************************************************
 displayF:  Displays entire stores inventory
 Calls headerF(), and print(), loops to print each item
 Uses fucntion void print, to reduce redundancy
 ******************************************************************/

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
}

/******************************************************************
 sortF:  Modified version of Pr8-4.cpp
 Takes an int as size, number of items in inventory
 Uses buble sort to sort entire inventory by product.name
 ******************************************************************/

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

/******************************************************************
 searchF:  Modified version of Pr8-2.cpp
 Takes a int as size, number of items in inventory
 Takes a string as find, specific product.name to find
 Uses binary search, to search entire inventory by product.name
 ******************************************************************/

int searchF(int size, string find)
{
    int first = 0,         // First array element
    last = size - 1,       // Last array element
    middle,                // Mid point of search
    position = -1;         // Postion of search value
    bool found = false;    // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (product[middle].name == find) 
        {
            found = true;
            position = middle;
        }
        else if (product[middle].name > find)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

/******************************************************************
 main:  While loop of menuF, to display choices for switch statment
 Takes in a int choice, and calls desired case 1-6
 Calls desired functions, and couts appropriate messages
 ******************************************************************/

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
                 int changeAmount;
                 cout << endl << "Enter product name of product to modify: ";
                 cin >> findPro;
                 sortF(count);
                 found = searchF(count, findPro);
                 if (found != -1)
                 {
                  cout << "Enter desired change to quantity"
                       << "(use negative value to decrease quantity)"
                       << endl;
                  cin >> changeAmount;
                  product[found].quantity += changeAmount;
                 }
                 else
                     cout << endl << "Item NOT Found Please Try Again" << endl;
                 break;
            case 4:
                cout << endl << "Enter product name of product to find: ";
                cin >> findPro;
                sortF(count);
                found = searchF(count, findPro);
                if (found != -1)
                {
                    headerF();
                    print(product[found].name, nameWidth);
                    print(product[found].location, nameWidth);
                    print(product[found].quantity, nameWidth); cout << "$";
                    cout << setprecision(2) << fixed;
                    print(product[found].price, nameWidth); cout << endl;
                }
                else
                    cout << endl << "Item NOT Found Please Try Again" << endl;
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
