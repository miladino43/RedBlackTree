// cmpt225treelab.cpp : Defines the entry point for the console application.

//

// These three preprocessor directives are required to display debug data

// about memory leaks

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include "RedBlackTree.h"
#include <string>

 

 

#include <iostream>

#include "time.h"



 

using namespace std;

 
// Function Prototypes

template <class T>

void printTree(RedBlackTree<T> tree);

template <class T>

void publicAttributesTest(Node<T>* nd);

void simpleTest();

void leakTest1();

void leakTest2();

RedBlackTree<int>* leakTest3();

void RedBlackTreeTest();

void RedBlackTreeChar();

void RedBlackTreeString();

int main()

{

      srand(time(0));

 

      // This ugly stuff here is required to display debug data about memory leaks

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);

    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);

    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

 

      //cout << "... entering leakTest1 ..." << endl << endl;

      //leakTest1();

      //cout << "... leaving leakTest1 ..." << endl << endl;

      //cout << "... entering leakTest2 ..." << endl;

      //leakTest2();

      //cout << "... leaving leakTest2 ..." << endl << endl;

 

      

 
	  //RedBlackTreeTest();
	  RedBlackTreeChar();
	  //RedBlackTreeString();
      cout << endl << endl;
	  //simpleTest();
	  _CrtDumpMemoryLeaks();
	  //simpleTest();
      return 0;

}

 

void leakTest1()

{

      RedBlackTree<int> tree;

      int n = 10;

      for(int i=0; i < n; ++i){

//            tree.bstInsert(rand() % (n*2));

      }

      //tree.print();

      cout << endl << endl;

}

 

void leakTest2()

{

      RedBlackTree<int>* ptree;

      cout << "... entering leakTest3 ..." << endl;

      ptree = leakTest3();

      cout << "... leaving leakTest3 ..." << endl << endl;

      //ptree->print();

      cout << endl << endl;

      delete ptree;

}

 

RedBlackTree<int>* leakTest3()

{

      RedBlackTree<int>* result = new  RedBlackTree<int>();

      int n = 20;

      for(int i=0; i < n; ++i){

//            result->bstInsert(rand() % (n*2));

      }

      return result;

}

