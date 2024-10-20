#include <iostream>
using namespace std;

class phanso {
	private:
		int t,m;
	public:
		void nhap();
		void xuat();
		friend phanso tong(phanso p1, phanso p2);
		friend phanso tich(phanso p1, phanso p2);
		friend void rutgon(phanso &p);
		friend phanso congk(int k, phanso p1);
		phanso congk(int k);
};


int gcd(int a, int b) {
	while(b!=0) {
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

void rutgon(phanso &p) {
	int ucln = gcd(p.t,p.m);
	p.t /= ucln;
	p.m /= ucln;
}

void phanso::nhap() {
	cout<<"Nhap tu so: ";
	cin>>t;
	do {
		cout<<"Nhap mau so: ";
		cin>>m;
	} while(m==0);
}

void phanso::xuat() {
	cout<<t<<" "<<m<<endl;
}

phanso phanso::congk(int k) {
	phanso p;
	p.t = t + k*m;
	p.m = m;
	rutgon(p);
	return p;
}

phanso tong(phanso p1, phanso p2) {
	phanso p;
	if(p1.m != p2.m) {
		p.t = p1.t*p2.m + p2.t*p1.m;
		p.m = p1.m*p2.m;
	}
	else {
		p.t = p1.t+ p2.t;
		p.m = p1.m;
	}
	rutgon(p);
	return p;
}

phanso tich(phanso p1, phanso p2) {
	phanso p;
	p.t = p1.t*p2.t;
	p.m = p1.m*p2.m;
	rutgon(p);
	return p; 
}

phanso congk(int k, phanso p1) {
	phanso p;
	p.t = k*p1.m + p1.t;
	p.m = p1.m;
	rutgon(p);
	return p;
}

int main() {
	phanso p1, p2, p3, p4, p5, p6;
	p1.nhap();
	p2.nhap();
	
	p1.xuat();
	p2.xuat();
	
	p3=tong(p1, p2);
	p4=tich(p1, p2);
	
	p3.xuat();
	p4.xuat();
	
	int k;
	cout<<"Nhap k: ";
	cin>>k;
	p5 = congk(k, p3);
	p5.xuat();
	
	p6 = p4.congk(k);
	p6.xuat();
	return 0;
}