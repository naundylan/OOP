#include <iostream>
using namespace std;

struct date {
	int day, month, year;
};

class canbo {
	protected:
		string macanbo, hoten, gioitinh;
	public:
		string getMaCanBo() {
			return macanbo;
		}
		string getHoTen() {
			return hoten;
		}
		string getGioiTinh() {
			return gioitinh;
		}
		void nhap() {
			cout<<"Nhap ma can bo: ";
			cin>>macanbo;
			cout<<"Nhap ho ten: ";
			cin>>hoten;
			cout<<"Nhap gioi tinh: ";
			cin>>gioitinh;
		}
		void xuat() {
			cout<<"Ma can bo: "<<macanbo<<", Ho Ten: "<<hoten<<", Gioi Tinh: "<<gioitinh<<endl;
		}
};

class congnhan : public canbo {
	private:
		int bac, songaylam;
		date ngaykyhopdong;
	public:
		int getBac() {
			return bac;
		}
		int getSoNgayLam() {
			return songaylam;
		}
		date getNgayKyHopDong() {
			return ngaykyhopdong;
		}
		void nhap() {
			cout<<"Nhap bac: ";
			cin>>bac;
			cout<<"Nhap so ngay lam: ";
			cin>>songaylam;
			cout<<"Nhap ngay ky hop dong: ";
			cin>>ngaykyhopdong.day;
			cout<<"Nhap thang ky hop dong: ";
			cin>>ngaykyhopdong.month;
			cout<<"Nhap nam ky hop dong: ";
			cin>>ngaykyhopdong.year;
		}
		int tienluong() {
			if(bac == 1)
				return 300000;
			else if(bac == 2)
				return 350000;
			else if(bac == 3)
				return 400000;
		}
		void xuat() {
			cout<<"Bac: "<<bac<<", So ngay lam: "<<songaylam<<", Tien luong: "<<tienluong()<<endl;
		}
		bool operator > (const congnhan& other) {
			if(ngaykyhopdong.year != other.ngaykyhopdong.year) {
				return ngaykyhopdong.year > other.ngaykyhopdong.year;
			}
			else if(ngaykyhopdong.month != other.ngaykyhopdong.month) {
				return ngaykyhopdong.month > other.ngaykyhopdong.month;
			}
			else {
				return ngaykyhopdong.day > other.ngaykyhopdong.day;
			}
		}
};

class quanly {
	private:
		congnhan ds[50];
		int soluong;
	public:
		quanly() {
			soluong = 0;
		}
		void sapxep() {
			for(int i = 0; i < soluong - 1; i++) {
				for(int j = 0; j < soluong - i - 1; j++) {
					if(ds[j] > ds[j + 1]) {
						congnhan tmp = ds[j];
						ds[j] = ds[j + 1];
						ds[j + 1] = tmp;
					}
				}
			}
		}
		void nhap() {
			cout<<"Nhap so luong cong nhan toi da: ";
			cin>>soluong;
			
			while(soluong <= 0 || soluong > 50) {
				cout<<"So luong khong hop le, Vui long nhap lai!";
				cin>>soluong;
			}
			
			for(int i = 0; i < soluong; i++) {
				cout<<"nhap can bo thu "<<i + 1<<":"<<endl;
				ds[i].canbo::nhap();
				ds[i].nhap();
			}
		}
		void xuat() {
			for(int i = 0; i < soluong; i++) {
				cout<<"Can bo thu "<<i + 1<<":"<<endl;
				ds[i].canbo::xuat();
				ds[i].xuat();
			}
		}
		void luongtb() {
			cout<<"Nhung can bo gioi tinh nu la: "<<endl;
			for(int i = 0; i < soluong; i++) {
				if(ds[i].getGioiTinh() == "nu") {
					ds[i].canbo::xuat();
					ds[i].xuat();
				}
			}
		}
};

int main() {
	quanly list;
	list.nhap();
	list.xuat();
	list.sapxep();
	list.xuat();
	list.luongtb();
	return 0;
}