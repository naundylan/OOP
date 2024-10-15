#include<iostream>
using namespace std;

class date{
	private:
		int ngay, thang, nam;
	public:
		void nhap();
		void xuat();
		void tang_1_Ngay();
		void tang_n_Ngay();
		bool namnhuan();
		int ngaytrongthang(int m, int y);	
};

int date::ngaytrongthang(int m, int y) {
	int ngay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(m == 2 && namnhuan())
		return 29;
	return ngay[m - 1];
}

bool date::namnhuan() {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

void date::nhap() {
	do {
		cout<<"Nhap so ngay: ";
		cin>>ngay;
		cout<<"Nhap so thang: ";
		cin>>thang;
		cout<<"Nhap so nam: ";
		cin>>nam;
		
		if(thang < 1 && thang > 12)
			cout<<"Thang khong hop le, vui long nhap lai!"<<endl;
		if(ngay < 1 && ngay > ngaytrongthang(thang, nam))
			cout<<"Ngay khong hop le, vui long nhap lai!"<<endl;
	}
	while(thang < 1 || thang > 12 || ngay < 1 || ngay > ngaytrongthang(thang, nam));
}

void date::xuat() {
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

void date::tang_1_Ngay(){
	int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (namnhuan()) {
        ngayTrongThang[1] = 29;
	}
	ngay++;
    if (ngay > ngayTrongThang[thang - 1]) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

void date::tang_n_Ngay() {
	int n;
	cout<<"Nhap so ngay: ";
	cin>>n;
    
    for(int i=0; i<n; i++) {
    	tang_1_Ngay();
	}
}

int main() {
	date day;
	day.nhap();
	day.xuat();
	
	day.tang_1_Ngay();
	
	day.tang_n_Ngay();
	return 0;
}