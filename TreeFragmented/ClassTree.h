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
	void insert(T data);
	//delete item
	void deleteItem(Node<T>* temp);
	// delete tree
	void clear();
	// delete item and dependet by index
	void clearitemByIndex(int index);
	// delete old items and set new root
	void setroot(T data);
	// find item by index
	Node<T>* find(int index);
	// find item and print it
	T findToPrint(int index);
	void watch();
	// return length of way from root to item
	int FindWay(T d);
	// return height of tree
	int height();
private:
	// delete item and dependet
	void clearItem(Node<T> *temp);
	// auxiliary(helper) for find↑
	Node<T>* find(Node<T> *current, int index);
	Node<T> *root;
	// auxiliary(helper) for height↑
	void height(Node<T>* current, int singleheight);
};
#endif