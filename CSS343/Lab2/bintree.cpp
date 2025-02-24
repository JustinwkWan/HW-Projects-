#include "bintree.h"

ostream& operator<<(ostream& output, const BinTree &tree) {
    if(tree.isEmpty()) {
        return output; 
    }
    tree.inorderHelper(output, tree.root);
    return output;
}

//----------------------------------------------------------------------------
// inorderHelper
void BinTree::inorderHelper(ostream& output, const Node* current) const {
    if(current != nullptr) 
    {
        inorderHelper(output, current->left);
        cout << *current->data << " "; 
        inorderHelper(output, current->right);
    }
}

//----------------------------------------------------------------------------
//default constructor
BinTree::BinTree() {
    root = nullptr; 
}

//----------------------------------------------------------------------------
// copy constructor
BinTree::BinTree(const BinTree &other) {
    if(other.root == nullptr) {
        root = nullptr; 
    } 
    copyHelper(root, other.root);
    
}

void BinTree::copyHelper(Node* &current, const Node* other) {
    if(other != nullptr) {
        current = new Node; 
        current->data = new NodeData(); 
        current->data = other->data; 
        current->right = current->left = nullptr; 
        
        copyHelper(current->left, other->left);
        copyHelper(current->right, other->right);
    }
} 

//----------------------------------------------------------------------------
// deconstructor
BinTree::~BinTree() {
    makeEmpty();
}

//----------------------------------------------------------------------------
// makeEmpty 
void BinTree::makeEmpty() {
    return deleteArrHelper(root);
    root = nullptr; 
}

void BinTree::deleteArrHelper(Node* current) {
    if(current != nullptr) {
        delete current->data;
        deleteArrHelper(current->left);
        deleteArrHelper(current->right);
        delete current; 
        current = nullptr;
    }
}

//----------------------------------------------------------------------------
// isempty 
bool BinTree::isEmpty() const {
    return root == nullptr; 
}

//----------------------------------------------------------------------------
// operator= 
BinTree& BinTree::operator=(const BinTree &other) {
    if(other.isEmpty()) {makeEmpty();}
    if(!(this == &other)){
        copyHelper(root, other.root);
    }
    return *this;
}

//----------------------------------------------------------------------------
// operator!= 
bool BinTree::operator!=(const BinTree &other) const {
    return !(equalHelper(root, other.root));
}

//----------------------------------------------------------------------------
// operator==
bool BinTree::operator==(const BinTree &other) const {
    return equalHelper(root, other.root);
}

bool BinTree::equalHelper(const Node* a,const Node* b) const{
    if(a == nullptr and b == nullptr) {
        return true; 
    } else if(a == nullptr || b == nullptr){
        return false; 
    } else {
        if(a->data == b->data) {
            equalHelper(a->left, b->left);
            equalHelper(a->right, b->right);
        } else {
            return false; 
        }
    }
    return true; 
}
//----------------------------------------------------------------------------
//insert
//inputs the new nodedata into the proper spot
bool BinTree::insert(NodeData* dataptr) {
   Node* ptr = new Node;     // exception is thrown if memory is not allocated
   ptr->data = dataptr;
   dataptr = nullptr;
   ptr->left = ptr->right = nullptr;
   if (isEmpty()) {
      root = ptr;
   }
   else {
      Node* current = root;
      bool inserted = false;
    
      // traverse tree, either walking left or right;
      // if item is less than current item, insert in left subtree,
      // otherwise, when >= insert in right subtree
      while (!inserted) {
        if(*ptr->data == *current->data) {
            return false; 
        }
        if (*ptr->data < *current->data) {
            if (current->left == nullptr) {           // at leaf, insert left
               current->left = ptr;                       
               inserted = true;
            }
            else
               current = current->left;               // one step left
         }
         else {                                       // handles >=
            if (current->right == nullptr) {          // at leaf, insert right
               current->right = ptr;
               inserted = true;
            }
            else
               current = current->right;              // one step right
         }
      }
   }
   return true;
}

//----------------------------------------------------------------------------
// remove
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
   if (target < *current->data) {                      // search left subtree
      return removeHelper(current->left, target, retNode);
   }

   // target >= *current->data                         // search right subtree
   return removeHelper(current->right, target, retNode);
}

//----------------------------------------------------------------------------
// deleteCurrent
void BinTree::deleteCurrent(Node*& current,  NodeData* &retNode) {
   // current has no children
   if (current->left == nullptr && current->right == nullptr) {
      retNode = current->data; 
      delete current->data;
      current->data = nullptr;
      delete current;
      current = nullptr;
   }

   // current has only right child
   else if (current->left == nullptr) {
      Node* temp = current;
      retNode = temp->data;
      current = current->right;
      delete temp->data;
      temp->data = nullptr;
      delete temp;
      temp = nullptr;
   }

   // current has only left child
   else if (current->right == nullptr) {
      Node* temp = current;
      retNode = temp->data;
      current = current->left;
      delete temp->data;
      temp->data = nullptr;
      delete temp;
      temp = nullptr;
   }

   // current has two children
   else {
      retNode = current->data;   
      delete current->data;
      current->data = findAndDeleteJustBigger(current->right);
   }
}

//---------------------------------------------------------------------------- 
// findAndDeleteJustBigger
// Pre-condition: current is not nullptr
NodeData* BinTree::findAndDeleteJustBigger(Node*& current) {
   if (current->left == nullptr) {
      NodeData* item = current->data;
      Node* junk = current;
      current = current->right;
      delete junk;
      junk = nullptr;
      return item;
   }
   return findAndDeleteJustBigger(current->left);
}
//----------------------------------------------------------------------------
// retrieve
// Change temp to root
bool BinTree::retrieve(const NodeData& x, NodeData*& y) const { 
    Node* temp = root;    
    while(!(temp == nullptr)) {
        if(*temp->data == x) {
            y = temp->data;
            return true; 
        }

        if(*temp->data > x) {
            temp = temp->left;
        } else {
           temp = temp->right;
        }
    }
    return(false);
};

void BinTree::bstreeToArray(NodeData* []) {
    NodeData* retArray[100];
    for(int i = 0; i < 100; i++) {
        retArray[i] = nullptr; 
    }
}

//----------------------------------------------------------------------------
// displaysideways
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

      cout << *current->data << endl;        // display information of object
      sidewaysHelper(current->left, level);
   }
}

bool BinTree::getSibling(const NodeData& target, NodeData& sibiling) const {
    return true;
    //begin traversing through list
    //if target is found, begin travesing through list again until 
    //parent->right->data or parent->left->data is correct
    //if they have a kid, return kid
}

bool BinTree::getParent(const NodeData& target, NodeData& parent) const {
    //if target is equal to parent left or right node return parent
    //else continue traversing the tree through recuresive call
    // on both left and right
    //if not found, return false
    return true; 
}