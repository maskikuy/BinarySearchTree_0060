#include<iostream>
#include<string>
using namespace std;

class Node {

public:
	string info;
	Node* leftchild;
	Node* rightchild;

	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;
	BinaryTree() {
		ROOT = NULL;
	}
	void insert(string element) {
		Node* newNode = new Node(element, NULL, NULL);
		newNode->info = element;
		newNode->leftchild = NULL;
		newNode->rightchild = NULL;

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode);

		if (parent == NULL) {
			ROOT = newNode;
			return;
		}
		if (element < parent->info) {
			parent->leftchild = newNode;
		}
		else if (element > parent->info) {
			parent->rightchild = newNode;

		}
	}
	void search(string element, Node*& parent, Node*& currentNode) {
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << "";
			inorder(ptr->leftchild);
		}
	}

	void preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << "";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}
	void postorder(Node* ptr) // function to perform inorder traversal
	{
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			postorder(ptr->leftchild); // left
			postorder(ptr->rightchild); // right
			cout << ptr->info << " "; // root
		}
	}
};
int main()
{
	BinaryTree x;
	while (true)
	{
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3':
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4':
		{
			x.postorder(x.ROOT);
			break;
		}
		case '5':
			return 0;
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
	}
}