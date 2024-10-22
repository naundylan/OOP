#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class circle {
	private:	
		int x, y, r;
	public:
		circle *next;
		circle(int x = 0, int y = 0, int r = 0) {
			this->x = x;
			this->y = y;
			this->r = r;
			this->next = NULL;
		}
		void xuat();
		void nhap();
		int get_x() {
			return x;
		}
		int get_y() {
			return y;
		}
};

void circle::nhap() {
	cout<<"Nhap toa do x: ";
	cin>>x;
	cout<<"Nhap toa do y: ";
	cin>>y;
	cout<<"Nhap ban kinh r: ";
	cin>>r;
}

void circle::xuat() {
	cout<<"Toa do tam va ban kinh: "<<x<<" "<<y<<" "<<r<<endl;
}

class quanly {
	private:
		circle *first;
	public:
		quanly() {
			first = NULL;
		}
		void xuat();
		void bosung();
		void xuatx();
};

void quanly::bosung() {
	circle *p = new circle;
	p->nhap();
	p->next = first;
	first = p;
}

void quanly::xuat() {
	circle *p = first;
	while(p != NULL) {
		p->xuat();
		p = p->next;
	}
}

void quanly::xuatx() {
	circle *p = first;
	while(p != NULL) {
		if(p->get_y() == 0) {
			p->xuat();
		}
		p = p->next;
	}
}

int main() {
	quanly ds;
	char ch;
	do {
		ds.bosung();
		cout<<"Nhap esc de ket thuc!, nhap phim bat ki de tiep tuc:"<<endl;
		ch = getch();
	} while(ch != 27);
	cout<<"Cac hinh tron nam tren truc hoanh: "<<endl;
	ds.xuatx();
	return 0;
}