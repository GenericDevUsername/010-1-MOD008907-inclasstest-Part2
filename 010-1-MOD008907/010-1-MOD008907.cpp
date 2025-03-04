// 010-1-MOD008907.cpp : This file contains PART 2
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// All Parts: precedence calculator
int precedence(char opChar) {
  if (opChar == '/' || opChar == '*') return 2;
  if (opChar == '+' || opChar == '-') return 1;
  if (opChar == '^') return 3;
  return 0;
}


/// IN-CLASS TEST ANSWERS ///

// Part 2: Infix to Postfix Converter using std::stack (taking brackets into consideration)
string infixToPostfixPart2(string infix) {

  stack<char> charStack;
  string output = "";

  for (char currChar : infix) {
    if (isalnum(currChar)) // Operand
      output += currChar;
    else if (currChar == '(')
      charStack.push(currChar);
    else if (currChar == ')') {
      while (!charStack.empty() && charStack.top() != '(') {
        output += charStack.top();
        charStack.pop();
      }
      charStack.pop(); // Remove '('
    }
    else { // Operator
      while (!charStack.empty() && precedence(charStack.top()) >= precedence(currChar)) {
        output += charStack.top();
        charStack.pop();
      }
      charStack.push(currChar);
    }
  }

  while (!charStack.empty()) {
    output += charStack.top();
    charStack.pop();
  }

  return output;
}

int main() {
  string infix;
  // Take user input 
  cout << "Enter a infix: ";
  getline(cin, infix);

  // Strip invalid characters
  char chars[] = " ";
  for (unsigned int i = 0; i < strlen(chars); ++i)
  {
    infix.erase(std::remove(infix.begin(), infix.end(), chars[i]), infix.end());
  }

  string postfix;

  // Attempt to convert infix to postfix.
  try {
    postfix = infixToPostfixPart2(infix);
  }
  catch (const exception& e) {
    cerr << "Exception caught: " << e.what() << endl;
  }

  // Print postfix answer.
  cout << "Postfix: " << postfix << endl;
  return 0;
}