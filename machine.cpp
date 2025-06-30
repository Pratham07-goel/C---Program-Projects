#include <iostream>
#include <iomanip>
using namespace std;

class Product {
private:
    string name;
    float price;
    int quantity;

public:
    Product(string n, float p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

	    string getName() {
	        return name;
	    }
	
	    float getPrice() {
	        return price;
	    }
	
	    int getQuantity() {
	        return quantity;
	    }

    bool isAvailable(int q) {
        return quantity >= q;
    }

    float purchase(int q) {
        if (q <= quantity) {
            quantity -= q;
            return price * q;
        }
        return -1.0f;
    }

    void display(int index) {
        cout << index + 1 << ". " << name
             << " (?" << fixed << setprecision(2) << price
             << ") - Qty: " << quantity << endl;
    }
};

const int NUM_ITEMS = 4;
Product* items[NUM_ITEMS] = {
    new Product("Chips", 20.0f, 10),
    new Product("Soda", 30.0f, 8),
    new Product("Candy", 10.0f, 15),
    new Product("Cookies", 25.0f, 12)
};

float totalEarnings = 0;
float machineCash = 500.0f; // Starting cash in machine

void displayItems() {
    cout << "\nAvailable Products:\n";
    cout << "-------------------\n";
    for (int i = 0; i < NUM_ITEMS; ++i) {
        items[i]->display(i);
    }
}

void purchaseItems() {
    int choice, qty;
    float total = 0;

    while (true) {
        displayItems();
        cout << "\nEnter item number to buy (0 to finish): ";
        cin >> choice;
        if (choice == 0) break;

        if (choice < 1 || choice > NUM_ITEMS) {
            cout << "Invalid item number.\n";
            continue;
        }

        cout << "Enter quantity for " << items[choice - 1]->getName() << ": ";
        cin >> qty;

        if (!items[choice - 1]->isAvailable(qty)) {
            cout << "Not enough stock. Available: " << items[choice - 1]->getQuantity() << endl;
            continue;
        }

        float cost = items[choice - 1]->purchase(qty);
        total += cost;

        cout << "Added ?" << cost << " to your bill.\n";
    }

    if (total > 0) {
        cout << "\nTotal amount to pay: ?" << total;
        float money;
        cout << "Enter money inserted: ?";
        cin >> money;

        if (money < total) {
            cout << "Not enough money. Transaction cancelled.\n";
            return;
        }

        float change = money - total;

        if (change > machineCash) {
            cout << "Machine doesn't have enough change. Transaction cancelled.\n";
            return;
        }

        // Transaction success
        machineCash += total;
        machineCash -= change;
        totalEarnings += total;

        cout << "Transaction successful! Change returned: ?" << change << endl;
    } else {
        cout << "No items purchased.\n";
    }
}

void showSummary() {
    cout << "\nFinal Summary:\n";
    cout << "--------------\n";
    for (int i = 0; i < NUM_ITEMS; ++i) {
        cout << items[i]->getName() << " - Qty left: " << items[i]->getQuantity() << endl;
    }
    cout << "Total earnings: ?" << totalEarnings << endl;
    cout << "Cash left in machine: ?" << machineCash << endl;
}

int main() {
    cout << "Welcome to the Vending Machine!\n";

    char another = 'y';
    while (another == 'y' || another == 'Y') {
        purchaseItems();
        cout << "\nWould you like to make another purchase? (y/n): ";
        cin >> another;
    }

    showSummary();

    for (int i = 0; i < NUM_ITEMS; ++i) {
        delete items[i];
    }

    return 0;
}


