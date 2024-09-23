#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void nhap(int arr[], int &n) {
    do {
    	cin >> n;
	} while (n > MAX_SIZE);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void cong(int a[], int b[], int n, int c[]) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void cong(int tu1, int mau1, int tu2, int mau2, int &tuKetQua, int &mauKetQua) {
    int mauSoChung = mau1 * mau2 / gcd(mau1, mau2);
    tuKetQua = tu1 * (mauSoChung / mau1) + tu2 * (mauSoChung / mau2);
    mauKetQua = mauSoChung;
}

int main() {
    int n;
    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    int tu1, mau1, tu2, mau2, tuKetQua, mauKetQua;
	
	//vector
    nhap(a, n);
    nhap(b, n);

    cong(a, b, n, c);
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
	
	// phan so
    cin >> tu1 >> mau1;
    cin >> tu2 >> mau2;

    // Cong hai phan so
    cong(tu1, mau1, tu2, mau2, tuKetQua, mauKetQua);
    cout << "Tong hai phan so la: " << tuKetQua << "/" << mauKetQua << endl;
    return 0;
}