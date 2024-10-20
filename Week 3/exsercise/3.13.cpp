#include <iostream>
#include <vector>
using namespace std;

class dathuc {
	private:
		int n;
		vector<int> heso;
	public:
		friend istream& operator >> (istream &in, dathuc &a);
		friend ostream& operator << (ostream &out, dathuc a);
		friend dathuc operator + (dathuc a, dathuc b);
		friend dathuc operator - (dathuc a, dathuc b);
};

istream& operator >> (istream &in, dathuc &a) {
	cout<<"nhap bac cua da thuc: ";
	in>>a.n;
	a.heso.resize(a.n + 1);
    for (int i = 0; i <= a.n; i++) {
        cout << "Nhap he so bac " << i << ": ";
        in >> a.heso[i];
    }
    return in;
}

ostream& operator << (ostream &out, dathuc a) {
	for (int i = a.heso.size() - 1; i >= 0; i--) {
        if (a.heso[i] != 0) {
            out << a.heso[i] << "x^" << i;
            if (i > 0)
            	if(a.heso[i-1] != 0)
					out << " + ";
        }
    }
    out << endl;
    return out;
}

dathuc operator + (dathuc a, dathuc b) {
	dathuc kq;
	int n = max(a.heso.size(), b.heso.size());
	kq.heso.resize(n);
	for(int i=0; i<n; i++) {
		kq.heso[i] = a.heso[i] + b.heso[i];
	}
	return kq;
}

dathuc operator - (dathuc a, dathuc b) {
	dathuc kq;
	int n = max(a.heso.size(), b.heso.size());
	kq.heso.resize(n);
	for(int i=0; i<n; i++) {
		kq.heso[i] = a.heso[i] - b.heso[i];
	}
	return kq;
}

int main() {
	dathuc dt1, dt2, kq;

    cin>>dt1;

    cin>>dt2;

    kq = dt1 + dt2;

    cout<<"Tong hai da thuc la: ";
    cout<<kq<<endl;
    cout<<dt1<<endl;
    cout<<dt2;
	return 0;
}