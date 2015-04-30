#ifdef _REDBLACKTREE_
//#include "RedBlackTree.h"

 

// Default Constructor

// PRE:

// POST: root set to NULL
template <class T>
RedBlackTree<T>::RedBlackTree()

{

      root = NULL;
	  treeSize = 0;

}
// Copy Constructor

// PRE:

// POST: root set to NULL
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree& tree){

	treeSize = tree.treeSize;
	copyTree(tree.root, root);

}

// Overloaded assignment operator
// In tree1 = tree2 assigns tree2 to tree1 and returns tree1
// PARAM: rhs = tree to be assigned to the calling object
// PRE:
// POST: Copies ls to calling object, returns calling object
template <class T>
RedBlackTree<T> & RedBlackTree<T>::operator=(const RedBlackTree& rhs){

	// Only copy the tree if it is a different object
	// The this pointer is the address of the calling object
	// i.e. if(calling object is not the parameter)
	if(this != &rhs){
		deleteTree(root); //deallocate dynamic memory
		treeSize = rhs.treeSize;
		copyTree(rhs.root,root); //build new tree
	}
	return *this; //dereference pointer
}

// De-allocates dynamic memory associated with tree

// PRE:

// POST: Value is inserted, in order, in tree
template <class T>
RedBlackTree<T>::~RedBlackTree()

{
	

      deleteTree(root);

	  
}

// returns pointer to tree root

// PRE:

// PARAM: 

// POST: returns pointer to tree root or null if tree is empty
template <class T>
Node<T> * RedBlackTree<T>:: getRoot(){

	return root;
}

// inserts value at a node in tree if value does not already exist

// PRE:

// PARAM: value to be inserted

// POST: Returns true if value is inserted and false otherwise
template <class T>
bool RedBlackTree<T>::insert(T value){

	bool duplicate = search(value);

	//if it wasnt in tree
	if(!duplicate){
	
		rbInsert(value);
		treeSize++;
		return !duplicate;
	}

	//if it was in tree
	return !duplicate;
	

	

}

// Insert value in tree maintaining bst property

// PRE:

// PARAM: value = value to be inserted

// POST: Value is inserted, in order, in tree
template <class T>
Node<T> * RedBlackTree<T>::bstInsert(T value)

{

      Node<T>* newNode = new Node<T>(value);

      Node<T>* parent = root;

      Node<T>* pos = root;

      bool isLeft = true;

      // Set new root if tree is empty

      if(root == NULL){

            root = newNode;

      }else{

            // Find parent of new node

            while(pos != NULL){

                  parent = pos;

                  if(value < parent->data){

                        pos = parent->left;

                        isLeft = true;

                  }else{

                        pos = parent->right;

                        isLeft = false;

                  }

            }

            // Insert new node

            if(isLeft){

                  parent->left = newNode;
				  parent->left->parent = parent;

            }else{

                  parent->right = newNode;
				  parent->right->parent = parent;

            }

      }
	  return newNode;

}

// Insert value in tree maintaining red black tree  property

// PRE:

// PARAM: value = value to be inserted

// POST: Value is inserted, in order with color, in tree. and tree is balanced
template <class T>
void RedBlackTree<T>::rbInsert(T value){
	Node<T> * x;
	Node<T> * y;
	x = bstInsert(value); //insert as per binary search tree and return pointer to the inserted node
	//we have inserted a red node with a red parent
	while (x != root && (x->parent->isBlack)==false){
	//if x's parent is a left child
		if(x->parent == x->parent->parent->left){
			y = x->parent->parent->right; //uncle of x
			//if unncle is also red
			if(y != NULL && y->isBlack == false  ){
				x->parent->isBlack = true;;
				y->isBlack = true;
				x->parent->parent->isBlack = false;
				x = x->parent->parent;
			}//uncle is black
			else{
				//if newnode is a right child
				if(x == x->parent->right){
					x = x->parent;
					leftRotate(x);
				}
			
				x->parent->isBlack = true;
				x->parent->parent->isBlack = false;
				rightRotate(x->parent->parent);
			
			}
		
		}//x's parent is a right child
		else{
		
			y = x->parent->parent->left;//uncle of x
			//if unncle is also red
			if(y != NULL && y->isBlack == false  ){
				x->parent->isBlack = true;;
				y->isBlack = true;
				x->parent->parent->isBlack = false;
				x = x->parent->parent;
			}//uncle is black
			else{
				//if newnode is a left child
				if(x == x->parent->left){
					x = x->parent;
					rightRotate(x);
				}
			
				x->parent->isBlack = true;
				x->parent->parent->isBlack = false;
				leftRotate(x->parent->parent);
			
			}
		
		}
	 
	
	
	}
	//make sure root is always black
	root->isBlack = true;


}
// Searches tree for target

