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
		int get_t();
		void set_t(int t);
		int get_m();
		void set_m(int m);
};

int phanso::get_t() {
	return t;
}

void phanso::set_t(int t) {
	this->t = t;
}

int phanso::get_m() {
	return m;
}

void phanso::set_m(int m) {
	this->m = m;
}

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

phanso phanso::cong(phanso p2) {
	phanso p;
	p.set_t(this->get_t() + p2.get_t());
	if(this->get_m() == p2.get_m())
		p.set_m(p2.get_m());
	return p;
}

phanso phanso::tich(phanso p2) {
	phanso p;
	p.set_t(this->get_t() * p2.get_t());
	p.set_m(this->get_m() * p2.get_m());
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