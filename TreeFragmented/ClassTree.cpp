#include "ClassTree.h"
#include "ClassNode.h"
#include <iostream>


template<typename T>
Tree<T>::Tree()
{
	root = nullptr;
}

template<typename T>
Tree<T>::~Tree()
{
	clear();
}

template<typename T>
void Tree<T>::setroot(T data)
{
	clear();
	Node<T>* current = new Node<T>(data);
	root = current;
}

template<typename T>
void Tree<T>::insert(T data)
{
	Node<T>* temp = new Node<T>(data);
	if (root == nullptr) {
		root = temp;
		return;
	}
	Node<T>* current = root;
	Node<T>* prev = nullptr;
	int i = 0;
	//compares the date with the current value and go along tree
	while (current != nullptr) {
		prev = current;
		if (data > current->getData()) {
			current = current->getRight();
			i = 2 * i + 2; //formula for count
		}
		else {
			current = current->getLeft();
			i = 2 * i + 1; //formula for count
		}
	}
	// prev is an item, which I link new Node
	// current is nullptr, that went forward
	temp->setParent(prev);
	temp->setCount(i);
	if (data > prev->getData()) prev->setRight(temp);
	else prev->setLeft(temp);
}

template<typename T>
void Tree<T>::deleteItem(Node<T>* temp)
{
	Node<T>* parent = temp->getParent(); // саздание переменной, которая будет родителем удаляемого елемента
	if (temp->getLeft() == nullptr) { //работает, когда елемент является листком
		if (temp->getRight() != nullptr) { // работает, когда у удаляемого елемента есть только правый наследник
			parent->setRight(temp->getRight());
			temp->getRight()->setParent(parent);
		}
		delete temp;
		return;
	}
	if (temp->getRight() == nullptr) { // работает, когда есть только левый наследник
		parent->setLeft(temp->getLeft());
		temp->getLeft()->setParent(parent);
		delete temp;
		return;
	}
	if (temp->getData() > temp->getParent()->getData()) { // if и else аналогичны для правой и левой ветки соответственно
		parent->setRight(temp->getLeft()); 
		temp->getLeft()->setParent(temp->getParent());
		if (temp->getLeft()->getRight() == nullptr) { // замена недостающего наследника правой подветкой
			temp->getLeft()->setRight(temp->getRight());
		}
		else temp->getLeft()->getRight()->setRight(temp->getRight()); // происходит сдвиг правой подветки на 1 ниже
	}
	else {
		parent->setLeft(temp->getRight());
		temp->getRight()->setParent(temp->getParent());
		if (temp->getRight()->getLeft() == nullptr) { // замена недостающего наследника левой подветкой
			temp->getRight()->setLeft(temp->getLeft());
		}
		else temp->getRight()->getLeft()->setLeft(temp->getLeft()); // происходит сдвиг левой подветки на 1 ниже
	}
	delete temp;
	return;
}

template<typename T>
void Tree<T>::clear()
{
	Node<T> *temp = root;
	clearItem(temp);
};

template<typename T>
void Tree<T>::clearItem(Node<T>* temp)
{
	if (temp)
	{
		clearItem(temp->getRight());
		clearItem(temp->getLeft());
		delete temp;
	}
}

template<typename T>
void Tree<T>::clearitemByIndex(int index)
{
	Node<T>* temp = find(index);
	clearItem(temp);
}

/*
bypass width
template<typename T>
Node<T>* Tree<T>::find(int index)
{
	Node<T> *current = root;
	return find(current, index);
}*/

/*template<typename T>
Node<T>* Tree<T>::find(Node<T>* current, int index)
{
	if (current->getCount() == index)  return current;
	bool Saw = false;
	if (root->getSee() == true) Saw = true;
	if (current->getLeft() != nullptr) {
		if(current->getLeft()->getSee() == Saw) current = current->getLeft();
	}
	else {
		if (current->getRight() != nullptr) {
			if(current->getRight()->getSee() == Saw) current = current->getRight();
		}
		else {
			if (current->getSee() == true) current->setSee(false);
			else current->setSee(true);
			current = current->getParent();
			}
		}
	if (root->getSee() != Saw) {
		cout << "Item with this index is not real";
		return root;
	}
	
	find(current, index);
}*/

