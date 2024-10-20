#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Vector {
	private:
		int n;
		vector<int> ds;
	public:
		friend istream& operator >> (istream& in, Vector &a);
		friend ostream& operator << (ostream& out, Vector a);
		int tichvohuong(Vector a);
		double modul();
};

istream& operator >>(istream& in, Vector &a) {
	cout<<"Nhap kich thuoc cua vector: ";
    in>>a.n;
    a.ds.resize(a.n);
    for (int i=0; i<a.n; i++) {
        cout<<"Nhap phan tu thu "<<i+1<< ": ";
        in>>a.ds[i];
    }
    return in;
}

ostream& operator << (ostream& out, Vector a) {
	for(int i=0; i<a.n; i++) {
		cout<<a.ds[i]<<" ";
	}
	out<<endl;
	return out;
}

int Vector::tichvohuong(Vector a) {
	if(n != a.n) {
		cout<<"Hai vector khong cung kich thuoc"<<endl;
		return 0;
	}
	int tich=0;
	for(int i=0; i<n; i++) {
		tich+=ds[i] * a.ds[i];
	}
	return tich;
}

double Vector::modul() {
	double result = 0;
    for (int i = 0; i < n; i++) {
        result += ds[i] * ds[i];
    }
    return sqrt(result);
} 

int main() {
	Vector a, b;
	cin>>a;
	cin>>b;
	cout<<"vector a: "<<endl;
	cout<<a;
	cout<<"vector b: "<<endl;
	cout<<b;
	
	cout<<"tich vo huong: ";
	cout<<a.tichvohuong(b)<<endl;
	
	cout<<"modul a: ";
	cout<<a.modul()<<endl;
	cout<<"modul b: ";
	cout<<b.modul();
	return 0;
}