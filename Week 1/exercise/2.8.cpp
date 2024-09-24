#include <iostream>
#include <math.h>
using namespace std;

const float pi = 3.14;

float dientich(float a, float b) {
	return a*b;
}

float dientich(float a, float b, float c) {
	float p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

float dientich(float r) {
	return pi*r*r;
}

int main() {
	cout<<"dien tich hinh chu nhat: "<<dientich(10,20)<<endl;
	cout<<"dien tich hinh tron:: "<<dientich(10)<<endl;
	cout<<"dien tich hinh tam giac: "<<dientich(3,4,5);
	return 0;
}