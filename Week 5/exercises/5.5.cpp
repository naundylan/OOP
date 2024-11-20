#include <iostream>
using namespace std;

class stack {
	private:
		char *arr; // con tro tro den mang dong
		int top; // dinh cua stack
		int storage; // suc chua hien tai cua stack
	public:
		stack() {}
		stack(int size) {
			storage = size;
			arr = new char[storage];
			top = -1;
		}
		~stack() {
			delete[] arr;
		}
		void push(char x) {
			if(top == storage - 1) {
				cout<<"Stack overflow!"<<endl;
			}
			arr[++top] = x;
		}
		char pop() {
			if(isEmpty()) {
				cout<<"Stack underflow!"<<endl;
				return '\0';
			}
			return arr[top--];
		}
		bool isEmpty() {
			return top == -1;
		}
};

class converter : public stack {
	public:
		converter() : stack(100) {}
		
		string chuyendoiso(int number, int base) {
			string digits = "0123456789ABCDEF";
			string result = "";
			
			while(number > 0) {
				int remainder = number % base;
				push(digits[remainder]);
				number /= base;
			}
			
			while(!isEmpty()) {
				result += pop();
			}
			return result;
		}
			
};

int main() {
	converter chuyen_doi;
    int number, base;

    cout << "Nhap so nguyen duong he 10: ";
    cin >> number;

    cout << "Nhap co so dich (2/8/16): ";
    cin >> base;

    if (base == 2 || base == 8 || base == 16) {
        string result = chuyen_doi.chuyendoiso(number, base);
        cout << "So " << number << " trong he co so " << base << " la: " << result << endl;
    }
	else {
        cout << "Co so khong hop le! Chi chap nhan 2, 8 hoac 16." << endl;
    }
	return 0;
}