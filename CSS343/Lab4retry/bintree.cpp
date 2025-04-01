
////////////////////////////////  bintree.cpp file  /////////////////////////////

#include "bintree.h"

void BinTree::display() const{
    inorderHelper(root);
}
void BinTree::inorderHelper( const Node* current) const {
    if(current != nullptr) //As long as there are still nodes   
    {
        inorderHelper(current->left);
        current->data->display();
        inorderHelper(current->right);
    }
}

//----------------------------------------------------------------------------
// BinTree: Default constructor
BinTree::BinTree() {
    root = nullptr; 
}

//----------------------------------------------------------------------------
// ~BinTree: Destructor, calls makeEmpty
BinTree::~BinTree() {
    makeEmpty();
}

//----------------------------------------------------------------------------
// makeEmptry: deletes and sets all nodes in tree to nullptr
// deleteArrHelper: recursive iterator that deletes from each node
void BinTree::makeEmpty() {
    deleteArrHelper(root);
    root = nullptr;     
}

void BinTree::deleteArrHelper(Node* current) {
    if(current != nullptr) { //While tree not empty
        delete current->data;
        deleteArrHelper(current->left);
        deleteArrHelper(current->right);
        delete current; //deletes node information and node itself
        current = nullptr;
    }
}

//----------------------------------------------------------------------------
// isEmpty: checks to see if the tree is empty
bool BinTree::isEmpty() const{
    return root == nullptr; 
}

//----------------------------------------------------------------------------
// displaysideways: displays a vizualization of the tree
void BinTree::displaySideways() const {
    sidewaysHelper(root,0);
}

//----------------------------------------------------------------------------
// sidewaysHelper
void BinTree::sidewaysHelper(Node* current, int level) const {
   if (current != nullptr) {
      level++;
      sidewaysHelper(current->right, level);

      // indent for readability, same number of spaces per depth level 
      for(int i = level; i >= 0; i--) {
          cout << "         ";
      }

      cout << *current->data << endl; // display information of object
      sidewaysHelper(current->left, level);
   }
}

//----------------------------------------------------------------------------
//insert
//is responsible for sorting the tree. 
//Assumes parameter is pointing to a valid object
//assumes the tree is inorder
bool BinTree::insert(NodeData* dataptr) {
   Node* ptr = new Node;  // exception is thrown if memory is not allocated
   ptr->data = dataptr;
   dataptr = nullptr;
   ptr->left = ptr->right = nullptr;
   if (isEmpty()) { //if empty insert node as root
      root = ptr;
      return true;
   }
   else {
      Node* current = root;
      bool inserted = false;
    
      // traverse tree, either walking left or right;
      // if item is less than current item, insert in left subtree,
      // otherwise, when >= insert in right subtree
      while (!inserted) {
        if (*ptr->data < *current->data) {
            if (current->left == nullptr) { // at leaf, insert left
               current->left = ptr;                       
               inserted = true;
            } else
               current = current->left;     // one step left
         }
         else if(*ptr->data > *current->data) { // handles >=
            if (current->right == nullptr) { // at leaf, insert right
               current->right = ptr;
               inserted = true;
            }
            else
               current = current->right;    // one step right
         } else {
            
            //if duplicate
            delete ptr; 
            ptr = nullptr; 
            return false; 
         }
      }
   }
   return true;
}

//----------------------------------------------------------------------------
// operator!=: will return opposite of operator==
bool BinTree::operator!=(const BinTree &other) const {
    return !(equalHelper(root, other.root));
}

//----------------------------------------------------------------------------
// operator==: Equality operator
// Checks if two trees are identical in structure and content
// Returns: true if trees are equal, false otherwise
// equalHelper: recursively compares nodes in both trees 
// Assume other is a valid tree
bool BinTree::operator==(const BinTree &other) const {
    return equalHelper(root, other.root);
}

bool BinTree::equalHelper(const Node* current,const Node* other) const {
    if((current == nullptr) && (other == nullptr)) {
        return true; 
    } 
    if(current == nullptr || other == nullptr){
        return false; 
    }

    //if data is ever not equal, return false, else continue iterating 
    //through tree
    return (*current->data == *other->data) &&
            equalHelper(current->left, other->left) &&
            equalHelper(current->right, other->right);
}

//----------------------------------------------------------------------------
// retrieve: Searches for a node with the given data
// If found, sets the second parameter to point to the found data
// Returns: true if the data was found, false otherwise
// assumes tree is in order
bool BinTree::retrieve(const NodeData& target, NodeData*& retNode) const { 
    Node* temp = root; //set and traverse tree using temp
    while(!(temp == nullptr)) {
        
        if(*temp->data == target) {
            retNode = temp->data;
            return true; 
        }
        if(*temp->data > target) { 
            if(temp->left != nullptr) {
           temp = temp->left; // using binary search
        } else {
            break;
        }
            
        } else {
            if(temp->right != nullptr) {
                temp = temp->right;
            } else {
                break;
            }  
        }
    }
    return false; //if we break out of loop, means target is not in BST
};

//----------------------------------------------------------------------------
// remove: Removes a node with the given data from the tree
// will return the retNode if target is found within tree
// assumes tree is in order
bool BinTree::remove(const NodeData& target, NodeData* &retNode) {
   return removeHelper(root, target, retNode);
}

bool BinTree::removeHelper(Node*& current, const NodeData& target,
NodeData* &retNode) {
   // tree or subtree is empty
   if (current == nullptr) {
      return false;
   }

   // found item to remove
   if (target == *current->data) {
      deleteCurrent(current, retNode);
      return true;
   }
   if (target < *current->data) {                 // search left subtree
      return removeHelper(current->left, target, retNode);
   }

   // target >= *current->data                    // search right subtree
   return removeHelper(current->right, target, retNode);
}

