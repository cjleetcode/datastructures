/* Caleb Lee
Lab 104
CS 2150
cjl2pub
AVLTree.cpp
*/

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>

using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  root = insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  return pathFromNode(root, x);
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  return findValue(root, x);
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  return numNodesRoot(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
 int BL = calculateBL(n);
  if(BL == 2){
    if(calculateBL(n -> right) == -1)
     n -> right = rotateRight(n -> right);
   n = rotateLeft(n);
  }
  else if(BL == -2){
    if(calculateBL(n -> left) == 1)
      n -> left = rotateLeft(n -> left);
   n = rotateRight(n);
  }
  else{
    return;
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
   if(n == NULL)
    return NULL;

  AVLNode* one = n -> right;
  AVLNode* zed = one -> left;
  
  one -> left = n;
  n -> right = zed;

  n -> height = max(height(n -> left), height(n -> right)) + 1;
  one -> height = max(height(one -> left), height(one -> right)) + 1;
		    
  return one;
  
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  if(n == NULL)
    return NULL;

  AVLNode* one = n -> left;
  AVLNode* zed = one -> right;
  
  one -> right = n;
  n -> left = zed;

  n -> height = max(height(n -> left), height(n -> right)) + 1;
  one -> height = max(height(one -> left), height(one -> right)) + 1;
		    
  return one;
  
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
      
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}

//custom code: allows traversal through tree and rebalances as needed
AVLNode* AVLTree::insert(AVLNode* n, const string& x){
if(n == NULL){
    AVLNode* no = new AVLNode();
    no -> value = x;
    return no;
  }

  if(x == n -> value)
    return n;
  else if(x < n -> value){
    n -> left = insert(n -> left, x);
    n -> height = 1 + max(height(n -> left), height(n -> right));
  }
  else{
    n -> right = insert(n -> right, x);
    n -> height = 1 + max(height(n -> left), height(n -> right));
  }

  //balance tree
  balance(n);
  return n;
}

int AVLTree::calculateBL(AVLNode* n){
  if(n == NULL)
    return -1;

  //if either path has a NULL node on either side
  if(n -> left == NULL & n -> right != NULL)
    return height(n -> right) + 1;
  else if(n -> left != NULL & n -> right == NULL)
    return -height(n -> left) - 1;

  //if both valeus are present
  else if(n -> left != NULL & n -> right != NULL)
    return (height(n -> right)) - height(n -> left);

  //dead end
  else{
    return 0;
  }
}
  //custom code: finds s in a tree with n as the root
bool AVLTree::findValue(AVLNode* n, const string& x) const{
  if(n == NULL)
    return false;

  if((n -> value).compare(x) == 0)
    return true;

  return findValue(n -> left, x) || findValue(n -> right, x);
}
  
  //custom code: prints num of nodes with n as the root
int AVLTree::numNodesRoot(AVLNode* n) const{
  if(n == NULL)
    return 0;

  return numNodesRoot(n -> left) + numNodesRoot(n -> right) + 1;
}

 //custom code: traverses the tree and prints the path starting from n
string AVLTree::pathFromNode(AVLNode* n, const string& x) const{
  
  if(n == NULL)
    return "";

  if(!findValue(n, x))
    return "";

  if((n -> value).compare(x) == 0)
    return n -> value + " ";

  else if((n -> value).compare(x) > 0){
    return n -> value + " " + pathFromNode(n -> left, x) + " ";
    }
    else{
      return n -> value + " " + pathFromNode(n -> right, x) + " ";
  }
  return n -> value;
  
}


