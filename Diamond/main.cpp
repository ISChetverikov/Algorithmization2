#include <iostream>
#include <string>

using namespace std;

class A {
public:

	void virtual fun1(int m) { cout << "fun A" << endl; }
};
class B : public virtual A {
public:
	
	void fun()  { cout << "fun B" << endl; }
};
class C : public virtual A {
public:
	
	void fun()  { cout << "fun C" << endl; }
};
class D : public virtual B, public virtual C {
public:
	
	//void fun()  { cout << "fun D" << endl; }
};
void test() {
	A a; 	B b; 	C c; 	D d;
	a.fun1(5); b.fun(); c.fun(); d.fun1(4);
}

int main() {

	test();

	return 0;
}