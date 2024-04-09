#include "treenode.h"
bool compare_int(const int& a, const int& b) {
    return a < b;
}

int main() {
    TreeNode<int> root(1);

    // Ad?ugare noduri
    root.add_node(2);
    root.add_node(3);
    root.add_node(4);

    // Afi?are num?r de copii ai r?d?cinii
    printf("Number of children of root: %zu\n", root.count());

    // Sortare noduri
    root.sort([](const int& a, const int& b) { return a < b; });

    // Afi?are valorile nodurilor sortate
    printf("Sorted values of children: ");
    const TreeNode<int>* current = root.get_node();
    while (current) {
        printf("%d ", current->get_value());
        current = current->get_next_sibling();
    }
    printf("\n");

    // C?utare nod cu valoarea 3
    TreeNode<int>* foundNode = root.find([](const int& val) { return val == 3; });
    if (foundNode) {
        printf("Node with value 3 found.\n");
    }
    else {
        printf("Node with value 3 not found.\n");
    }

    // ?tergere nod cu valoarea 4 ?i to?i descenden?ii s?i
    TreeNode<int>* nodeToDelete = root.find([](const int& val) { return val == 4; });
    if (nodeToDelete) {
        root.delete_node(nodeToDelete);
    }

    // Afi?are num?r de copii ai r?d?cinii dup? ?tergere
    printf("Number of children of root after deletion: %zu\n", root.count());

    return 0;
}

