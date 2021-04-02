
//*********************************************************************************************//
//  Class Node (implementation)                                                                //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 1                                                            //
//  Date  : 2021-04-01                                                                         //
//  Program Description: Implementation file for the Node Object.                              //
//***********************************************************************************************

#include <iostream>
#include "Node.h"

////////// CONSTRUCTORS ////////// 
Node::Node()
{
	next = NULL;
	previous = NULL;
}

Node::Node(const dataType& initData, Node* initNext, Node* initPrevious)
{
	data = initData;
	next = initNext;
	previous = initPrevious;
}

////////// DECTRUCTOR ////////// 
Node::~Node() 
{
    next = NULL;
    previous = NULL;
}

////////// SETTERS //////////
void Node::setData(const dataType& newData)       
{
    data = newData;
}

void Node::setNext (Node* nextLink)               
{
    next = nextLink;
}

void Node::setPrevious (Node* previousLink)       
{
    previous = previousLink;
}

            
////////// GETTERS //////////
const Node* Node::getPrevious() const             
{
    return previous;
}

Node* Node::getPrevious()                         
{
    return previous;
}

const Node* Node::getNext() const                 
{
    return next;
}

Node* Node::getNext()                             
{
    return next;
}

const Node::dataType Node::getData() const
{
    return data;
}

