//Daniel Charua A01017419

#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"
#include "PostfixTree.h"
#include "TreeNode.h"


class Postfix {
  private:
    std::string infix;
    std::string postfix;
    PostfixTree<char> postfix_tree;

    float computeOperator(float num1, float num2, char sign);
    int comparePrecedence(char op1, char op2);
    bool IsNumeric(char num);
    bool isOperator(char op);
    int floatToInt(float num);
    float charToFloat(const char c);
    float recursiveTreeEvaluate(TreeNode<char> *_root);
  public:
    Postfix () {}
    Postfix (std::string _infix) { infix = _infix; }
    void setInfix (std::string _infix) { infix = _infix; }
    void convertToPostfix();
    void postfixTree();
    float evaluate();
    std::string getPostfix() { return postfix; }
    void printTree();
    void EvaluatePostfixToTree();
    float recursiveTreeEvaluate(){ return recursiveTreeEvaluate(postfix_tree.getRoot());}
};

//Function to make the matematical operation
float Postfix::computeOperator(float num1, float num2, char sign){
  if (sign == '^')
    return pow(num1, num2);
  else if (sign == '*')
    return num1 * num2;
  else if (sign == '/')
    return num1 / num2;
  else if (sign == '%')
    return floatToInt(num1) % floatToInt(num2);
  else if (sign == '+')
    return num1 + num2;
  else if (sign == '-')
    return num1 - num2;
  else
    return 0;
}

//Function to compere the preference of operators
int Postfix::comparePrecedence(char op1, char op2){
  char operators[] = { '^', '*', '/', '%', '+', '-' };
  int precedence[] = {   3,   2,   2,   2,   1,   1 };
  int size = sizeof(operators) / sizeof(operators[0]);
  int value1, value2;

  for (int i=0; i<size; i++)
  {
    if (op1 == operators[i])
      value1 = precedence[i];
    if (op2 == operators[i])
      value2 = precedence[i];
  }
  // Returns the difference in the precedence
  // If larger than 0, value 1 has higher precedence
  return value1 - value2;
}

//Function to convert Infix to Postfix
void Postfix::convertToPostfix(){
  int size = infix.length();
  Stack<char> conversionStack;
  Node<char> * item;
  char token;

  postfix = "";   // Initialize postfix as an empty string

  for (int i=0; i<size; i++)
  {
    token = infix[i];
    // Case 1: numbers
    if (IsNumeric(token))
      postfix += token;
    // Case 2: (
    else if (token == '(')
      conversionStack.push(token);
    // Case 3: )
    else if (token == ')')
    {
      while (conversionStack.top()->getData() != '(')
      {
        // Get the top element from the stack
        item = conversionStack.pop();
        // Append the data it holds to the postfix string
        postfix += item->getData();
        delete item;
      }
      // Get rid of the '('
      item = conversionStack.pop();
      delete item;
    }
    // Case 4: )
    else if (isOperator(token))
    {
    // This one has higher precedence
    if ( conversionStack.isEmpty() ||
      conversionStack.top()->getData() == '(' ||
      comparePrecedence(token, conversionStack.top()->getData()) > 0 )
    {
      conversionStack.push(token);
    }
    else
    {
      while ( !conversionStack.isEmpty() && comparePrecedence(token, conversionStack.top()->getData()) <= 0 )
      {
        item = conversionStack.pop();
        postfix += item->getData();
        delete item;
      }
      conversionStack.push(token);
      }
    }   // Case 4
  }   // for
  // Pop anything left in the stack after finishing the string
  while ( !conversionStack.isEmpty() )
  {
    item = conversionStack.pop();
    postfix += item->getData();
    delete item;
  }
}

