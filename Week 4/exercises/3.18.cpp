#include <iostream>
#include <string>
using namespace std;

class nhanvien {
	private:
		string manv;
		string hoten;
		int sdt;
	public:
		nhanvien *next;
		nhanvien() {}
		nhanvien(string id, string hoten, int sdt) {
			this->manv = id;
			this->hoten = hoten;
			this->sdt = sdt;
		}
		~nhanvien(){}
		string get_manv() {
			return manv;
		}
		string get_hoten() {
			return hoten;
		}
		int get_sdt() {
			return sdt;
		}
		void set_manv(string manv) {
			this->manv = manv;
		}
		void set_hoten(string hoten) {
			this->hoten = hoten;
		}
		void set_sdt(int sdt) {
			this->sdt = sdt;
		}
		void set(string manv, string hoten, int sdt) {
			this->manv = manv;
			this->hoten = hoten;
			this->sdt = sdt;
		}
		void xuat() {
			cout<<manv<<" "<<hoten<<" "<<sdt<<endl;
		}
};

class quanly {
	private:
		nhanvien *first;
	public:
		quanly() {
			first = NULL;
		}
		void nhap();
		void sapxepthuan();
		nhanvien* timkiem(string manv);
		void xuat();
};

void quanly::nhap() {
	string manv, hoten;
	int sdt;
	do {
		cout<<"Nhap ma nhan vien: ";
		getline(cin, manv);
		cout<<manv<<endl;
		if(manv.length() != 0) {
			cout<<"Nhap ho ten nhan vien: ";
			getline(cin, hoten);
			cout<<hoten<<endl;
			cout<<"Nhap sdt nhan vien: ";
			cin>>sdt;
			cout<<sdt<<endl;
			cin.ignore();
			nhanvien *p = new nhanvien(manv, hoten, sdt);
			p->next = first;
			first = p;
		}
	} while(manv.length() != 0);
}

void quanly::xuat() {
	nhanvien *p = first;
	while(p != NULL) {
		cout<<"Nhan vien:"<<endl;
		p->xuat();
		p = p->next;
	}
}

void quanly::sapxepthuan() {
	nhanvien *p, *q;
	string tmp_manv, tmp_hoten;
	int tmp_sdt;
	if(first != NULL) {
		for(p = first; p->next != NULL; p = p->next) {
			for(q = p->next; q != NULL; q = q->next) {
				if(p->get_hoten() > q->get_hoten()) {
					tmp_manv = p->get_manv();
					tmp_hoten = p->get_hoten();
					tmp_sdt = p->get_sdt();
					p->set(q->get_manv(), q->get_hoten(), q->get_sdt());
					q->set(tmp_manv, tmp_hoten, tmp_sdt);
				}
			}
		}
	}
}

nhanvien* quanly::timkiem(string manv) {
	nhanvien *p = first;
	while(p != NULL && p->get_manv() != manv)
		p = p->next;
	return p;
}

int main() {
	quanly ds;
	ds.nhap();
	cout<<"Danh sach nhan vien:"<<endl;
	ds.xuat();
	ds.sapxepthuan();
	cout<<"Danh sach nhan vien sau khi sap xep la:"<<endl;
	ds.xuat();
	string manv;
	cout<<"Nhap ma nhan vien can tim: ";
	getline(cin, manv);
	nhanvien *p = ds.timkiem(manv);
	if(p != NULL) {
		cout<<"Tim thay nhan vien can tim:"<<endl;
		cout<<p->get_manv()<<endl;
		cout<<p->get_hoten()<<endl;
		cout<<p->get_sdt();
	}
	else
		cout<<"Khong tim thay nhan vien can tim";
	return 0;
}