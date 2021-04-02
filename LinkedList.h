
//*********************************************************************************************//
//  Class LinkedList (header)                                                                  //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120                                                                           //
//  Date  : 2021-04-01                                                                         //
//  Program Description: Header file for the linked list Object.      						   //
//***********************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
	public:
        ////////// TYPEDEF ////////////////////////////// 
		// Extension of the Node typedef to ensure data types match.
		typedef Node::dataType dataType;

		////////// CONSTRUCTORS /////////////////////////

		// Precondition: None
		// Postcondition: A new instance of am empty linked list is created
		    // All pointers set to NUll, list length set to 0.
		LinkedList();
        // Precondition: None
        // Postcondition: A new instance of a linked list is created with a single node.
            // All pointers set to the new node, list size incremented to 1.
		LinkedList(dataType& data);

		////////// DESTRUCTOR ///////////////////////////

		// Precondition: None.
		// Postcondition: Deletes all nodes in the list.
		    // Calls the removeFromHead() function in a while loop.
		~LinkedList();

		////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition:
        // Postcondition:
		void addToHead(const dataType data);        // Adds a node to the head of the list and updates relevant pointers.

        // Precondition:
        // Postcondition:
		void addToTail(const dataType data);        // Adds a node to the tail of the list and updates relevant pointers.

        // Precondition:
        // Postcondition:
		void addToCurrent(const dataType data);     // Adds a new node in front of the current pointers position.

        // Precondition:
        // Postcondition:
		dataType removeFromHead();

        // Precondition:
        // Postcondition:
		dataType removeFromTail();

        // Precondition:
        // Postcondition:
		dataType removeFromCurrent();

		// Precondition:
        // Postcondition:
		void remove(string target);

		// Precondition:
        // Postcondition:
		void removeEarlier(int hour, int min);
		
		////////// ACCESSOT FUNCTIONS (GETTERS) /////////

        // Precondition:
        // Postcondition:
        dataType getCurrent();

        // Precondition:
        // Postcondition:
		void start(); 	                            // moves to current head

        // Precondition:
        // Postcondition:
		void end(); 	                            // moves to current tail

        // Precondition:
        // Postcondition:
		void forward();                             // moves current one node to the right

        // Precondition:
        // Postcondition:
		void back(); 	                            // moves current one node to the left

        // Precondition:
        // Postcondition:
		const int getSize() const;

	    // Precondition:
        // Postcondition:			
		double calcTotalWeight();

		/////////// MEMBER OPERATOR OVERLOAD ////////////
		// Precondition:
        // Postcondition:
		void operator += (LinkedList& list2);
	
	private:
		Node* head;                                 // Variable that points to the head node
		Node* tail;                                 // Variable that points to the tail node
		Node* current;                              // Variable that points to the current node
		int length;                           		// Variable to track the length of the list.
};
/////////// MEMBER OPERATOR OVERLOAD ////////////
// Precondition:
// Postcondition:
ostream& operator << (ostream& output, LinkedList& list);

#endif