//Function to evaluate Postfix, returns the result
float Postfix::evaluate(){
	Stack<float> evaluationStack;
  float num1, num2, result=0;
	for(int i = 0; i< postfix.length();i++) {
		// If character is operator, pop two elements from stack, perform operation and push the result back.
	  if(isOperator(postfix[i])){
		// Pop two numbers.
    num2 =  evaluationStack.top()->getData();
    evaluationStack.pop();
		num1 = evaluationStack.top()->getData();
    evaluationStack.pop();
		// Perform operation
		result = computeOperator(num1, num2, postfix[i]);
		//Push back result of operation on stack.
		evaluationStack.push(result);
	}
	else if(IsNumeric(postfix[i])){
    //if its a number, convert to int and push number to Stack
		evaluationStack.push(charToFloat(postfix[i]));
		}
	}
	//returning the result
	return evaluationStack.top()->getData();
}


//Function to convert the Postfix into a Tree
void Postfix::postfixTree(){
  //Declare three node pointers
  TreeNode<char> *new_node, *right_child, *left_child;
  //Declare the stack of node pointers
  Stack<TreeNode<char> *> toTreeStack;

	for(int i = 0; i< postfix.length();i++) {
	// If character is operator, pop two elements from stack, the operator is the root of the tree, the two characters are its childern.
	  if(isOperator(postfix[i])){
		// Pop two Node pointers from the Stack, asign them to left and right childs
    right_child = toTreeStack.pop()->getData();
    left_child = toTreeStack.pop()->getData();
    //make the new node the operators
    new_node = new TreeNode<char> (postfix[i]);
    //asign them to Left and Right childern
    new_node->setRight(right_child);
    new_node->setLeft(left_child);
    //Push the new node pointer back to teh stack
    toTreeStack.push(new_node);
  }
  //if its a number
	else if(IsNumeric(postfix[i])){
    //Convert it to a node pointer
    new_node = new TreeNode<char>(postfix[i]);
    // push the new node pointer to the Stack of Node pointers
		toTreeStack.push(new_node);
		}
	}
  //Set the last element form the stack as the root of the Tree
  postfix_tree.setRoot(toTreeStack.top()->getData());
}

//Function to recursivly evaluate the PostfixTree
float Postfix::recursiveTreeEvaluate(TreeNode<char> * _root) {
  float left, right;
  //Empty Tree case
	if(_root== nullptr)
		return 0;
      //Number Case
  else if (IsNumeric(_root->getData()))
    //Convert to float and return
    return charToFloat(_root->getData());
      //operator Case
	else{
    //Get the value of the left number recusivly calling function with left root
    left = recursiveTreeEvaluate(_root->getLeft());
    //Get the value of the right number recusivly calling function with right root
    right = recursiveTreeEvaluate(_root->getRight());
    //Returns the value of the operation
    return computeOperator(left, right, _root->getData() );
  }
}


//Function to print a tree
void Postfix::printTree(){
  postfix_tree.printTree();
  std::cout<<std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout<< " In Order: "<<std::endl;
  postfix_tree.printInOrder();
  std::cout<<std::endl;
  std::cout<< " Post Order: "<<std::endl;
  postfix_tree.printPostOrder();
  std::cout<<std::endl;
}

//Function to convert to int for % case
int Postfix::floatToInt(float num){
  return num;
}

//function to check if its a number
bool Postfix::IsNumeric(char num) {
	if(num >= '0' && num <= '9')
    return true;
	else
    return false;
}

//Function to check if its an operator
bool Postfix::isOperator(char op){
  if (op== '^' || op== '*' || op == '/' || op == '%' || op == '+' || op == '-')
    return true;
  else
    return false;
}

//Function to convert form char to float
float Postfix::charToFloat(const char c){
  switch (c)
  {
  case '0':
  	return 0;
  case '1':
  	return 1;
  case '2':
  	return 2;
  case '3':
  	return 3;
  case '4':
  	return 4;
  case '5':
  	return 5;
  case '6':
  	return 6;
  case '7':
  	return 7;
  case '8':
  	return 8;
  case '9':
  	return 9;
  default:
  	return 0;
  }
}
#endif