void BinTree::deleteCurrent(Node*& current, NodeData* &retNode) {

   // current has no children
   if (current->left == nullptr && current->right == nullptr) {
      retNode = current->data; 
      current->data = nullptr;
      delete current;
      current = nullptr;
   }

   // current has only right child
   else if (current->left == nullptr) {
      retNode = current->data; 
      Node* temp = current;
      current = current->right;
      temp->data = nullptr;
      delete temp;
      temp = nullptr;
   }

   // current has only left child
   else if (current->right == nullptr) {
      retNode = current->data; 
      Node* temp = current;
      current = current->left;
      temp->data = nullptr;
      delete temp;
      temp = nullptr;
   }

   // current has two children
   else {
      retNode = current->data; 
      current->data = findAndDeleteJustBigger(current->left);
   }
}

//---------------------------------------------------------------------------- 
// findAndDeleteJustBigger
// Pre-condition: current is not nullptr
NodeData* BinTree::findAndDeleteJustBigger(Node*& current) {
   if (current->right == nullptr) {
      NodeData* retNode = current->data;
      Node* junk = current;
      current = current->left;
      delete junk;
      junk = nullptr;
      return retNode;
   }
   return findAndDeleteJustBigger(current->right);
}
//----------------------------------------------------------------------------
// getParent: Finds the parent of a node with the given data
// parentHelper: Recursive function that searchs for the parent node
// assumes tree is not in order but a regular tree, need to traverse whole
bool BinTree::getParent(const NodeData& target, NodeData& retNode) const {
    if(isEmpty()) { return false; }
    if(*root->data == target) { return false; } //root has no parent
    Node* current = root;
    return parentHelper(current, target, retNode);
}

bool BinTree::parentHelper(const Node* current, const NodeData& target,
 NodeData& retNode) const {
    if (current == nullptr) { //Base case
        return false;

        //Iterating though children node to check if current is the parent
    } else if (current->left != nullptr && *current->left->data == target) {
        retNode = *current->data; 
        return true;
    } else if (current->right != nullptr && *current->right->data==target) {
        retNode = *current->data;
        return true;
    } else {

        // || because method will continue to traverse though whole tree
           return (parentHelper(current->left, target , retNode) ||
        parentHelper(current->right, target , retNode));
    }
}

//----------------------------------------------------------------------------
// getSibling: Finds the sibling of a node with the given data
// siblingHelper: recursively looks for the sibling node
// if the node has no sibling, we return false
//assumes tree isn't in order but a regular tree, need to traverse whole tree
bool BinTree::getSibling(const NodeData& target, NodeData& retNode) const {
    if(isEmpty()) {
        return false;
    }
    if(target == *root->data) { //root can't have a sibling
        return false;
    }
    Node* current = root;
    return siblingHelper(current, target, retNode);
}

bool BinTree::siblingHelper(const Node* current, const NodeData& target,
 NodeData& retNode) const {
    if(current == nullptr) { //reached last child
        return false;

        //if target is found, need to check if child has a sibling
        //if true, return sibling, else return false
    } else if(current->left != nullptr && *current->left->data == target) {
        if(current->right != nullptr) {
            retNode = *current->right->data;
            return true;
        } else {
            return false;
        }
    } else if(current->right != nullptr && 
    *current->right->data == target) {
        if(current->left != nullptr) {
            retNode = *current->left->data; 
            return true; 
        } else {
            return false;
        }
    } else {

        // || because method will continue to traverse though whole tree
        return siblingHelper(current->left, target, retNode) || 
        siblingHelper(current->right,target,retNode);
    }
}
//----------------------------------------------------------------------------
//bstreeToArray: convert binary search tree to Array
//Assume array is empty
//inOrderBSTToArr: Helper method that adds to the array in accending order
void BinTree::bstreeToArray(NodeData* retArr[]) {
    if(isEmpty()) {return; }
    int i = 0;
    return inOrderBSTToArr(i, root, retArr);
}

void BinTree::inOrderBSTToArr(int& i, Node* &current, NodeData* retArr[]) {
    if (current != nullptr) { //as long as bst is not empty
        inOrderBSTToArr(i, current->left, retArr);
        retArr[i] = current->data; //adding to array
        i++;
        inOrderBSTToArr(i, current->right, retArr);
        current->data = nullptr;
        delete current;
        current = nullptr;
    }
};
//----------------------------------------------------------------------------
//arrayToBSTree: creates a balanced BST 
//assumes BST is empty
//inOrderArrToBSTreeHelper: sets middle to be root and recursively build tree
void BinTree::arrayToBSTree(NodeData* retArr[]) {
    if(retArr == nullptr) {
        makeEmpty();
        return; 
    }
    int arrSize = 0; 
    while(retArr[arrSize] != nullptr) {
        arrSize++;
    }
    root = inOrderArrToBSTreeHelper(retArr, 0, arrSize - 1);
}

BinTree::Node* BinTree::inOrderArrToBSTreeHelper(NodeData* retArr[],
 int start, int end) {
    if(start > end) { //base case 
        return nullptr;
    }

    //take middle of array/subarray to become next node
    int middle = (start + end) / 2; 
    Node* current = new Node; 

    current->left = current->right = nullptr; 
    current->data = retArr[middle];
    retArr[middle] = nullptr; 

    current->left = inOrderArrToBSTreeHelper(retArr, start, middle - 1);
    current->right = inOrderArrToBSTreeHelper(retArr, middle + 1, end);
    return current; 
}