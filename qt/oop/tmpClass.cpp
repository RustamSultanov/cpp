#include "tmpclass.h"

tmpClass::tmpClass(int a, int b)
{
    this->a = a;
    this->b = b;
}
tmpClass::tmpClass()
{

}
int tmpClass::tmpClass::get()
{
//    if ( a == nullptr || b == nullptr) {
//        a = 0;
//        b = 0;
//    }
    return a*b;
}
