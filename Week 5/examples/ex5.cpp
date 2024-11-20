#include <iostream>
using namespace std;

class nguoi {
	protected:
		string ma, hoten;
	public:
		void nhap() {
			cin.ignore();
			cout<<"nhap ma: ";
			getline(cin, ma);
			cout<<"nhap ho ten: ";
			getline(cin, hoten);
		}
		void xuat() {
			cout<<"ma la: "<<ma<<" ";
			cout<<"ho ten la: "<<hoten<<" ";
		}
};

class sinhvien: public nguoi {
	protected:
		float dtb;
	public:
		void nhap_sv() {
			cout<<"nhap diem trung binh: ";
			cin>>dtb;
		}
		void xuat_sv() {
			cout<<"diem trung binh la: "<<dtb<<endl;
		}
		bool khenthuong() {
			return dtb > 8;
		}
};

class giaovien: public nguoi {
	protected:
		float sbb;
	public:
		void nhap_gv() {
			cout<<"nhap so bai bao: ";
			cin>>sbb;
		}
		void xuat_gv() {
			cout<<"so bai bao la: "<<sbb<<endl;
		}
		bool khenthuong() {
			return sbb >= 1;
		}
};

class quanly {
	private:
		sinhvien a[100];
		giaovien b[50];
		int n;
		int m;
	public:
		void nhap_ds() {
			cout<<"nhap so luong sinh vien: ";
			cin>>n;
			cout<<"nhap so luong giao vien: ";
			cin>>m;
			cout<<endl<<"nhap danh sach sinh vien: "<<endl<<endl;
			// nhap danh sach sinh vien
			for(int i = 0; i < n; i++) {
				a[i].nhap();
				a[i].nhap_sv();
			}
			cout<<endl<<"nhap danh sach giao vien: "<<endl<<endl;
			// nhap danh sach giao vien
			for(int i = 0; i < m; i++) {
				b[i].nhap();
				b[i].nhap_gv();
			}
		}
		void xuat_ds() {
			cout<<endl<<"danh sach sinh vien la: "<<endl<<endl;
			// xuat danh sach sinh vien
			for(int i = 0; i < n; i++) {
				a[i].xuat();
				a[i].xuat_sv();
			}
			cout<<endl<<"danh sach giao vien la: "<<endl<<endl;
			// xuat danh sach giao vien
			for(int i = 0; i < m; i++) {
				b[i].xuat();
				b[i].xuat_gv();
			}
		}
		void dskhenthuong() {
			cout<<endl<<"danh sach khen thuong sinh vien la: "<<endl<<endl;
			// danh sach khen thuong sinh vien
			for(int i = 0; i < n; i++) {
				if(a[i].khenthuong()) {
					a[i].xuat();
					a[i].xuat_sv();
				}
			}
			cout<<endl<<"danh sach khen thuong giao vien la: "<<endl<<endl;
			// danh sach khen thuong giao vien
			for(int i = 0; i < m; i++) {
				if(b[i].khenthuong()) {
					b[i].xuat();
					b[i].xuat_gv();	
				}
			}
		}
};

int main() {
	quanly a;
	a.nhap_ds();
	a.xuat_ds();
	a.dskhenthuong();
	return 0;
}