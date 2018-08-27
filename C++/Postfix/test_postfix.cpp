#include <iostream>
#include "Postfix.h"

int main(){
  Postfix expression;

  expression.setInfix("9-3*2^2+5");
  expression.convertToPostfix();
  std::cout << "Postfix: " << expression.getPostfix() << std::endl;
  std::cout << "Result: " << expression.evaluate() << std::endl;

  expression.setInfix("8+8*2^5-9");
  expression.convertToPostfix();
  std::cout << "Postfix: " << expression.getPostfix() << std::endl;
  std::cout << "Result: " << expression.evaluate() << std::endl;
}
