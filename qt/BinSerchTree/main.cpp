#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct Node {
    int* value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int i, Node *prnt = nullptr) {
        value = new int(i);
        left = nullptr;
        right = nullptr;
        parent = prnt;
    }
    Node() {
        value = nullptr;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

bool add_node (Node *tree, int value) {
//    cout << "adding new node " << value << endl;
    Node *curent = tree;
    if (curent->value == nullptr) {
        curent->value = new int(value);
        return true;
    }
    while ( true ) {
        if(*curent->value > value) {
            if (curent->left == nullptr) {
                curent->left = new Node(value, curent);
                break;
            }
            curent = curent->left;
        } else {
            if (curent->right == nullptr) {
                curent->right = new Node(value, curent);
                break;
            }
            curent = curent->right;
        }
    }
    tree = curent;
    return false;
}

void print_next(Node *n, int deep, bool orient) {
    if (n == nullptr || n->value == nullptr) {
        cout << endl;
        return;
    }
    for (int i = 0; i < deep; ++i) cout << "    ";

    if (orient) {
        cout << "left: ";
    } else {
        cout << "right: ";
    }
    cout << *n->value << endl;

    if (n->right != nullptr){
        print_next(n->right, 1 + deep, false);
    }

    if (n->left != nullptr) {
        print_next(n->left, 1 + deep, true);
    }
}

void print_tree (Node *n) {
    if (n == nullptr || n->value == nullptr) {
        cout << "empty!!" << endl;
        return;
    }

    cout << "root: " << *n->value << endl;

    if (n->right != nullptr){
        print_next(n->right, 1, false);
    }

    if (n->left != nullptr) {
        print_next(n->left, 1, true);
    }
}

void direct_print(Node *node) {
    if (node == nullptr || node->value == nullptr) {
       return;
    }
    cout << *node->value << " ";
    direct_print(node->left);
    direct_print(node->right);
}

void postfix_print(Node *node) {
    if (node == nullptr || node->value == nullptr) {
       return;
    }
    postfix_print(node->left);
    cout << *node->value << " ";
    postfix_print(node->right);
}

void down_top_print(Node *node) {
    if (node == nullptr || node->value == nullptr) {
       return;
    }
    down_top_print(node->left);
    down_top_print(node->right);
    cout << *node->value << " ";
}

Node* find_node (Node *root, int k) {
    if (root == nullptr)
        return nullptr;
    if (*root->value == k)
        return root;

    if (root->left == nullptr && root->right == nullptr) 
        return nullptr;
    
    Node *found = nullptr;
//    new(found) Node;
    found = find_node(root->left, k);
    if (found == nullptr) found = find_node(root->right, k);

    return found;
}

Node* find_next (Node *root) {
    Node *current = root->right;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

bool clean_parent(Node *node, Node *child) {
    if(node->parent != nullptr) {
        if (*node->parent->value <= *node->value) {
            node->parent->right = child;
        } else {
            node->parent->right = child;
        }
        return true;
    } else {

        return true;
    }
    return false;
}

bool remove_node(Node *kik) {
    if (kik == nullptr) return false;

    // leave element
    if (kik->left == nullptr && kik->right == nullptr) {
        clean_parent(kik, nullptr);
        if (kik->parent == nullptr) {
            kik->value = nullptr;
            return true;
        }
        if (kik !=nullptr && kik->value != nullptr)
            delete(kik);
        return true;
    }
    
    // 2 childres
    if (kik->left != nullptr && kik->right != nullptr) {

        Node *next = find_next(kik);
        kik->value = new int(*next->value);

        if (!remove_node(next))
            return false;

        return true;
    }

    // one child
    if (kik->left != nullptr || kik->right != nullptr) {
        if (kik->left != nullptr) {
            clean_parent(kik, kik->left);
            delete(kik);
        } else {
            if (!clean_parent(kik, kik->right))
                return false;
            delete(kik);
        }
        return true;
    }

    return false;
}

bool remove_node(Node *n, int k) {
    Node *kik = find_node(n, k);
    if (kik == nullptr)
        return false;

    return remove_node(kik);;
}

int main(int argc, char *argv[]) {

    cout << "hello! its BST" << endl;

    Node *myTree = new Node();

    add_node(myTree, 3);
//    add_node(myTree, 1);
//    add_node(myTree, 6);
//    add_node(myTree, 0);
//    add_node(myTree, 4);
//    add_node(myTree, 7);
//    add_node(myTree, 10);
//    add_node(myTree, 14);
//    add_node(myTree, 13);
//    add_node(myTree, -2);
//    add_node(myTree, -5);
//    add_node(myTree, -8);

    print_tree(myTree);

//    cout << "deleting 8" << endl;
//    cout << "delete ok? -> " << remove_node(myTree, 8) << endl;

    cout << "deleting 3" << endl << endl << "______________" << endl;
    cout << "delete ok? -> " << remove_node(myTree, 3) << endl;

    print_tree(myTree);

    add_node(myTree, -8);
    print_tree(myTree);
    cout << "deleting -8" << endl << endl << "______________" << endl;
    cout << "delete ok? -> " << remove_node(myTree, -8) << endl;


    print_tree(myTree);


//    cout << "deleting" << endl << endl << "______________";;
//    cout << "delete ok? -> " << remove_node(myTree, 0) << endl << endl << "****" << endl;

//    print_tree(myTree);

//    cout << "deleting" << endl << endl << "______________";
//    cout << "delete ok? -> " << remove_node(myTree, -2) << endl;

//    print_tree(myTree);

//    cout << endl << endl << endl << "______________";

    cout << endl << "print_top_down" << endl << endl << "______________";
    direct_print(myTree);
    cout << endl;

    cout << endl << "branch_print;" << endl << endl << "______________";
    postfix_print(myTree);
    cout << endl;

    cout << endl << "down_top_print" << endl << endl << "______________";
    down_top_print(myTree);
    cout << endl;

//    delete_node(myTree, 4);

    if (myTree !=nullptr && myTree->value != nullptr)
        delete myTree;

    return 0;
}
