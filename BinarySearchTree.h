//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Node1 {
        Node1 (std::string position_id, std::string state_code, std::string county, std::string latitude, std::string longitude, std::string line, std::string construction);
        Node1 (Location &_data);
        Location data;
        Node1 *right;
        Node1 *left;
    };

    class BinarySearchTree {
        Node1 *root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert_binarytree(Location data);
        void clear(Node1* NodeToDelete);
        bool is_empty();
        Node1 *get_root();
        void search_binarytree(std::string position_id);
        void print_binarytree(Node1* NodeToPrint);
        void load_locations_binarytree(std::string file_name);
    };

}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
