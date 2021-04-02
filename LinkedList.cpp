
//*********************************************************************************************//
//  Class LinkedList (implementation)                                                          //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120                                                                           //
//  Date  : 2021-04-01                                                                         //
//  Program Description: Implementation file for the Linked List Object.                       //
//***********************************************************************************************

#include <iostream>
#include "LinkedList.h"


///// CONSTRUCTORS /////
LinkedList::LinkedList() {                                  // Creates an empty list setting all pointers to NULL
    head = NULL;
    tail = NULL;
    current = NULL;
    length = 0;
}
LinkedList::LinkedList(dataType& data) {                    // Creat a list with its first node
    head = new Node( data );
    tail = head;
    current = tail;
    length = 1;
}

////////// DESTRUCTOR //////////
LinkedList::~LinkedList() {                                 // Loops through the list deleting the head until all nodes are deleted.
    while (head != NULL)
        removeFromHead();
    tail = NULL;
}

////////// MUTATOR FUNCTIONS (SETTERS) //////////
void LinkedList::addToHead(dataType data) {                 // Adds a new node to the head of the list.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node( data );
        tail = head;
        current = tail;
        length = 1;
    } else {
        Node* headInsert = new Node( data );                // Creates a new node on the heap.
        head->setPrevious( headInsert );                    // Sets the old heads previous pointer from NULL to the new head.
        headInsert->setNext( head );                        // Sets the new heads next pointer to the old head.
        head = headInsert;                                  // Sets the head pointer to the new head.
        head->setPrevious(NULL);                            // Sets the head previous to NULL
        length++;                                           // Increments the length of the list by 1
        headInsert = NULL;                                  // Sets the temporary pointer to null.
    }
}

void LinkedList::addToTail(dataType data) {                 // Adds a new node to the tail of the list.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node( data );
        tail = head;
        current = tail;
        length = 1;
    } else {
        Node* tailInsert = new Node( data );                // Creates a new node on the heap.
        tail->setNext( tailInsert );                        // Sets the old tails next pointer from NULL to the new tail.
        tailInsert->setPrevious( tail );                    // Sets the new tails previous pointer to the old tail.
        tail = tailInsert;                                  // Sets the tail pointer to the new tail.
        tail->setNext(NULL);                                // Sets the tails next to NULL
        length++;                                           // Increments the length of the list by 1
        tailInsert = NULL;                                  // Sets the temporary pointer to null.
    }
}

void LinkedList::addToCurrent(dataType data) {              // Inserts a new node between current and its previous.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node( data );
        tail = head;
        current = tail;
        length = 1;
    } else if (length == 1) {
        addToHead(data);
    } else {
        Node* currentInsert = new Node( data );             // Creates a new node on the heap.
        currentInsert->setNext( current );                  // Sets the new nodes next pointer to current (link1).
        currentInsert->setPrevious(current->getPrevious()); // Sets the new nodes previous pointer to the previous node (Link3).
        current->setPrevious(currentInsert);                // Sets the current nodes previous pointer to the new node (link4).
        current = currentInsert->getPrevious();             // Moves the current pointer to the node previous.
        current->setNext(currentInsert);                    // Sets the previous nodes next pointer to the new node (link2).
        current = currentInsert->getNext();                 // Moves the current pointer back to its original position.
        length++;                                           // Increments the length of the list by 1.
        currentInsert = NULL;                               // Sets the temporary pointer to null.
    }
}

LinkedList::dataType LinkedList::removeFromHead() {         // Removes the head node from the linked list.
	dataType temp = head->getData();                        // Creates a temp node on the stack to store the head node data.
	if (length == 0) {                                      // Returns null if the list is empty. 
        return temp;
	} else if (length == 1) {                               // Removes the head and sets all pointers to NULL if it's the only node.
        delete head;
        head = NULL;
        tail = NULL;
        current = NULL;
        length--;
    } else {                                                // If > 1 node, this will remove the node and adjust pointers.
        current = head;
        head = current->getNext();                          // Moves the head pointer to the next node.
        delete current;                                     // Deletes the head pointer.
        length--;                                           // Decrements the length of the list.
        current = head;                                     // Moves the current pointer to the head.
        head->setPrevious(NULL);                            // Set the heads prvious to NULL. 
    }
    return temp;                                            // Returns the deleted nodes data. 
}

