#include <iostream>
#include "classdecl.class"

using namespace std;

int main ()
{
    Obj obj1 = Obj();
    Obj obj2 = Obj();

    obj1.setNum(3);
    obj2.setNum(4);

    cout << "obj1 num is " << obj1.getNum() << endl;
    cout << "obj2 num is " << obj2.getNum() << endl;

}