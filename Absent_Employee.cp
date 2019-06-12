//
//  main.cpp
//  cv
//
//  Created by Jasmin Gomez Heredia  on 6/11/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;
int noOfEmployees();
int totalnoDays(int);
double absentAvg(int, int);

int main() {
    int x, y, z;
    // function calls to obtain appropriate data
    x = noOfEmployees();
    y = totalnoDays(x);
    z = absentAvg(x, y);
    //displays the total average of absent days of all employees.
    cout<< "The total average is: "<< z <<endl;
    
    return 0;
}


int noOfEmployees(){
    int no_emp;
    //Do-while loop used to validate user input
    do {
        cout<<"Please enter the number of employees you have: "<<endl;
        cin >> showpoint>> no_emp  ;
        
        if (no_emp <1){
            cout<<"Please input a number greater than one. "<<endl;
        }

    } while (no_emp < 1);
    
    
    return no_emp;
}


int totalnoDays(int no_emp) {
    int days;
    int days_total = 0;
    cout<<"Please enter the number of days each employee was absent. "<<endl;
    // for-loop is used to keep track of each employee's number of absent days.
    for (int x=1;x <= no_emp; x++) {
        cout<<"Enter the number of days for employee: "<< x <<endl;
        cin >>showpoint >>days;
        //Add up the total number of days all employees were absent.
        days_total = 0 + days;
    }
    return days_total;
}

double absentAvg(int no_emp, int days){
    double average;
    //computes average and returns value.
    average = days % no_emp;
    
    return average;
}

