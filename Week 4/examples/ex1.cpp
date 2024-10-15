#include <iostream>
using namespace std;

class B;
class A {
	private:
		int n;
	public:
		void nhap();
		void xuat();
		friend void traodoi(A &ob1, B &ob2);
};

class B {
	private:
		int m;
	public:
		void nhap();
		void xuat();
		friend void traodoi(A &ob1, B &ob2);
};

void A::nhap() {
	cout<<"Nhap n = ";
	cin>>n;
}

void A::xuat() {
	cout<<"n = "<<n<<endl;
}

void B::nhap() {
	cout<<"Nhap m = ";
	cin>>m;
}

void B::xuat() {
	cout<<"m = "<<m<<endl;
}


void traodoi(A &x, B &y) {
	int tmp = x.n;
	x.n = y.m;
	y.m = tmp;
}

int main() {
	A ob1;
	B ob2;
	ob1.nhap();
	ob2.nhap();
	cout<< "Gia tri ban dau :" <<endl;
	ob1.xuat();
	ob2.xuat();
	
	cout<<"Gia tri sau khi trao doi :"<<endl;
	traodoi(ob1, ob2);
	ob1.xuat();
	ob2.xuat();
	return 0;
}