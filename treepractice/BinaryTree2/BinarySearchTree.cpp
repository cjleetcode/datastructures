#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
   root = insert(root, x);
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
   root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const{
  return pathFromRoot(root, x);
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  return findValue(root, x);
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  return numNodesFromNode(root);
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
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



  //custom code: traverses through tree and prints s
BinaryNode* BinarySearchTree::insert(BinaryNode* n, const string& x){
   
  if(n == NULL){
    BinaryNode* no = new BinaryNode();
    no -> value = x;
    return no;
  }

  if(x == n -> value)
    return n;
  else if(x < n -> value)
    n -> left = insert(n -> left, x);
  else{
    n -> right = insert(n -> right, x);
  }
  
  return n;
}

  //custom code: traverses the tree and prints the path starting from n
string BinarySearchTree::pathFromRoot(BinaryNode* n, const string& s) const{
  
  if(n == NULL)
    return "";

  if(!findValue(n, s))
    return "";

  if((n -> value).compare(s) == 0)
    return n -> value + " ";

  else if((n -> value).compare(s) > 0){
    return n -> value + " " + pathFromRoot(n -> left, s) + " ";
    }
    else{
      return n -> value + " " + pathFromRoot(n -> right, s) + " ";
  }
  return n -> value;
  
}
  
  //custom code: finds s in a tree with n as the root
bool BinarySearchTree::findValue(BinaryNode* n, const string& s) const{
  if(n == NULL)
    return false;

  if((n -> value).compare(s) == 0)
    return true;

  return findValue(n -> left, s) || findValue(n -> right, s);
}
  
  //custom code: prints num of nodes with n as the root
int BinarySearchTree::numNodesFromNode(BinaryNode* n) const{
  if(n == NULL)
    return 0;

  return numNodesFromNode(n -> left) + numNodesFromNode(n -> right) + 1;
}
