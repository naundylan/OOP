#include <iostream>
using namespace std;

class mang {
	private:
		int n;
		int *arr;
	public:
		mang();
		mang(int n);
		void nhap();
		void xuat();
		mang tong(mang& a);
		~mang();
};

mang::mang() {
	n = 0;
	arr = nullptr;
}

mang::mang(int n) {
	int size = n;
	arr = new int[size];
}

void mang::nhap() {
	cout<<"nhap kich thuoc mang: ";
	cin>>n;
	arr = new int[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
}

void mang::xuat() {
	cout<<"Mang: ";
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

mang mang::tong(mang& a) {
//	if(n != a.n)
//		return mang();
	mang kq(n);
    for (int i = 0; i < n; i++) {
        kq.arr[i] = arr[i] + a.arr[i];
    }
    return kq;
}

mang::~mang() {
	delete[] arr;
}

int main() {
	mang a, b, c;
	
	a.nhap();
	b.nhap();
	
	a.xuat();
	b.xuat();
	
	cout<<"tong cua hai mang la: "<<endl;
	c = a.tong(b);
	c.xuat();
	return 0;
}