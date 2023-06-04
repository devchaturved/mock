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

    Node* insertNodeRecursive(Node* current, Node* prev, int value) {
        if (current == nullptr) {
            Node* newNode = new Node(value);
            if (prev == nullptr) {
                newNode->isThreaded = true;
                newNode->right = nullptr;
            }
            return newNode;
        }

        if (value < current->data) {
            current->left = insertNodeRecursive(current->left, current, value);
        } else {
            if (current->isThreaded) {
                Node* newNode = new Node(value);
                newNode->right = current->right;
                newNode->isThreaded = true;
                current->right = newNode;
                current->isThreaded = false;
            } else {
                current->right = insertNodeRecursive(current->right, prev, value);
            }
        }

        return current;
    }

    void inorderTraversal(Node* current) {
        if (current == nullptr)
            return;

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
                if (temp == nullptr)
                    break;
                while (temp->left != nullptr && !temp->isThreaded) {
                    temp = temp->left;
                }
            }
        }
    }

public:
    ThreadedBinarySearchTree() {
        root = nullptr;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, nullptr, value);
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

    cout << "Inorder traversal of the threaded binary tree: ";
    tree.inorderTraversal();

    return 0;
}
