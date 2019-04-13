//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"
#include <fstream>
#include <string>
#include <vector>

namespace UTEC {

    struct Node {
        Node(std::string position_id, std::string state_code, std::string county, std::string latitude, std::string longitude, std::string line, std::string construction);
        Node(Location& data);
        Location data;
        Node* next;
    };

    class LinkedList {
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        LinkedList() = default;
        ~LinkedList();
        int size();
        bool is_empty();
        void RemoveHead();
        Node* get_head();
        Node* get_tail();
        void add_head(Location& data);
        void add_tail(Location& data);
        void print_linkedlist();
        void insert_linkedlist(int position, Location& data);
        Node* search_linkedlist(std::string position_id);
        void load_locations(std::string file_name);
    };

}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
