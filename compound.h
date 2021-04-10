//
//  compoud.h
//  Final Project
//
//  Created 2019/11/16.
//  Copyright © 2019 Jasmin Gomez Heredi . All rights reserved.
//

#ifndef compound_h
#define compound_h

#include <string>
using namespace std;

class compound{
public:
    //constructor
    compound();
    //setters
    void setinitial(double);
    void setmolar(double);
    void setempirical(string);
    void setno_moles(double);
    //getters
    double getinitial();
    double getmolar();
    double getno_moles();
    string getempirical();
    void print();
    
    // class function prototypes
    void user_vals();
    double compute(double, double);
    double perc_mass(double, double);
    double molarity (double, double);
    double dilution (double, double); 
private:
    //variable intilization
    double initial_mass;
    double molar_mass;
    double no_moles; 
    string empirical;
};

#endif /* compound_h */
