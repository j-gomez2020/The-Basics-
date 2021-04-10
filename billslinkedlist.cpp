//
//  billslinkedlist.cpp
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
