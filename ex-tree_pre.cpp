#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() : root(nullptr) {}

    Node* constructTree(string prefix) {
        stack<Node*> stk;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];

            if (isdigit(c)) {
                stk.push(new Node(c));
            } else {
                Node* node = new Node(c);
                node->left = stk.top();
                stk.pop();
                node->right = stk.top();
                stk.pop();
                stk.push(node);
            }
        }
        return stk.top();
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    ExpressionTree tree;
    string prefix;

    cout << "Enter a prefix expression: ";
    cin >> prefix;

    tree.root = tree.constructTree(prefix);

    cout << "In-order traversal of the expression tree: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
