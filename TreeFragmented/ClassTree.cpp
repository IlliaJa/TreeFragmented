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
Node<T>* Tree<T>::getRoot()
{
	return root;
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
void Tree<T>::deleteItem(T data)
{
	Node<T>* temp = find(data);
	deleteItem(temp);
	if (find(data) != nullptr) deleteItem(data);
}

template<typename T>
void Tree<T>::deleteItem(Node<T>* temp)
{
	if (temp->getRight() == nullptr && temp->getLeft() == nullptr) {
		if (temp->getParent()->getLeft() == temp) temp->getParent()->setLeft(nullptr);
		else temp->getParent()->setRight(nullptr);
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
}

// item have only right link 
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

// item have only left link 
template<typename T>
void Tree<T>::deleteWithLeft(Node<T>* temp)
{
	Node<T>* parent = temp->getParent();
	if (parent->getRight() == temp) parent->setRight(temp->getLeft());
	else parent->setLeft(temp->getLeft());
	temp->getLeft()->setParent(parent);
	delete temp;
	setCounts();
	return;
}

// item have left and right link 
template<typename T>
void Tree<T>::deleteWithTwo(Node<T>* temp)
{
	Node<T>* parent = temp->getParent();
	int i = temp->getData() - 1;
	// find(i) - item, that closest to the value of temp on the left and replace with temp
	while (find(i) == nullptr) {
		i--;
	}
	Node<T>* exchange = find(i);
	if(parent == nullptr) root = exchange;

	Node<T>* exchangeLeft = exchange->getLeft();
	Node<T>* exchangeRight = exchange->getRight();
	Node<T>* exchangeParent = exchange->getParent();
	// set links of exchange
	exchange->setRight(temp->getRight());
	if (temp->getLeft() != exchange) exchange->setLeft(temp->getLeft());
	exchange->setParent(parent);
	// set links to exchange
	if (parent != nullptr) {
		if (parent->getRight() == temp) parent->setRight(exchange);
		else parent->setLeft(exchange);
	}
	if(temp->getLeft() != exchange) temp->getLeft()->setParent(exchange);
	else temp->setLeft(nullptr);
	temp->getRight()->setParent(exchange);

	// set relationship for item near exchange (in first place)
	if(exchangeLeft != nullptr) exchangeLeft->setParent(exchangeParent);
	if(exchangeParent != nullptr) exchangeParent->setRight(exchangeLeft);
	if (exchangeRight != nullptr) exchangeRight->setParent(exchangeLeft);

	delete temp;
	setCounts();
	return;
}

template<typename T>
Node<T>* Tree<T>::find(T data)
{
	Node<T> * current = root;
	return find(current, data);
}

template<typename T>
Node<T>* Tree<T>::find(Node<T>* current, T data)
{
	if (current == nullptr) return nullptr;
	if (current->getData() == data) return current;
	Node<T>* next;
	if (current->getData() <= data)  next = this->find(current->getRight(), data);
	else  next = this->find(current->getLeft(), data);
	if (next != nullptr) return next;
	return nullptr;
}

template<typename T>
Node<T>* Tree<T>::findByIndex(int index)
{
	Node<T> * current = root;
	return findByIndex(current, index);
}

template<typename T>
Node<T>* Tree<T>::findByIndex(Node<T>* current, int index)
{
	if (current == nullptr) return nullptr;
	if (current->getCount() == index) return current;
	Node<T> *inLeft = this->findByIndex(current->getLeft(), index);
	Node<T> *inRight = this->findByIndex(current->getRight(), index);
	if (inLeft != nullptr) return inLeft;
	if (inRight != nullptr) return inRight;
	return nullptr;
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
			if (findByIndex(iForPrintItem) != nullptr) cout << findByIndex(iForPrintItem)->getData();
			else cout << "##";
			iForPrintItem = iForPrintItem + 1;
		} 
		//поочередный вывод пробелов и чисел
		for (k; k < aReply; k++) {
			// вывод пробела нужной длины
			for (int l = 0; l < lengthOfOneSpace; l++) {
				cout << " ";
			}
			if(findByIndex(iForPrintItem) != nullptr) cout << findByIndex(iForPrintItem)->getData();
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

template<typename T>
void Tree<T>::setCounts()
{
	if (root == nullptr) {
		return;
	}
	int count = 0;
	setCounts(root, count);
	return;
}

template<typename T>
void Tree<T>::setCounts(Node<T>* current, int count)
{
	current->setCount(count);
	if (current->getLeft() != nullptr) {
		int countForLeft = count * 2 + 1;
		setCounts(current->getLeft(), countForLeft);
	}
	if (current->getRight() != nullptr) {
		int countForRight = count * 2 + 2;
		setCounts(current->getRight(), countForRight);
	}
	return;
}

template<typename T>
void Tree<T>::printCount(T data)
{
	setCounts();
	Node<T> * current = find(data);
	cout << current->getCount();
}

//===========================================================================
// for problems
// простите за второй парамент, но я не хотел разделять на 2 функции
template<typename T>
void Tree<T>::first(int N, Node<T>* current)
{
	if (current == nullptr) return; // функция не олжна работать с нулевой ссылкой
	this->first(N, current->getLeft()); // рекурсивный запуск функции с тем же N, но с левым елементом
	this->first(N, current->getRight());// рекурсивный запуск функции с тем же N, но с правым елементом
	if ((current->getData() % N) == 0) deleteItem(current->getData()); // удаление елемента, если он подходит под условие
	return;
}

template<typename T>
void Tree<T>::second(Node<T>* current)
{
	// полная аналогия с 1, только мы не передаем N, а просто смотрим остачу от деления на 2
	if (current == nullptr) return; 
	this->second(current->getLeft()); 
	this->second(current->getRight());
	if ((current->getData() % 2) != 0) deleteItem(current->getData()); 
	return;
}

template<typename T>
void Tree<T>::third(int N, Node<T>* current)
{
	if (current == nullptr) return;
	this->third(N, current->getLeft());
	this->third(N, current->getRight());
	if (current->getData() > N) deleteItem(current->getData());
	return;
}

template<typename T>
void Tree<T>::fourth(int N, Node<T>* current)
{
	if (current == nullptr) return;
	this->fourth(N, current->getLeft());
	this->fourth(N, current->getRight());
	if (current->getData() < N) deleteItem(current->getData());
	return;
}

template<typename T>
void Tree<T>::fifth(Node<T>* current)
{
}

template<typename T>
void Tree<T>::sixth(Node<T>* current)
{
}

template<typename T>
void Tree<T>::seventh(Node<T>* current)
{
}

template<typename T>
void Tree<T>::eighth(int X, int Y, Node<T>* current)
{
}

template<typename T>
void Tree<T>::ninth(int N, Node<T>* current)
{
}

template<typename T>
void Tree<T>::tenth(int N, Node<T>* current)
{
}

template<typename T>
void Tree<T>::eleventh(int X, int Y, Node<T>* current)
{
}

template<typename T>
void Tree<T>::twelfth(Node<T>* current)
{
}