// PRE:

// PARAM: target = value to be found

// POST: Returns true iff target is in tree
template <class T>
bool RedBlackTree<T>::search(T target)

{

      Node<T>* p = root;

      while(p != NULL){

            if(target == p->data){

                  return true;

            }else if(target < p->data){

                  p = p->left;

            }else{

                  p = p->right;

            }

      }

      return false;

}
// Searches tree for values between first and second argument

// PRE:

// PARAM: val1= starting node, val2 = ending node, size= number of elements in the array

// POST: Returns a ponter to an integer array in dynamic memeory with values in between(and including) first and second argument. if no values exists returns NULL
template <class T>
T * RedBlackTree<T>::search(T val1,T val2, int & size){

	T * arr = NULL;
	//check to see if values exist
	Node<T> * start = searchNodes(val1);
	Node<T> * end = searchNodes(val2);

	int numElements= 0;
	//if both values exist
	if (start != NULL && end != NULL){
	
		int index = 0;
		//get the number of elements first
		inOrderGetSize(root,start,end,numElements);
		arr = new T[numElements];
		//copy all the elements
		inOrderCopy(root,start,end,arr,index);
	
	}

	size = numElements;
	return arr;



}
// Searches tree for target

// PRE:

// PARAM: target = value to be found

// POST: Returns true iff target is in tree
template <class T>
Node<T> * RedBlackTree<T>::searchNodes(T target)

{
	 Node<T>* p = root;

      while(p != NULL){
		  //if we have found the correct node
            if(target == p->data){

                  return p ;

            }
			//if target is less than nodes data
			else if(target < p->data){
				//move to nodes left
                  p = p->left;

            }else{
				//move to nodes right
                  p = p->right;

            }

      }
      return NULL;

}


// returns a pointer to in int array that contains all values in tree

// PRE:

// PARAM:size= number of elements in the array

// POST: Returns a ponter to an integer array in dynamic memeory with all values in tree in ascending order
template <class T>
T * RedBlackTree<T>::dump(int & arrSize){

	arrSize = treeSize;
	T * arr = new T[treeSize];
	int index = 0;
	inOrderCopy(root,arr,index);

	return arr;
} 

// Performs an in-order traversal of tree and copys nodes value to dynamic array

// PRE:
// PARAM: nd = root node,  arr= dynamic array to fill, index= index of array to fill
// POST:fills array with all the tree nodes vlues in ascending order
template <class T>
void RedBlackTree<T>::inOrderCopy(Node<T>* nd, T * arr, int & index)

{

  if(nd != NULL){

            inOrderCopy(nd->left,arr,index);
			//copy contents
            arr[index] = nd->data;
			index++;

            inOrderCopy(nd->right,arr,index);

      }


}

// Performs an in-order copying of nodes to dynamic array

// PRE:
// PARAM: nd = root node, start= starting node, end= ending node, arr= dynamic array to fill, index= index of array to fill
// POST: fills array with the values between start ad end
template <class T>
void RedBlackTree<T>::inOrderCopy(Node<T> * nd,Node<T>* start,Node<T> * end,T * arr, int & index){

	if(nd != NULL){

            inOrderCopy(nd->left,start,end,arr,index);
			//if the nodes value is in between start and end (including start and end)
			if (nd->data >= start->data && nd->data <= end->data){
				arr[index] = nd->data; //copy contents
				index++;
			}

            inOrderCopy(nd->right,start,end,arr,index);

      }
}
// Performs an in-order traversal of and gets the number of elements between start and end node

