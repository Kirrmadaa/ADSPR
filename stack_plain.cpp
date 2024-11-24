#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char value) : data(value), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (!top) return '\0';
        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    ~Stack() {
        while (!isEmpty()) pop();
    }
};

void printOriginalAndReversed(const string& str) {
    Stack s;
    for (char c : str) s.push(c);

    cout << "Original String: " << str << endl;
    cout << "Reversed String: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

bool isPalindrome(const string& str) {
    Stack s;
    for (char c : str) s.push(c);

    string reversed;
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    return str == reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    printOriginalAndReversed(str);

    if (isPalindrome(str))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";

    return 0;
}
