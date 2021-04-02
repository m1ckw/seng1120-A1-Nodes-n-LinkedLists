
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
        ////////// TYPEDEF ////////// 
        typedef Train dataType;

        ////////// CONTRUCTORS //////////
        // Precondition:
        // Postcondition:
        Node();
        // Precondition:
        // Postcondition:
        Node(const dataType& initData, Node* initNext = NULL, Node* initPrevious = NULL);
		
        ////////// DESTRUCTOR //////////
        // Precondition:
        // Postcondition:
        ~Node();

        ////////// SETTERS //////////
        // Precondition:
        // Postcondition:
        void setData(const dataType& newData);  

        // Precondition:
        // Postcondition:
        void setNext (Node* nextLink);   

        // Precondition:
        // Postcondition:           
        void setPrevious (Node* previousLink);  

        ////////// GETTERS //////////
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
        ///// PRIVATE MEMBER VARIABLES /////
        dataType data;
        Node* next;
        Node* previous;

};

#endif