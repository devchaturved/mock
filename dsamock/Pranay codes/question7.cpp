#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        isThreaded = false;
    }
};

class ThreadedBinarySearchTree {
private:
    Node* root;

    Node* insertNodeRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            if (current->left == nullptr) {
                Node* newNode = new Node(value);
                newNode->right = current;
                newNode->isThreaded = true;
                current->left = newNode;
            } else {
                current->left = insertNodeRecursive(current->left, value);
            }
        } else {
            if (current->isThreaded || current->right == nullptr) {
                Node* newNode = new Node(value);
                newNode->right = current->right;
                newNode->isThreaded = true;
                current->right = newNode;
                current->isThreaded = false;
            } else {
                current->right = insertNodeRecursive(current->right, value);
            }
        }

        return current;
    }

    Node* findLeftMost(Node* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorderTraversal(Node* current) {
        if (current == nullptr) {
            return;
        }

        Node* node = findLeftMost(current);
        while (node != nullptr) {
            cout << node->data << " ";

            if (node->isThreaded) {
                node = node->right;
            } else {
                node = findLeftMost(node->right);
            }
        }
    }

public:
    ThreadedBinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    ThreadedBinarySearchTree tree;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insertNode(value);
    }

    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    char choice;
    do {
        cout << "Do you want to insert another node? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the value of the node: ";
            cin >> value;
            tree.insertNode(value);

            cout << "Inorder traversal: ";
            tree.inorderTraversal();
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
