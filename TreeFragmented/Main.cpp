#include "ClassTree.cpp"
#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"

using namespace std;

int heighththt = 0;

int main() {
	Tree<int> tree;

	tree.insert(11);
	tree.insert(20);
	tree.insert(5);
	tree.insert(40);
	tree.insert(3);
	//tree.insert(60);
	//tree.insert(7);
	//tree.insert(30);
	//tree.insert(70);
	tree.watch();
	tree.deleteItem(tree.find(2));
	tree.watch();
	//cout << tree.find(2);
	//cout<< tree.FindWay(70)<<endl;
	//cout << tree.findToPrint(2) << endl;
	//cout << tree.height() << endl;


	system("pause");
}

/*int main() {
	Tree<int> tree;
	
}*/
