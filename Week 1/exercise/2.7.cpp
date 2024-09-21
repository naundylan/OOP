#include <iostream>
#include <string>

using namespace std;

struct sinhvien {
    string masv;
    string hoten;
    string lop;
    float dtb;
};

void nhap(sinhvien ds[], int n) {
	for(int i=0; i<n; i++) {
        cout << "Ma sinh vien: ";
        cin >> ds[i].masv;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, ds[i].hoten);
        cout << "Lop: ";
        cin >> ds[i].lop;
        cout << "Diem trung binh: ";
        cin >> ds[i].dtb;
	}
}

void swap(sinhvien &a, sinhvien &b) {
    sinhvien temp = a;
    a = b;
    b = temp;
}

void sapxep(sinhvien ds[], int n) {
	for(int i=0; i<n-1; i++) {
		int max = i;
		for(int j=i; j<n; j++) {
			if(ds[j].dtb > ds[max].dtb) {
				max = j;
			}
		}
		swap(ds[max], ds[i]);
	}
}

void in(sinhvien ds[], int n) {
	cout << "Danh sach sinh vien:" << endl;
    for (int i=0; i<n; i++) {
        cout << "Ma SV: " << ds[i].masv << endl;
        cout << "Ho ten: " << ds[i].hoten << endl;
        cout << "Lop: " << ds[i].lop << endl;
        cout << "Diem trung binh: " << ds[i].dtb << endl;
    }
}

int main() {
	int n;
	cout<<"nhap n: ";
	cin>>n;
	sinhvien* ds = new sinhvien[n];
    nhap(ds, n);
    sapxep(ds, n);
    in(ds, n);
    delete[] ds;
    return 0;
}