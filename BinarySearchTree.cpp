//
// Created by ruben on 4/5/19.
//

#include <iostream>
#include <string>
#include "Location.h"
#include <fstream>
#include "BinarySearchTree.h"

UTEC::BinarySearchTree::BinarySearchTree() {

    root = nullptr;

}

UTEC::BinarySearchTree::~BinarySearchTree() {

    clear(root);

}

void UTEC::BinarySearchTree::insert_binarytree(Location data) {

    Node1* NewNode = new Node1(data);
    if(root == nullptr) {root = NewNode;}
    else if(root != nullptr) {
        for(Node1* i = root; i != nullptr;) {
            if(i->data.getposition_id() > NewNode->data.getposition_id()) {
                if(i->left == nullptr) {i->left = NewNode; break;}
                else {i = i->left;}
            }
            else if(i->data.getposition_id() < NewNode->data.getposition_id()) {
                if(i->right == nullptr) {i->right = NewNode; break;}
                else {i = i->right;}
            }
        }
    }

}

void UTEC::BinarySearchTree::clear(Node1* NodeToDelete) {

    if(NodeToDelete == nullptr) {return;}
    clear(NodeToDelete->left);
    clear(NodeToDelete->right);
    delete NodeToDelete;
    NodeToDelete = nullptr;

}

bool UTEC::BinarySearchTree::is_empty() {

    if(root == nullptr) {return true;}
    else {return false;}

}

UTEC::Node1* UTEC::BinarySearchTree::get_root() {

    return root;

}

void UTEC::BinarySearchTree::search_binarytree(std::string position_id) {

    for(Node1* Temp = root; Temp != nullptr;) {
        if(Temp->data.getposition_id() == position_id) {Temp->data.printdatos(); break;}
        else if(Temp->data.getposition_id() > position_id) {Temp = Temp->left;}
        else if(Temp->data.getposition_id() < position_id) {Temp = Temp->right;}
    }

}

void UTEC::BinarySearchTree::print_binarytree(Node1* NodeToPrint) {

    if(NodeToPrint) {
        print_binarytree(NodeToPrint->left);
        NodeToPrint->data.printdatos();
        print_binarytree(NodeToPrint->right);
    }

}

void UTEC::BinarySearchTree::load_locations_binarytree(std::string file_name) {

    Node1* NewNode = nullptr;
    std::string position_id;
    std::string state_code;
    std::string county;
    std::string latitude;
    std::string longitude;
    std::string line;
    std::string construction;

    std::ifstream ArchivoALeer;
    ArchivoALeer.open(file_name);
    if(!ArchivoALeer.is_open()) {std::cout << "ERROR: No Se Pudo Abrir Archivo";}

    while(ArchivoALeer.good()) {

        getline(ArchivoALeer, position_id, ',');
        getline(ArchivoALeer, state_code, ',');
        getline(ArchivoALeer, county, ',');
        getline(ArchivoALeer, latitude, ',');
        getline(ArchivoALeer, longitude, ',');
        getline(ArchivoALeer, line, ',');
        getline(ArchivoALeer, construction, '\n');

        NewNode = new Node1(position_id, state_code, county, latitude, longitude, line, construction);
        if(root == nullptr) {root = NewNode;}
        else if(root != nullptr) {
            for(Node1* i = root; i != nullptr;) {
                if(i->data.getposition_id() > NewNode->data.getposition_id()) {
                    if(i->left == nullptr) {i->left = NewNode; break;}
                    else {i = i->left;}
                }
                else if(i->data.getposition_id() < NewNode->data.getposition_id()) {
                    if(i->right == nullptr) {i->right = NewNode; break;}
                    else {i = i->right;}
                }
            }
        }

    }
}

UTEC::Node1::Node1 (std::string position_id, std::string state_code, std::string county, std::string latitude, std::string longitude, std::string line, std::string construction){

    data.filldata(position_id, state_code, county, latitude, longitude, line, construction);
    left = nullptr;
    right = nullptr;

}

UTEC::Node1::Node1 (Location &_data) {

    data.setposition_id(_data.getposition_id());
    data.setstate_code(_data.getstate_code());
    data.setcounty(_data.getcounty());
    data.setlatitude(_data.getlatitude());
    data.setlongitud(_data.getlongitud());
    data.setline(_data.getline());
    data.setconstruction(_data.getconstruction());
    left = nullptr;
    right = nullptr;

}