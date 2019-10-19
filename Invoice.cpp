//
//  Invoice.cpp
//  classlab_gomez
//  Created by Jasmin Gomez Heredia  on 10/17/19.
//  Copyright © 2019 Jasmin Gomez Heredia . All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void testthisclass();
void userclassvals();

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
    
    cout <<"This is a test!\n";
    cout <<"Part Number: "<< mytest.getpart() << " \n";
    cout <<"Part Description: "<< mytest.getdescrip() <<"  \n";
    cout <<"Quantity: "<< mytest.getquantity()<< " \n";
    cout <<"Price per item: $ "<< mytest.getpriceperitem()<< "  \n";
    cout <<"Invoice amount: $ "<< mytest.getInvoiceAmount(quant, price)<< "  \n";
}

void userclassvals(){
    //assigns values that will be sent to setter function
    Invoice myitem;
    string part, desc;
    int quant, price, cont;
    
    do {
        cout << "Welcome to the Invoice Program!\n";
        cout <<"Please enter the five digit part number:\n";
        cin >> part;
        cout << "Enter part description:  \n";
        cin >> desc;
        cout << "How many "<< desc << "(s) will there be total:\n";
        cin >> quant;
        cout << "What is the price for each "<< desc << " $:\n";
        cin >> price;
        cout << "Would you like to contine? (1)YES (2) NO\n";
        cin >> cont;
        
    }while (cont == 1);
    
    myitem.setpart(part);
    myitem.setdescrip(desc);
    myitem.setquantity(quant);
    myitem.setpriceperitem(price);
    
    //print statements
    cout <<"-------------------------------------------\n";
    cout <<"Part Number: "<< myitem.getpart() << "\n";
    cout <<"Part Description: "<< myitem.getdescrip() <<"\n";
    cout <<"Quantity: "<< myitem.getquantity()<< "\n";
    cout <<"Price per item: $ "<< myitem.getpriceperitem()<< "\n";
    cout <<"Invoice amount: $ "<< myitem.getInvoiceAmount(quant, price)<< "\n";
    cout <<"                                 \n";
}
/*------main function---------------------------------*/

int main() {
    userclassvals();// original values
    cout <<"                          \n";
    testthisclass(); // test function
    cout<<"                           \n";
    
    return 0;
}
