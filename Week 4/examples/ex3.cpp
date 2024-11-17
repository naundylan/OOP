#include <iostream>
#include <string>
using namespace std;

class Hocphan {
	private:
		string mahp,tenhp;
		int sotc;
	public:
		Hocphan *next;
		Hocphan() {}
		Hocphan(string mhp,string thp, int stc) {
			mahp = mhp;
			tenhp = thp;
			sotc = stc;
		}
		 //cac ham lay gia tri thuoc tinh
		string GetMaHP() {
			return mahp;
		}
		
		string GetTenHP() {
			return tenhp;
		}
		
		int GetSoTC() {
			return sotc;
		}
		void Set(string mhp,string thp, int stc) {
			mahp = mhp;
			tenhp = thp;
			sotc = stc;
		}
};

//lop List de mo ta cac doi tuong la dslk
class List {
	private:
		Hocphan *first;
	public:
		List() {
			first = NULL;
		}
		void Nhap(); //nhap danh sach cac hoc phan
		void HienThi(); //hien thi cac hoc phan
		void SapXep(); //sap xep theo ma hoc phan
		Hocphan *TimKiem(string hp);
		void Xoa(string hp);
};

void List::Nhap(){
	string mhp,thp;
	int stc;
	do {
		cout<<"\n Nhap ma hoc phan: ";
		getline(cin,mhp);
		if(mhp.size() != 0) {
			cout<<"\n Nhap ten hoc phan: ";
			getline(cin,thp);
			cout<<"\n Nhap so tin chi: ";
			cin>>stc;
			cin.ignore();
			Hocphan *p = new Hocphan(mhp,thp,stc);
			p->next = first;
			first = p;
		}
	} while(mhp.size() != 0);
}

void List::HienThi() {
	Hocphan *p = first;
	while(p != NULL) {
		cout<<"\n\n-----------------------------";
		cout<<"\n Ma hoc phan: "<<p->GetMaHP();
		cout<<"\n Ten hoc phan: "<<p->GetTenHP();
		cout<<"\n So tin chi: "<<p->GetSoTC();
		cout<<"\n\n-----------------------------";
		p = p->next;
	}
}

void List::SapXep() {
	Hocphan *p,*q;
	string temmahp,temthp;
	int temtc;
	if(first != NULL)
		for(p = first; p->next != NULL; p= p->next)
			for(q = p->next; q != NULL; q = q->next)
				if(p->GetMaHP() > q->GetMaHP()) {
					temmahp = p->GetMaHP();
					temthp = p->GetTenHP();
					temtc = p->GetSoTC();
					p->Set(q->GetMaHP(),q->GetTenHP(),q->GetSoTC());
					q->Set(temmahp,temthp,temtc);
				}
}

Hocphan * List::TimKiem(string mhp) {
	Hocphan *p = first;
	while (p!=NULL && p->GetMaHP()!= mhp)
		p = p->next;
	return p;
}

void List::Xoa(string mhp) {
	while (first!=NULL && first->GetMaHP()==mhp) {
		Hocphan *tam = first;
		first = first ->next;
		delete tam;
	}
	if(first!=NULL) {
		Hocphan *p = first;
		while(p->next!=NULL)
			if(p->next->GetMaHP()==mhp) {
			Hocphan *tam = p->next;
			p->next = p->next->next;
			delete tam;
		}
		else
			p = p->next;
	}
}


int main() {
	List ds; //khai bao 1 ds doi tuong cua lop List
	ds.Nhap();
	cout<<"\n Hien thi danh sach hoc phan: ";
	ds.HienThi();
	ds.SapXep();
	cout<<"\n Hien thi sau khi sap xep: ";
	ds.HienThi();
	string mhp,thp;
	cout<<"\n Nhap vao ma hp muon xoa: ";
	getline(cin,mhp);
	ds.Xoa(mhp);
	cout<<"\n Hien thi sau khi xoa: ";
	ds.HienThi();
	cout<<"\n Nhap vao ma hp muon tim kiem ";
	getline(cin,mhp);	
	Hocphan *p = ds.TimKiem(mhp);
	if(p!= NULL) {
		cout<<"\n Da tim thay hp cua ban! ";
		cout<<"\n Ma hp :"<<p->GetMaHP();
		cout<<"\n Ten hp:"<<p->GetTenHP();
		cout<<"\n So tc:"<<p->GetSoTC();
	}
	else
		cout<<"\n Khong tim thay ma hoc phan nay";
	return 0;
}