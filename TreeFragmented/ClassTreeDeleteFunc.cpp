#include "ClassTree.h"
#include "ClassNode.h"
#include <iostream>


/*template<typename T>
void Tree<T>::deleteItem(Node<T>* temp)
{
	if (temp->getLeft() == nullptr) { //работает, когда елемент является листком
		if (temp->getRight() != nullptr) { // работает, когда у удаляемого елемента есть только правый наследник
			parent->setRight(temp->getRight());
			temp->getRight()->setParent(parent);

		}
		delete temp;
		setCounts();
		return;
	}
	if (temp->getRight() == nullptr) { // работает, когда есть только левый наследник
		parent->setLeft(temp->getLeft());
		temp->getLeft()->setParent(parent);
		delete temp;
		setCounts();
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
	setCounts();
	return;
}*/

template<typename T>
void Tree<T>::deleteItem(int data)
{
	Node<T>* temp = find(data);
	deleteItem(temp);
}

template<typename T>
void Tree<T>::deleteItem(Node<T>* temp)
{
	if (temp->getRight() == nullptr && temp->getLeft() == nullptr) {
		delete temp;
		setCounts();
		return;
	}
	if (temp->getRight() == nullptr) {
		deleteWithLeft(temp);
		return;
	}
	if (temp->getLeft() == nullptr) {
		deleteWithRight(temp);
		return;
	}
	deleteWithTwo(temp);
	return;
}


template<typename T>
void Tree<T>::deleteWithRight(Node<T>* temp)
{
	Node<T>* parent = temp->getParent();
	parent->setRight(temp->getRight());
	temp->getRight()->setParent(parent);
	delete temp;
	setCounts();
	return;
}

template<typename T>
void Tree<T>::deleteWithLeft(Node<T>* temp)
{
	Node<T>* parent = temp->getParent();
	parent->setLeft(temp->getLeft());
	temp->getLeft()->setParent(parent);
	delete temp;
	setCounts();
	return;
}

template<typename T>
void Tree<T>::deleteWithTwo(Node<T>* temp)
{
	Node<T>* parent = temp->getParent();
	int i = temp->getData() - 1;
	// find(i) - item, that closest to the value of temp on the left
	while (find(i) != nullptr) {
		i--;
	}

	Node<T>* exchange = find(i); // item, that replace with temp
	// set relationship for item near exchange
	if (exchange->getLeft() != nullptr) { 
		exchange->getParent()->setRight(exchange->getLeft());
		exchange->getLeft()->setParent(exchange->getParent());
	}

	exchange->setRight(temp->getRight());
	exchange->setLeft(temp->getLeft());
	exchange->setParent(parent);

	if (parent->getRight() == temp) parent->setRight(exchange);
	else parent->setLeft(exchange);
	exchange->getRight()->setParent(exchange);
	exchange->getLeft()->setParent(exchange);

	delete temp;
	setCounts();
	return;
}	
