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
		int get_doanhthu();
};

class ngoaithanh {
	private:
		string maso, hoten, noiden;
		int soxe, songay, doanhthu;
	public:
		void nhap();
		void xuat();
		void nhapsoluong(int &n);
		int get_doanhthu();
};

int noithanh::get_doanhthu() {
	return doanhthu;
}

int ngoaithanh::get_doanhthu() {
	return doanhthu;
}

int tien(noithanh noi[], int n) {
	int tong = 0;
	for(int i=0; i<n; i++) {
		tong+=noi[i].get_doanhthu();
	}
	return tong;
}

int tien(ngoaithanh ngoai[], int n) {
	int tong = 0;
	for(int i=0; i<n; i++) {
		tong+=ngoai[i].get_doanhthu();
	}
	return tong;
}

void noithanh::nhap() {
	cin.ignore();
	cout<<"Nhap ma so: ";
	getline(cin, maso);
	cout<<"Nhap ho ten: ";
	getline(cin, hoten);
	cout<<"Nhap so xe: ";
	cin>>soxe;
	cout<<"Nhap so tuyen: ";
	cin>>sotuyen;
	cout<<"Nhap so km: ";
	cin>>sokm;
	cout<<"Nhap doanh thu: ";
	cin>>doanhthu;
}

void noithanh::xuat() {
	cout<<maso<<" "<<hoten<<" "<<soxe<<" "<<sotuyen<<" "<<sokm<<" "<<doanhthu<<endl;
}

void ngoaithanh::xuat() {
	cout<<maso<<" "<<hoten<<" "<<soxe<<" "<<noiden<<" "<<songay<<" "<<doanhthu<<endl;
}

void ngoaithanh::nhap() {
	cin.ignore();
	cout<<"Nhap ma so: ";
	getline(cin, maso);
	cout<<"Nhap ho ten: ";
	getline(cin, hoten);
	cout<<"Nhap so xe: ";
	cin>>soxe;
	cin.ignore();
	cout<<"Nhap noi den: ";
	getline(cin, noiden);
	cout<<"Nhap so ngay: ";
	cin>>songay;
	cout<<"Nhap doanh thu: ";
	cin>>doanhthu;
}

void noithanh::nhapsoluong(int &n) {
	cout<<"Nhap n: ";
	cin>>n;
}

void ngoaithanh::nhapsoluong(int &n) {
	cout<<"Nhap m: ";
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
	
	cout<<tien(noi, n)<<endl;
	cout<<tien(ngoai, m);
	return 0;
}