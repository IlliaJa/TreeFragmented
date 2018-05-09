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
	// delete item, that doesnt have similar
	void deleteItem(T data);
	// corectly delete, but not comfortable
	void deleteItem(Node<T>* temp);
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
	// num- number of arguments;    delete item, that doesnt have similar
	void fifth(int num, ...);
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
	// auxiliary(helper) for find
	Node<T>* findByIndex(Node<T> *current, int index);
	Node<T> *root;
	// auxiliary(helper) for height
	void height(Node<T>* current, int singleheight);
	// reset all counts in tree
	void setCounts();
	void setCounts(Node<T>* current, int count);
	Node<T>* find(Node<T>* current, T data);
	// helper for delete
	void deleteWithTwo(Node<T>* temp);
};
#endif