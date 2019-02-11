#include <iostream>
#include <string>

using namespace std;

class A {
public:
	A() { cout << "A"; };
	A(const A &) { cout << "a"; };
	void virtual fun() { cout << "gun " << endl; }
	void virtual fun1(int m) { cout << "fun A" << endl; }
};
class B : public virtual A {
public:
	B() { cout << "B"; };
	B(const B &) { cout << "b"; };
	//void fun()  { cout << "fun B" << endl; }
};
class C : public virtual A {
public:
	C() { cout << "C"; };
	C(const C &) { cout << "c"; };
	//void fun()  { cout << "fun C" << endl; }
};
class D : B, C {
public:
	D() { cout << "D"; };
	D(const D &) { cout << "d"; };
	//void fun()  { cout << "fun D" << endl; }
};
void test() {
	//A a; 	B b; 	C c; 	D d;
	//a.fun1(5); b.fun(); c.fun(); d.::B::fun();
}

int main() {

	//test();
	D d1;
	D d2(d1);
	return 0;
}