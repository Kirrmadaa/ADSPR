#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (!top) {
            cout << "Underflow\n";
        } else {
            cout << top->data << " popped\n";
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void peek() {
        if (!top) {
            cout << "Empty\n";
        } else {
            cout << "Top: " << top->data << endl;
        }
    }
    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; stack.push(value); break;
            case 2: stack.pop(); break;
            case 3: stack.peek(); break;
            case 4: stack.display(); break;
        }
    } while (choice != 5);

    return 0;
}
