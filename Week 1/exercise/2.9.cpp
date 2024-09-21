#include <iostream>
#include <math.h>
using namespace std;

void giaipt(float a, float b, float &x) {
	if(a==0) {
		if(b!=0) {
			cout<<"vo nghiem"<<endl;
		}
		cout<<"vo so nghiem"<<endl;
	}
	else {
		x = -b/a;
	}
}

void giaipt(float a, float b, float c, float &x1, float &x2) {
	float d = b*b - 4*a*c;
	if(a==0) {
		giaipt(b, c, x1);
	}
	else {
		if(d<0) {
			cout<<"vo nghiem"<<endl;
		}
		else if (d==0) {
			x1 = -b/2*a;
			x2 = -b/2*a;
		}
		else {
			x1 = (-b+sqrt(d))/2*a;
			x2 = (-b-sqrt(d))/2*a;
		}
	}
}

int main() {
	//giai pt bac nhat
	float x;
	giaipt(10, 5, x);
	cout<<x;
	
	//giai pt bac hai
	float x1, x2;
	giaipt(10, 20, 30, x1, x2);
	cout<<x1<<" "<<x2<<endl;
	giaipt(5, 30, 1, x1, x2);
	cout<<x1<<" "<<x2<<endl;
	giaipt(2, 3, 5, x1, x2);
	cout<<x1<<" "<<x2<<endl;
	return 0;
}