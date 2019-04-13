//
// Created by ruben on 4/5/19.
//

#include <iostream>
#include "Location.h"


void Location::filldata(std::string _position_id, std::string _state_code, std::string _county, std::string _latitude, std::string _longitude, std::string _line, std::string _construction){
    position_id = _position_id;
    state_code = _state_code;
    county = _county;
    latitude = _latitude;
    longitude = _longitude;
    line = _line;
    construction = _construction;
}

void Location::printdatos(){
    std::cout << position_id << ", " << state_code << ", " << county << ", " << latitude << ", " << longitude << ", " << line << ", " << construction;
    std::cout << std::endl;
}