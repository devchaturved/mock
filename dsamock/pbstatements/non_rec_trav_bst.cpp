#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertNodeRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertNodeRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertNodeRecursive(current->right, value);
        }

        return current;
    }

    void inorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        inorderTraversalRecursive(current->left);
        cout << current->data << " ";
        inorderTraversalRecursive(current->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, value);
    }

    void inorderTraversalRecursive() {
        inorderTraversalRecursive(root);
        cout << endl;
    }

    void inorderTraversalNonRecursive() {
        if (root == nullptr) {
            return;
        }

        stack<Node*> s;
        Node* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            cout << current->data << " ";

            current = current->right;
        }

        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insertNode(value);
    }

    cout << "Inorder traversal (recursive): ";
    tree.inorderTraversalRecursive();

    cout << "Inorder traversal (non-recursive): ";
    tree.inorderTraversalNonRecursive();

    return 0;
}
