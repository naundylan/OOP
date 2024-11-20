#include <iostream>
using namespace std;

class A {
	protected: int x;
	public:
		void nhap_x() {
			cout<<"nhap x: ";
			cin>>x;
		}
};

class B: public A {
	protected: int y;
	public:
		void nhap_y() {
			cout<<"nhap y: ";
			cin>>y;
		}
};

class C: public B {
	protected: int z;
	public:
		void nhap_z() {
			cout<<"nhap z: ";
			cin>>z;
		}
		void multi() {
			cout<<"tich = "<<x * y * z<<endl;
		}
};

int main() {
	C a;
	a.nhap_x();
	a.nhap_y();
	a.nhap_z();
	a.multi();
	return 0;
}