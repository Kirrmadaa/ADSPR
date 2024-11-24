#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

void decimalToBinary(int number) {
    Stack stack(32);  // A stack large enough to hold the binary representation of the number

    if (number == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    // Push remainders of division by 2 onto the stack
    while (number > 0) {
        stack.push(number % 2);
        number /= 2;
    }

    // Pop from stack and display binary
    cout << "Binary: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int decimalNumber;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToBinary(decimalNumber);

    return 0;
}
