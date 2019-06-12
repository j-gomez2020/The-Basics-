//
//  main.cpp
//  calcretail
//
//  Created by Jasmin Gomez Heredia  on 5/28/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;
double consumer();
double distributor();

int main() {
    int x;
    // choose consumer|| distrubtor, to call the right function
   do{
       cout<<"Hey, are you a consumer(0) or distributor(1)? "<<endl;
       cin>> x;
       
        if (x==0){
            consumer();
            break;
        }else if (x==1){
            distributor();
            break;
        }else
            cout<<"That is an invalid response please try again. "<<endl;
       
    }while (x != 0 || x !=1);
    
    return 0;
    
}


// calculates once item at a time
double consumer(){
    
    double wholesale, percent;
    float markup;
    double retail = 0;
    
    // used fixed point notation to validate input
    cout<<"Please input the wholesale price for the item: $#.## "<<endl;
    cin>> wholesale;
    if (wholesale <= 0.01) {
        cout<<"That is an invalid number please try again. "<<endl;
        cin>> wholesale;
    }
    
    cout<<"Please input the markup percentage for the item: ##%" <<endl;
    cin>> markup >> setw(2);
    if (markup < 1) {
        cout<<"Please try again. "<<endl;
        cin>> markup;
    }
    
    
    percent = (markup/100);
    
    retail = (wholesale * percent) + wholesale;
    
     cout<<"The total after the markup price is the following: $"<< setprecision(4) <<showpoint<< retail<< endl;
    
    return retail;
   
}





double distributor () {
    double no_units, unitprice,grosstot, nettot;
    float markperc, percent;
    
    cout<<"Please enter the number of units for the specific item: # "<<endl;
    cin >> no_units;
    
    
    cout<<"Please enter in the price for each unit: #.##"<<endl;
    cin >> unitprice;
    if (unitprice <= 0.01) {
        cout<<"That is an invalid number please try again. "<<endl;
        cin>> unitprice;
    }
    
    cout<< "Please enter the markup percent: ##%"<<endl;
    cin >> markperc;
    if (markperc <1) {
        cout<<"Please try again. "<<endl;
        cin>> markperc >> setw(2);
    }
    
    percent = markperc/100;
    
    nettot = (no_units * unitprice) ;
    
    grosstot = (nettot * percent) + nettot;
    
    cout<< "The total markup price for all of the units combined is: $"<< grosstot <<endl;
    cout<<"That comes out to $"<< setprecision(4)<<showpoint << (grosstot/no_units)<< " per unit, after the markup. "<<endl;
    
    return 0;
}

