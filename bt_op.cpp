#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void display() {
        inOrderTraversal(root);
        cout << endl;
    }

    void displayLeafNodes() {
        displayLeafNodesRecursive(root);
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

    void inOrderTraversal(Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void displayLeafNodesRecursive(Node* node) {
        if (node) {
            if (!node->left && !node->right) {
                cout << node->data << " ";
            }
            displayLeafNodesRecursive(node->left);
            displayLeafNodesRecursive(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    do {
        cout << "\n1.Insert 2.Display In-Order 3.Display Leaf Nodes 4.Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "In-order display of tree: ";
                tree.display();
                break;
            case 3:
                cout << "Leaf nodes: ";
                tree.displayLeafNodes();
                break;
        }
    } while (choice != 4);

    return 0;
}
