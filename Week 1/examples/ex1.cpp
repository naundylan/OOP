//Viết lại Chương trình trên nhưng việc nhập giá trị cho biến n không thực hiện trong hàm main.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// cách 1: dùng & để truyền tham chiếu
// cách 2: dùng con trỏ và khi gọi hàm phải truyền địa chỉ
int n;

struct hocsinh {
	string hoten;
	float d1,d2,d3,td;
};

//hàm nhập
void nhap(hocsinh ts[], int &n) {
	cin >> n;
	for (int i=0;i<n;++i) {
		cin.ignore();
		cout << "\nThi sinh:"<<i+1;
		cout << "\nHo ten: ";
		getline(cin, ts[i].hoten);
		cout << "Diem cac mon thi :";
		cin>>ts[i].d1>>ts[i].d2>>ts[i].d3;
		ts[i].td=ts[i].d1+ts[i].d2+ts[i].d3;
	}
}

//hàm sắp xếp
void sapxep(hocsinh ts[], int n) {
	for (int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j)
			if(ts[i].td<ts[j].td) {
				hocsinh tam;
				tam = ts[i];
				ts[i]=ts[j];
				ts[j]=tam;
			}
}

// hàm in
void xuat(hocsinh ts[], int n) {
	cout<<"\n Danh sach sau khi sap xep : "<<endl;
	for (int i=0;i<n;++i)
		cout<<setw(30)<< ts[i].hoten <<setw(5)<<ts[i].td<<endl;
}


int main() {
	hocsinh ts[100];
	nhap(ts,n);
	sapxep(ts,n);
	xuat(ts,n);
	return 0;
}