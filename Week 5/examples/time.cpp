#include <iostream> 
using namespace std;

class time {
	private:
		int h, m, s;
	public:
		time() {
			h = 0; m = 0; s = 0;
		}
		time(int a, int b, int c) {
			h = a; m = b; s = c;
		}
		void chuanhoa();
		void giatang(int a, int b, int c);
		void dieuchinh(int a, int b, int c);
		void nhap();
		void xuat();
		time operator +(time b) {
			time result = *this;
			result += b;
			return result; 
		}
		time operator -(time b) {
			time result = *this;
			result -= b;
			return result;
		}
		int operator ==(time b);
		int operator !=(time b);
		time& operator +=(time b);
		time& operator -=(time b);
};

void time::chuanhoa() {
	int tong = h * 3600 + m * 60 + s;
	h = (tong / 3600) % 24;
	m = (tong / 60) % 60;
	s = tong % 60;
}

void time::giatang(int a, int b, int c) {
	h += a;
	m += b;
	s += c;
	chuanhoa();
}

void time::dieuchinh(int a, int b, int c) {
	h = a;
	m = b;
	s = c;
	chuanhoa();
}

void time::nhap() { 
	while(1) { 
		cout << "Nhap vao gio, phut va giay: ";
		cin>>h>>m>>s; 
		if (h >= 0 and m >=0 and s>=0)
			break; 
		cout << "Nhap sai! Hay nhap lai." << endl;
	} 
}

void time::xuat() { 
	cout<<h<<":"<<m<<":"<<s<<endl;
}

time& time::operator +=(time b) {
	int totalSecond = s + b.s;
	int totalMinute = m + b.m;
	int totalHour = h + b.h;
	s = totalSecond;
	m = totalMinute;
	h = totalHour;
	chuanhoa();
	return *this;
}

time& time::operator -=(time b) {
	int totalSecond = s - b.s;
	int totalMinute = m - b.m;
	int totalHour = h - b.h;
	s = totalSecond;
	m = totalMinute;
	h = totalHour;
	chuanhoa();
	return *this;
}

int time::operator ==(time b) {
	return h==b.h && m==b.m && s==b.s;
}

int time::operator !=(time b) {
	return !(*this==b);
}

int main() {
	
	return 0;
}