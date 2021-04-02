//Class Train (implementation)
/******************************/							//**********************************************//
//Author: Alex Mendes										//	Used as the data type for a Linked List		//
//Course: SENG1120											//	within the SENG1120 Assignment 1 			//
//Date  : 2021-03-11										//	Implemented by: Mick Wiedermann c3315267	//
//Updated by: Dan Bell										//**********************************************//
//Program Description: Implementation for the Train Object.

#include "Train.h"
#include <cstdlib>

// Constructors
Train::Train()
{
	id = "";
	hour = 0;
	minutes = 0;
	trainWeight = 0;
}

Train::Train(string id_, int hour_, int minutes_, int trainWeight_)
{
	id = id_;
	hour = hour_;
	minutes = minutes_;
	trainWeight = trainWeight_;
}

// Destructor
Train::~Train()
{
	// nothing to be 'destructed'
}

// Mutator methods (setters)
void Train::set_id(const string id_) 
{
	id = id_;
}

void Train::set_time_hour(const int hour_) 
{
	hour = hour_;
}

void Train::set_time_min(const int minutes_) 
{
	minutes = minutes_;
}

void Train::set_weight(const int trainWeight_)
{ 
	trainWeight = trainWeight_;
}

// Accessor methods (getters)
string Train::get_id() const 
{
	return id;
}

int Train::get_time_hour() const 
{
	return hour;
}

int Train::get_time_min() const 
{
	return minutes;
}

int Train::get_weight() const 
{
	return trainWeight;
}

// overloaded ostream operator
ostream& operator << (ostream& out, const Train& value)
{
	out << "(" << value.get_id() << ", " << value.get_time_hour() << ":" << value.get_time_min() << ", " << value.get_weight() << ") ";
    return out;
}
