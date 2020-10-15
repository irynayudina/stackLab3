#include <iostream>
using namespace std;
#include "STACK.h"

int main() {
    int ch=0, val;
    STACK TheStack;
    while (ch != 9) {
        cout << "choose the action" << endl;
        cout << "1 - push" << endl;
        cout << "2 - pop" << endl;
        cout << "3 - top" << endl;
        cout << "4 - display" << endl;
        cout << "5 - swap_top_and_bottom" << endl;
        cout << "6 - reverse_stack" << endl;
        cout << "7 - delete_all" << endl;
        cout << "8 - is_element_belong" << endl;
        cout << "9 - exit this part of menu" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "enter the value" << endl;
            cin >> val;
            TheStack.push(val);
            break;
        case 2:
            TheStack.pop();
            break;
        case 3:
            TheStack.top();
            break;
        case 4:
            TheStack.display();
            break;
        case 5:
            TheStack.swap_top_and_bottom();
            break;
        case 6:
            TheStack.reverse_stack();
            break;
        case 7:
            TheStack.delete_all();
            break;
        case 8:
            cout << "enter the value" << endl;
            cin >> val;
            cout << TheStack.is_element_belong(val);
            break;
        }
    }
    return 0;
}
