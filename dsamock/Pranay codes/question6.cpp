#include <iostream>
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

    void preorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        cout << current->data << " ";
        preorderTraversalRecursive(current->left);
        preorderTraversalRecursive(current->right);
    }

    void inorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        inorderTraversalRecursive(current->left);
        cout << current->data << " ";
        inorderTraversalRecursive(current->right);
    }

    void postorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        postorderTraversalRecursive(current->left);
        postorderTraversalRecursive(current->right);
        cout << current->data << " ";
    }

    Node* deleteNodeRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteNodeRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteNodeRecursive(current->right, value);
        } else {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            } else if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            } else {
                Node* minValueNode = findMinValueNode(current->right);
                current->data = minValueNode->data;
                current->right = deleteNodeRecursive(current->right, minValueNode->data);
            }
        }

        return current;
    }

    Node* findMinValueNode(Node* current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, value);
    }

    void preorderTraversal() {
        preorderTraversalRecursive(root);
        cout << endl;
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorderTraversalRecursive(root);
        cout << endl;
    }

    void deleteNode(int value) {
        root = deleteNodeRecursive(root, value);
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

    cout << "Preorder traversal: ";
    tree.preorderTraversal();

    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    cout << "Postorder traversal: ";
    tree.postorderTraversal();

    cout << "Enter the node value to delete: ";
    cin >> value;
    tree.deleteNode(value);

    cout << "Inorder traversal after deleting node: ";
    tree.inorderTraversal();

    return 0;
}
