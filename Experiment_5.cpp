#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int MAX;

public:
    Stack(int size) {
        MAX = size;
        arr = new int[MAX];
        top = -1;
    }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push element.\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed successfully.\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Stack is empty.\n";
        } else {
            cout << arr[top--] << " popped successfully.\n";
        }
    }

    void peek() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements (Top to Bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    ~Stack() {
        delete[] arr;
    }
};

int main() {

    int choice, value;
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack s(size);

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);break;
            case 2: s.pop();break;
            case 3: s.peek();break;
            case 4: s.display();break;
            case 5: cout << "Exiting program...\n";break;
            default:
                cout << "Invalid choice! \n";
        }
    } while (choice != 5);
    return 0;
}
