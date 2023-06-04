#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return nullptr;
    }
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the binary search tree
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to perform in-order traversal of the tree (left, root, right)
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function to perform pre-order traversal of the tree (root, left, right)
void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform post-order traversal of the tree (left, right, root)
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Function to check whether two trees are equal
bool areTreesEqual(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return (areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right));
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Create a new tree for comparison
    Node* root2 = nullptr;
    cout << "Enter the values of the nodes for the second tree: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root2 = insertNode(root2, value);
    }

    if (areTreesEqual(root, root2)) {
        cout << "The two trees are equal." << endl;
    }
    else {
        cout << "The two trees are not equal." << endl;
    }

    return 0;
}
