//
//  main.cpp
//  DataStructureproj
//
//  Created by Jasmin Gomez Heredia  on 4/27/20.
//  Copyright © 2020 Jasmin Gomez Heredia . All rights reserved.
//
#include <iomanip>
#include <iostream>
#include "Header.h"
using namespace std;

/* Given a reference to the head inserts a new node on the front of the list.
 This file is responsible for holding the linked list where all bills will be
 inserted and retrieved.  */

//setter functions
void bill::setamount(float inputamount){
    amount = inputamount;
}
void bill::setdate(double inputdate){
    date = inputdate;
}
void bill::setinvoice(double inputinvoice){
    invoice = inputinvoice;
}
void bill::setname(string inputname){
    name = inputname;
}


/**
 pushbill () - This function pushes a bill node into the linked list database.

 @param head_ref - pointer to the head of the node
 @param new_amount - sets the amount of the bill
 @param new_date - describes what the user is paying for
 @param new_invoice - generates a random invoice number to identify the bill in question
 @param new_name - names the bill to be identified by the user
 */
void pushbill(bill** head_ref, float new_amount, double new_date, double new_invoice, string new_name){
    /*allocates a new bill */
    bill* new_node = new bill();
    
    /* inserts all data members for the bill class*/
    new_node->bill::setamount(new_amount);
    new_node->bill::setdate(new_date);
    new_node->bill::setinvoice(new_invoice);
    new_node->bill::setname(new_name);
    /* Make next of new node as head */
    new_node->next = (*head_ref);
    
    /* Move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the givenprev_node
 still unsure if this has any value in my program specifically
 */

void insertbillAfter(bill* prev_node, float new_amount, double new_date, double new_invoice, string new_name)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous entry cannot be empty";
        
    }
    
    /* allocate new node */
    bill* new_node = new bill();
    
    /* set the data for data members*/
    new_node->bill::setamount(new_amount);
    new_node->bill::setdate(new_date);
    new_node->bill::setinvoice(new_invoice);
    new_node->bill::setname(new_name);
    
    /*Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference to the head
 of a list then appends a new node at the end */
void appendbill(bill** head_ref, float new_amount, double new_date, double new_invoice, string new_name)
{
    /* 1. allocate node */
    bill* new_node = new bill();
    
    bill *last = *head_ref; /* used in step 5*/
    
    /* 2. put in the data */
    new_node->bill::setamount(new_amount);
    new_node->bill::setdate(new_date);
    new_node->bill::setinvoice(new_invoice);
    new_node->bill::setname(new_name);
    
    /* This new node is going to be
     the last node, so make next of
     it as NULL*/
    new_node->next = NULL;
    
    /* If the Linked List is empty,
     then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    
    /*  Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    
    /* Change the next of last node */
    last->next = new_node;
    return;
}

float getgrosspay(){
    float grosspay;
    cout <<"Please enter the amount of gross pay you recieved last month: \n";
    cin >> grosspay;
    return grosspay;
}

float getpretaxDed(){
    float pretaxded;
    cout<<"Please enter the total amount of all pretax deductions combined: \n";
    cin >> pretaxded;
    return pretaxded;
}

/**
 federalincometax2020 - The function that calculates the federal income tax a customer would be deducted
 from their gross whcih they provide. All values in this function are provided on the IRS tax website.

 @param monthlypay - the gross pay value that we get from the customer in the getgrosspay() function.
 @return taxrate - the float value (decimal format) that will be used to compute the tax deducted from grosspay.
 */
float federalincometax2020(float monthlypay){
    float taxrate, annualrate;
    
    annualrate = monthlypay*12;
    
    if (annualrate <= 9875) {
        taxrate = 0.10;
    } else if(annualrate >= 9876 && annualrate <= 40125){
        taxrate = 0.12;
    }else if(annualrate >= 40126 && annualrate <= 85525){
        taxrate = 0.22;
    }else if(annualrate >= 85526 && annualrate <= 163300){
        taxrate = 0.24;
    }else if(annualrate >= 163301 && annualrate <= 207350){
        taxrate = 0.32;
    }else if(annualrate >= 207351 && annualrate <= 518400){
        taxrate = 0.35;
    }else if(annualrate >= 518401){
        taxrate = 0.37;
    }else{
        taxrate = 1;
        cout<<"invalid income \n";
    }
    
    return taxrate;
}

