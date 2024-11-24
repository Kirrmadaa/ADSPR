#include <iostream>
using namespace std;

struct Node {
    int marks;
    Node* left;
    Node* right;
    Node(int value) : marks(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void displayInAscendingOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void displayMinMax() {
        if (root) {
            cout << "Minimum Marks: " << findMin(root)->marks << endl;
            cout << "Maximum Marks: " << findMax(root)->marks << endl;
        }
    }

private:
    Node* insertRecursive(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->marks) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->marks << " ";
            inOrderTraversal(node->right);
        }
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }
};

int main() {
    BST bst;
    int choice, marks;

    do {
        cout << "\n1.Insert Marks 2.Print Marks in Ascending Order 3.Print Min and Max Marks 4.Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Marks: ";
                cin >> marks;
                bst.insert(marks);
                break;
            case 2:
                cout << "Marks in Ascending Order: ";
                bst.displayInAscendingOrder();
                break;
            case 3:
                bst.displayMinMax();
                break;
        }
    } while (choice != 4);

    return 0;
}
