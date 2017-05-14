#include <iostream>

using namespace std;


struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int i) {
        this->value = i;
        left = NULL;
        right = NULL;
    }
};

struct BST {
    Node* root;
};

bool add_node (BST *tree, int value) {

    cout << "adding new node " << value << endl;

    if (tree->root == NULL) {
        cout << "new root" << endl;
        tree->root = new Node(value);
        return true;
    }

    Node *curent = tree->root;
    int i =0;

    while ( true ) {
        cout << "in while " << i++ ;
        if(curent->value > value) {
            cout << "to left" << endl;
            if (curent->left == NULL) {
//                Node *ptr = Node(value);
                curent->left = new Node(value);
                curent->left->parent = curent;
                break;
            }
            curent = curent->left;
        } else {
            cout << "to right" << endl;
            if (curent->right == NULL) {
//                Node ptr =
                curent->right = new Node(value);
                curent->right->parent = curent;
                break;
            }
            curent = curent->right;
        }
    }
//    curent->value = value;

    return false;
}

void print_next(Node *n, int deep, bool orient) {
    if (n == NULL)
        return;
    for (int i = 0; i < deep; ++i) cout << "    ";

    if (orient) {
        cout << "left: ";
    } else {
        cout << "right: ";
    }

    cout << n->value << endl;

    if (n->left != NULL) {
        print_next(n->left, 1 + deep, true);
    }
    if (n->right != NULL){
        print_next(n->right, 1 + deep, false);
    }
}

void print_next (Node *n) {
    if (n == NULL)
        return;

    cout << "root: " << n->value << endl;

    if (n->left != NULL) {
        print_next(n->left, 1, true);
    }
    if (n->right != NULL){
        print_next(n->right, 1, false);
    }

}

void print_tree (BST *tree) {
    cout << "printing" << endl;

    if (tree->root == NULL)
        return;
    Node *n = tree->root;

    cout << n->value << endl;

    print_next(n);

}

int remove(Node *n, int k) {


    return 0;
}

bool delete_node(BST *tree, int k) {
    Node *root = tree->root;

    if (k == tree->root) {

    }

    bool b = remove(root, k);

    return b;
}

int main(int argc, char *argv[]) {
    BST *myTree = new BST();

    cout << "hello! its BST" << endl;

    add_node(myTree, 0);
    add_node(myTree, 1);
    add_node(myTree, 2);
    add_node(myTree, 3);
    add_node(myTree, 4);
    add_node(myTree, -2);
    add_node(myTree, -1);

    print_tree(myTree);

    delete_node(myTree, 4);

    delete myTree;

    return 0;
}

