#include <iostream>
#include <vector>
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

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);

        return node;
    }

    void inorderRecursive(Node* node) {
        if (node == nullptr)
            return;

        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void preorderRecursive(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void postorderRecursive(Node* node) {
        if (node == nullptr)
            return;

        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }

    void inorderNonRecursive() {
        if (root == nullptr)
            return;

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
    }

    void preorderNonRecursive() {
        if (root == nullptr)
            return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";

            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
    }

    void postorderNonRecursive() {
        if (root == nullptr)
            return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            Node* current = s2.top();
            s2.pop();
            cout << current->data << " ";
        }
    }

    void constructFromInorderPreorder(vector<int>& inorder, vector<int>& preorder) {
        int n = inorder.size();
        root = constructHelper(inorder, preorder, 0, n - 1, 0, n - 1);
    }

    Node* constructHelper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd) {
        if (inStart > inEnd || preStart > preEnd)
            return nullptr;

        int rootValue = preorder[preStart];
        Node* root = new Node(rootValue);

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootValue) {
                inIndex = i;
                break;
            }
        }

        int leftSize = inIndex - inStart;

        root->left = constructHelper(inorder, preorder, inStart, inIndex - 1, preStart + 1, preStart + leftSize);
        root->right = constructHelper(inorder, preorder, inIndex + 1, inEnd, preStart + leftSize + 1, preEnd);

        return root;
    }
};

int main() {
    BST bst;

    // Insert nodes
    bst.insert(15);
    bst.insert(6);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);
    bst.insert(9);
    bst.insert(18);
    bst.insert(17);
    bst.insert(20);

    // Recursive traversals
    cout << "Inorder traversal (Recursive): ";
    bst.inorderRecursive(bst.root);
    cout << endl;

    cout << "Preorder traversal (Recursive): ";
    bst.preorderRecursive(bst.root);
    cout << endl;

    cout << "Postorder traversal (Recursive): ";
    bst.postorderRecursive(bst.root);
    cout << endl;

    // Non-recursive traversals
    cout << "Inorder traversal (Non-Recursive): ";
    bst.inorderNonRecursive();
    cout << endl;

    cout << "Preorder traversal (Non-Recursive): ";
    bst.preorderNonRecursive();
    cout << endl;

    cout << "Postorder traversal (Non-Recursive): ";
    bst.postorderNonRecursive();
    cout << endl;

    // Construct tree from given inorder and preorder traversals
    vector<int> inorder = { 2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20 };
    vector<int> preorder = { 15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20 };
    bst.constructFromInorderPreorder(inorder, preorder);

    cout << "Inorder traversal of constructed tree: ";
    bst.inorderRecursive(bst.root);
    cout << endl;

    return 0;
}