template<typename T>
Node<T>* Tree<T>::find(int index)
{
	Node<T> * current = root;
	return find(current, index);
}

template<typename T>
Node<T>* Tree<T>::find(Node<T>* current, int index)
{
	
	if (current == nullptr) return nullptr;
	if (current->getCount() == index) return current;
	Node<T> *inLeft = this->find(current->getLeft(), index);
	Node<T> *inRight = this->find(current->getRight(), index);
	if (inLeft != nullptr) return inLeft;
	if (inRight != nullptr) return inRight;
	return nullptr;
	//throw std::exception("Wrong index");
	/*if (current != nullptr)
	{
		if (current->getCount() == index) {
			return current;
		}
		return find(current->getRight(), index) 
			find(current->getLeft(), index);
	}*/
	
}

template<typename T>
T Tree<T>::findToPrint(int index)
{	
	if (find(index) == nullptr) 
		return 0;
	return find(index)->getData();
}

template<typename T>
void Tree<T>::watch()
{
	if (root == nullptr) {
		cout << "sorry, but Tree is empty" << endl;
		return;
	}
	int N = 0; // 
	int iForPrintItem = 0;// счетчик count для печати
	int	lengthOfOneSpace, lengthOfSpaces; // количество пробелов между числами, сумарное количество пробелов в строке 
	int a = 1; // количество елементов на 1 уровне
	int aReply = 1;
	int hmax = height();
	for (int h = 1; h < hmax; h++)
	{
		N = 2 * N + 1;
		a = a * 2;
	}
	int length = (a - 1) * 4 + a * 2; // длина самой длинной строчки
	// вывод для каждого уровня
	for (int h = 0; h < hmax; h++) {
		lengthOfSpaces = length - aReply * 2;
		lengthOfOneSpace = lengthOfSpaces / (aReply + 1);
		int k = 0; // для поочередного вывода, при hmax оно на 1 больше
		// проверка, если это последний уровень, то сначала пробел не надо
		if (h + 1 == hmax) {
			lengthOfOneSpace = 4;
			k = 1;
			if (find(iForPrintItem) != nullptr) cout << find(iForPrintItem)->getData();
			else cout << "##";
			iForPrintItem = iForPrintItem + 1;
		} 
		//поочередный вывод пробелов и чисел
		for (k; k < aReply; k++) {
			// вывод пробела нужной длины
			for (int l = 0; l < lengthOfOneSpace; l++) {
				cout << " ";
			}
			if(find(iForPrintItem) != nullptr) cout << find(iForPrintItem)->getData();
			else cout << "##";
			iForPrintItem = iForPrintItem + 1;
		}
		aReply = aReply * 2;
		cout << "\n\n";
	}
}

//compares the date with the current value and go along tree
template<typename T>
int Tree<T>::FindWay(T d)
{
	Node<T>* current = root;
	int H = 0; // standart length is 0
	while (current != nullptr) {
		if (current->getData() != d) {
			if (d > current->getData()) {
				if (current->getRight() == nullptr) return -1;
				current = current->getRight();
				H = H + 1;
			}
			else {
				if (current->getLeft() == nullptr) return -1;
				current = current->getLeft();
				H = H + 1;
			}
		}
		else break;
	}
	return H;
}



template<typename T>
int Tree<T>::height()
{
	if (root == nullptr) {
		cout << "sorry, but Tree is empty" << endl;
		return 0;
	}
	Node<T>* current = root;
	heighththt = 1; // standart height is 1
	height(root, 1);
	return heighththt;
}

/*
heighththt- global value, it increase when singleheight(L or R) reach higher value
singleheight- current value of height for branch
singleheightLeft- count of height for left branch
singleheightRight- count of height for right branch
*/
template<typename T>
void Tree<T>::height(Node<T>* current, int singleheight)
{
	if (current->getLeft() != nullptr) {
		int singleheightLeft = singleheight + 1;
		if (singleheightLeft > heighththt) heighththt = heighththt + 1; // if branch reached higher value of height, global height increase
		height(current->getLeft(), singleheightLeft);
	}
	if (current->getRight() != nullptr) {
		int singleheightRight = singleheight + 1;
		if (singleheightRight > heighththt) heighththt = heighththt + 1;// if branch reached higher value of height, global height increase
		height(current->getRight(), singleheightRight);
	}
	return;
}