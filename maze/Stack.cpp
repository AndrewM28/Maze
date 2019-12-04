/*************************************************************************
File Name: Stack.cpp
Des:  This file contains the implementation of a class in which a linked
	list is used to dynamically create a stack
Author: Andrew Mock

*************************************************************************/



#include "Stack.h"
#include <iostream>


//Constructor 
Stack::Stack() {
	Top = NULL;
}


//Deconstructor: deletes dynamically allocated memory 
Stack::~Stack() {

	Node* temp = Top;
	
	while (Top != NULL) {
		temp = Top->Next;
		delete Top;
		Top = temp;
		
	}

	


}

//Empty: Checks if Top pointer is NULL, if so the stack is empty 
bool Stack::Empty() {
	if (Top == NULL) {
		return true;
	}
	else {
		return false;
	}

}


//Pop: Takes a variable passed by refereance and then places the data
//located at the top node into that variable, and then deletes the top node
bool Stack::Pop(Coordinate &data) {

	//Checks if stack is empty. If it is there is nothing to pop
	if (Empty()) {
		return false;
	}
	//Checks to see if there is only one node in the list, so when it pops
	//the list will be empty
	else if (Top->Next == NULL) {
		data = Top->Element;
		delete Top;
		Top = NULL;
		return true;
	}
	//For if there are multiple nodes in the list
	else {
		Node* temp = Top;
		Top = Top->Next;
		data = temp->Element;
		delete temp;
		return true;
	}

}


//Push: Takes a data variable and then dynamically creates a new node to place 
//it in and adds it to the top of the stack
bool Stack::Push(Coordinate data) {
	Node* p = new Node;

	//Checks if there is not enough memory for p
	if (p == NULL) {
		return false;
	}
	
	else {
		p->Element = data;

		//Checks if this will be the first node in the stack
		if (Empty()) {
			Top = p;
			Top->Next = NULL;
		}

		//Adds a node to a stack that already has nodes in it
		else {
			p->Next = Top;
			Top = p;
		}
		return true;
	}
}