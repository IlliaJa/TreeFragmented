#include "ClassTree.cpp"
#include <iostream>

using namespace std;

int heighththt = 0;

int main() {
	Tree<int> tree;
	// random elements in tree
	for (int i = 0; i < 15; i++) {
		int r = rand() % 99;
		tree.insert(r);

	}
	tree.watch();

	// input elements
	/*int r;
	for (int i = 0; i < 15; i++)
	{
		cin >> r;
		tree.insert(r);
	} */
	tree.first(5, tree.getRoot());
	//tree.second(tree.getRoot());
	//tree.third(90, tree.getRoot());
	//tree.fourth(130, tree.getRoot());
	//tree.fifth(3, 8, 10, 16);
	//tree.sixth(tree.getRoot());
	//tree.seventh(tree.getRoot());
	//tree.eighth(5, 20, tree.getRoot());
	//tree.ninth(1, tree.getRoot());
	tree.watch();
	system("pause");
} 