void RedBlackTreeTest(){


	RedBlackTree<int> tree;
	////-----x is right child and y's right child is black
	//tree.rbInsert(71);
	//tree.rbInsert(47);
	//tree.rbInsert(87);
	//tree.rbInsert(32);
	//tree.rbInsert(65);
	//tree.rbInsert(93);
	//tree.rbInsert(81);
	//tree.rbInsert(80);
	//tree.rbDelete(93);
	//------------------------------------------------
	
	////--x is left child and y's left is black

	/*tree.rbInsert(47);	
	tree.rbInsert(32);
	tree.rbInsert(71);
	tree.rbInsert(93);
	tree.rbInsert(65);
	tree.rbInsert(87);
	tree.rbInsert(81);
	tree.rbInsert(82);
	tree.rbInsert(80);
	tree.rbInsert(83);
	tree.rbDelete(81);*/
	////------------------------------------------------------

	//--x is right child and y's left is black
	/*tree.rbInsert(71);
	tree.rbInsert(47);
	tree.rbInsert(87);
	tree.rbInsert(32);
	tree.rbInsert(65);
	tree.rbInsert(93);
	tree.rbInsert(81);
	tree.rbInsert(86);	
	tree.rbDelete(93);*/
	//------------------------------------------------------
	
	////--x is left child and y's right is black

	/*tree.rbInsert(47);	
	tree.rbInsert(32);
	tree.rbInsert(71);
	tree.rbInsert(93);
	tree.rbInsert(65);
	tree.rbInsert(87);
	tree.rbInsert(81);
	tree.rbInsert(83);
	tree.rbInsert(80);
	tree.rbInsert(82);
	tree.rbDelete(81);*/
	////------------------------------------------------------

	//-----x sibling is red
	
	/*tree.rbInsert(47);
	tree.rbInsert(71);
	tree.rbInsert(32);
	
	tree.rbInsert(30);
	tree.rbInsert(34);
	tree.root->left->isBlack = false;
	tree.root->left->left->isBlack = true;
	tree.root->left->right->isBlack = true;
	
	tree.rbDelete(71);*/
	//------------------------------------------------

	
	////-----x sibling is black
	
	/*tree.rbInsert(47);
	tree.rbInsert(71);
	tree.rbInsert(32);
	
	tree.rbInsert(60);
	tree.rbInsert(72);
	tree.root->right->isBlack = false;
	tree.root->right->left->isBlack = true;
	tree.root->right->right->isBlack = true;
	
	tree.rbDelete(72);*/
	//------------------------------------------------
	
	//inserting duplicates
	/*bool inserted;
	inserted = tree.insert(16);
	cout<<"1-"<<inserted<<endl;
	tree.insert(16);
	tree.insert(12);
	tree.insert(18);
	inserted = tree.insert(12);
	cout<<"0-"<<inserted<<endl;*/

	//------------------------------------------------

		
	//removing duplicates
	/*bool removed;
    tree.insert(16);
	removed = tree.remove(16);
	cout<<"1-"<<removed<<endl;
	tree.insert(16);
	tree.insert(12);
	removed = tree.remove(20);
	cout<<"0-"<<removed<<endl;
	tree.insert(18);
	removed = tree.remove(12);
	cout<<"1-"<<removed<<endl;*/

	//------------------------------------------------
	//get root test ----x is left child and y's left is black
	//Node<int> * rootptr = tree.getRoot();
	//tree.insert(47);	
	//tree.insert(32);
	//tree.insert(71);
	//tree.insert(93);
	//tree.insert(65);
	//tree.insert(87);
	//tree.insert(81);
	//tree.insert(82);
	//tree.insert(80);
	//tree.insert(83);
	//rootptr = tree.getRoot();

	//tree.remove(81);
	//
	//rootptr = tree.getRoot();
	//-----------------------------------------------------------------------------------------

	//dump test-x is left child and y's left is black

	tree.insert(47);	
	tree.insert(32);
	tree.insert(71);
	tree.insert(93);
	tree.insert(65);
	tree.insert(87);
	tree.insert(81);
	tree.insert(82);
	tree.insert(80);
	tree.insert(83);
	int sz = 0;
	int  * arr = tree.dump(sz);
	for(int i = 0;i < sz; i++){
		cout<<arr[i]<<",";
	
	}
	cout<<endl<<"10-"<<sz<<endl;
	delete[] arr;
	//---------------------------------------------------

	//testing search in between nodes
	/*tree.insert(47);	
	tree.insert(32);
	tree.insert(71);
	tree.insert(93);
	tree.insert(65);
	tree.insert(87);
	tree.insert(81);
	tree.insert(82);
	tree.insert(80);
	tree.insert(83);
	int sz = 0;
	int  * arr = tree.search(32,80,sz);
	for(int i = 0;i < sz; i++){
		cout<<arr[i]<<",";
	
	}
	cout<<endl<<"5-"<<sz<<endl;

	arr = tree.search(32,900,sz);
	if (arr==NULL){
		
		cout<<"NULL"<<endl;
	
	}
	cout<<"0-"<<sz<<endl;*/
	//---------------------------------------------------

	//tree.rbInsert(47);
	//tree.rbInsert(71);
	//tree.rbInsert(32);
	//
	//tree.rbInsert(60);
	//tree.rbInsert(72);

	//RedBlackTree<int> evergreen(tree);//test copy constructor

	//RedBlackTree<int> tree3 = tree;

	//cout<<"3-"<<tree.height()<<endl;
 //------------------------------------------------------------------------
	Node<int> * milad;
	//cout<<"data:"<<(tree.root)->right->left->data<<endl;
	// milad = tree.successor((tree.root)->right->left);
	// if (milad == NULL)
	//	 cout <<"NULL"<<endl;
	// else
	//cout<<"data:"<<milad->data<<endl;


	// cout<<"data:"<<(tree.root)->right->right->data<<endl;
	// milad = tree.predecessor((tree.root)->right->right);
	// if (milad == NULL)
	//	 cout <<"NULL"<<endl;
	// else
	//cout<<"data:"<<milad->data<<endl;

	//milad = tree.searchNodes(65);

	//cout<<milad->data<<endl;
	
	/*tree.bstInsert(10);
	tree.bstInsert(8);
	tree.bstInsert(81);
	tree.rbInsert(7);
	tree.print();

	tree.leftRotate((tree.root)->right);

	cout<<endl<<endl;*/

	//tree.print();
	cout<<"end"<<endl;
}

