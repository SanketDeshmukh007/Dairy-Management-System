#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
private:
    string supplierName;
    string itemName;
    int price;
    int quantity;
    int rating;

public:
    void addNewItem();
    void buyItem();
    void showItems();
    bool isPopularItem();
    string getItemName()
    {
        return this->itemName;
    }
};

void Item::addNewItem()
{
    cin.ignore();
    cout << "Enter Name of a Supplier: ";
    getline(cin, supplierName);
    cout << "Enter Name of an item: ";
    getline(cin, itemName);
    cout << "Enter price of an item: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter rating of an item out of 5: ";
    cin >> rating;
}

void Item::showItems()
{
    cout << "Supplier Name: " << supplierName << endl;
    cout << "Supplied Product Name: " << itemName << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity available: " << quantity << endl;
    cout << "Rating out of 5: " << rating << endl;
}

bool Item::isPopularItem()
{
    return rating >= 4;
}

void Item::buyItem()
{
    int requiredQuantity;
    cout << "\nQuantity Available: " << quantity << "\nQuantity Required? ";
    cin >> requiredQuantity;

    if (requiredQuantity <= quantity)
    {
        int amount = price * requiredQuantity;
        cout << "Amount to be paid: " << amount << "\n";
        cout << "Please pay the amount: ";
        int paidAmount;
        cin >> paidAmount;

        if (paidAmount == amount)
        {
            string customername;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin,customername);

            cout << "\n  ------- Item bought!!---------" << endl;
            cout << "\n  -----Details of item bought------\n";
            cout << "\tName: " << customername << endl;
            cout << "\tProduct name: " << itemName << endl;
            cout << "\tQuantity: " << requiredQuantity << endl;
            cout << "\tAmount paid: " << paidAmount << endl;
            quantity -= requiredQuantity;
        }
        else
        {
            cout << "\nSorry, the item cannot be bought due to incorrect payment\n";
        }
    }
    else
    {
        cout << "\nSorry, the required quantity is not available\n";
    }
}

int login()
{
    string username;
    string pass;

    cout << "Enter your User Name : ";
    getline(cin, username);

    cout << "Enter your password : ";
    getline(cin, pass);

    if (username == "sanket" && pass == "12345")
    {
        printf("\n\nLogged In Successful\n");
        return 1;
    }

    else
    {

        printf("\n\n\t\t  Wrong  Username / Password \n");
        return 0;
    }
}

int main()
{
    while(!login());
    vector<Item> items;

    cout << "<--------------------WELCOME USER-------------------->\n\n";

    int choice;
    do
    {
        cout << "\n\t\t1. ADD SUPPLIERS STOCK DETAILS\n"
             << "\t\t2. Buy Item\n"
             << "\t\t3. DISPLAY ALL SUPPLIERS\n"
             << "\t\t4. Premium Products Available\n"
             << "\t\t5. Exit\n";
        cout << "\n\t\tEnter choice from above: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Item newItem;
            newItem.addNewItem();
            items.push_back(newItem);
            break;
        }
        case 2:
        {
            if (!items.empty())
            {
                cin.ignore();
                string itemName;
                cout << "\nEnter name of an item to buy: ";
                getline(cin, itemName);

                bool found = false;
                for (Item &item : items)
                {
                    if (item.getItemName() == itemName)
                    {
                        item.buyItem();
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "\nItem not found!!\n";
                }
            }
            else
            {
                cout << "No items available for purchase.\n";
            }
            break;
        }
        case 3:
        {
            cout << "\n----------All Suppliers Record------------\n\n";
            for (Item &item : items)
            {
                item.showItems();
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "\n-----------Premium Dairy Products--------------\n";
            cout << "\n";
            for (Item &item : items)
            {
                if (item.isPopularItem())
                {
                    item.showItems();
                    cout << endl;
                }
            }
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "\nEnter a valid choice\n";
        }
    } while (choice != 5);

    return 0;
}
