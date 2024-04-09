#include <iostream>
#include <functional>

template <typename T>
class TreeNode {
private:
    T value;
    TreeNode<T>* parent;
    TreeNode<T>* firstChild;
  

public:
    TreeNode<T>* nextSibling;
    const TreeNode<T>* get_next_sibling() const {
        return nextSibling;
    }

    TreeNode(T val, TreeNode<T>* parentPtr = nullptr)
        : value(val), parent(parentPtr), firstChild(nullptr), nextSibling(nullptr) {}
    T get_value() const {
        return value;
    }

    void add_node(T val, TreeNode<T>* parentPtr = nullptr) {
        TreeNode<T>* newNode = new TreeNode<T>(val, parentPtr);
        if (!parentPtr) {
            if (!firstChild)
                firstChild = newNode;
            else {
                TreeNode<T>* temp = firstChild;
                while (temp->nextSibling)
                    temp = temp->nextSibling;
                temp->nextSibling = newNode;
            }
        }
        else {
            if (!parentPtr->firstChild)
                parentPtr->firstChild = newNode;
            else {
                TreeNode<T>* temp = parentPtr->firstChild;
                while (temp->nextSibling)
                    temp = temp->nextSibling;
                temp->nextSibling = newNode;
            }
        }
    }

    TreeNode<T>* get_node(TreeNode<T>* parentNode = nullptr) {
        if (!parentNode)
            return this;
        return parentNode;
    }

    void delete_node(TreeNode<T>* node) {
        if (!node) {
            return;
        }
        if (node->parent) {
            if (node->parent->firstChild == node) {
                node->parent->firstChild = node->nextSibling;
            }
            else {
                TreeNode<T>* current = node->parent->firstChild;
                while (current && current->nextSibling != node) {
                    current = current->nextSibling;
                }
                if (current) {
                    current->nextSibling = node->nextSibling;
                }
            }
        }
        delete node;
    }

    TreeNode<T>* find(bool (*compare)(const T&)) {
        if (compare(value)) {
            return this;
        }
        TreeNode<T>* found = nullptr;
        if (firstChild) {
            found = firstChild->find(compare);
        }
        if (!found && nextSibling) {
            found = nextSibling->find(compare);
        }
        return found;
    }


    void insert(TreeNode<T>* parentNode, T val, size_t index) {
        if (!parentNode) {
            return;
        }
        TreeNode<T>* newNode = new TreeNode<T>(val, parentNode);
        if (!parentNode->firstChild) {
            parentNode->firstChild = newNode;
            return;
        }
        TreeNode<T>* current = parentNode->firstChild;
        size_t i = 0;
        while (current->nextSibling && i < index) {
            current = current->nextSibling;
            ++i;
        }
        if (i == index) {
            newNode->nextSibling = current->nextSibling;
            current->nextSibling = newNode;
        }
        else {
            current->nextSibling = newNode;
        }
    }

    void sort(bool (*compare)(const T&, const T&) = nullptr) {
        if (!compare)
            return;
        if (firstChild) {
            TreeNode<T>* current = firstChild;
            while (current) {
                TreeNode<T>* minNode = current;
                TreeNode<T>* next = current->nextSibling;
                while (next) {
                    if (compare(next->value, minNode->value))
                        minNode = next;
                    next = next->nextSibling;
                }
                if (minNode != current) {
                    T temp = current->value;
                    current->value = minNode->value;
                    minNode->value = temp;
                }
                current = current->nextSibling;
            }
        }
    }


    size_t count(const TreeNode<T>* parentNode = nullptr) const {
        const TreeNode<T>* node = parentNode ? parentNode : this;
        size_t count = 0;
        const TreeNode<T>* current = node->firstChild;
        while (current) {
            ++count;
            current = current->nextSibling;
        }
        return count;
    }

};
 


