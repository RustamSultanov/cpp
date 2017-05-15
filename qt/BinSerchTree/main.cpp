#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int i, Node *prnt) {
        this->value = i;
        this->left = NULL;
        this->right = NULL;
        this->parent = prnt;
    }
    Node(int i){
//        Node(i, NULL);
        this->value = i;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

bool add_node (Node *tree, int value) {

    cout << "adding new node " << value << endl;

//    if (tree->left == NULL && tree->right == NULL) {
//        cout << "new root" << endl;
//        tree = new Node(value);
//        return true;
//    }

    Node *curent = tree;
    int i =0;

    while ( true ) {
//        cout << "in while " << i++ ;
        if(curent->value > value) {
//            cout << "to left" << endl;
            if (curent->left == NULL) {
//                Node *ptr = Node(value);
                curent->left = new Node(value, curent);
                break;
            }
            curent = curent->left;
        } else {
//            cout << "to right" << endl;
            if (curent->right == NULL) {
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
    if (n == NULL) {
        cout << endl;
        return;
    }
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

void print_tree (Node *n) {
    if (n == NULL) {
        cout << endl;
        return;
    }

    cout << "root: " << n->value << endl;

    if (n->left != NULL) {
        print_next(n->left, 1, true);
    }

    if (n->right != NULL){
        print_next(n->right, 1, false);
    }

}

int remove(Node *n, int k) {


    return 0;
}

void print_top_down(Node *node) {
    if (node == NULL) {
       return;
    }
    queue<Node *> q;
    q.push(node);

    while (!q.empty() ) {
        Node* temp = q.front();
        q.pop();
        cout << temp->value << " ";

        if ( temp->left != NULL )
            q.push(temp->left);

        if ( temp->right != NULL )
            q.push(temp->right);
   }
}

void branch_print(Node *node) {
    if (node == NULL) {
       return;
    }
    cout << node->value << " ";
    branch_print(node->left);
    branch_print(node->right);
}

void down_top_print(Node *node) {
    if (node == NULL) {
       return;
    }
    down_top_print(node->left);
    down_top_print(node->right);
    cout << node->value << " ";
}

int main(int argc, char *argv[]) {

    cout << "hello! its BST" << endl;

    Node *myTree = new Node(0);

    add_node(myTree, 1);
    add_node(myTree, 2);
//    cout << myTree->right->right->value << endl;
    add_node(myTree, 3);
    add_node(myTree, 4);
    add_node(myTree, -2);
    add_node(myTree, -1);
    add_node(myTree, -2);
    add_node(myTree, -2);
    add_node(myTree, -5);
    add_node(myTree, -8);

    print_tree(myTree);

    cout << endl << "print_top_down" << endl;
    print_top_down(myTree);
    cout << endl;

    cout << endl << "preorderPrint;" << endl;
    branch_print(myTree);
    cout << endl;

    cout << endl << "down_top_print" << endl;
    down_top_print(myTree);
    cout << endl;

//    delete_node(myTree, 4);

    delete myTree;

    return 0;
}

