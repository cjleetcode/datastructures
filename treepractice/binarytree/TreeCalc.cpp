// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
 
  if(tree == NULL)
    return;

  cleanTree(tree -> left);
  cleanTree(tree -> right);
  delete tree;
  
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
     
        insert(response);
       
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {

  if(val == "+" || val == "-" || val == "*" || val == "/"){
    TreeNode* t = new TreeNode(val);
    t -> right = expressionStack.top();
    
    expressionStack.pop();
    
    t -> left =  expressionStack.top();
    expressionStack.pop();
    expressionStack.push(t);
  }
  else{
    TreeNode* ten = new TreeNode(val);
    expressionStack.push(ten);
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  if(tree != NULL){
  cout << tree -> value;
  printPrefix(tree -> left);
  printPrefix(tree -> right);
  }
  else{
    return;
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
  if(tree != NULL){
    printInfix(tree -> left);
    cout << tree -> value;
    printInfix(tree -> right);
  }
  else{
    return;
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
  if(tree != NULL){
    printPostfix(tree -> left);
    printPostfix(tree -> right);
    cout << tree -> value;
  }
  else{
    cout << "";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  
  if(tree -> left == NULL && tree -> right == NULL)
    return stoi(tree -> value);
  else{
    
  int left = calculate(tree -> left);
  int right = calculate(tree -> right);

  if(tree -> value == "+"){
    return left + right;
  }
  else if(tree -> value == "-")
    return left - right;
  else if(tree -> value == "*")
    return left * right;
  else if(tree -> value == "/")
    return left/ right;
  else{
    return -1;
  }
  }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  TreeNode* ref = expressionStack.top();
 
  int f =  calculate(ref);
  cleanTree(expressionStack.top());
  expressionStack.pop();
  return f;
}
