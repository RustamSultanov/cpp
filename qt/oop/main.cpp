#include <QCoreApplication>
#include "tmpclass.h"
#include <iostream>
#include <cstdlib>

#include <QDebug>

using namespace std;

// todo переопределить стандартные -+/*

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tmpClass *obj = new tmpClass(1, 3);

    qDebug() << "Hello World";
    cout << "Hello World!" << obj->get() << endl;
    system("PAUSE");
    return a.exec();
}
