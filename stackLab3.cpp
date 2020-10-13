#include <iostream>
using namespace std;
int stack[100], n = 100, stack_pointer = -1;
int reversed_stack[100];
void push(int val) {
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
void top() {
    if (stack_pointer <= -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "The top of the stack is " << stack[stack_pointer] << endl;
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
        cout << "Stack is empty";
}
void swap_top_and_bottom() {
    if (stack_pointer > -1) {
        int temp = stack[stack_pointer];
        stack[stack_pointer] = stack[0];
        stack[0] = stack[stack_pointer];
    }
    else { cout << "Stack is empty" << endl; }
}
void reverse_stack() {
    if (stack_pointer >= 0) {
        for (int i = stack_pointer; i >= 0; i--) {
            for (int j = 0; i >= stack_pointer; j++) {
                reversed_stack[j] = stack[i];
            }            
        }    
        for (int i = stack_pointer; i >= 0; i--) {            
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
bool is_element_belong(int elem) {
    for (int i = stack_pointer; i >= 0; i--) {
        if (stack[stack_pointer] == elem) {
            return true;
        }
    }
    return false;
}
int main() {
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2: {
            pop();
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            cout << "Exit" << endl;
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}
