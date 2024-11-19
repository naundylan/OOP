#include <iostream>
using namespace std;

#define MAX 50

class canbo {
	protected:
		string macanbo, madonvi, hoten, ngaysinh;
	public:
		void nhap();
		void xuat();
		string get_madonvi();
};

void canbo::nhap() {
	cout<<"Nhap ma can bo: ";
	getline(cin, macanbo);
	cout<<"Nhap ma don vi: ";
	getline(cin, madonvi);
	cout<<"Nhap ho ten: ";
	getline(cin, hoten);
	cout<<"Nhap ngay sinh can bo: ";
	getline(cin, ngaysinh);
}

void canbo::xuat() {
	cout<<"Ma can bo la: "<<macanbo<<" ";
	cout<<"Ma don vi can bo la: "<<madonvi<<" ";
	cout<<"Ho ten can bo: "<<hoten<<" ";
	cout<<"Ngay sinh can bo: "<<ngaysinh<<endl;
}

string canbo::get_madonvi() {
	return madonvi;
}

class luong : public canbo {
	protected:
		int phucap, hesoluong, baohiem;
	public:
		void nhapluong();
		int tinhluong();
		void xuatluong();
};

void luong::nhapluong() {
	nhap();
	cout<<"Nhap phu cap: ";
	cin>>phucap;
	cout<<"Nhap ho so luong: ";
	cin>>hesoluong;
	cout<<"Nhap bao hiem: ";
	cin>>baohiem;
}

void luong::xuatluong() {
	cout<<"luong can bo la: "<<tinhluong()<<endl;
}

int luong::tinhluong() {
	int luong;
	luong = hesoluong * 1350000 + phucap - baohiem;
	return luong;
}

class quanly {
	private:
		luong ds[MAX];
		int n;
	public:
		void nhap_ds();
		void xuat_ds();
};

void quanly::nhap_ds() {
	cout<<"Nhap so luong can bo: ";
	cin>>n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
		ds[i].nhapluong();
	}
}

void quanly::xuat_ds() {
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; i < n; i++) {
			if(ds[i].get_madonvi() < ds[j].get_madonvi()) {
				luong tmp = ds[i];
				ds[i] = ds[j];
				ds[j] = tmp;
			}
		}
	}
	
	cout<<"danh sach can bo:"<<endl;
	for(int i; i < n; i++) {
		if(i == 0 || ds[i].get_madonvi() != ds[i-1].get_madonvi())
			cout<<"Ma don vi: "<<ds[i].get_madonvi();
		else
			ds[i].xuatluong();
	}
}
int main() {
	quanly a;
	a.nhap_ds();
	a.xuat_ds();
	return 0;
}