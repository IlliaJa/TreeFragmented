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
	// delete tree
	void clear();
	// delete item and dependet
	void clearItem(Node<T> *temp);
	// delete item and dependet by index
	void clearitemByIndex(int index);
	// delete old items and set new root
	void setroot(T data);
	// find item by index
	Node<T>* find(int index);
	// auxiliary(helper) for find↑
	Node<T>* find(Node<T> *current, int index);
	// find item and print it
	T findToPrint(int index);
	Node<T> *root;
	void watch();
	// return length of way from root to item
	int FindWay(T d);
	// return height of tree
	int height();
	// auxiliary(helper) for height↑
	void height(Node<T>* current, int singleheight);
};
#endif