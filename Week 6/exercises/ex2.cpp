#include <iostream>
using namespace std;

class computer {
	protected:
		string id, brand;
		int year, price;
	public:
		string getId() {
			return id;
		}
		string getBrand() {
			return brand;
		}
		int getYear() {
			return year;
		}
		int getPrice() {
			return price;
		}
		void nhap() {
			cout<<"Nhap ma may: ";
			cin>>id;
			cout<<"Nhap hang san xuat: ";
			cin>>brand;
			cout<<"Nhap nam san xuat: ";
			cin>>year;
			cout<<"Nhap gia ban: ";
			cin>>price;
		}
		void xuat() {
			cout<<"Ma may: "<<id<<", Thuong hieu: "<<brand<<", Nam sx: "<<year<<", Gia ban: "<<price;
		}
};

class laptop : public computer {
	private:
		float weight, thickness, scrSize;
		string operatorSystem;
	public:
		float getWeight() {
			return weight;
		}
		float getThickness() {
			return thickness;
		}
		float getScrSize() {
			return scrSize;
		}
		string getOperatorSystem() {
			return operatorSystem;
		}
		float years() const {
			return 2024 - year;
		}
		float remainValue() const {
			if(operatorSystem == "Windows") {
				return price - (years() * 0.1 * price);
			}
			return price - (years() * 0.05 * price);
		}
		void nhap() {
			cout<<"Nhap can nang: ";
			cin>>weight;
			cout<<"Nhap do day: ";
			cin>>thickness;
			cout<<"Nhap kich thuoc man hinh: ";
			cin>>scrSize;
			cout<<"Nhap he dieu hanh: ";
			cin>>operatorSystem;
		}
		void xuat() {
			computer::xuat();
			cout<<", Can nang: "<<weight<<", Do day: "<<thickness<<", Kich thuoc: "<<scrSize<<", He dieu hanh: "<<operatorSystem<<endl;
		}
		bool operator >(laptop& other) const {
			return this->remainValue() > other.remainValue();
		}
};

class quanly {
	private:
		laptop ds[50];
		int soluong;
	public:
		quanly() {
			soluong = 0;
		}
		void nhap() {
			cout<<"Nhap vao so luong toi da: "; cin>>soluong;
			
			while(soluong <= 0 || soluong > 50) {
				cout<<"So luong khong hop le, Vui long nhap lai: ";
				cin>>soluong;
			}
			
			for(int i = 0; i < soluong; i++) {
				ds[i].computer::nhap();
				ds[i].nhap();
			}
		}
		void xuat() {
			cout<<"Danh sach laptop la:"<<endl;
			for(int i = 0; i < soluong; i++) {
				ds[i].xuat();
			}
		}
		void sapxep() {
			for(int i = 0; i < soluong - 1; i++) {
				for(int j = 0; j < soluong - i - 1; j++) {
					if(ds[j] > ds[j + 1]) {
						laptop tmp = ds[j];
						ds[j] = ds[j + 1];
						ds[j + 1] = tmp;
					}
				}
			}
		}
		void highestYear() {
			int max = 0;
			for(int i = 0; i < soluong; i++) {
				if(ds[i].years() > max)
					max = ds[i].years();
			}
			
			cout<<"Danh sach laptop co so nam su dung cao nhat la:"<<endl;
			for(int i = 0; i < soluong; i++) {
				if(ds[i].years() == max) {
					ds[i].xuat();
				}
			}
		}	
};

int main() {
	quanly list;
	list.nhap();
	list.xuat();
	list.sapxep();
	list.xuat();
	list.highestYear();
	return 0;
}