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
	void deleteItem(T data);
	// find item by data
	Node<T>* find(T data);
	// find item by index
	Node<T>* findByIndex(int index);
	// find item and print it
	T findToPrint(int index);
	void watch();
	// return length of way from root to item
	int FindWay(T d);
	// return height of tree
	int height();
	void printCount(T data);
	//======================================================
	// for problems
	void first(int N, Node<T>* current);
	void second(Node<T>* current);
	void third(int N, Node<T>* current);
	void fourth(int N, Node<T>* current);
	void fifth(Node<T>* current);
	void sixth(Node<T>* current);
	void seventh(Node<T>* current);
	void eighth(int X, int Y, Node<T>* current);
	void ninth(int N, Node<T>* current);
	void tenth(int N, Node<T>* current);
	void eleventh(int X, int Y, Node<T>* current);
	void twelfth(Node<T>* current);
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
	Node<T>* find(Node<T>* current, T data);
	// helpers for delete
	void deleteWithRight(Node<T>* temp);
	void deleteWithLeft(Node<T>* temp);
	void deleteWithTwo(Node<T>* temp);
};
#endif