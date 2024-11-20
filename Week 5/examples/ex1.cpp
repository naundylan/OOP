#include <iostream>
using namespace std;

class A {
	private: int x;
	protected: int y;
	public:
		int z;
		A() {
			x = 0; y = 0; z = 0;
		} // ham tao khong ke thua
};

class B: public A {
	// public cua A se tro thanh public cua B, protected cua A se tro thanh protected cua B
	public:
		void showData() {
			cout<<"x khong the in ra"<<endl;
			cout<<"y la: "<<y<<endl;
			cout<<"z la: "<<z<<endl;
		}
};

int main() {
	B a;
	a.showData();
	a.z = 5;
	a.y = 1; // khong the truy cap y vi y dang nam trong protected
	return 0;
}