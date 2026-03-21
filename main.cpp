#include <iostream>
using namespace std;

// struct VongTron
class VongTron {
public: 
	float x;
	float y;
	float r;

	void nhap(/*VongTron& d*/) {
		cout << "x: "; cin >> /*d.*/x;
		cout << "y: "; cin >> /*d.*/y;
		cout << "r: "; cin >> /*d.*/r;
	}

	void xuat(/*VongTron d*/) {
		cout << "(" << /*d.*/x << ":" << /*d.*/y << "," << r << ")";
	}

	float dien_tich(/*VongTron v */) {
		return 3.14 * r * r;
	}

};

class Diem {
private: 
	float x; 
	float y;
public: 
	Diem(float xx, float yy) {
		cout << "Diem(" << xx << "," << yy << ")" << endl;
		x = xx;
		y = yy;
	}
	Diem() : Diem(0, 0) {}

	void nhap(/*Diem& d*/) {
		cout << "x: "; cin >> /*d.*/x;
		cout << "y: "; cin >> /*d.*/y;
	}

	void xuat(/*Diem d*/) {
		cout << "(" << /*d.*/x << ":" << /*d.*/y << ")";
	}

	float khoang_cach_den(/*Diem d1, */ Diem d2) {
		return sqrt((/*d1.*/x - d2.x) * (/*d1.*/x - d2.x) + (/*d1.*/y - d2.y) * (/*d1.*/y - d2.y));
	}
};

// class : lớp 
// object : biến 
// method: các hàm đi kèm với class/struct
// Encapsulation : đóng gói 

class vector2D {
private: 
	float x; 
	float y;
public: 
	vector2D(float xx, float yy) {
		x = xx;
		y = yy;
	}
	vector2D() :vector2D(0, 0) {}

};

class SoPhuc {
private: 
	float thuc;
	float ao;
public: 
	SoPhuc(float t, float a) {
		thuc = t;
		ao = a;
	}
	SoPhuc() : SoPhuc(0, 0) {}
	void nhap() {}
	void xuat() {
		cout << thuc << " + " << ao << "i" << endl;
	}
	SoPhuc cong(/* SoPhuc a, */SoPhuc b) {
		SoPhuc kq;
		kq.thuc = /*a.*/thuc + b.thuc;
		kq.ao = /*a.*/ao + b.ao;
		return kq;
	}
	SoPhuc tru(SoPhuc b) {
		SoPhuc kq;
		kq.thuc = /*a.*/thuc - b.thuc;
		kq.ao = /*a.*/ao - b.ao;
		return kq;
	}
	SoPhuc nhan(SoPhuc b) {

	}
	SoPhuc chia(SoPhuc b) {

	}


};

class PhanSo {
private: 
	int tu;
	int mau;

	int uscln(int a, int b) {
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
	void toiGian() {
		int tmp = uscln(tu, mau);
		tu = tu / tmp;
		mau = mau / tmp;
	}

public: 
	void nhap(/*PhanSo& a*/) {
		cout << "tu: "; cin >> /*a.*/tu;
		cout << "mau: "; cin >> /*a.*/mau;
	}

	void xuat(/*PhanSo a*/) {
		cout << "(" << /*a.*/tu << "/" << /*a.*/mau << ")" << endl;
	}

	// constructor 
	PhanSo(/*PhanSo a, */int t, int m) {
		if (m == 0) {
			cout << "Mau so phai khac khong" << endl;
			tu = 0;
			mau = 1;
 		return;
		}

		mau = m;
		tu = t;
	}

	// default constructor 
	PhanSo():PhanSo(0,1) {
	}

	//PhanSo(int t): PhanSo(t,1) {}

	void setMau(/*PhanSo a, */float m) {
		if (m == 0) {
			cout << "Mau so phai khac khong" << endl;
			return;
		}

		mau = m;
	}

	void setTu(/*Phan a, */float t) {
		tu = t;
	}

	PhanSo nhan(/*PhanSo a,*/PhanSo b) {
		PhanSo kq;
		kq.tu = tu * b.tu;
		kq.mau = mau * b.mau;
		kq.toiGian();
		return kq;
	}

	PhanSo cong(/*PhanSo a,*/PhanSo b) {
		PhanSo kq;
		kq.tu = tu * b.mau + mau * b.tu;
		kq.mau = mau * b.mau;
		kq.toiGian();
		return kq;
	}

	/*
	* = 0 nếu bằng, -1 nếu a < b, 1 nếu a > b
	*/
	int sosanh(/*PhanSo a,*/PhanSo b) {
		int tmp = tu * b.mau - mau * b.tu;
		if ((mau > 0 && b.mau > 0) || (mau < 0 && b.mau < 0)) {
			return tmp == 0 ? 0 : (tmp < 0 ? -1 : 1);
		} else {
			return tmp == 0 ? 0 : (tmp < 0 ? 1 : -1);
		}
	}

	PhanSo operator+(/*PhanSo trai,*/ PhanSo phai) {
		return cong(phai);
	}
	PhanSo operator+(/*PhanSo trai,*/ float phai) {
		PhanSo t(phai, 1);
		return cong(t);
	}

	friend PhanSo operator+(float trai, PhanSo phai);
};

PhanSo operator+(float trai, PhanSo phai) {
	PhanSo t(trai, 1);
	PhanSo kq;
	kq.tu = t.tu * phai.mau + t.mau * phai.tu;
	kq.mau = t.mau * phai.mau;
	kq.toiGian();
	return kq;

	//return t.cong(phai);
}

class PlayingCard {
private: 
	int rank;  // 1 = Xì, 2, ... , 10, 11 = Bồi, 12 = Đầm, 13 = Già
	int suite; // 4 = Cơ, 3 = Rô, 2 = Chuồn , 1 = Bích
public: 
	PlayingCard(int r, int s) {
		rank = r;
		suite = s;
	}
	PlayingCard() : PlayingCard(1, 1) {}

