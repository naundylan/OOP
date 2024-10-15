#include <iostream>
using namespace std;

class phanso {
	private:
		int t, m;
	public:
		void nhap();
		void xuat();
		phanso cong(phanso p2);
		phanso tich(phanso p2);
		void rutgon();
};


void phanso::nhap() {
	cout<<"Nhap phan tu: ";
	cin>>t;
	do {
		cout<<"Nhap phan mau khac 0: ";
		cin>>m;
	} while(m == 0);
}

void phanso::xuat() {
	cout<<"Phan so: "<<t<<" "<<m<<endl;
}

int gcd(int a, int b) {
	while(b!=0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void phanso::rutgon() {
	int ucln = gcd(t, m);
	t /= ucln;
	m /= ucln;
}

phanso phanso::cong(phanso p2) {
	phanso p;
	p.t = t*p2.m + m*p2.t;
	p.m = m * p.m;
	p.rutgon();
	return p;
}

phanso phanso::tich(phanso p2) {
	phanso p;
	p.t = t * p2.t;
	p.m = m * p2.m;
	p.rutgon();
	return p;
}

int main() {
	phanso a, b;
	a.nhap();
	b.nhap();
	
	a.xuat();
	b.xuat();
	
	phanso tich, tong;
	tich = a.tich(b);
	tong = a.cong(b);
	
	tich.xuat();
	tong.xuat();
	return 0;
}