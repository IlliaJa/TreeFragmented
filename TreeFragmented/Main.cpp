#include "ClassTree.cpp"
#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"

using namespace std;

int heighththt = 0;

int main() {
	Tree<int> tree;

	tree.insert(50);
	tree.insert(100);
	tree.insert(125);
	tree.insert(150);
	tree.insert(75);
	tree.insert(111);
	tree.insert(70);
	tree.insert(95);
	tree.insert(25);
	tree.insert(21);
	tree.insert(45);
	tree.insert(27);
	tree.insert(51);
	//tree.watch();
	//cout << tree.height() << endl;
	//tree.deleteItem(2);
	//tree.printCount(3);
	tree.watch();
	tree.deleteItem(75);
	tree.watch();
	tree.deleteItem(50);
	//tree.deleteItem(100);
	tree.watch();
	//cout << tree.find(2);
	//cout<< tree.FindWay(70)<<endl;
	//cout << tree.findToPrint(2) << endl;
	cout << "x";

	system("pause");
}

// main for problems
/*int main() {
	Tree<int> tree;
	for (int i = 0; i < 5; i++) {
		int r = rand() % 99;
		tree.insert(r);

	}
	tree.insert(10);
	tree.insert(8);
	tree.insert(12);
	/*int r;
	for (int i = 0; i < 15; i++)
	{
		cin >> r;
		tree.insert(r);
	} 
	tree.watch();
	tree.first(5, tree.getRoot());
	cout << "x";
	tree.watch();
	system("pause");
} */
