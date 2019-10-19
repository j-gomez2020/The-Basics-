//
//  main.cpp
//  classlab_gomez
//  Created by Jasmin Gomez Heredia  on 10/17/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void testthisclass();
void ogclassvals();

//class declarator
class Invoice {
public:
    //'setter' decalarations
    void setpart (string);
    void setdescrip(string);
    void setquantity(int);
    void setpriceperitem(int);
    
    //'getter' declarations
    string getpart ();
    string getdescrip();
    int getquantity();
    int getpriceperitem();
    int getInvoiceAmount(int, int);
private:
    // var declarations
    string part;
    string description;
    int quantity;
    int priceperitem;
    int value;
};

//setters
void Invoice::setpart(string partno){
    part = partno;
}

void Invoice:: setdescrip(string desc){
    description = desc;
}

void Invoice::setquantity(int quan){
    quantity = quan;
}

void Invoice:: setpriceperitem(int pricit){
    priceperitem = pricit;
    
}

/*-----------------------------------------------------------------------------*/
//getters

string Invoice::getpart(){
    return part;
}

string Invoice:: getdescrip(){
    return description;
}

int Invoice:: getquantity(){
    return quantity;
}

int Invoice::getpriceperitem(){
    return priceperitem;
}

int Invoice:: getInvoiceAmount(int quantity, int priceperitem){
    value = fabs(quantity * priceperitem);
    return value;
}
/*----------Test Run---------------------------------------------------*/

void testthisclass(){
    Invoice mytest;
    int quant = 2 , price = -7;
    mytest.setpart("12234");
    mytest.setdescrip("Hammer");
    mytest.setquantity(quant);
    mytest.setpriceperitem(price);
    
    cout <<"Part Number: "<< mytest.getpart() << " \n";
    cout <<"Part Description: "<< mytest.getdescrip() <<"  \n";
    cout <<"Quantity: "<< mytest.getquantity()<< " \n";
    cout <<"Price per item: $ "<< mytest.getpriceperitem()<< "  \n";
    cout <<"Invoice amount: $ "<< mytest.getInvoiceAmount(quant, price)<< "  \n";
}

void ogclassvals(){
    //assigns values that will be sent to setter function
    Invoice myitem;
    int quant = 3, price = 3;
    myitem.setpart("11234");
    myitem.setdescrip("screwdriver");
    myitem.setquantity(quant);
    myitem.setpriceperitem(price);
    
    
    //print statements
    cout <<"Part Number: "<< myitem.getpart() << " \n";
    cout <<"Part Description: "<< myitem.getdescrip() <<"  \n";
    cout <<"Quantity: "<< myitem.getquantity()<< " \n";
    cout <<"Price per item: $ "<< myitem.getpriceperitem()<< "  \n";
    cout <<"Invoice amount: $ "<< myitem.getInvoiceAmount(quant, price)<< "  \n";
    cout <<"                                 \n";
}
/*------main function---------------------------------*/

int main() {
    ogclassvals();// original values
    cout <<"                          \n";
    testthisclass(); // test function
    cout<<"                           \n";
    
    return 0;
}
