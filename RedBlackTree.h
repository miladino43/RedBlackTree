#ifndef _REDBLACKTREE_
#define _REDBLACKTREE_

#include <cstdlib>


using namespace std;

// Node class
template <class T>
class Node

{

public:

	T data;

	Node<T>* left;

	Node<T>* right;
	Node<T>* parent;
	bool isBlack;
	//constructor
	Node(T value);
	//constructor
	Node(T value, Node *Left ,Node *Right,bool color);

};
// constructor
// PARAM: value = the data of the node
// PRE:
// POST: Creates a node with data value with no left,right and parent
template <class T>
Node<T>::Node(T value){

	data = value; 
	left = NULL; 
	right = NULL; 
	parent = NULL; 
	isBlack = false;

}
// constructor
// PARAM: value = the data of the node, Left= nodes left node, Right= Nodes right node, color = nodes color
// PRE:
// POST: Creates a node with data value with  left, and right nodes  and no  parent
template <class T>
Node<T>::Node(T value, Node<T> *Left ,Node<T> *Right,bool color){
	 
	
	data = value; 
	left = Left; 
	right = Right; 
	parent = NULL;
	isBlack = color;


}
 
template <class T>
class RedBlackTree

{

public:

      // Default Constructor

      // PRE:

      // POST: root set to NULL

      RedBlackTree();

	  // Copy Constructor

      // PRE:

      // POST: root set to NULL
	  RedBlackTree(const RedBlackTree& tree);
 
	  // Overloaded assignment operator
	  // In tree1 = tree2 assigns tree2 to tree1 and returns tree1
      // PARAM: rhs = tree to be assigned to the calling object
      // PRE:
      // POST: Copies ls to calling object, returns calling object
	  RedBlackTree& operator=(const RedBlackTree& rhs);

      // De-allocates dynamic memory associated with tree

      // PRE:

      // POST: Value is inserted, in order, in tree

      // **NOTE: not implemented!

      ~RedBlackTree();


	// Searches tree for target

      // PRE:

      // PARAM: target = value to be found

      // POST: Returns true iff target is in tree

      bool search(T target);

	  // Searches tree for values between first and second argument

      // PRE:

      // PARAM: val1= starting node, val2 = ending node, size= number of elements in the array

      // POST: Returns a ponter to an integer array in dynamic memeory with values in between(and including) first and second argument. if no values exists returns NULL
	  T * search(T val1,T val2, int & size);

      // inserts value at a node in tree if it does not exist

      // PRE:

      // PARAM: value to be inserted

      // POST: Returns true if value is inserted and false otherwise
	  bool insert(T value);

	  // removes value at a node in tree if it exists

      // PRE:

      // PARAM: value to be removed

      // POST: Returns true if value is removedand false if value does not exist in tree
	  bool remove(T value);

	  // returns pointer to tree root

      // PRE:

      // PARAM: 

      // POST: returns pointer to tree root or null if tree is empty
	  Node<T> * getRoot();
	  
	  // returns a pointer to in int array that contains all values in tree

      // PRE:

      // PARAM:size= number of elements in the array

      // POST: Returns a ponter to an integer array in dynamic memeory with all values in tree in ascending order

	  T * dump(int & arrSizeize);

	  // Deletes all the nodes in the tree

      // PRE:

      // POST: Deletes all nodes, de-allocating dynamic memory
	  void removeAll();
	 
	  //returns the number of nodes in the tree
	  // PRE:

      // POST: returns the number of nodes in the tree
	  int size();
	  //returns the height of the tree
	  // PRE:

      // POST: returns the longest path from root to a leaf
	  int height();




private:

      

 

      Node<T>* root;

	  int treeSize;
      
	  // Insert value in tree maintaining bst property

      // PRE:

      // PARAM: value = value to be inserted

      // POST: Value is inserted, in order, in tree and a pointer to the node is returned
	  Node<T> * bstInsert(T value);
	  
	   // Insert value in tree maintaining red black tree  property

       // PRE:

       // PARAM: value = value to be inserted

       // POST: Value is inserted, in order with color, in tree. and tree is balanced
	  void rbInsert(T value);
      // Performs an in-order traversal of tree

      // PRE:

      // POST: Prints contents of tree in order

      void inOrderCopy(Node<T>* nd,T * arr, int & index);

 
	  // Performs an in-order traversal of tree

      // PRE:

      // POST: Prints contents of tree in order

      void inOrderCopy(Node<T>* nd,Node<T>* start,Node<T> * end,T * arr, int & index);

		// Performs an in-order traversal of tree

      // PRE:

      // POST: Prints contents of tree in order

      void inOrderGetSize(Node<T> * nd,Node<T>* start,Node<T> * end,int & numElements);

     
	  // Deletes all the nodes in the tree

      // PRE:

      // POST: Deletes all nodes, de-allocating dynamic memory

      void deleteTree(Node<T>*& nd);

	  // Copy all the nodes in the tree

      // PRE:

      // POST: Copy all nodes
	  void copyTree(Node<T> * treePtr, Node<T> *& newTreePtr);

	  // Performs a left rotation about a node

      // PRE:

      // POST: Left rotates subtree about the node nd
	  void leftRotate(Node<T> * nd);

	  // Performs a right rotation about a node

      // PRE:

      // POST: right rotates subtree about the node nd
	  void rightRotate(Node<T> * nd);
	   // Finds the successor(left most node in the right subtree) of a node

      // PARAM: nd = node to be used for finding its successor 

      // POST: Returns a pointer to the node that is the successor of argument
	  Node<T> * successor(Node<T> * nd);
	  
	  // Deletes the specied value from the tree

      // PRE: target = value to be removed

      // POST: Deletes the specied value from the tree 
	 
	  void rbDelete(T target);
	  // Fixes the coloring of tree after a node has been deleted(if required)

      // PRE: nd = deleted nodes child, xd = deleted nodes parent , isleft = true if deleted node was left child

      // POST: Fixes tree colors after a delete
	  void rbDeleteFixUp(Node<T> * nd,Node<T> * xd, bool isleft);

	  // Searches tree for target

      // PRE:

      // PARAM: target = value to be found

      // POST: Returns pointer to target node if found

      Node<T> * searchNodes(T target);

	  // Helper method for determing the height of a tree

      // PRE:

      // PARAM: nd = the node used for determing its height

      // POST: Returns the height of the specified node
	  int heightHelper(Node<T> * nd);
	  
	  // Finds the maximum value between two values (used for finding maximum height)

      // PRE:

      // PARAM: x= value1 , y = value2

      // POST: the maximum value(height) between two iput arguments
	  int maxVal(int x, int y) const;
};

#include "RedBlackTree.cpp"

 

#endif