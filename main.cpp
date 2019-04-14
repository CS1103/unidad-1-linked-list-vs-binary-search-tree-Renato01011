#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <assert.h>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;
using namespace std::chrono;

int main() {

    // Declarando variables
    std::fstream archivo;
    archivo.open(SEARCH_FILE);
    LinkedList ll;
    BinarySearchTree bst;
    std::vector <int> vsearch;
    std::string position_id_search;
    Location Location_test;
    Location_test.filldata("548965", "FL","PINELLAS COUNTY", "20.015797", "-85.654789", "Residential", "Wood");


    // Grabar Datos del archivo "Locations.csv" en ll
    ll.load_locations(LOCATION_FILE);
    assert(ll.size() == 36635);
    // Grabar Datos del archivo "Locations.csv" en bst
    bst.load_locations_binarytree(LOCATION_FILE);
    assert(!bst.is_empty());
    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    while (getline(archivo, position_id_search, '\n')) {
        vsearch.push_back(stoi(position_id_search));
    }

    //Check insert
    ll.insert_linkedlist(2, Location_test);
    bst.insert_binarytree(Location_test);

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd

    auto start = high_resolution_clock::now();
    for(int i = 0; i < vsearch.size(); i++) {
        ll.search_linkedlist(std::to_string(vsearch[i]));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "El tiempo aproximado que tomo la busqueda con linked-list es : " << duration.count() << " microsegundos.";

    auto start_1 = high_resolution_clock::now();
    for(int i = 0; i < vsearch.size(); i++) {
        bst.search_binarytree(std::to_string(vsearch[i]));
    }
    auto stop_1 = high_resolution_clock::now();
    auto duration_1 = duration_cast<microseconds>(stop_1 - start_1);
    std::cout << "El tiempo aproximado que tomo la busqueda con binary-tree es : " << duration_1.count() << " microsegundos.";

    return 0;
}