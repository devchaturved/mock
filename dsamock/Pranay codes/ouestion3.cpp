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

class BinaryTree {
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

    Node* cloneTreeRecursive(Node* current) {
        if (current == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(current->data);
        newNode->left = cloneTreeRecursive(current->left);
        newNode->right = cloneTreeRecursive(current->right);

        return newNode;
    }

    void deleteTreeRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        deleteTreeRecursive(current->left);
        deleteTreeRecursive(current->right);
        delete current;
    }

public:
    BinaryTree() {
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

    BinaryTree cloneTree() {
        BinaryTree clonedTree;
        clonedTree.root = cloneTreeRecursive(root);
        return clonedTree;
    }

    void eraseTree() {
        deleteTreeRecursive(root);
        root = nullptr;
    }
};

int main() {
    BinaryTree tree;
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

    BinaryTree clonedTree = tree.cloneTree();
    cout << "Cloned tree - Inorder traversal: ";
    clonedTree.inorderTraversal();

    tree.eraseTree();
    cout << "Original tree after erasing all nodes - Inorder traversal: ";
    tree.inorderTraversal();

    return 0;
}
