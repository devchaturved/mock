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

    void preorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        cout << current->data << " ";
        preorderTraversalRecursive(current->left);
        preorderTraversalRecursive(current->right);
    }

    void postorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        postorderTraversalRecursive(current->left);
        postorderTraversalRecursive(current->right);
        cout << current->data << " ";
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

        stack<Node*> stack;
        Node* current = root;

        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();
            cout << current->data << " ";

            current = current->right;
        }

        cout << endl;
    }

    void preorderTraversalRecursive() {
        preorderTraversalRecursive(root);
        cout << endl;
    }

    void preorderTraversalNonRecursive() {
        if (root == nullptr) {
            return;
        }

        stack<Node*> stack;
        stack.push(root);

        while (!stack.empty()) {
            Node* current = stack.top();
            stack.pop();
            cout << current->data << " ";

            if (current->right != nullptr) {
                stack.push(current->right);
            }
            if (current->left != nullptr) {
                stack.push(current->left);
            }
        }

        cout << endl;
    }

    void postorderTraversalRecursive() {
        postorderTraversalRecursive(root);
        cout << endl;
    }

    void postorderTraversalNonRecursive() {
        if (root == nullptr) {
            return;
        }

        stack<Node*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            Node* current = stack1.top();
            stack1.pop();
            stack2.push(current);

            if (current->left != nullptr) {
                stack1.push(current->left);
            }
            if (current->right != nullptr) {
                stack1.push(current->right);
            }
        }

        while (!stack2.empty()) {
            Node* current = stack2.top();
            stack2.pop();
            cout << current->data << " ";
        }

        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;
    int numNodes, value;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < numNodes; i++) {
        cin >> value;
        tree.insertNode(value);
    }

    cout << "Inorder traversal (recursive): ";
    tree.inorderTraversalRecursive();

    cout << "Inorder traversal (non-recursive): ";
    tree.inorderTraversalNonRecursive();

    cout << "Preorder traversal (recursive): ";
    tree.preorderTraversalRecursive();

    cout << "Preorder traversal (non-recursive): ";
    tree.preorderTraversalNonRecursive();

    cout << "Postorder traversal (recursive): ";
    tree.postorderTraversalRecursive();

    cout << "Postorder traversal (non-recursive): ";
    tree.postorderTraversalNonRecursive();

    return 0;
}