float getposttaxded(){
    float postded;
    cout<<"Please enter the total amount of post-tax deductions combined: \n";
    cin>> postded;
    return postded;
}

//test complete still work on date output

void printbills(bill *node){
    // need to find a way to organize displaying data
    cout<<"These are all of your current bills for the month: \n";
    cout<<"--------------------------------------------------- \n";
    cout<<"                                                    \n";
    
    while (node != NULL){
        // find fix the precison for the appropriate data type
        cout <<right<<" "<<setprecision(2)<<fixed<<"Amount due: $"<<node->amount<<" \n";
        //need to format date to display nicer
        cout <<right<<" "<<setprecision(0)<<"Date Due: "<<node->date<<" \n";
        cout <<right<<" "<<setprecision(1)<<fixed<<"Invoice Number: # "<<node->invoice<<" \n";
        cout <<right<<" "<<"Description: "<<node->name<<" \n";
        cout <<"                                      \n";
        node = node->next;
        cout<<"                                          \n";
    }
}

//calculates netpay 
float netpay(float totalfunds, float pretaxD, float postaxD, float taxrate){
    float netpay, afterpret;
    
    afterpret = (totalfunds - pretaxD);
    netpay = afterpret - (afterpret * taxrate)- postaxD;
    
    return netpay;
}

//passed test and works
float disposibleincom(float netpay, bill *node){
    float dispinc;
    float billsum = 0;
    
    while(node != NULL){
        billsum += node->amount;
        node = node->next;
    }
    
    dispinc = netpay - billsum; // include the function for calculating disposible income
    cout<< dispinc;
    
    return dispinc;
}

//explains the purpose of the programs
void programintro(){
    cout<<"A program built to balance your fiances \n";
    cout<<"You will be able to see a montly breakdown of your cashflow \n";
    cout<<"Lets start by grabbing some info: \n";
    cout<<"                         \n";
}

// prints out the actual cashflow breakdown for the user
void printbreakdown(float grosspay,float pretaxded, float taxrate, float postded, float dips ){
    cout<<"Let's Review your spending for the month \n";
    cout<<"---------------------------------------------- \n";
    cout<<"                                             \n";
    cout<<right<<"Your gross pay monthly is: $"<<grosspay<<" \n";
    cout<<"                                              \n";
    cout<<right<<"Your Pre-Tax Deductions comined are: $"<<pretaxded<<" \n";
    cout<<"                                             \n";
    cout<<right<<"Your Federal Tax Rate is: "<<taxrate<<" % based on your income. \n";
    cout<<"                                                       \n";
    cout<<right<<"Your Netpay after Post-Tax deductions is: $"<<postded<<" \n";
    cout<<"                                                      \n";
    cout<<right<<"After all your bills your diposible income is : $"<<dips<<" \n";
    cout<<"                                                       \n";
    cout<<right<<"This is your monthly breakdown of your cashflow, Happy Spending! \n";
    
}

int main() {
    float a, b, c, x, y, z;
    bill* head = nullptr;
    
    appendbill(&head, 100, 15022020, 001, "Direct TV");
    pushbill(&head, 75.23, 12022020, 002, "Phone bill");
    pushbill(&head, 152.13, 23022020, 003, "Car Insurance");
    
   
    
    programintro();
    a = getgrosspay();
    x = federalincometax2020(a);
    b = getpretaxDed();
    c = getposttaxded();
    printbills(head);
    y = netpay(a, b, c, x);
    z = disposibleincom(y, head);
    printbreakdown(a, b, x, c, z);

    return 0;
}
