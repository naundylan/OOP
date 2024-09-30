#include<iostream>

using namespace std;

class xeNoiThanh{
	private:
		string maSo, hoTen, soXe;
		int soTuyen, soKm, doanhThu;
	public:
		xeNoiThanh(){
			
		}
		xeNoiThanh(string maSo, string hoTen, string soxe, int soTuyen, int soKm, int doanhThu){
			this->hoTen = hoTen;
			this->maSo = maSo;
			this->soXe = soXe;
			this->soTuyen = soTuyen;
			this->soKm = soKm;
			this->doanhThu = doanhThu;
		}
		~xeNoiThanh(){
			
		}
		void in(){
			cout<<"\n****************************\n";
			cout<<"Ma so chuyen: "<<maSo<<endl;
			cout<<"Ho ten tai xe: "<<hoTen<<endl;
			cout<<"So xe: "<<soXe<<endl;
			cout<<"So tuyen: "<<soTuyen<<endl;
			cout<<"So km di duoc: "<<soKm<<endl;
			cout<<"Doanh thu: "<<doanhThu<<endl;
		}
		int getDoanhThu(){
			return doanhThu;
		}
};

class xeNgoaiThanh{
	private:
		string maSo, hoTen, soXe, noiDen;
		int soNgayDi, doanhThu;
	public:
		xeNgoaiThanh(){
			
		}
		xeNgoaiThanh(string maSo, string hoTen, string soxe, string noiDen, int soNgayDi, int doanhThu){
			this->hoTen = hoTen;
			this->maSo = maSo;
			this->soXe = soXe;
			this->noiDen = noiDen;
			this->soNgayDi = soNgayDi;
			this->doanhThu = doanhThu;
		}
		~xeNgoaiThanh(){
			
		}
		void in(){
			cout<<"\n****************************\n";
			cout<<"Ma so chuyen: "<<maSo<<endl;
			cout<<"Ho ten tai xe: "<<hoTen<<endl;
			cout<<"So xe: "<<soXe<<endl;
			cout<<"Noi den: "<<noiDen<<endl;
			cout<<"So ngay di: "<<soNgayDi<<endl;
			cout<<"Doanh thu: "<<doanhThu<<endl;
		}
		int getDoanhThu(){
			return doanhThu;
		}
};


int main(){
	string maSo, hoTen, soXe, noiDen;
	int soTuyen, soKm, doanhThu, soNgayDi;
	
	// xe noi thanh
	cout<<"Nhap so chuyen xe noi thanh: ";
	int n; cin>>n;
	cin.ignore();
	xeNoiThanh *xe1 = new xeNoiThanh[n];
	for( int i=0; i<n; i++){
		cout<<"Ma so chuyen: ";
		cin>>maSo;
		cin.ignore();
		cout<<"Ho ten tai xe: "; getline(cin,hoTen);
		cout<<"So xe: ";	cin>>soXe;
		cout<<"So tuyen: "; cin>>soTuyen;
		cout<<"So km di duoc: "; cin>> soKm;
		cout<<"Doanh thu: "; cin>>doanhThu;
		xe1[i] =  xeNoiThanh(maSo,hoTen,soXe,soTuyen,soKm,doanhThu);
	}
	//xe ngoai thanh
	cout<<"Nhap so chuyen xe noi thanh: ";
	int t; cin>>t;
	cin.ignore();
	xeNgoaiThanh *xe2 = new xeNgoaiThanh[t];
	for( int i=0; i<t; i++){
		cout<<"Ma so chuyen: ";
		cin>>maSo;
		cin.ignore();
		cout<<"Ho ten tai xe: "; getline(cin,hoTen);
		cout<<"So xe: ";	cin>>soXe;
		cout<<"Noi den: "; cin>>noiDen;
		cout<<"So ngay di: "; cin>> soNgayDi;
		cout<<"Doanh thu: "; cin>>doanhThu;
		xe2[i] = xeNgoaiThanh(maSo,hoTen,soXe,noiDen,soNgayDi,doanhThu);
	}
	
	//in xe noi thanh va xe ngoai thanh
	for( int i=0; i<n; i++){
		xe1[i].in();
	}
	for( int i=0; i<t; i++){
		xe2[i].in();
	}
	//tinh tong doanh thu xe noi thanh va xe ngoai thanh
	int sum = 0;
	for( int i=0; i<n; i++){
		sum+=xe1[i].getDoanhThu();
	}
	cout<<"\n*******\nTong doanh thu cac xe noi thanh: ";
	cout<<sum<<endl;
	int sum2 = 0;
	for( int i=0; i<t; i++){
		sum2+=xe2[i].getDoanhThu();
	}
	cout<<"\n*******\nTong doanh thu cac xe ngoai thanh: ";
	cout<<sum2<<endl;
	delete[] xe1;
	delete[] xe2;
	return 0;
}
