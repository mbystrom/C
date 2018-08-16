#include <iostream>
#include "classdecl.class"
#include "list.class"

using namespace std;

int main ()
{
    Obj obj1 = Obj();
    Obj obj2 = Obj();

    obj1.setNum(3);
    obj2.setNum(4);

    cout << "obj1 num is " << obj1.getNum() << endl;
    cout << "obj2 num is " << obj2.getNum() << endl;

    List ls = List();
    ls.append(1);
    ls.append(2);
    ls.append(3);
    ls.append(4);
    ls.append(5);
    ls.append(6);
    ls.append(7);
    ls.append(8);
    ls.append(9);

    cout << "ls is " << ls.length() << " members long" << endl;
    cout << "ls[4] is " << ls.retrieve(4) << endl;

    cout << "popping last item! it is: " << ls.pop() << endl;
    cout << "popping third item! it is: " << ls.pop(2) << endl;

    cout << "deleting list!" << endl;
    ls.~List();
}