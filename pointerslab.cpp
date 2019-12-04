//
//  main.cpp
//  pointerslab
//
//  Created by Jasmin Gomez Heredia  on 10/31/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//

#include <iostream>
#include <random> // contains C++11 random number generation features
#include <ctime>
#include <iomanip>
using namespace std;

//Function definitions
void moveHare(int*);
void moveTortoise(int*);
void location(int* , int* );
int const race_iterations = 70;

//random number generator used to mark positions for the hare and tortoise
default_random_engine rand_engine( static_cast<unsigned int>( time(0) ) );
uniform_int_distribution<unsigned int> randomno( 1, 10 );

void  moveHare(int* hare_pos){
    int loc = randomno(rand_engine);
    
    // algorthim for assiging Hare moves
    if (loc >= 1 && loc <= 2){
        *hare_pos = 0;
    }else if (loc >= 2 && loc <= 4){
        *hare_pos += 9;
    }else if (loc >= 4 && loc <= 5){
        *hare_pos -= 12;
    }else if (loc >= 5 && loc <=8){
        *hare_pos +=1;
    }else if (loc >= 8 && loc <=10){
        *hare_pos -=2;
    }
    
    //the safegaurd required to return the hare's location back to one if the random numbers become too negative
    if ( *hare_pos < 1){
        *hare_pos = 1;
    }else if (*hare_pos > race_iterations){
        *hare_pos = race_iterations;
    }
    
}

void moveTortoise(int* tort_pos){
    int pos = randomno(rand_engine);
    
    if (pos >= 1 && pos <=5){
        *tort_pos += 3;
    }else if (pos >= 6 && pos <=7){
        *tort_pos -= 6;
    }else if (pos >= 8 && pos <=10){
        *tort_pos += 1;
    }
    
    if (*tort_pos < 1){
        *tort_pos = 1;
    }else if (*tort_pos > race_iterations){
        *tort_pos = race_iterations;
    }
}

void location(int* hare, int* tort){
    if (*hare == *tort){
        cout << setw(*hare)<< "Ouch!!! \n";
    }else if (*hare < *tort){
        cout << setw(*hare)<< 'L' << setw(*tort - *hare)<< 'T';
    }else{
        cout << setw(*tort)<< 'T'<< setw(*hare - *tort)<< 'L';
    }
    
    cout << " \n";
}

int main(int argc, const char * argv[]) {
    int hare_start = 1;
    int tortoise_start = 1;
    int time = 0;
    
    cout << "BANG!!!!! \n";
    cout << "AND THEY'RE OFF !!!!! \n";
    
    // loop through the events
    do {
        
        moveHare(&hare_start);
        moveTortoise(&tortoise_start);
        location(&hare_start, &tortoise_start);
        ++time;
    } while (hare_start != race_iterations && tortoise_start != race_iterations);
    
    
    if ( hare_start >= tortoise_start )
        cout << "The Hare wins!! \n";
    else
        cout << "TORTOISE WINS !!! YAY !!! \n";
    
    cout << "TIME ELAPSED = " << time << " seconds" << endl;
    return 0;
}
