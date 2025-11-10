#include <iostream>
using namespace std;

class BaseClass {
public:

    BaseClass(int val) : value(val) {}
    virtual ~BaseClass() = default;
    virtual int getValue() const {
        return value;
    }
    virtual void print() const {
        cout << "Base total: " << getValue() << endl;
    }

protected:
    int value;
};

class DerivedClass : public BaseClass {
public:

    DerivedClass(int v, int e) : BaseClass(v), extraValue(e) {}
    int getValue() const override {
        return value + extraValue;
    }
    void print() const override {
        cout << "Derived total: " << getValue() << endl;
    }
public:
    int extraValue;
};

int main() {
    BaseClass obj1(10);
    DerivedClass obj2(10, 5);

    obj1.print();  // Base total: 10
    obj2.print();  // Derived total: 15

    BaseClass* obj3 = new BaseClass(10);
    BaseClass* obj4 = new DerivedClass(10, 5);

    obj3->print();  // Base total: 10
    obj4->print();  // Derived total: 15

    delete obj3;
    delete obj4;

    return 0;
}
