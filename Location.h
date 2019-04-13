//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>

class Location {
    std::string position_id;
    std::string state_code;
    std::string county;
    std::string latitude;
    std::string longitude;
    std::string line;
    std::string construction;
public:
    Location() = default;
    void filldata(std::string position_id, std::string state_code, std::string county, std::string latitude, std::string longitude, std::string line, std::string construction);

    //Getters
    std::string getposition_id() {return position_id;}
    std::string getstate_code() {return state_code;}
    std::string getcounty() {return county;}
    std::string getlatitude() {return latitude;}
    std::string getlongitud() {return longitude;}
    std::string getline() {return line;}
    std::string getconstruction() {return construction;}

    //Setters
    void setposition_id(std::string _position_id) {position_id = _position_id;}
    void setstate_code(std::string _state_code) {state_code = _state_code;}
    void setcounty(std::string _county) {county = _county;}
    void setlatitude(std::string _latitude) {latitude = _latitude;}
    void setlongitud(std::string _longitude) {longitude = _longitude;}
    void setline(std::string _line) {line = _line;}
    void setconstruction(std::string _construction) {construction = _construction;}

    //Print Datos
    void printdatos();

};


#endif //LINKEDLISTVSBINARYTREE_LOCATION_H