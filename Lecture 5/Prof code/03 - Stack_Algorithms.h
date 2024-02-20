// Created by Dayu Wang (dwang@stchas.edu) on 2022-09-21

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-28


#ifndef STACK_ALGORITHMS_H
#define STACK_ALGORITHMS_H

#include "List_Stack.h"

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::ostringstream;
using std::stoi;
using std::string;
using std::vector;

/** Reverses a vector of integers.
    @param vec: vector of integers to reverse
*/
void reverse(vector<int>& vec) {
    List_Stack<int> stk;
    for (size_t i = 0; i < vec.size(); i++) { stk.push(vec.at(i)); }
    for (size_t j = 0; j < vec.size(); j++) {
        vec[j] = stk.top();
        stk.pop();
    }
}  // Time complexity: O(n)

/** Tests whether a string is a palindrome.
    @param s: string to test
    @return: {true} if the string is palindromic; {false} otherwise
*/
bool is_palindromic(const string& s) {
    List_Stack<char> stk;
    for (string::const_iterator it = s.begin(); it != s.end(); it++) { stk.push(*it); }
    string reversed;
    while (!stk.empty()) {
        reversed.push_back(stk.top());
        stk.pop();
    }
    return reversed == s;
}  // Time complexity: O(n)

/** Tests whether parentheses are balanced in an expression.
    @param exp: expression to test
    @return: {true} if parentheses are balanced; {false} otherwise
*/
bool is_balanced(const string& exp) {
    List_Stack<char> stk;
    for (string::const_iterator it = exp.begin(); it != exp.end(); it++) {
        if (*it == '(' || *it == '[' || *it == '{') { stk.push(*it); }
        if (*it == ')' || *it == ']' || *it == '}') {
            if (stk.empty()) { return false; }
            if (*it == ')' && stk.top() != '(') { return false; }
            if (*it == ']' && stk.top() != '[') { return false; }
            if (*it == '}' && stk.top() != '{') { return false; }
            stk.pop();
        }
    }
    return stk.empty();
}  // Time complexity: O(n)

/** Evaluates a postfix expression.
    @param postfix: postfix expression to evaluate
    @return: evaluation result
    @throws exception: divide-by-zero
*/
int eval_postfix(const string& postfix) {
    istringstream iss(postfix);
    List_Stack<int> stk;
    string token;  // Current token
    while (iss >> token) {
        if (isdigit(token.front())) { stk.push(stoi(token)); }
        else {
            int right = stk.top();
            stk.pop();
            int left = stk.top();
            stk.pop();

            // Supported operators
            if (token == "+") { stk.push(left + right); }
            if (token == "-") { stk.push(left - right); }
            if (token == "*") { stk.push(left * right); }
            if (token == "/") {
                if (!right) { throw exception("Divide by zero"); }
                stk.push(left / right);
            }
        }
    }
    return stk.top();
}  // Time complexity: O(n)

/** Returns the precedence of an operator.
    @param oper: operator to return its precedence
    @return: precedence
    @throws exception: operator unsupported
*/
int precedence(const string& oper) {
    if (oper == "*" || oper == "/") { return 5; }
    if (oper == "+" || oper == "-") { return 6; }
    throw exception("Unsupported operator");
}  // Time complexity: O(1)

/** Converts an infix expression to postfix expression.
    @param infix_exp: infix expression to convert
    @return: postfix expression converted from the infix expression
*/
string infix_to_postfix(const string& infix_exp) {
    istringstream iss(infix_exp);
    ostringstream oss;
    List_Stack<string> stk;
    string token;
    while (iss >> token) {
        if (isdigit(token.front())) { oss << ' ' << token; }
        else if (token == "(") { stk.push(token); }
        else if (token == ")") {
            while (stk.top() != "(") {
                oss << ' ' << stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (!stk.empty() && stk.top() != "(" && precedence(token) >= precedence(stk.top())) {
                oss << ' ' << stk.top();
                stk.pop();
            }
            stk.push(token);
        }
    }
    while (!stk.empty()) {
        oss << ' ' << stk.top();
        stk.pop();
    }
    return oss.str();
}  // Time complexity: O(n)

#endif