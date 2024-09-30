#include <iostream>
using namespace std;

class A {
	private:
		int a;
	public:
		float b;
		int &get_a() { // phai co dau & moi co the gan gia tri duoc con khong thi chi lay gia tri
			return a;
		}
};

int main() {
	A ob;
	//ob.a = 5; loi
	ob.get_a() = 5;
	ob.b = 10;
	return 0;
}