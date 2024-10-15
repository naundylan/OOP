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
		friend phanso rutgon();
};

int gcd(int a, int b) {
	while(b!=0) {
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

void rutgon() {
	int ucln = gcd(t,m);
	t = t/ucln;
	m = m/ucln;
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

phanso tong(phanso p1, phanso p2) {
	phanso p;
	p.t = p1.t*p2.m + p2.t*p1.m;
	p.m = p1.m*p2.m;
	return p;
}

phanso tich(phanso p1, phanso p2) {
	phanso p;
	p.t = p1.t*p2.t;
	p.m = p1.m*p2.m;
	return p; 
}

int main() {
	
	return 0;
}