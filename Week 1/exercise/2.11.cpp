#include <iostream>
#include <math.h>
using namespace std;

const int maxsize = 10;

void nhap(int &n) {
	do {
    	cin >> n;
	} while (n > maxsize);
}

void nhapvector(int v[], int n) {
	for(int i=0; i<n; i++) {
		cin>>v[i];
	}
}

void tich(int u[], int v[], int n, int &ketqua) {
	ketqua = 0;
	for(int i=0; i<n; i++) {
		ketqua += u[i]*v[i];
	}
}

void tich(int tu1, int mau1, int tu2, int mau2, int &kqtu, int &kqmau) {
	kqtu = tu1*tu2;
	kqmau = mau1*mau2;
}

void nhapphanso(int &tu, int &mau) {
	cin>>tu;
	cin>>mau;
}

void tich() {
	
}

int main() {
	// vector
	int a[maxsize], b[maxsize], ketqua;
	int n;
	nhap(n);
	
	// nhap vector
	nhapvector(a, n);
	nhapvector(b, n);
	tich(a, b, n, ketqua);
	cout<<ketqua<<endl;
	
	// phan so
	int tu1, mau1, tu2, mau2, kqtu, kqmau;
	nhapphanso(tu1, mau1);
	nhapphanso(tu2, mau2);
	tich(tu1, mau1, tu2, mau2, kqtu, kqmau);
	cout<<kqtu<<" "<<kqmau;
	return 0;
}