#include <iostream>
using namespace std;

class stack {
	private:
		int *arr; // con tro tro den mang dong
		int top; // dinh cua stack
		int storage; // suc chua hien tai cua stack
	public:
		stack(int size = 10) {
			storage = size;
			arr = new int[storage];
			top = -1;
		}
		~stack() {
			delete[] arr;
		}
		void push(int x) {
			if(top >= storage - 1) {
				resize();
			}
			arr[++top] = x;
		}
		void pop() {
			if(top < 0) {
				cout<<"Stack underflow!"<<endl;
				return -1;
			}
			return arr[--top];
		}
		private:
			void resize() {
				storage *= 2;
				int newarray = new int[storage];
				for(int i = 0; i <= top; i++) {
					newarray[i] = arr[i];
				}
				delete[] arr;
				arr = newarray;
			}
		bool isEmpty() {
			return top == -1;
		}
};

class converter {
	public:
		// converter	
};

int main() {
	
	return 0;
}