//
//  Header.h
//  DataStructureproj

//input file that will contain all data 
//
//  Created by Jasmin Gomez Heredia  on 4/27/20.
//  Copyright © 2020 Jasmin Gomez Heredia . All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
using namespace std;
//identfy the right amount of digits for each of the data types 
class bill{
public:
    //data member declarations
    float amount;
    double date;
    double invoice;
    string name;
    bill *next;
    
    // prototypes
    //setter functions
    void setamount(float);
    void setdate(double);
    void setinvoice(double);
    void setname(string);
    
};
#endif /* Header_h */
