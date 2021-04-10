#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include "compound.h"

using namespace std;

compound::compound() {
    initial_mass = 0;
    molar_mass = 0;
    empirical =" ";
    no_moles = 0;
}
//------------ Setter Functions --------------------
void compound::setempirical(string name){
    empirical = name;
}
void compound::setinitial(double i_mass){
    initial_mass = i_mass;
}
void compound::setmolar(double m_mass){
    molar_mass = m_mass;
}
void compound::setno_moles(double n_moles){
    no_moles = n_moles;
}
//-------------Getter Functions -----------------------
double compound::getmolar(){
    return molar_mass;
}
double compound::getinitial(){
    return initial_mass;
}
string compound::getempirical(){
    return empirical;
}
double compound::getno_moles(){
    return no_moles; 
}
// provides introductory information that we will need to perform the other calculations.

void compound::user_vals(){
    compound uservals;
    double m, i, moles;
    string n;
    //Asks the user for the molar mass, name and initial mass of the object
    cout<< "Please enter the empirical formula for the compound: \n";
    getline(cin,n);
    
    cout<< "How many gram of a substance do you have? \n";
    cin >> i;
    
    cout << "Please enter the molar mass for the empirical forumla of the compound:\n";
    cin >> m;
    
    uservals.setempirical(n);
    uservals.setinitial(i);
    uservals.setmolar(m);
    
    string j = uservals.getempirical();
    //obtain number of moles by calling compute.
    moles = compute(uservals.getinitial(),uservals.getmolar());
    //Print statements
    cout << "You have "<< moles<< setprecision(3) << "  mole(s) . \n";
    cout <<"Name: "<< j << endl;
    
}
double compound::compute (double initialGrams, double molarMass){
    
    // moles = initial grams/ molar mass
    double moles;
    moles = fabs(initialGrams / molarMass);
    return moles;
}
// function works with hardcoded values in main
// fix me: find a way to use the user values pertaining to mass in user-val function to perform this calculation (pointer? )

double compound::perc_mass(double cmpmass, double totmass){
    double percentmass;
    
    percentmass = (cmpmass / totmass) * 100;
    
    cout << "The mass percent of this substance in the solution is "<< percentmass << "  % \n";
    return percentmass;
}
// fixme logic check on the computation but it runs :)
double compound::molarity(double cmpmass, double totvol){
    double molarity;
    // volume of soultion is held locally b/c other computations rely soley on mass.
    // Recall formula for molarity = moles / liters of solution
    cout <<"Please enter the total number of liters in your solution: " ;
    cin >> totvol;
    
    molarity = cmpmass/ totvol;
    cout << "The molarity of your substance is: "<< molarity << "  (mol/L) \n";
    
    return molarity;
}
// works --- just need to find a way to channel data like in perc-mass
double compound::dilution(double mi, double vi){
    double mf, vf;
    int choice;
    
    cout<< "Would you like to know the final volume or the final mass?  1-mass 2-volume \n";
    cin >> choice;
    
    switch(choice){
        case 1:
            cout << "Enter the final volume of the total solution: \n";
            cin >> vf;
            mf = (mi * vi)/ vf;
            cout<< "The final mass of the compound in the diluted solution is: "<< mf <<" g. \n" ;
            break;
        case 2:
            cout <<"Enter the final mass of the total solution : \n";
            cin >> mf;
            vf = (mi*vi)/mf;
            cout <<"The final volume of the compound in the diluted solution: "<< vf<<" mL. \n";
            break;
    }
    return 0;
}
