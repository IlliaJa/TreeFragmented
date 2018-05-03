#pragma once
#ifndef __ClassTree__
#define __ClassTree__

#include "ClassNode.h"
#include "ClassTree.h"

template<typename T>
class Tree {
public:
	Tree();
	~Tree();
	Node<T> * getRoot();
	void insert(T data);
	// delete tree
	void clear();
	// have 3 helpers for different situations
	void deleteItem(int data);
	// find item by data
	Node<T>* find(int data);
	// find item by index
	Node<T>* findByIndex(int index);
	// find item and print it
	T findToPrint(int index);
	void watch();
	// return length of way from root to item
	int FindWay(T d);
	// return height of tree
	int height();
	void printCount(int data);
	//======================================================
	// for problems
	void first(int N, Node<T>* current);
	void second(Node<T>* current);
	void third(int N);
	void fourth(int N);
	void fifth();
	void sixth();
	void seventh();
	void eighth(int X, int Y);
	void ninth(int N);
	void tenth(int N);
	void eleventh(int X, int Y);
	void twelfth();
	//======================================================
private:
	// auxiliary(helper) for clear
	void clearItem(Node<T> *temp);
	//delete item
	void deleteItem(Node<T>* temp);
	// auxiliary(helper) for find
	Node<T>* findByIndex(Node<T> *current, int index);
	Node<T> *root;
	// auxiliary(helper) for height
	void height(Node<T>* current, int singleheight);
	// reset all counts in tree
	void setCounts();
	void setCounts(Node<T>* current, int count);
	Node<T>* find(Node<T>* current, int data);
	// helpers for delete
	void deleteWithRight(Node<T>* temp);
	void deleteWithLeft(Node<T>* temp);
	void deleteWithTwo(Node<T>* temp);
};
#endif