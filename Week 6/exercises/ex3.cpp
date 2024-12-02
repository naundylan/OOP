#include <iostream>
using namespace std;

class Media {
protected:
    string id;        
    int year;       
    float price;   
public:
    void nhap() {
        cout << "Nhap ma phuong tien: ";
        cin >> id;
        cout << "Nhap nam xuat ban: ";
        cin >> year;
        cout << "Nhap gia ban: ";
        cin >> price;
    }
    void xuat() {
        cout << "Ma: " << id << ", Nam xuat ban: " << year << ", Gia ban: " << price;
	}
    string getId() {
        return price;
    }
    int getYear() {
        return year;
    }
    float getPrice() {
        return price;
    }
};

class Book : public Media {
private:
    string title;    
    string author;   
    int pages;      

public:
    void nhap() {
        Media::nhap();
        cout << "Nhap ten sach: ";
        cin.ignore();
        getline(cin, title);
        cout << "Nhap tac gia: ";
        getline(cin, author);
        cout << "Nhap so trang: ";
        cin >> pages;
    }
    void xuat() {
        Media::xuat();
        cout << ", Ten sach: " << title << ", Tac gia: " << author << ", So trang: " << pages << endl;
    }
    int getPages() const {
        return pages;
    }
    bool operator>(const Book& other) const {
        return this->pages > other.pages;
    }
};

class QuanLy {
private:
    Book ds[50];
    int soluong;

public:
    QuanLy() : soluong(0) {}
    void nhap() {
        cout << "Nhap so luong sach: ";
        cin >> soluong;

        while (soluong <= 0 || soluong > 50) {
            cout << "So luong khong hop le. Nhap lai: ";
            cin >> soluong;
        }

        for (int i = 0; i < soluong; i++) {
            cout << "Nhap thong tin cho sach thu " << i + 1 << ":\n";
            ds[i].nhap();
        }
    }
    void xuat() const {
        cout << "Danh sach cac cuon sach:\n";
        for (int i = 0; i < soluong; i++) {
            ds[i].xuat();
        }
    }
    void sapxep() {
        for (int i = 0; i < soluong - 1; i++) {
            for (int j = i + 1; j < soluong; j++) {
                if (ds[i] > ds[j]) {
                    swap(ds[i], ds[j]);
                }
            }
        }
    }
    void inSachGiaCaoNhat() const {
        float maxPrice = 0;
        for (int i = 0; i < soluong; i++) {
            if (ds[i].getPrice() > maxPrice) {
                maxPrice = ds[i].getPrice();
            }
        }

        cout << "Cac sach co gia ban cao nhat (" << maxPrice << "):\n";
        for (int i = 0; i < soluong; i++) {
            if (ds[i].getPrice() == maxPrice) {
                ds[i].xuat();
            }
        }
    }
    void tinhTong() const {
        int tongSoTrang = 0;
        float tongGiaTri = 0;

        for (int i = 0; i < soluong; i++) {
            tongSoTrang += ds[i].getPages();
            tongGiaTri += ds[i].getPrice();
        }

        cout << "Tong so trang cua tat ca sach: " << tongSoTrang << endl;
        cout << "Tong gia tri cua tat ca sach: " << tongGiaTri << endl;
    }
};

int main() {
    QuanLy ql;

    ql.nhap();
    cout << "\nDanh sach truoc khi sap xep:\n";
    ql.xuat();

    ql.sapxep();
    cout << "\nDanh sach sau khi sap xep tang dan theo so trang:\n";
    ql.xuat();

    cout << "\nSach co gia ban cao nhat:\n";
    ql.inSachGiaCaoNhat();

    cout << "\nTong so trang va tong gia tri sach:\n";
    ql.tinhTong();

    return 0;
}
