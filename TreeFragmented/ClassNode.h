#pragma once
#ifndef __ClassNode__
#define __ClassNode__

template<typename T>
class Node {
public:
	T data;
	int count;
	Node<T> *parent;
	Node<T> *left;
	Node<T> *right;
	Node(T data = T(), Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr, int count = 0) {
		this->data = data;
		this->parent = parent;
		this->left = left;
		this->right = right;
		this->count = count;
	}
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		return this->data;
	}
	void setParent(Node<T> *parent) {
		this->parent = parent;
	}
	Node<T>* getParent() {
		return parent;
	}
	void setLeft(Node<T> *left) {
		this->left = left;
	}
	Node<T>* getLeft() {
		return left;
	}
	void setRight(Node<T> *right) {
		this->right = right;
	}
	Node<T>* getRight() {
		return right;
	}
	void setCount(int count) {
		this->count = count;
	}
	int getCount() {
		return count;
	}
};
#endif

