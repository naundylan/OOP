#include <iostream>
using namespace std;

class chuoi {
	private:
		string str;
		int len;
	public:
		chuoi() {
			str = "";
			len = 0;
		}
		chuoi(string s) {
	        len = s.length();
	        str = s;
    	}
    	void nhap();
    	void xuat();
    	char character(int i);
    	chuoi ghep(chuoi b);
};

void chuoi::nhap() {
	cout << "Nhap chuoi: ";
    getline(cin, str);
    len = str.length();
}

void chuoi::xuat() {
	cout << str << endl;
}

char chuoi::character(int i) {
    if (i >= 0 && i < len) {
        return str[i];
    }
	else {
        cout << "Vi tri khong hop le!" << endl;
        return '\0';
    }
}

chuoi chuoi::ghep(chuoi a) {
	chuoi ketqua;
	ketqua.str = str + a.str;
	ketqua.len = len + a.len;
	return ketqua;
}

int main() {
	chuoi str1, str2;
    str1.nhap();
    str2.nhap();
    
    cout << "Chuoi thu nhat la: ";
    str1.xuat();
    
    cout << "Chuoi thu hai la: ";
    str2.xuat();
    
    cout << "Ky tu tai vi tri 3 cua chuoi thu nhat la: " << str1.character(2) << endl;
    
    chuoi ketqua = str1.ghep(str2);
    cout << "Chuoi ket qua la: ";
    ketqua.xuat();
    
	return 0;
}