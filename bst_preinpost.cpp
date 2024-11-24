#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void displayPreOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void displayPostOrder() {
        postOrderTraversal(root);
        cout << endl;
    }

private:
    Node* insertRecursive(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    void preOrderTraversal(Node* node) {
        if (node) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BST bst;
    int choice, value;

    do {
        cout << "\n1.Insert 2.Display PreOrder 3.Display InOrder 4.Display PostOrder 5.Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "PreOrder traversal: ";
                bst.displayPreOrder();
                break;
            case 3:
                cout << "InOrder traversal: ";
                bst.displayInOrder();
                break;
            case 4:
                cout << "PostOrder traversal: ";
                bst.displayPostOrder();
                break;
        }
    } while (choice != 5);

    return 0;
}
