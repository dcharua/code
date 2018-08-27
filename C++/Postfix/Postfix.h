#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

class Postfix {
    private:
        std::string infix;
        std::string postfix;

        int computeOperator(int num1, int num2, char sign);
        int comparePrecedence(char op1, char op2);
        bool IsNumeric(char num);
        bool isOperator(char op);
        int charToInt(const char c);
    public:
        Postfix () {}
        Postfix (std::string _infix) { infix = _infix; }
        void setInfix (std::string _infix) { infix = _infix; }
        void convertToPostfix();
        int evaluate();
        std::string getPostfix() { return postfix; }

};


int Postfix::computeOperator(int num1, int num2, char sign)
{
    if (sign == '^')
        return pow(num1, num2);
    else if (sign == '*')
        return num1 * num2;
    else if (sign == '/')
        return num1 / num2;
    else if (sign == '%')
        return num1 % num2;
    else if (sign == '+')
        return num1 + num2;
    else if (sign == '-')
        return num1 - num2;
    else
        return 0;
}

int Postfix::comparePrecedence(char op1, char op2)
{
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

void Postfix::convertToPostfix()
{
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

int Postfix::evaluate()
{
	Stack<int> evaluationStack;
  int num1, num2, result=0;
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
			evaluationStack.push(charToInt(postfix[i]));
		}
	}
	//returning the result
	return evaluationStack.top()->getData();
}

bool Postfix::IsNumeric(char num) {
	if(num >= '0' && num <= '9')
    return true;
	else
    return false;
}

bool Postfix::isOperator(char op){
  if (op== '^' || op== '*' || op == '/' || op == '%' || op == '+' || op == '-')
    return true;
  else
    return false;
}

int Postfix::charToInt(const char c){
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
