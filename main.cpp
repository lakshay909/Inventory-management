#include <iostream>
#include <string>

using namespace std;

// Structure to represent an item in the inventory
struct InventoryItem {
    int id;
    string name;
    int quantity;
    float price;
    InventoryItem* next;
};

// Inventory Management System class
class InventoryManagementSystem {
private:
    InventoryItem* head; // Head pointer of the linked list
    InventoryItem* tail; // Tail pointer of the linked list

public:
    // Constructor to initialize an empty inventory
    InventoryManagementSystem() : head(nullptr), tail(nullptr) {}

    // Function to add an item to the inventory
    void addItem(int id, const string& name, int quantity, float price) {
        // Create a new item
        InventoryItem* newItem = new InventoryItem;
        newItem->id = id;
        newItem->name = name;
        newItem->quantity = quantity;
        newItem->price = price;
        newItem->next = nullptr;

        // If the inventory is empty, set head and tail to the new item
        if (head == nullptr) {
            head = tail = newItem;
        } else {
            // Insert the new item at the end of the linked list
            tail->next = newItem;
            tail = newItem;
        }

        cout << "Item added to inventory." << endl;
    }

    // Function to remove an item from the inventory (FIFO)
    void removeItem() {
        if (head == nullptr) {
            cout << "Inventory is empty. No items to remove." << endl;
            return;
        }

        // Remove the first item from the linked list (FIFO)
        InventoryItem* temp = head;
        head = head->next;
        delete temp;

        cout << "Item removed from inventory." << endl;
    }

    // Function to search for an item by ID
    void searchByID(int id) {
        InventoryItem* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                cout << "Item found:" << endl;
                cout << "ID\tName\tQuantity\tPrice" << endl;
                cout << current->id << "\t" << current->name << "\t" << current->quantity << "\t\t$" << current->price << endl;
                return;
            }
            current = current->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    // Function to remove items for sale with a specified quantity
    void sellItem(int id, int quantity) {
        InventoryItem* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                if (current->quantity >= quantity) {
                    current->quantity -= quantity;
                    cout << quantity << " units of " << current->name << " sold." << endl;
                    return;
                } else {
                    cout << "Insufficient stock for " << current->name << "." << endl;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    // Function to display the total stock details
    void displayTotalStock() {
        cout << "Total Stock Details:" << endl;
        cout << "ID\tName\tQuantity\tPrice" << endl;
        InventoryItem* current = head;
        while (current != nullptr) {
            cout << current->id << "\t" << current->name << "\t" << current->quantity << "\t\t$" << current->price << endl;
            current = current->next;
        }
    }
};

int main() {
    InventoryManagementSystem inventorySystem;

    // Adding some sample items to the inventory
    inventorySystem.addItem(1, "Chair", 20, 25.5);
    inventorySystem.addItem(2, "Table", 10, 75.0);
    inventorySystem.addItem(3, "Lamp", 15, 12.75);

    // Displaying the inventory
    inventorySystem.displayTotalStock();

    // Searching for an item by ID
    inventorySystem.searchByID(2);

    // Selling an item
    inventorySystem.sellItem(1, 5);

    // Displaying the updated inventory
    inventorySystem.displayTotalStock();

    return 0;
}