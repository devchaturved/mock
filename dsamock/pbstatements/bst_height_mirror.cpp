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

    int findHeightRecursive(Node* current) {
        if (current == nullptr) {
            return -1;
        }

        int leftHeight = findHeightRecursive(current->left);
        int rightHeight = findHeightRecursive(current->right);

        return max(leftHeight, rightHeight) + 1;
    }

    Node* createMirrorImageRecursive(Node* current) {
        if (current == nullptr) {
            return nullptr;
        }

        Node* mirrorNode = new Node(current->data);
        mirrorNode->left = createMirrorImageRecursive(current->right);
        mirrorNode->right = createMirrorImageRecursive(current->left);

        return mirrorNode;
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

    int findHeight() {
        return findHeightRecursive(root);
    }

    BinarySearchTree createMirrorImage() {
        BinarySearchTree mirrorTree;
        mirrorTree.root = createMirrorImageRecursive(root);
        return mirrorTree;
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

    int height = tree.findHeight();
    cout << "Height of the tree: " << height << endl;

    BinarySearchTree mirrorTree = tree.createMirrorImage();
    cout << "Mirror Image of the tree - Inorder traversal: ";
    mirrorTree.inorderTraversal();

    return 0;
}
