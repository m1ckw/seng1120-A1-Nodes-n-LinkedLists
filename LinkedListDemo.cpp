//LinkedListDemo - Main Program
/******************************/							//**********************************************//
//Author: Alex Mendes										//	SENG1120 | Assignment 1	| LinkedList class	//
//Course: SENG1120											//	implemented by: Mick Wiedermann c3315267	//
//Date  : 2021-03-11										//**********************************************//
//Updated by: Dan Bell
//Program Description: This program demonstrates the basic functionality of a linked list that stores trains circulation data.
//It will demo the functions of a basic linked list.
//The program adds content to a linked list, removes individual nodes, among other functionalities.

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Train.h"
using namespace std;

// initialiser function - creates a Train object and populates the Linked List with a series of them
void initialize(LinkedList &l1, LinkedList &l2)
{
    Train c("RV2T", 11, 38, 500);
    l1.addToTail(c);
    c.set_id("GMYB"); c.set_time_hour(9); c.set_time_min(53); c.set_weight(10000); l1.addToTail(c);
	c.set_id("I4EN"); c.set_time_hour(15); c.set_time_min(24); c.set_weight(6000); l1.addToTail(c);
	c.set_id("PE8Y"); c.set_time_hour(10); c.set_time_min(12); c.set_weight(18000); l1.addToTail(c);
	c.set_id("TPI2"); c.set_time_hour(18); c.set_time_min(47); c.set_weight(13000); l1.addToTail(c);
    c.set_id("EAZ3"); c.set_time_hour(12); c.set_time_min(33); c.set_weight(5000); l1.addToTail(c);
	
	c.set_id("UT5H"); c.set_time_hour(21); c.set_time_min(22); c.set_weight(8500); l2.addToTail(c);
	c.set_id("K5RD"); c.set_time_hour(7); c.set_time_min(17); c.set_weight(11500); l2.addToTail(c);
	c.set_id("9JIT"); c.set_time_hour(14); c.set_time_min(34); c.set_weight(15000); l2.addToTail(c);

}

// program entry point
int main()
{
	// linked list declarations
    LinkedList firstDay;
	LinkedList secondDay;
	
	// populate
	initialize(firstDay, secondDay);

	// display lists
	cout << "Start lists:" << endl;
	cout << "List 1: " << firstDay  <<  endl;
	cout << "List 2: " << secondDay <<  endl << endl;

	// concatenate the lists
	cout << "Concatenating the two lists onto list '1':" << endl;
	firstDay += secondDay;
    cout << "List 1: " << firstDay  << endl;
	cout << "List 2: " << secondDay << endl << endl;

	// remove trains
	cout << "Removing train 'PE8Y' from list '1':" << endl;
    firstDay.remove("PE8Y");
    cout << "List 1: " << firstDay  << endl;
	cout << "List 2: " << secondDay << endl << endl;

	cout << "Removing train '9JIT' from list '1':" << endl;
    firstDay.remove("9JIT");
    cout << "List 1: " << firstDay  << endl;
	cout << "List 2: " << secondDay << endl << endl;
	
	cout << "Removing train 'UT5H' from list '2':" << endl;
    secondDay.remove("UT5H");
    cout << "List 1: " << firstDay  << endl;
	cout << "List 2: " << secondDay << endl << endl;
	
	cout << "Removing trains earlier than 12:00 from list '1':" << endl;
    firstDay.removeEarlier(12,00);
    cout << "List 1: " << firstDay  << endl;
	cout << "List 2: " << secondDay << endl << endl;

	// total weight
	cout << "Total weight (tons) of list '2': ";
	cout << secondDay.calcTotalWeight() << endl << endl;
	
//  Uncomment this section if you are implementing the function order()	
//	cout << "Ordered lists by time of day: " << endl;
//	firstDay.order();
//	secondDay.order();
//	cout << "List 1: " << firstDay  << endl;
//	cout << "List 2: " << secondDay << endl << endl;

	cout << "The program has finished." << endl;
	return 0;
}