void RedBlackTreeChar(){

RedBlackTree<char> chartree;

chartree.insert('a');
chartree.insert('b');
chartree.insert('c');
chartree.insert('w');
bool inserted;
inserted = chartree.insert('r');
cout<<"1-"<<inserted<<endl;

inserted = chartree.insert('r');
cout<<"0-"<<inserted<<endl;
	int size = 0;
	char * charArr = chartree.dump(size);
	for(int i = 0;i < size; i++){
		cout<<charArr[i]<<",";
	
	}
	cout<<endl<<"5-"<<size<<endl;


	bool removed;
	removed = chartree.remove('r');
	cout<<"1-"<<removed<<endl;
	removed = chartree.remove('r');
	cout<<"0-"<<removed<<endl;

	chartree.removeAll();
	int siz = chartree.size();
	cout<<"0-"<<siz<<endl;
	/*Node<int> * root = chartree.getRoot();
	if (root == NULL){
	
	cout <<"NULL"<<endl;
	}*/
	delete[] charArr;
}

void RedBlackTreeString(){

	RedBlackTree<string> stringtree;

	stringtree.insert("HELLO");
	stringtree.insert("sdfhvb");
	stringtree.insert("tyuiy");
	//bool inserted;
	/*inserted = */stringtree.insert("qw");
	/*cout<<"1-"<<inserted<<endl;
	inserted = stringtree.insert("qw");
	cout<<"0-"<<inserted<<endl;*/
	int size = 0;
	string * stringArr = stringtree.dump(size);
	for(int i = 0;i < size; i++){
		cout<<stringArr[i]<<",";
	
	}
	cout<<endl<<"4-"<<size<<endl;
	/*bool removed;
	removed = stringtree.remove("HELLO");
	cout<<"1-"<<removed<<endl;
	removed = stringtree.remove("HELLO");
	cout<<"0-"<<removed<<endl;*/
	
	
	delete[] stringArr;
}
void simpleTest()

{

  // Int Tree Tests     

  RedBlackTree<int> intTree1;

  RedBlackTree<int> intTree2;

  intTree1.insert(42);

  intTree1.insert(71);

  intTree1.insert(13);

  intTree1.insert(96);

  intTree1.insert(62);

  intTree2 = intTree1;

  intTree1.remove(13);

  intTree1.remove(96);

  printTree<int>(intTree2);

  cout << endl << "search" << endl << "------" << endl;

  cout << "42? " << intTree1.search(42) << endl;

  cout << "21? " << intTree1.search(21) << endl;

 

  cout << endl;

 

  // String Tree Tests

  RedBlackTree<string> stringTree1;

  stringTree1.insert("Aphrodite");

  stringTree1.insert("Artemis");

  stringTree1.insert("Athena");

  stringTree1.insert("Demeter");

  stringTree1.insert("Eris");

  stringTree1.insert("Hecate");

  RedBlackTree<string> stringTree2(stringTree1);

  stringTree1.remove("Artemis");

  stringTree1.remove("Athena");

  printTree<string>(stringTree2);

  cout << endl << "Athena ... Freya" << endl;

  cout << "----------------" << endl;

  int n = 0;

  string* arr = stringTree2.search("Athena", "Freya", n);

  for(int i=0; i < n; i++){

         cout << arr[i] << endl;

  }

}

 

template <class T>

void publicAttributesTest(Node<T>* nd)

{

  // Confirm that node attributes are accessible

  Node<T>* l = nd->left;

  Node<T>* r = nd->right;

  Node<T>* p = nd->parent;

  bool isBlack = nd->isBlack;

}

 

template <class T>

void printTree(RedBlackTree<T> tree)

{

  int n = 0;

  publicAttributesTest(tree.getRoot());

  T* arr = tree.dump(n);

  cout << "size = " << tree.size() << endl;

  cout << "height = " << tree.height() << endl;

  cout << "root contains: " << tree.getRoot()->data << endl;

 

  for(int i = 0; i < n; ++i){

         cout << arr[i] << endl;

  }

  delete[] arr;

}