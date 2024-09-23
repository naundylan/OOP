#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class sinhvien {
	private:
		string ten, ns;
		float gpa;
	public:
		void xinchao() {
			cout<<"hello"<<endl;
		}
		// constructor
		sinhvien() {
			cout<<"Ham tao lop sinh vien"<<endl;
		}
		sinhvien(string ten, string ns, float gpa) {
			this->ten = ten;
			this->ns = ns;
			this->gpa = gpa;
		}
		// ham huy
		~sinhvien() {
			cout<<"Ham huy sinh vien khi ket thuc ham main"<<endl;
		}
		// lay thuoc tinh trong private
		void setTen(string ten) {
			this->ten = ten;
		}
		string getTen() {
			return this->ten;
		}
		// khai bao mot ham ngoai lop nhung van thuoc lop do
		void nhap();
};

// khai bao ham ngoai
void sinhvien::nhap() {
	getline(cin, ten);
	getline(cin, ns);
	cin>>gpa;
}

int main() {
	sinhvien a;
//	a.ten = "Tao"; a.ten la thuoc tinh private nen khong the truy cap
	a.xinchao();
	sinhvien s;
	sinhvien t("teo", "18122005", 10);
	cout<<t.getTen()<<endl;
	t.setTen("quyen");
	cout<<t.getTen()<<endl;
	
	//nhap
	sinhvien n;
	n.nhap();
	return 0;
}