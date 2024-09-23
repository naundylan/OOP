#include <iostream>
#include <math.h>
using namespace std;

void nhap(int &n) {
	cin>>n;
}

void nhap(int &n, int &m) {
	cin>>n;
	cin>>m;
}

void nhapmang(int u[], int n) {
	for(int i=0; i<n; i++) {
		cin>>u[i];
	}
}

void nhapmang(int u[][100], int n, int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>u[i][j];
		}
	}
}

void tong(int u[], int v[], int n, int res[]) {
	for(int i=0; i<n; i++) {
		res[i] = u[i] + v[i];
	}
}

void tong(int u[][100], int v[][100], int n, int m, int res[][100]) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			res[i][j] = u[i][j] + v[i][j];
		}
	}
}

int main() {
	// mang mot chieu
	int n;
	nhap(n);
	int u[n], v[n], res[n];
	nhapmang(u, n);
	nhapmang(v, n);
	tong(u, v, n, res);
	for(int i=0; i<n; i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	// mang hai chieu
	int m;
	nhap(n, m);
	int q[n][100], p[n][100], kq[n][100];
	nhapmang(q, n, m); // Thay thế u bằng q
	nhapmang(p, n, m); // Thay thế u bằng p
	tong(q, p, n, m, kq);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<kq[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}