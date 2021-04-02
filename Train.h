//Class Train (header)
/******************************/							//**********************************************//
//Author: Alex Mendes										//	Used as the data type for a Linked List		//
//Course: SENG1120											//	within the SENG1120 Assignment 1 			//
//Date  : 2021-03-11										//	Implemented by: Mick Wiedermann c3315267	//
//Updated by: Dan Bell										//**********************************************//
//Program Description: Header file for the Train Object, to be stored in the Linked List

#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Train 
{
	public:
		// Constructors
		Train();
		Train(const string, const int, const int, const int);

		// Destructor
	    ~Train();

		// Setters
	    void set_id(const string);
		void set_time_hour(const int);
		void set_time_min(const int);
		void set_weight(const int);

		// Getters
		string get_id() const;
		int get_time_hour() const;
		int get_time_min() const;
		int get_weight() const;

	//Private member variables
	private:
		string id; 			// train's ID
		int hour;			// time (hrs component)
		int minutes;		// time (mins component)
		int trainWeight;	// train's weight
};

ostream& operator <<(ostream&, const Train&);

#endif