LinkedList::dataType LinkedList::removeFromTail() {         // Removes the tail node from the linked list.
    dataType temp = tail->getData();                        // Creates a temp node on the stack to store the tail node data.
	if (length == 0) {                                      // Returns null if the list is empty. 
        return temp;
    }else if (length == 1) {                                // Removes the tail and sets all pointers to NULL if it's the only node.
        delete tail;
        head = NULL;
        tail = NULL;
        current = NULL;
        length--;
    } else {                                                // If > 1 node, this will remove the node and adjust pointers.
        current = tail;
        tail = current->getPrevious();
        delete current;
        length--;
        current = head;
    }
	return temp;
}

LinkedList::dataType LinkedList::removeFromCurrent() {      // Removes the node current is pointing to.
    dataType temp = current->getData();                     // Creates a TEMP data storage for the data type.
	if (current == head) {                                  // If the target is the head, invokes removeFromHead().
        removeFromHead();
    }else if (current == tail) {                            // If the target is the tail, invokes removeFromTail().
        removeFromTail();
    } else {
        Node* targetDelete;                                 // Creates a TEMP node pointer.
		targetDelete = current;                             // Sets the TEMP to current, the deletion target.
		current = current->getPrevious();                   // Moves current to the previous node.
		current->setNext(targetDelete->getNext());          // Sets current next to skip deletion target.
		current = current->getNext();                       // Moves current to the node past the deletion target.
		current->setPrevious(targetDelete->getPrevious());  // Sets current previous to skip deletion target.
		delete targetDelete;                                // Deletes target
        length--;                                           // Decrements list length
        targetDelete = NULL;                                // sets the temp noe pointer to null
    }
    return temp;                                            // Returns the data from the deleted node.
}

void LinkedList::remove(string target) {
	start();
	while (target != getCurrent().get_id())	                // Checks target against train ID. Note, snake_case is from Train.
		forward();
	if (target == getCurrent().get_id()) {
		removeFromCurrent();
	} else {
		cout << " The train you are looking for doesn't exist " << endl;
	}
}	

void LinkedList::removeEarlier(int hour, int minute) {
	current = head;                                         // Moves the current pointer to the head.
    int currentSize = getSize();                            // CLocal variable to ensure the loop executes the required no. of times.
    for (int i = 0; i < currentSize; i++) {
        if (hour > getCurrent().get_time_hour()) {          // Selects any train with an hour less than 12. 
            Node* nextTarget = current->getNext();          // Creates a TEMP node pointer to track deletion targets.
            removeFromCurrent();                            // Calls the removeFromCurrent to delete target and adjust pointers
            current = nextTarget;                           // Readjusts current pointer to next node after target deletion.
        } else { 
            forward();                                      // If train hour is > 12 moves current to next node. 
        } 
    }; 
}	

////////// GETTERS //////////
LinkedList::dataType LinkedList::getCurrent() {             // Retrieves the data from the current node.
    return current->getData();
}	

void LinkedList::start() {                                  // Moves the current pointer to head
    if (length == 0) {
        cout << "There is no head, there is no tail, there's nothing, nothing here at all... " << endl;
    } else {
        current = head;
    }
}

void LinkedList::end() {                                    // Moves the current pointer to tail
    if (length == 0) {
        cout << "There is no tail, there is no head, there's nothing, nothing here at all... " << endl;
    } else {
        current = tail;
    }
}

void LinkedList::forward() {                                // Moves the current pointer one node to the right
    if (length == 0) {
        cout << "There is no forward, there is no back, there's nothing, nothing here at all... " << endl;
    } else {
        current = current->getNext();
    }
}

void LinkedList::back() {                                   // moves current one node to the left.
    if (length == 0) {
        cout << "There is no back, there is no forward, there's nothing, nothing here at all... " << endl;
    } else {
        current = current->getPrevious();
    }
}

const int LinkedList::getSize() const {
    return length;
}

double LinkedList::calcTotalWeight() {
	current = head;
    double sum = 0;
	for (int i=0; i < length; i++) {
		sum = sum + getCurrent().get_weight();
        forward();
    } 
    return sum;
}

void LinkedList::operator+= (LinkedList& list2) {
    list2.start();
	int size = list2.getSize();
	for (int i=0; i < size; i++) {
		addToTail(list2.getCurrent());
		list2.forward();
	}
}


ostream& operator << (ostream& output, LinkedList& list) {
    list.start();
	int size = list.getSize();
	for (int i=0; i < size; i++) {
		output << list.getCurrent();
		list.forward();
    }
	return output;
}