// PRE:
// PARAM: nd = root node, start= starting node, end= ending node, numElements = number of elements that are between start and end
// POST: determines the number of elements in between start and end
template <class T>
void RedBlackTree<T>::inOrderGetSize(Node<T> * nd,Node<T>* start,Node<T> * end,int & numElements){

	if(nd != NULL){

            inOrderGetSize(nd->left,start,end,numElements);
			//if value lies in correct range(between start and end)
			if (nd->data >= start->data && nd->data <= end->data){
				numElements++;
			}

            inOrderGetSize(nd->right,start,end,numElements);
			
      }
}


// Deletes all the nodes in the tree

// PRE:

// POST: Deletes all nodes, de-allocating dynamic memory
template <class T>
void RedBlackTree<T>::deleteTree(Node<T>*& nd)

{

 if(nd != NULL){

            deleteTree(nd->left);

            deleteTree(nd->right);

			delete nd;
			nd = NULL;

      }
 
}
// Deletes all the nodes in the tree

// PRE:

// POST: Deletes all nodes, de-allocating dynamic memory
template <class T>
void RedBlackTree<T>::removeAll(){

	deleteTree(root);
	treeSize = 0;


}

// Copy all the nodes in the tree

// PRE:

// POST: Copy all nodes
template <class T>
void RedBlackTree<T>::copyTree(Node<T> * treePtr, Node<T> *& newTreePtr){

	if (treePtr != NULL)
	{
	
		newTreePtr = new Node<T> (treePtr->data, NULL, NULL,treePtr->isBlack);
		copyTree(treePtr->left, newTreePtr->left);
		copyTree(treePtr->right, newTreePtr->right);
	
	}else {
	
		newTreePtr = NULL;
	}

}

// Performs a left rotation about a node

// PRE:

// POST: Left rotates subtree about the node nd
template <class T>
void RedBlackTree<T>::leftRotate(Node<T> * nd){
	Node<T> * y;
	y = nd->right;
	nd->right = y->left;

	if(y->left != NULL){
		y->left->parent = nd;

	}
	y->parent = nd->parent;

	if(nd->parent== NULL){
		root = y;
	}
	else if(nd == nd->parent->left){
		nd->parent->left = y;
	}else{
		nd->parent->right = y;
	}

	y->left = nd;
	nd->parent = y;

}
// Performs a right rotation about a node

// PRE:

// POST: right rotates subtree about the node nd
template <class T>
void RedBlackTree<T>::rightRotate(Node<T> * nd){

	Node<T> * y;
	y = nd->left;
	nd->left = y->right;

	if(y->right != NULL){
		y->right->parent = nd;

	}
	y->parent = nd->parent;

	if(nd->parent== NULL){
		root = y;
	}
	else if(nd == nd->parent->left){
		nd->parent->left = y;
	}else{
		nd->parent->right = y;
	}

	y->right = nd;
	nd->parent = y;
}
// Finds the successor(left most node in the right subtree) of a node

// PARAM: nd = node to be used for finding its successor 

// POST: Returns a pointer to the node that is the successor of argument
template <class T>
Node<T> * RedBlackTree<T>::successor(Node<T> * nd){

	Node<T> * tmp = nd;
	if (tmp == NULL){
		return NULL;
	}
	//if there is a right child
	if(tmp ->right != NULL){
		
		tmp = tmp->right;

		while(tmp->left != NULL){
		
			tmp= tmp->left;
		}
	
		return tmp;
	}
	//if there is no right child
	else{
	
		while(tmp != NULL){
			
			Node<T> * p = tmp->parent;

			if(p == NULL){
				break;
			}
			if(p->left == tmp){
				return p;
			}
			else{
				tmp = p;
			}
		
		}
	
	}


	return NULL;



}


// removes value at a node in tree if it exists

// PRE:

// PARAM: value to be removed

// POST: Returns true if value is removedand false if value does not exist in tree
template <class T>
bool RedBlackTree<T>::remove(T value){

		bool duplicate = search(value);

	//if it wasn in tree
	if(duplicate){
	
		rbDelete(value);
		treeSize--;
		return duplicate;
	}

	//if it wasnt in tree
	return duplicate;

}
// Deletes the specied value from the tree

// PRE: target = value to be removed

