#include<iostream>

using namespace std;

bool namNhuan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getNgay(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31; 
        case 4: case 6: case 9: case 11:
            return 30; 
        case 2:
            return namNhuan(year) ? 29 : 28;
        default:
            return 0;
    }
}


bool kiemTra(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false; 
    }
    int check = getNgay(month, year);
    if (day < 1 || day > check) {
        return false;
    }
    return true;
}

class date{
	private:
		int ngay, thang, nam;
	public:
		date(){
			
		}
		date(const int ngay,const int thang,const int nam){
			this->ngay = ngay;
			this->thang = thang;
			this->nam = nam;
		}
		~date(){}
		void tang_1_Ngay(){
			if( ngay == 31 ){
				ngay = 1;
				thang +=1;
			}else{
				ngay += 1;
			}
			if( thang > 12){
				thang = 1;
				nam += 1;
			}
			cout<<ngay<<'/'<<thang<<'/'<<nam<<endl;
		}
		void tang_n_Ngay(int n) {
            for (int i = 0; i < n; i++) {
                int soNgayTrongThang = getNgay(thang, nam);
                if (ngay == soNgayTrongThang) {
                    ngay = 1;
                    thang += 1;
                } else {
                    ngay += 1;
                }

                if (thang > 12) {
                    thang = 1;
                    nam += 1;
                }
            }
            cout << "Ngay moi la: " << ngay << '/' << thang << '/' << nam << endl;
        }
		
};

int main(){
	int ngay,thang,nam;
	cout<<"Nhap ngay thang nam: ";
	cin>>ngay>>thang>>nam;
	if (!kiemTra(ngay, thang, nam)) {
        cout << "Ngay khong hop le!\n";
        return 1; 
    }
	date *ngaythangnam = new date(ngay,thang,nam);
	cout<<"Tang them 1 ngay: ";
	ngaythangnam->tang_1_Ngay();
	cout<<"Nhap so luong ngay de tang: ";
	int n; cin>>n;
	ngaythangnam->tang_n_Ngay(n);
	delete ngaythangnam;
	return 0;
}
