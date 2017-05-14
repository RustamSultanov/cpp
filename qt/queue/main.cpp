#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct list0 {
        int data;
        list0 *next;
};

struct queue {
        list0 *head;
        list0 *tail;
};

void create_queue(queue *q) {
        q->head = NULL;
        q->tail = NULL;
};

void push(queue *q, int i) {

        list0 *node = (list0*)malloc(sizeof(list0));
        node->data = i;
        node->next = NULL;
        if (q->head == NULL && q->tail == NULL) {
                cout << "pushed first el " << i << endl;
                q->tail = node;
                q->head = node;
        }
        else {
                cout << "pushed new el " << i << endl;
                q->tail->next = node;
                q->tail = node;
        }
};

void pop(queue *q) {

        if (q->head == NULL) {
                cout << "empty queue";
                return;
        };
        //int data = q->head->data;
        // how to free space
        list0 *node = q->head;
        q->head = q->head->next;
        node->next = NULL;
        free(node);

        //return data;
};

void print_queue(queue *q) {
        list0 *node = q->head;

        while (node != NULL){
                cout << node->data << endl;
                node = node->next;
        };
}

void length_queue(queue *q) {
        list0 *node = q->head;
        int count = 0;
        while (node != NULL) {
                count++;
                node = node->next;
        }
        cout << "length = " << ++count << endl;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    queue *q;
    q = (queue*)malloc(sizeof(queue*));

    create_queue(q);
    push(q, 0);
    push(q, 1);
    push(q, 2);
    push(q, 3);
    print_queue(q);
    length_queue(q);

    pop(q);
    cout << "after pop" << endl;
    print_queue(q);
    length_queue(q);

    pop(q);
    pop(q);
    pop(q);
    pop(q);

    system("pause");

    return a.exec();
}
