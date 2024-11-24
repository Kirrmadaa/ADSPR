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

    Node* constructTree(string postfix) {
        stack<Node*> stk;
        for (int i = 0; i < postfix.length(); i++) {
            char c = postfix[i];

            if (isdigit(c)) {
                stk.push(new Node(c));
            } else {
                Node* node = new Node(c);
                node->right = stk.top();
                stk.pop();
                node->left = stk.top();
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
    string postfix;

    cout << "Enter a postfix expression: ";
    cin >> postfix;

    tree.root = tree.constructTree(postfix);

    cout << "In-order traversal of the expression tree: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
