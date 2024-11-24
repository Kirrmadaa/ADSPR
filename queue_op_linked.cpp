#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued\n";
}

void dequeue() {
    if (!front) {
        cout << "Queue Underflow\n";
        return;
    }
    Node* temp = front;
    cout << front->data << " dequeued\n";
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void display() {
    if (!front) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = front;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Value: "; 
                cin >> value; 
                enqueue(value); 
                break;
            case 2: 
                dequeue(); 
                break;
            case 3: 
                display(); 
                break;
        }
    } while (choice != 4);

    return 0;
}
