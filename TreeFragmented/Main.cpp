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
	tree.insert(30);
	tree.insert(2);
	tree.watch();
	//cout << tree.height() << endl;
	tree.deleteItem(2);
	//tree.printCount(3);
	tree.watch();
	//cout << tree.find(2);
	//cout<< tree.FindWay(70)<<endl;
	//cout << tree.findToPrint(2) << endl;
	//cout << "x";

	system("pause");
}

/*int main() {
	Tree<int> tree;
	
}*/
