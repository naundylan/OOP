#include <iostream>
using namespace std;

class A {
	public:
		void xuat() {
			cout<<"Lop A"<<endl;
		}
};

class B : public A {
	public:
		void xuat() {
			cout<<"Lop B"<<endl;
		}
};

int main() {
	B ob;
	ob.xuat(); // Lop B
	ob.A::xuat(); // Lop A
	return 0;
}