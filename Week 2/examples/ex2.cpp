#include <iostream>
#include <iomanip> 
#include <algorithm>
using namespace std;
 
class Sinhvien { 
	private: 
		string masv, ht; 
		float dtb; 
	public: 
		void nhap();
		void xuat();
		float get_dtb();
		string get_masv();
};

string Sinhvien::get_masv() {
	return masv;
}

bool cmp(Sinhvien a, Sinhvien b) {
	return a.get_masv() < b.get_masv();
}

void Sinhvien::nhap() { 
	cout<<"\n Nhap ma sv :"; 
	getline(cin, masv); //co the dung ham gets de nhap chuoi cin.ignore(); 
	cout<<"\n Nhap ho ten sv :"; 
	getline(cin, ht); //co the dung ham gets de nhap chuoi cin.ignore(); 
	cout<<"\n Diem trung binh :";
	cin>>dtb;
	cin.ignore();
}

void Sinhvien::xuat() { 
	cout<<setw(10)<<masv<<" "<<setw(30)<<ht<<" "<<setw(5)<<dtb<<endl; 
}

float Sinhvien::get_dtb() {
	return dtb;
}

int main() {
	Sinhvien sv[50]; //khai bao mang doi tuong co toi da 50 sv
	int n; 
	//nhap dssv 
	cout<<"\n Nhap so sinh vien :"; 
	cin>>n; cin.ignore(); 
	for (int i=0; i<n; i++)
		sv[i].nhap(); 
	cout<<"\nDanh sach sinh vien \n"; 
	for (int i=0; i<n ; i++) 
		sv[i].xuat();
	float max;
	max = sv[0].get_dtb();
	for (int i=1;i<n;i++) 
		if (max < sv[i].get_dtb()) 
			max = sv[i].get_dtb();
	cout<<"\n Danh sach sinh vien co dtb cao nhat: \n";
	for (int i=0;i<n;i++)
		if (sv[i].get_dtb() == max) 
			sv[i].xuat();
			
	sort(sv, sv+n, cmp);
	cout<<"Danh sach sinh vien sau khi sap xep tang dan theo masv:"<<endl;
	for(int i=0; i<n; i++)
		sv[i].xuat();
	return 0;
}
