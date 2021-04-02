
//*********************************************************************************************//
//  Class Node (header)                                                                        //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120                                                                           //
//  Date  : 2021-04-01                                                                         //
//  Program Description: Header file for the Node Object to be used within a linked list.      //
//***********************************************************************************************

#ifndef NODE_H
#define NODE_H
#include <cstdlib> 
#include "Train.h"

class Node
{
    public:
        ////////// TYPEDEF ////////////////////////////// 
        typedef Train dataType;

        ////////// CONSTRUCTORS /////////////////////////
        // Precondition: None.
        // Postcondition: 
        Node();
        // Precondition:
        // Postcondition:
        Node(const dataType& initData, Node* initNext = NULL, Node* initPrevious = NULL);
		
        ////////// DESTRUCTOR ///////////////////////////
        // Precondition:
        // Postcondition:
        ~Node();

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////
        // Precondition:
        // Postcondition:
        void setData(const dataType& newData);  

        // Precondition:
        // Postcondition:
        void setNext (Node* nextLink);   

        // Precondition:
        // Postcondition:           
        void setPrevious (Node* previousLink);  

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////
        // Precondition:
        // Postcondition:
        const dataType getData() const;

        // Precondition:
        // Postcondition:
        const Node* getNext() const;
        // Precondition:
        // Postcondition:                 
        Node* getNext(); 

        // Precondition:
        // Postcondition:
        const Node* getPrevious() const;             
        // Precondition:
        // Postcondition:
        Node* getPrevious();                           

    private:
        dataType data;                      // Private member variable that stores the datatypes data.
        Node* next;                         // Private member variable that points to the next node.   
        Node* previous;                     // Private member variable that points to the next node.

};

#endif