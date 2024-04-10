#include "Hotel.h"
#include<iostream>
using namespace std;


Hotel::Hotel() {
    head = nullptr;
}

Hotel::~Hotel() {
}

void Hotel::menu() {
    int choice;
    do {
        cout << "******** Welcome to Hotel Sero ********\n";
        cout << "1. Allocate rooms (Inserting a new room)\n";
        cout << "2. Search rooms (Searching rooms with room id)\n";
        cout << "3. Update rooms (Updating the room records)\n";
        cout << "4. Delete rooms\n";
        cout << "5. Show room records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                update();
                break;
            case 4:
                del();
                break;
            case 5:
                show();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (choice != 6);
}

void Hotel::insert() {
    cout << "******** Hotel Sero ********\n";
    Node* newNode = new Node;
    cout << "Enter the id of the room: ";
    cin >> newNode->id;
    cout << "Enter the customer name: ";
    cin >> newNode->name;
    cout << "Enter the allocated date: ";
    cin >> newNode->date;
    cout << "Enter room type (single/double/twin): ";
    cin >> newNode->roomtype;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Room added successfully.\n";
}

void Hotel::search() {
    cout << "******** Hotel Sero ********\n";
    int roomId;
    cout << "Enter the room id to search: ";
    cin >> roomId;

    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->id == roomId) {
            cout << "Room found:\n";
            cout << "ID: " << temp->id << endl;
            cout << "Customer Name: " << temp->name << endl;
            cout << "Allocated Date: " << temp->date << endl;
            cout << "Room Type: " << temp->roomtype << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Room not found.\n";
    }
}

void Hotel::update() {
    cout << "******** Hotel Sero ********\n";
    int roomId;
    cout << "Enter the room id to update: ";
    cin >> roomId;

    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->id == roomId) {
            cout << "Enter the new details:\n";
            cout << "ID: ";
            cin >> temp->id;
            cout << "Customer Name: ";
            cin >> temp->name;
            cout << "Allocated Date: ";
            cin >> temp->date;
            cout << "Room Type: ";
            cin >> temp->roomtype;
            cout << "Room details updated.\n";
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Room not found.\n";
    }
}

void Hotel::del() {
    cout << "******** Hotel Sero ********\n";
    int roomId;
    cout << "Enter the room id to delete: ";
    cin >> roomId;

    Node* temp = head;
    Node* prev = nullptr;
    bool found = false;
    while (temp != nullptr) {
        if (temp->id == roomId) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Room deleted.\n";
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        cout << "Room not found.\n";
    }
}

void Hotel::show() {
    cout << "******** Hotel Sero ********\n";
    if (head == nullptr) {
        cout << "No rooms to show.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "Room ID: " << temp->id << endl;
        cout << "Customer Name: " << temp->name << endl;
        cout << "Allocated Date: " << temp->date << endl;
        cout << "Room Type: " << temp->roomtype << endl;
        temp = temp->next;
    }
}

void Hotel::sort() {
    cout << "Sorting functionality to be implemented.\n";
}

