#pragma once
/// BARASCU BIANCA
#include <initializer_list>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class AVLTree {
protected:
    static_assert(is_arithmetic<T>::value, "AVLTree<T>: T must be a numeric type.");
    struct Node {
        T key;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;

    void rrotation(Node*& node);
    void lrotation(Node*& node);
    void rlrotation(Node*& node);
    void lrrotation(Node*& node);

    Node* insert(Node*& node, T key);
    Node* remove(Node*& node, T key);
    Node* minValueNode(Node* node);
    int height(Node* node);
    int getBalance(Node* node);
    void preorderTraversal(Node* node, vector<T>& result);
    void inorderTraversal(Node* node, vector<T>& result);
    void postorderTraversal(Node* node, vector<T>& result);
    bool has(Node* node, T key);
 
    void removeAll(Node* node);
    void balance(Node*& node);
    int max(int a, int b);
public:
    AVLTree();
    AVLTree(initializer_list<T> nodes);
    void push(T node);
    void remove(T node);
    void removeAll();
    bool empty();
    void balance();

    static AVLTree<T> _union( AVLTree<T>, AVLTree<T>);
    vector<T> preorder();
    vector<T> inorder();
    vector<T> postorder();
    static AVLTree<T> from(T arr[], int);
    bool has(T node);
 
    int getHeight();
    int getBalance();
    void add(initializer_list<T> items);

};
template<typename T>
void AVLTree<T>::add(initializer_list<T> items) {
    for (const T& item : items) {
        if (!has(item)) {
            push(item);
        }
    }
}
template<typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template<typename T>
AVLTree<T>::AVLTree(initializer_list<T> nodes) : root(nullptr) {
    for (const T& node : nodes) {
        push(node);
    }
}

template<typename T>
void AVLTree<T>::push(T node) {
    root = insert(root, node);
}

template<typename T>
void AVLTree<T>::remove(T node) {
    root = remove(root, node);
}

template<typename T>
void AVLTree<T>::removeAll() {
    removeAll(root);
    root = nullptr;
}

template<typename T>
bool AVLTree<T>::empty() {
    return root == nullptr;
}

template<typename T>
void AVLTree<T>::balance() {
    balance(root);
}
template<typename T>
vector<T> AVLTree<T>::inorder() {
    vector<T> result;
    inorderTraversal(root, result);
    return result;
}
template<typename T>
AVLTree<T> AVLTree<T>::_union(AVLTree<T> A, AVLTree<T> B) {
    AVLTree<T> result; 
    vector<T> inorderA = A.inorder();
    vector<T> inorderB = B.inorder();

    for (T node : inorderA) {
        result.push(node);
    }
    for (T node : inorderB) {
        result.push(node);
    }

    return result;
}
template<typename T>
vector<T> AVLTree<T>::preorder() {
    vector<T> result;
    preorderTraversal(root, result);
    return result;
}



template<typename T>
vector<T> AVLTree<T>::postorder() {
    vector<T> result;
    postorderTraversal(root, result);
    return result;
}

template<typename T>
AVLTree<T> AVLTree<T>::from(T arr[], int nr) {
    AVLTree<T> result;
   
    for (int i = 0; i < nr; ++i) {
        result.push(arr[i]);
    }

    return result;
}

template<typename T>
bool AVLTree<T>::has(T node) {
    return has(root, node);
}


template<typename T>
int AVLTree<T>::getHeight() {
    return height(root);
}

template<typename T>
int AVLTree<T>::getBalance() {
    return getBalance(root);
}

template<typename T>
void AVLTree<T>::rrotation(Node*& node) {
    if (node == nullptr || node->left == nullptr) {
        return;
    }

    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;

    node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;
}

template<typename T>
void AVLTree<T>::lrotation(Node*& node) {
    if (node == nullptr || node->right == nullptr) {
        return;
    }

    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;

    node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;
}
template<typename T>
void AVLTree<T>::rlrotation(Node*& node) {
    rrotation(node->right);
    lrotation(node);
}

template<typename T>
void AVLTree<T>::lrrotation(Node*& node) {
    lrotation(node->left);
    rrotation(node);
}
template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node*& node, T key) {
    if (node == nullptr) {
        Node* newNode = new Node{ key, nullptr, nullptr, 1 };
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    balance(node);

    return node;
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::remove(Node*& node, T key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }

            delete temp;
        }
        else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    if (node == nullptr) {
        return node;
    }

    balance(node);

    return node;
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template<typename T>
int AVLTree<T>::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

template<typename T>
int AVLTree<T>::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

template<typename T>
void AVLTree<T>::preorderTraversal(Node* node, vector<T>& result) {
    if (node != nullptr) {
        result.push_back(node->key);
        preorderTraversal(node->left, result);
        preorderTraversal(node->right, result);
    }
}

template<typename T>
void AVLTree<T>::inorderTraversal(Node* node, vector<T>& result) {
    if (node != nullptr) {
        inorderTraversal(node->left, result);
        result.push_back(node->key);
        inorderTraversal(node->right, result);
    }
}

template<typename T>
void AVLTree<T>::postorderTraversal(Node* node, vector<T>& result) {
    if (node != nullptr) {
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->key);
    }
}

template<typename T>
bool AVLTree<T>::has(Node* node, T key) {
    if (node == nullptr) {
        return false;
    }

    if (key < node->key) {
        return has(node->left, key);
    }
    else if (key > node->key) {
        return has(node->right, key);
    }
    else {
        return true;
    }
}



template<typename T>
void AVLTree<T>::removeAll(Node* node) {
    if (node == nullptr) {
        return;
    }

    removeAll(node->left);
    removeAll(node->right);
    delete node;
}

template<typename T>
void AVLTree<T>::balance(Node*& node) {
    if (node == nullptr) {
        return;
    }

    int balanceFactor = getBalance(node);

    if (balanceFactor > 1) {
        if (getBalance(node->left) >= 0) {
            rrotation(node);
        }
        else {
            lrrotation(node);
        }
    }
    else if (balanceFactor < -1) {
        if (getBalance(node->right) <= 0) {
            lrotation(node);
        }
        else {
            rlrotation(node);
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));
}

template<typename T>
int AVLTree<T>::max(int a, int b) {
    return (a > b) ? a : b;
}