//
//  main.cpp
//  functionslab
//
//  Created by Jasmin Gomez Heredia  on 10/4/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int max(int, int, int);
int min(int, int, int);

int main() {
    int firstnum, secnum, thrdnum, x, y;
    cout <<"Enter the three integers and we'll find the max and min. \n"<<"Enter the first digit:  \n";
    cin >> firstnum;
    
    cout<< "Enter the second number: \n";
    cin >> secnum;
    
    cout << "Enter the third number: \n";
    cin >> thrdnum;
    
    x = max(firstnum, secnum, thrdnum);
    y = min(firstnum, secnum, thrdnum);
    
    cout<< "             \n";
    cout<< "The max number is: "<< x<< " \n";
    cout<< "The min number is: "<< y<< " \n";
    
    return 0;
}

int max(int firstval, int secval, int thrdval){
    int max = 0;
    
    if (firstval > secval && firstval > thrdval){
        max = firstval;
    }else if(secval > firstval && secval > thrdval){
        max = secval;
    }else if (thrdval > firstval && thrdval> secval){
        max = thrdval;
    }else
        cout<< "An error occured, input new numbers. \n";
    
    return max;
}


int min(int firstval, int secval, int thrdval){
    int min=0;
    
    if (firstval < secval && firstval < thrdval){
        min = firstval;
    }else if(secval < firstval && secval < thrdval){
        min = secval;
    }else if (thrdval < firstval && thrdval < secval){
        min = thrdval;
    }else
        cout<< "An error occured, input new numbers. \n";
    
    return min;
}
