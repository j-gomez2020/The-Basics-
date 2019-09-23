//
//  main.cpp
//  Lab2_comsc165
//  Total of 12 wrestlers on the team.
//  Created by Jasmin Gomez Heredia  on 9/17/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    //All variable declarations are below.
    double team = 12;
    vector<double> weightls(team);
    double avg_weight, max_weight;
    double x;
    
    
    // Use a loop to collecter userinput, only positive no. allowed.
    double tot_weight;
    cout <<"Enter weight for all members on your team : \n";
    for (x = 0; x < weightls.size(); ++x) {
         cin >> weightls.at(x);
         tot_weight += weightls.at(x);// calc the sum of weight.
    }
    
    //Try out fmax function from math libary to identify max valdouble fmax  (double x     , double y);
    //algoritm for finding max
    // Math logic for total and average computation
    avg_weight = (tot_weight)/ 12;
    max_weight = *max_element(weightls.begin(), weightls.end());
    
    // Displays the required outout for our user.
    cout<< "These are the values entered: ";
    for (x = 0; x < weightls.size(); ++x) {
        cout << weightls.at(x)<< "   ";
    }
    cout<< "            \n"; 
    cout<< "Total Weight : "<< tot_weight<< " \n";
    cout<< "Average Weight : "<< avg_weight<< " \n";
    cout<< "Max Weight : "<<max_weight<< " \n";
    return 0;
}
