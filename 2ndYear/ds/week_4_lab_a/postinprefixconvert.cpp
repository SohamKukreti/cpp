#include <iostream>
#include <cstring>
class CharStack {
private:
char data[100];
int top;
public:
CharStack() : top(-1) {}
void push(char c) {
if (top < 100 - 1) {
data[++top] = c;
}
}
char pop() {
if (top >= 0) {
return data[top--];
}
return '\0';
}
char peek() const {
if (top >= 0) {
return data[top];
}
return '\0';
}
bool isEmpty() const {
return (top == -1);
}
};
bool isOperator(char c) {
return c == '+' || c == '-' || c == '*' || c == '/';
}
int getPrecedence(char op) {
if (op == '+' || op == '-')
return 1;
if (op == '*' || op == '/')
return 2;
return 0;
}
std::string infixToPostfix(const std::string& infix) {
std::string postfix = "";
CharStack stack;
for (char c : infix) {
if (isdigit(c)) {
postfix += c;
} else if (c == '(') {
stack.push(c);
} else if (c == ')') {
while (!stack.isEmpty() && stack.peek() != '(') {
postfix += stack.pop();
}
stack.pop(); // Pop '('
} else if (isOperator(c)) {
while (!stack.isEmpty() && stack.peek() != '(' && getPrecedence(stack.peek()) >=
getPrecedence(c)) {
postfix += stack.pop();
}
stack.push(c);
}
}
while (!stack.isEmpty()) {
postfix += stack.pop();
}
return postfix;
}
double evaluatePostfix(const std::string& postfix) {
CharStack stack;
for (char c : postfix) {
if (isdigit(c)) {
stack.push(c);
} else if (isOperator(c)) {
double operand2 = stack.pop() - '0';
double operand1 = stack.pop() - '0';
double result;
switch (c) {
case '+': result = operand1 + operand2; break;
case '-': result = operand1 - operand2; break;
case '*': result = operand1 * operand2; break;
case '/': result = operand1 / operand2; break;
}
stack.push(result + '0');
}
}
return stack.pop() - '0';
}
std::string reverseString(const std::string& str) {
std::string reversed;
for (int i = str.length() - 1; i >= 0; --i) {
reversed += str[i];
}
return reversed;
}
std::string infixToPrefix(const std::string& infix) {
std::string reversedInfix = reverseString(infix);
std::string postfix = infixToPostfix(reversedInfix);
std::string reversedPrefix = reverseString(postfix);
return reversedPrefix;
}
std::string prefixToPostfix(const std::string& prefix) {
CharStack stack;
for (int i = prefix.length() - 1; i >= 0; --i) {
char c = prefix[i];
if (isdigit(c)) {
stack.push(c);
} else if (isOperator(c)) {
char operand1 = stack.pop();
char operand2 = stack.pop();
std::string newExpr = std::string(1, operand1) + std::string(1, operand2) + c;
stack.push(newExpr[0]);
}
}
return std::string(1, stack.pop());
}
int main() {
// Given infix expression
std::string infix = "(4 + 9 * 6) - ((8 - 6) / 2 * 4) * 9 / 3";
// Convert infix to postfix
std::string postfix = infixToPostfix(infix);
std::cout << "Expression in postfix : " << postfix << std::endl;
// Evaluate postfix expression
double result = evaluatePostfix(postfix);
std::cout << "Output: " << result << std::endl;
// Convert infix to prefix
std::string prefix = infixToPrefix(infix);
std::cout << "Expression in prefix: " << prefix << std::endl;
// Convert prefix to postfix
std::string newPostfix = prefixToPostfix(prefix);
std::cout << "New postfix expression: " << newPostfix << std::endl;
return 0;
}