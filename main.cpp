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

class PhanSo {
private: 
	float tu;
	float mau;

public: 
	void nhap(/*PhanSo& a*/) {
		cout << "tu: "; cin >> /*a.*/tu;
		cout << "mau: "; cin >> /*a.*/mau;
	}

	void xuat(/*PhanSo a*/) {
		cout << "(" << /*a.*/tu << "/" << /*a.*/mau << ")";
	}

	// constructor 
	PhanSo(/*PhanSo a, */float t, float m) {
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
		return kq;
	}
};

float f2() {
	return 0;
}

float f1() {
	return 1.0f;
}

float f3() {
	return 0;
}

int main(int) {

	int i = 1;

	PhanSo a(2, 3);
	PhanSo b(7, 3);
	
	PhanSo c = a.nhan(b);

	c.xuat();

	PhanSo ps[2];

	//Diem diem[10];
	//Diem p;
	//int n;

	//cout << "Nhap so diem: "; cin >> n;

	//for (int i = 0; i < n; i++) {
	//	//nhap(diem[i]);
	//	diem[i].nhap();
	//}
	
	//cout << "Nhap diem P" << endl;
	//nhap(p);
	//p.nhap();

	//int min_i = 0;
	//float min_d = diem[0].khoang_cach_den(p);
	//for (int i = 1; i < n; i++) {
	//	float d = diem[i].khoang_cach_den(p);
	//	if (d < min_d ) {
	//		min_d = d;
	//		min_i = i;
	//	}
	//}


	//int min_i = 0;
	//int min_j = 1;
	//float min_d = diem[0].khoang_cach_den(diem[1]);

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		float d = diem[i].khoang_cach_den(diem[j]);
	//		if (d < min_d) {
	//			min_d = d;
	//			min_i = i;
	//			min_j = j;
	//		}
	//	}
	//}

    //cout << "Diem gan voi diem P"; 
	//xuat(p);
	//p.xuat();
	//cout << " nhat la ";
	//xuat(diem[min_i]); 
	//diem[min_i].xuat(); 

	cout << endl;
}
