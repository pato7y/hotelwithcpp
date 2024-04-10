#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>

class Hotel {
private:
    struct Node {
        int id, date;
        std::string name, roomtype;
        Node* next;
    };

    Node* head;

public:
    Hotel(); 
    ~Hotel(); 
    void insert();
    void search();
    void update();
    void del(); 
    void show();
    void sort();
    void menu();
};
#endif



