#include <iostream>
using namespace std;

const int MAX = 100;

class stack {
	private:
		int top;
		int arr[MAX];
	public:
		stack() {
        	top = -1;
    	}
		bool isEmpty();
		bool Full();
    	void push(int x);
    	int pop();
    	void xuat();
};

bool stack::isEmpty() {
	return top == -1;
}

bool stack::Full() {
	return top == MAX - 1;
}

void stack::push(int x) {
	if(Full()) {
		cout<<"Stack overflow!"<<endl;
		return;
	}
	arr[++top] = x;
}

int stack::pop() {
	if(isEmpty()) {
		cout<<"Stack underflow!"<<endl;
		return 0;
	}
	int x = arr[top--];
	return x;
}

void stack::xuat() {
	if (isEmpty()) {
        cout << "Stack rong" << endl;
        return;
    }
    cout << "Cac phan tu trong stack la: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.xuat();

    cout<<s.pop()<<" da duoc lay ra khoi danh sach!"<<endl;

    s.xuat();
	return 0;
}