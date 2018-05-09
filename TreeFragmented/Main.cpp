#include "ClassTree.cpp"
#include <iostream>

using namespace std;

int heighththt = 0;

/*int main() {
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
}*/

// main for problems
int main() {
	Tree<int> tree;
	// random elements in tree
	/*for (int i = 0; i < 5; i++) {
		int r = rand() % 99;
		tree.insert(r);

	}*/
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
