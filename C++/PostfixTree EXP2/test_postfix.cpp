// Daniel Charua A01017419

#include <iostream>
#include <string>
#include "Postfix.h"

void menu();

int main(){
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << " Program to convert Infix expression to Postfix Tree" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << std::endl;
  menu();
  return 0;
}

void menu(){

  Postfix expression;
  std::string infix;
  char option;

  std::cout << " Write the infix expression you want to convert :";
  std::cin >> infix;
  expression.setInfix(infix);
  expression.convertToPostfix();
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << " Your infix converted to postfix: " << expression.getPostfix() << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << " Do you want to evaluate this expression? (y/n): ";
  std::cin >> option;
  if (option == 'y'){
    std::cout << " Evaluating............" << std::endl;
    std::cout << " Result: " << expression.evaluate() << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
  }
  std::cout << " Do you want to convert Postfix into a tree? (y/n): ";
  std::cin >> option;
  if (option == 'y'){
    std::cout << " Converting............" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    expression.postfixTree();
    expression.printTree();
    std::cout << " Evaluating............" << std::endl;
    std::cout<< " Recursive Evaluation: " << expression.recursiveTreeEvaluate()<<std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
  }
  std::cout << " Thank you, goodbye!!!" << std::endl;
}
