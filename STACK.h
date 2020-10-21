 #pragma once
#include <iostream>
using namespace std;
struct NodeStack
{
    int item = 0;
    bool operator==(const NodeStack& p) {
        if (this->item == p.item) { return true; }
        else return false;
    }
    friend ostream& operator<< (ostream& out, const NodeStack& point);
    friend istream& operator>> (istream& out, NodeStack& point);
};
ostream& operator<<(ostream& out, const NodeStack& point)
{
    out << point.item << " ";
    return out;
}
istream& operator>> (istream& out, NodeStack& point)
{
    out >> point.item;
    return out;
}
template <typename T>
class STACK
{
private:
    T stack[100];
    int n = 100, stack_pointer = -1;
    T reversed_stack[100];
public:
    void push(T val) {
        if (stack_pointer >= n - 1)
            cout << "Stack Overflow" << endl;
        else {
            stack_pointer++;
            stack[stack_pointer] = val;
        }
    }
    void pop() {
        if (stack_pointer <= -1)
            cout << "Stack Underflow" << endl;
        else {
            cout << "The popped element is " << stack[stack_pointer] << endl;
            stack_pointer--;
        }
    }
    int pop_int() {
        if (stack_pointer <= -1)
            cout << "Stack Underflow" << endl;
        else {
            --stack_pointer;
            return stack[stack_pointer +1];
           
        }
    }
    void top() {
        if (stack_pointer <= -1)
            cout << "Stack is empty" << endl;
        else {
            cout << "The top of the stack is " << stack[stack_pointer] << endl;
        }
    }
    int top_int() {
        if (stack_pointer <= -1)
            cout << "Stack is empty" << endl;
        else {
            return stack[stack_pointer];;
        }
    }
    void display() {
        if (stack_pointer >= 0) {
            cout << "Stack elements are:";
            for (int i = stack_pointer; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
            cout << "Stack is empty" << endl;
    }
    void swap_top_and_bottom() {
        if (stack_pointer >= 0) {
            T temp = stack[stack_pointer];
            stack[stack_pointer] = stack[0];
            stack[0] = temp;
        }
        else { cout << "Stack is empty" << endl; }
    }
    void reverse_stack() {
        if (stack_pointer >= 0) {
            for (int i = stack_pointer; i >= 0; i--) {                
                    reversed_stack[stack_pointer - i] = stack[i];
            }
            for (int i = 0; i <= stack_pointer; i++) {
                stack[i] = reversed_stack[i];
            }
        }
        else
            cout << "Stack is empty";
    }
    void delete_all() {
        for (int i = stack_pointer; i >= 0; i--) {
            pop();
        }
    }
    bool is_element_belong(T elem) {
        for (int i = stack_pointer; i >= 0; i--) {
            if (stack[i] == elem) {
                return true;
            }
        }
        return false;
    }
    bool is_empty() {
        if (stack_pointer <= 0) {
            return true;
        }
        return false;
    }
};