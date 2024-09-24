#include <iostream>
#include <iomanip> 
#include <algorithm>
using namespace std;
 
class sach { 
	private: 
		string masach, tensach, tacgia, nhaxb;
		int soluong;	
	public:
		void nhap();
		void xuat();
		string get_masach();
};

string sach::get_masach() {
	return masach;
}

bool cmp(sach a, sach b) {
	return a.get_masach() < b.get_masach();
}

void sach::nhap() { 
	cout<<"Nhap ma sach :"; 
	getline(cin, masach);
	cout<<"Nhap ten sach :"; 
	getline(cin, tensach);
	cout<<"Nhap ten tac gia :"; 
	getline(cin, tacgia);
	cout<<"Nhap nha xuat ban :"; 
	getline(cin, nhaxb); 
	cout<<"Nhap so luong :";
	cin>>soluong;
	cin.ignore();
}

void sach::xuat() { 
	cout<<setw(10)<<masach<<" "<<setw(30)<<tensach<<setw(15)<<tacgia<<setw(15)<<nhaxb<<" "<<setw(5)<<soluong<<endl;
}

int main() {
	sach s[50]; //khai bao mang doi tuong co toi da 50 sv
	int n; 
	//nhap dssv 
	cout<<"Nhap so sach : "; 
	cin>>n; cin.ignore(); 
	for (int i=0; i<n; i++)
		s[i].nhap(); 
	cout<<"Danh sach sach:"<<endl; 
	for (int i=0; i<n ; i++) 
		s[i].xuat();
	
	// sap xep theo ma sach		
	sort(s, s + n, cmp);
	cout<<"Danh sach sach sau khi sap xep tang dan theo masach:"<<endl;
	for(int i=0; i<n; i++)
		s[i].xuat();
	return 0;
}