// POST: Deletes the specied value from the tree
template <class T>
void RedBlackTree<T>::rbDelete(T target){


	Node<T> * z = searchNodes(target);
	Node<T> * y;
	Node<T> * x;
	bool isleft = false;
	if (z->left == NULL || z->right == NULL){
		y = z; //node to be removed
	}
	else{
	
		y = successor(z); //or successor 
	}
	if(y->left != NULL){
		x= y->left;	
	}
	else{
		x = y->right;
	}

	if(x != NULL){
		x->parent = y->parent;
	}
	if(y->parent == NULL){
		root = x;
	}
	else{
	
		//Attach x to y's parent
		if (y == y->parent->left){//left child
			y->parent->left = x;
			isleft = true;
		}
		else{
			y->parent->right = x;
		
		}
	}
	if(y != z){//y has been moved up
		z->data = y->data;
	}

	if(y->isBlack == true){
		rbDeleteFixUp(x,y->parent,isleft); //x could be null
	}
	
	delete y;

}
// Fixes the coloring of tree after a node has been deleted(if required)

// PRE: nd = deleted nodes child, xd = deleted nodes parent , isleft = true if deleted node was left child

// POST: Fixes tree colors after a delete
template <class T>
void RedBlackTree<T>::rbDeleteFixUp(Node<T> * nd,Node<T> * xd, bool isleft){

	Node<T> * x = nd;
	//x's parent
	Node<T> *xp = xd;

	Node<T> * y;

	while (x != root && ( x == NULL ||x->isBlack == true)){
	
		if (x == xp->left){
			y = xp->right;

			if(y->isBlack == false){
				y->isBlack = true;
				xp->isBlack = false;
				leftRotate(xp);
				y = xp->right;
			}
			if (((y->left == NULL || y->left->isBlack == true) && (y->right == NULL || y->right->isBlack == true))){
				y->isBlack = false;
				x = xp;
			}
			else{
				//y's right child is black
				if(y->right == NULL || y->right->isBlack == true){
					y->left->isBlack = true;
					y->isBlack = false;
					rightRotate(y);
					y = xp->right;
				}
				//y's left child is black
				y->isBlack = xp->isBlack;
				xp->isBlack = true;
				y->right->isBlack = true;
				leftRotate(xp);
				x = root;
			}
			
			
		
		}
		else{
			y = xp->left;

			if(y->isBlack == false){
				y->isBlack = true;
				xp->isBlack = false;
				rightRotate(xp);
				y = xp->left;
			}
			if (((y->left == NULL || y->left->isBlack == true) && (y->right == NULL || y->right->isBlack == true))){
				y->isBlack = false;
				x = xp;
			}
			else{
			//y's right child is black
				if(y->left == NULL || y->left->isBlack == true){
					y->right->isBlack = true;
					y->isBlack = false;
					leftRotate(y);
					y = xp->left;
				}

			//y's left child is black
				y->isBlack = xp->isBlack;
				xp->isBlack = true;
				y->left->isBlack = true; //changed this from symmetric if
				rightRotate(xp);
				x = root;
		
			}
		}
	
	}
	if (x != NULL){
		x->isBlack = true;
	}

}

//returns the number of nodes in the tree
// PRE:

// POST: returns the number of nodes in the tree
template <class T>
int RedBlackTree<T>::size(){

	return treeSize;
}
//returns the height of the tree
// PRE:

// POST: returns the longest path from root to a leaf
template <class T>
int RedBlackTree<T>::height(){
	
	if (root == NULL){
		return -1;
	}else{

	int height = heightHelper(root);
	
	return height;
	}
}
// Helper method for determing the height of a tree

// PRE:

// PARAM: nd = the node used for determing its height

// POST: Returns the height of the specified node
template <class T>
int RedBlackTree<T>::heightHelper(Node<T> * nd){
	
	if (nd == NULL){
	
		return 0;
	}else{
	
	
            return maxVal(heightHelper(nd->left), heightHelper(nd->right)) + 1;
       
	
	}
	

}
// Finds the maximum value between two values (used for finding maximum height)

// PRE:

// PARAM: x= value1 , y = value2

// POST: the maximum value(height) between two iput arguments
template <class T>
int RedBlackTree<T>::maxVal(int val1, int val2) const{
    
	if (val1 >= val2){
        return val1;
    }
    else{
        return val2;
    }
}

#endif