	void xuat() {

	}

	// tính điểm 1 lá bài 
	int getPoint() {
		return -1;
	}
};

class Deck {
private: 
	PlayingCard * cards[52];
	int count;
public: 
	Deck() {
		int i = 0;
		for (int r = 1; r<=13; r++)
			for (int s = 1; s <= 4; s++) {
				cards[i] = new PlayingCard(r, s);
				i++;
			}
		count = 52;
	}

	void xuat() {
		for (int i = 0; i < count; i++) {
			cards[i]->xuat();
		}
	}

	PlayingCard* drawOne() {
		int p = -1; // random from 0 ... count - 1 
		
		// swap p and count - 1 

		PlayingCard* c = cards[count - 1];
		count--;
		return c;
	}
};

void test() {
	//char a[100];
	//int n;

	//char b[100];
	//int m;

	//int i = n - 1;
	//int j = m - 1;
	//int carry = 0;
	//int sum = 0;

	//while (i >= 0 || j >= 0) {
	//	int ca = i >= 0 ? a[i] - '0' : 0;
	//	int cb = j>=0? b[j] - '0': 0;

	//	// cong ca , cb , carry 
	//	carry = (ca + cb + carry) / 10;
	//	sum = (ca + cb + carry) % 10;


	//}

}


class TamGiac {
private:
	Diem * pA; 
	Diem * pB; 
	Diem * pC; 
public: 
	TamGiac(
		float xA, float yA, 
		float xB, float yB, 
		float xC, float yC)
	{
		pA = new Diem(xA, yA);
		pB = new Diem(xB, yB);
		pC = new Diem(xC, yC);
	}

	~TamGiac() {
		delete pA;
		delete pB;
		delete pC;
	}
};

void f() {
	TamGiac ABC(3, 3, 6, 2, 1, 0);
}

class CTime {
//private:
//	int h, m, s;
	int ss;
public:
	CTime(int hh, int mm, int ss) : ss(3600 * hh + 60 * mm + ss) {}
//	CTime(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {
		// h = hh;
		// m = mm;
		// s = ss;
//	}
	CTime() : CTime(0, 0, 0) {}

	CTime operator+(int ds) {
		CTime kq;
		kq.ss += ds;

		//CTime kq;
		//kq.s = (s + ds) % 60;
		//kq.m = (m + (s + ds) / 60)%60;
		//kq.h = 0; //(m + (s + ds) / 60) % 60;
		return kq;
	}
	friend CTime operator+(int ds, CTime phai);
	void xuat() {
		int h = ss / 3600;
		int m;
		int s = ss % 60;
	}
};

CTime operator+(int ds, CTime phai) {
	return phai + ds;
}


class CDate {
	int day, month, year;

	int so_ngay_cua_thang(int m, int y) {
		switch (m) {
		case 1: return 31; 
		case 2: 
			if (year % 4 == 0 && year % 100 != 0) 
				return 29; 
			else 
				return 28;
		case 3: return 31; 
		case 4: return 30; 
		case 5: return 31; 
		case 6: return 30; 
		case 7: return 31; 
		case 8: return 31; 
		case 9: return 30; 
		case 10: return 31; 
		case 11: return 30; 
		case 12: return 31; 

		}
	}
public: 
	CDate(int d, int m, int y) : day(d), month(m), year(y) {}
	CDate() : CDate(1, 1, 1980) {}

	CDate operator+(int dd) {
		CDate kq(day, month, year);
		int con_lai = dd;
		while (con_lai > 0) {
			int so_ngay_thang = so_ngay_cua_thang(kq.month, kq.year);
			int delta = so_ngay_thang - kq.day;
			if (con_lai <= delta) {
				kq.day += con_lai;
				con_lai = 0;
			}
			else { // con_lai > delta
				kq.day = 1;
				if (kq.month == 12) { 
					kq.month = 1;
					kq.year++; 
				}
				else kq.month++;

				con_lai -= delta + 1;
			}
			
		}
		return kq;
	}

	friend CDate operator+(int dd, CDate date);

	void xuat() {
		cout << day << "/" << month << "/" << year;
	}
};

CDate operator+(int dd, CDate date) {
	return date + dd;
}

class IntStack {
	int items[1000];
	int count;
public: 
	IntStack() {
		count = 0;
	}

	void push(int value) {
		items[count] = value;
		count++;
	}
	int pop() {
		if (count > 0) {
			int it = items[count - 1];
			count--;
			return it;
		}
	}
	int size() {
		return count;
	}

	IntStack& operator+(/*IntStack * this, */int value) {
		push(value);
		return *this;
	}
};

int main(int) {

	 IntStack s;
	 s.push(5);
	 cout << s.size() << endl; // ket qua: 1
	 s.push(6);
	 s.push(7);
	 cout << s.pop() + 5 << endl; // ket qua: 12
	 cout << s.pop() - 5 << endl;  // ket qua: 1
	 cout << (s + 6).size() << endl;	// ket qua: 2

	//CDate d1(28, 5, 2025);
	//(d1 + 5).xuat();

	//CTime t1(5, 30, 27);
	//CTime t2 = 456 + t1;
	//CTime t3 = t2 + 137;

	//PhanSo a(7*2, 3*2);
	//PhanSo b(7, 3);
	/*PhanSo c(3);
	PhanSo d(4);*/

	//	PhanSo e = 1.5 + a;

	//PhanSo t1 = a.cong(b);
	//PhanSo t2 = t1.cong(c);
	//PhanSo e = t2.cong(d);
}
