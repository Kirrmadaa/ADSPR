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

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void displayPreOrder() {
        preOrderTraversal(root);
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

    void preOrderTraversal(Node* node) {
        if (node) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
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
        cout << "\n1.Insert 2.Display InOrder 3.Display PreOrder 4.Display Leaf Nodes 5.Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "In-order display of tree: ";
                tree.displayInOrder();
                break;
            case 3:
                cout << "Pre-order display of tree: ";
                tree.displayPreOrder();
                break;
            case 4:
                cout << "Leaf nodes: ";
                tree.displayLeafNodes();
                break;
        }
    } while (choice != 5);

    return 0;
}
