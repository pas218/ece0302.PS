//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"


template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor


template<class ItemType>
Stack<ItemType>::~Stack()
{
	//get rid of all stack contents
	while(!isEmpty()){
		pop();
	}
}  // end destructor


template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}  // end isEmpty


template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	//make new node
	Node<ItemType>* newNode = new Node<ItemType>;

	//create new node and make is the top pointer
	newNode->setItem(newItem);
	newNode->setNext(headPtr);
	headPtr = newNode;
	newNode = nullptr;
	currentSize++;
	return true;


}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{

	
	if (!isEmpty()){

		//return item
		return headPtr->getItem();		

	}

	return 0;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	
	//set success varible

	bool success = 0;

	if (!isEmpty()){

		//make deleting pointer
		Node<ItemType>* deletingPtr = headPtr;

		//shift down headPtr
		headPtr = headPtr->getNext();

		//erase the top pointer
		deletingPtr->setNext(nullptr);
		deletingPtr = nullptr;

		//decrease size
		currentSize--;
		success = 1;

	}

	return success;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	//get rid of all stack contents
	while(!isEmpty()){
		pop();
	}
	
	//make currentSize 0
	currentSize = 0;
}  // end clear

