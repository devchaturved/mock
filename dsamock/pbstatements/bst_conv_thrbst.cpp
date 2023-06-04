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

class BinarySearchTree {
private:
    Node* root;

    Node* insertNodeRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertNodeRecursive(current->left, value);
        } else {
            current->right = insertNodeRecursive(current->right, value);
        }

        return current;
    }

    void convertToThreaded(Node* current, Node*& prev) {
        if (current == nullptr) {
            return;
        }

        convertToThreaded(current->left, prev);

        if (prev != nullptr && prev->right == nullptr) {
            prev->right = current;
            prev->isThreaded = true;
        }

        prev = current;

        convertToThreaded(current->right, prev);
    }

    void inorderTraversal(Node* current) {
        Node* temp = current;
        while (temp != nullptr) {
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            cout << temp->data << " ";

            if (temp->isThreaded) {
                temp = temp->right;
            } else {
                temp = temp->right;
                while (temp != nullptr && !temp->isThreaded) {
                    temp = temp->left;
                }
            }
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, value);
    }

    void convertToThreadedBinarySearchTree() {
        Node* prev = nullptr;
        convertToThreaded(root, prev);
    }

    void inorderTraversal() {
        inorderTraversal(root);
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

    tree.convertToThreadedBinarySearchTree();

    cout << "Inorder traversal of the threaded binary search tree: ";
    tree.inorderTraversal();

    return 0;
}
