#include <iostream>
#include <vector>

using namespace std;

class Base {
private:
    int num;
public:
    Base() {}
    void setNum (int n) { num = n; }
    int getNum () { return num; }
    int pNum;

    virtual void printType () {
        cout << "BASE CLASS!" << endl;
    }

    // required for the derived method to work
    // it makes me sad that it's neccessary
    virtual void derivedOnlyMethod() {}
};

class Derived : public Base {
public:
    Derived () : Base() {}
    virtual void printType () {
        cout << "DERIVED CLASS!" << endl;
    }

    virtual void derivedOnlyMethod () {
        cout << "this method is only on the derived class!" << endl;
    }
};

int main () {
    vector<Base*> vec;
    Base* base = new Base();
    Derived* der = new Derived();
    vec.push_back(base);
    vec.push_back(der);

    vec[0]->printType();
    vec[1]->printType();
    vec[1]->derivedOnlyMethod();

    delete base;
    delete der;
    
    for (int i = 0; i < vec.size(); i++) {
        delete vec[i];
    }
}
