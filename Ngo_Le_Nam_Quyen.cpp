#include <iostream>
#include <algorithm>
using namespace std;

class date {
	public:
		int ngay, thang, nam;
		void nhap();
};

void date::nhap() {
	cin>>ngay>>thang>>nam;
}

class khachhang {
	private:
		string maso, hoten, diachi;
		int chiso;
		date ngaytinh;
	public:
		void nhap();
		void xuat();
		long sotien();
		string get_maso() {
			return maso;
		}
		int get_ngay() {
			return ngaytinh.ngay;
		}
		int get_thang() {
			return ngaytinh.thang;
		}
		int get_nam() {
			return ngaytinh.nam;
		}
};

void khachhang::nhap() {
	cin.ignore();
	cout<<"nhap ma so khach hang: ";
	getline(cin, maso);
	cout<<"nhap ho ten cua khach hang: ";
	getline(cin, hoten);
	cout<<"nhap dia chi cua khach hang: ";
	getline(cin, diachi);
	cout<<"so dien tieu thu trong thang: ";
	cin>>chiso;
	cout<<"ngay tinh tien: ";
	ngaytinh.nhap();
}

void khachhang::xuat() {
	cout<<"ma so cua khach hang: "<<maso<<endl;
	cout<<"ho ten cua khach hang: "<<hoten<<endl;
	cout<<"dia chi cua khach hang: "<<diachi<<endl;
	cout<<"so dien tieu thu trong thang: "<<chiso<<endl;
	cout<<"ngay tinh tien: "<<ngaytinh.ngay<<" "<<ngaytinh.thang<<" "<<ngaytinh.nam<<endl;
}

long khachhang::sotien() {
	long tongtien;
	if(chiso <= 50)
		tongtien=chiso*1893;
	else if(chiso <= 100)
		tongtien=50*1893 + (chiso-50)*1956;
	else if(chiso <= 200)
		tongtien=50*1893 + 50*1956 + (chiso-100)*2271;
	else if(chiso <= 300)
		tongtien=50*1893 + 50*1956 + 100*2271 + (chiso-200)*2860;
	else if(chiso <= 400)
		tongtien=50*1893 + 50*1956 + 100*2271 + 100*2860 + (chiso-300)*3197;
	else	
		tongtien=50*1893 + 50*1956 + 100*2271 + 100*2860 + 100*3197 + (chiso-400)*3302;
	return tongtien;
}

class quanly {
	private:
		khachhang list[1000];
		int n;
	public:
		void nhap();
		void hienthi();
		void sapxep();
		void xoa();
		bool kiemtra(string maso, int x);
		void set_n(int soluong) {
			this->n = soluong;
		}
};

bool quanly::kiemtra(string maso, int x) {
	for(int i=0; i<x; i++) {
		if(list[i].get_maso() == maso) {
			return true;
		}
	}
	return false;
}

void quanly::nhap() {
	cout<<"nhap so luong khach hang: ";
	cin>>n;
	for(int i=0; i<n; i++) {
		khachhang kh;
		kh.nhap();
		if(i!=0) {
			if(kiemtra(kh.get_maso(), i)) {
				cout<<"ma so da ton tai!"<<endl;
				i-=1;
				continue;
			}
		}
		list[i] = kh;
	}
}

void quanly::hienthi() {
	khachhang max=list[0];
	for(int i=1; i<n; i++) {
		if(max.sotien() < list[i].sotien())
			max=list[i];
	}
	max.xuat();
}

//void swap(khachhang &a, khachhang &b) {
//    khachhang temp = a;
//    a = b;
//    b = temp;
//}
//
//void quanly::sapxep() {
//	for(int i=0; i<n-1; i++) {
//		int max = i;
//		for(int j=i; j<n; j++) {
//			if(list[j].get_ngay() != list[max].get_ngay()) {
//				max = j;
//			}
//		}
//		swap(list[max], list[i]);
//	}
//}

void quanly::xoa() {
	int soluong = n;
    for (int i=soluong-1; i>=0; i--) {
        if (list[i].sotien() == 0) {
            for (int j=i; j<soluong-1; j++) {
                list[j] = list[j+1];
            }
            soluong--;
        }
    }
	set_n(soluong);
}

int main() {
	quanly a;
	a.nhap();
	a.hienthi();
	
	a.xoa();
	return 0;
}