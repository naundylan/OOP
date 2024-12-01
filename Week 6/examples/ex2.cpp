#include <iostream>
using namespace std;

class A {
	public:
		virtual void xuat() {
			cout <<"\n Lop A";
		}
};
class B : public A {
	public:
		void xuat() {
			cout <<"\n Lop B";
		}
};

int main() {
	A *p; //con tro cua lop cơ so
	A a;
	B b;
	p =&a; //p tro den doi tuong lop cha A
	p->xuat(); //goi hàm lop A, in ra Lop A
	p=&b; //p tro den doi tuong lop con B
	p->xuat(); //goi hàm lop B, in ra : Lop B vì xuat() la phuong thuc ao
	return 0;
}