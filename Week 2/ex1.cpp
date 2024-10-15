#include <iostream>
using namespace std;

class noithanh {
	private:
		string maso, hoten;
		int soxe, sotuyen, sokm, doanhthu;
	public:
		void nhap();
		void xuat();
		void nhapsoluong(int &n);
};

class ngoaithanh {
	private:
		string maso, hoten, noiden;
		int soxe, songay, doanhthu;
	public:
		void nhap();
		void xuat();
		void nhapsoluong(int &n);
};

void noithanh::nhap() {
	cin.ignore();
	getline(cin, maso);
	getline(cin, hoten);
	cin>>soxe;
	cin>>sotuyen;
	cin>>sokm;
}

void noithanh::xuat() {
	cout<<maso<<" "<<hoten<<" "<<soxe<<" "<<sotuyen<<" "<<sokm<<" "<<doanhthu<<endl;
}

void ngoaithanh::xuat() {
	cout<<maso<<" "<<hoten<<" "<<soxe<<" "<<noiden<<" "<<songay<<" "<<doanhthu<<endl;
}

void ngoaithanh::nhap() {
	cin.ignore();
	getline(cin, maso);
	getline(cin, hoten);
	cin>>soxe;
	cin.ignore();
	getline(cin, noiden);
	cin>>songay;
}

void noithanh::nhapsoluong(int &n) {
	cin>>n;
}

void ngoaithanh::nhapsoluong(int &n) {
	cin>>n;
}

int main() {
	int n, m;
	noithanh *noi = new noithanh[100];
	ngoaithanh *ngoai = new ngoaithanh[100];
	
	// nhap so luong
	noi->nhapsoluong(n);
	ngoai->nhapsoluong(m);
	
	//nhap mang
	for(int i=0; i<n; i++) {
		noi[i].nhap();
	}
	for(int i=0; i<m; i++) {
		ngoai[i].nhap();
	}
	
	// xuat mang
	for(int i=0; i<n; i++) {
		noi[i].xuat();
	}
	for(int i=0; i<m; i++) {
		ngoai[i].xuat();
	}
	return 0;
}