//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

UTEC::LinkedList::~LinkedList() {
    for(int i = 0; i < size(); i++)
        RemoveHead();
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::RemoveHead() {
    if(size() == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node* Temp = head;
        head = Temp->next;
        delete Temp;
        Temp = nullptr;
    }
}

void UTEC::LinkedList::add_head(Location& data) {
    Node* temp = new UTEC::Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(Location& data) {
    Node* temp = new UTEC::Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::LinkedList::print_linkedlist(){

    Node* Temp = head;
    Temp->data.printdatos();
    for(int i = 1; i < size(); i++){
        Temp = Temp->next;
        Temp->data.printdatos();
    }


}

void UTEC::LinkedList::insert_linkedlist(int position, Location& data){

    Node* Temp = head;
    Node* NewNode = new UTEC::Node(data);
    for(int i = 1; i < position-1; i++)
        Temp = Temp->next;
    Temp->next = NewNode;
    Temp = Temp->next->next;
    NewNode->next = Temp;

}

UTEC::Node* UTEC::LinkedList::search_linkedlist(std::string position_id){

    Node* Temp = head;
    for(int i = 0; i < size(); i++){
        if(Temp->data.getposition_id() == position_id){
            Temp->data.printdatos();
            Temp = Temp->next;
        }
        else {
            Temp = Temp->next;
        }
    }

}

void UTEC::LinkedList::load_locations(std::string file_name){
    UTEC::Node* NewNode;
    std::string position_id;
    std::string state_code;
    std::string county;
    std::string latitude;
    std::string longitude;
    std::string line;
    std::string construction;

    ifstream ArchivoALeer;
    ArchivoALeer.open(file_name);
    if(!ArchivoALeer.is_open()){std::cout << "ERROR: File Could not open";}

    if(head == nullptr && tail == nullptr){
        while (ArchivoALeer.good()) {

            getline(ArchivoALeer, position_id, ',');
            getline(ArchivoALeer, state_code, ',');
            getline(ArchivoALeer, county, ',');
            getline(ArchivoALeer, latitude, ',');
            getline(ArchivoALeer, longitude, ',');
            getline(ArchivoALeer, line, ',');
            getline(ArchivoALeer, construction, '\n');

            NewNode = new UTEC::Node(position_id, state_code, county, latitude, longitude, line, construction);
            head = NewNode;
            head->next = tail;
            tail = NewNode;
        }
        ArchivoALeer.close();
    }
    else{
        while (ArchivoALeer.good()) {

            getline(ArchivoALeer, position_id, ',');
            getline(ArchivoALeer, state_code, ',');
            getline(ArchivoALeer, county, ',');
            getline(ArchivoALeer, latitude, ',');
            getline(ArchivoALeer, longitude, ',');
            getline(ArchivoALeer, line, ',');
            getline(ArchivoALeer, construction, '\n');

            NewNode = new UTEC::Node(position_id, state_code, county, latitude, longitude, line, construction);
            tail->next = NewNode;
            tail = NewNode;
        }
        ArchivoALeer.close();
    }
}

UTEC::Node::Node(std::string position_id, std::string state_code, std::string county, std::string latitude, std::string longitude, std::string line, std::string construction) {

    data.filldata(position_id, state_code, county, latitude, longitude, line, construction);

}

UTEC::Node::Node(Location &Data) {

    data.setposition_id(Data.getposition_id());
    data.setstate_code(Data.getstate_code());
    data.setcounty(Data.getcounty());
    data.setlatitude(Data.getlatitude());
    data.setlongitud(Data.getlongitud());
    data.setline(Data.getline());
    data.setconstruction(Data.getconstruction());

}
