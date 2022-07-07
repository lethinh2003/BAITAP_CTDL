#include <iostream>
#define MAX_SIZE 10;
using namespace std;
class SINHVIEN;
class MONHOC {
	friend SINHVIEN;
	string _sMaMon, _sTenMon;
	int _iSoTinChi;
	float _fDiem;

public:
	MONHOC();
	MONHOC(string maMon, string tenMon, int soTinChi, float diem);
	void display();

};
MONHOC::MONHOC() {


}
MONHOC::MONHOC(string maMon, string tenMon, int soTinChi, float diem) {
	_sMaMon = maMon;
	_sTenMon = tenMon;
	_iSoTinChi = soTinChi;
	_fDiem = diem;
}
void MONHOC::display() {
	cout << "Ma Mon: " << _sMaMon << endl;
	cout << "Ten Mon: " << _sTenMon << endl;
	cout << "So Tin Chi: " << _iSoTinChi << endl;
	cout << "Diem: " << _fDiem << endl;

}
class LOPSINHVIEN;
class SINHVIEN {
	friend LOPSINHVIEN;
	string _sMaSinhVien, _sHoTen, _sNgaySinh;
	MONHOC* _monHoc;
	int _iSoMonHoc;
	int _iSiSoMonHoc;
public:
	SINHVIEN();
	SINHVIEN(int soMonHoc);
	~SINHVIEN();
	void add(string maSinhVien, string hoTen, string ngaySinh);
	void addMonHoc(MONHOC lecture);
	void display();
	void suaHoTen(string hoTen);
	float diemTrungBinh();
	bool datDieuKienHocBong();


};
SINHVIEN::SINHVIEN() {
	_iSoMonHoc = MAX_SIZE;
	_monHoc = new MONHOC[_iSoMonHoc];
	_iSiSoMonHoc = 0;
}
SINHVIEN::SINHVIEN(int soMonHoc) {
	_iSoMonHoc = soMonHoc > 0 ? soMonHoc : MAX_SIZE;
	_monHoc = new MONHOC[_iSoMonHoc];
	_iSiSoMonHoc = 0;
}
void SINHVIEN::add(string maSinhVien, string hoTen, string ngaySinh) {
	_sMaSinhVien = maSinhVien;
	_sHoTen = hoTen;
	_sNgaySinh = ngaySinh;

}
bool SINHVIEN::datDieuKienHocBong() {
	if (diemTrungBinh() >= 7) {
		for (int i = 0; i < _iSiSoMonHoc; i++) {
			if (_monHoc[i]._fDiem < 5) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
void SINHVIEN::addMonHoc(MONHOC lecture) {
	if (_iSiSoMonHoc != _iSoMonHoc) {
		_monHoc[_iSiSoMonHoc] = lecture;
		_iSiSoMonHoc++;
	}
	else {
		cout << "HOC SINH NAY DA DAY MON HOC!" << endl;
	}
}
float SINHVIEN::diemTrungBinh() {
	float S = 0;
	for (int i = 0; i < _iSiSoMonHoc; i++) {
		S = S + _monHoc[i]._fDiem;
	}
	return S / _iSiSoMonHoc;
}
void SINHVIEN::suaHoTen(string hoTen) {
	_sHoTen = hoTen;
}
void SINHVIEN::display() {
	cout << "Ma SV: " << _sMaSinhVien << endl;
	cout << "Ho Ten SV: " << _sHoTen << endl;
	cout << "Ngay Sinh: " << _sNgaySinh << endl;
	cout << "Mon Hoc: " << endl;
	for (int i = 0; i < _iSiSoMonHoc; i++) {
		cout << "STT: " << i + 1 << endl; 
		_monHoc[i].display();
	}
	cout << "Diem Trung Binh: " << diemTrungBinh() << endl;
}
SINHVIEN::~SINHVIEN() {
	//delete[] _monHoc;
}
class LOPSINHVIEN {
	SINHVIEN* _sinhVien;
	int _iSoLuongSinhVien;
	int _iSiSoSinhVien;
public:
	LOPSINHVIEN();
	LOPSINHVIEN(int soLuong);
	~LOPSINHVIEN();
	bool isFull();
	void add(SINHVIEN data);
	void display();
	int timSinhVien(string maSinhVien);
	int timSinhVienNhiPhan(string hoTen);
	void suaHoTen(int pos ,string hoTen);
	void insertionSort();
	void selectionSort();
	void removeAt(int x);
	void danhSachHocBong();
};

LOPSINHVIEN::LOPSINHVIEN() {
	_iSoLuongSinhVien = MAX_SIZE;
	_sinhVien = new SINHVIEN[_iSoLuongSinhVien];
	_iSiSoSinhVien = 0;
}
LOPSINHVIEN::~LOPSINHVIEN() {
	delete[] _sinhVien;
}
LOPSINHVIEN::LOPSINHVIEN(int soLuong) {
	_iSoLuongSinhVien = soLuong > 0 ? soLuong : MAX_SIZE;
	_sinhVien = new SINHVIEN[_iSoLuongSinhVien];
	_iSiSoSinhVien = 0;
}
bool LOPSINHVIEN::isFull() {
	if (_iSiSoSinhVien == _iSoLuongSinhVien) {
		return true;
	}
	else {
		return false;
	}
}
void LOPSINHVIEN::add(SINHVIEN data) {
	if (!isFull()) {
		_sinhVien[_iSiSoSinhVien] = data;
		_iSiSoSinhVien++;
	}
	else {
		cout << "LOP HOC DA FULL!" << endl;
	}

}
int LOPSINHVIEN::timSinhVien(string maSinhVien) {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		if (_sinhVien[i]._sMaSinhVien == maSinhVien) {
			return i;
		}
	}
	return -1;
}
int LOPSINHVIEN::timSinhVienNhiPhan(string hoTen) {
	int first = 0;
	int last = _iSiSoSinhVien - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (_sinhVien[mid]._sHoTen < hoTen) {
			first = mid + 1;
		}
		else if (_sinhVien[mid]._sHoTen > hoTen) {
			last = mid - 1;
		}
		else if (_sinhVien[mid]._sHoTen == hoTen) {
			return mid;
		}
	}
	return -1;
}
void LOPSINHVIEN::display() {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		_sinhVien[i].display();
	}
}
void LOPSINHVIEN::suaHoTen(int pos, string hoTen) {
	if (pos >= 0 && pos < _iSiSoSinhVien) {
		_sinhVien[pos].suaHoTen(hoTen);
	}

}
void LOPSINHVIEN::insertionSort() {
	int pos;
	SINHVIEN x;
	for (int i = 1; i < _iSiSoSinhVien; i++) {
		x = _sinhVien[i];
		for (pos = i; pos > 0 &&  _sinhVien[pos]._sHoTen > _sinhVien[pos-1]._sHoTen; pos--) {
			swap(_sinhVien[pos], _sinhVien[pos - 1]);
		}
		_sinhVien[pos] = x;

	}
}
void LOPSINHVIEN::selectionSort() {
	for (int i = 0; i < _iSiSoSinhVien - 1; i++) {
		int min = i;
		for (int j = i + 1; j < _iSiSoSinhVien; j++) {
			if (_sinhVien[j].diemTrungBinh() < _sinhVien[i].diemTrungBinh()) {
				min = j;
			}
		}
		if (min != i) {
			swap(_sinhVien[i], _sinhVien[min]);
		}
	}

}
void LOPSINHVIEN::removeAt(int x) {
	if (x != -1) {
		for (int i = x + 1; i < _iSiSoSinhVien; i++) {
			_sinhVien[i - 1] = _sinhVien[i];
		}
		_iSiSoSinhVien--;
	}
}
void LOPSINHVIEN::danhSachHocBong() {
	for (int i = 0; i < _iSiSoSinhVien; i++) {
		if (_sinhVien[i].datDieuKienHocBong()) {
			_sinhVien[i].display();
		}
	}
}
int main() {
	LOPSINHVIEN LOPCNTTCK47(40);
	
	SINHVIEN THINH(2);
	MONHOC OOP("2121COMP1017", "Lap trinh huong doi tuong", 3, 7.3);
	MONHOC LTNC("2121COMP1013", "Lap trinh nang cao", 3, 9.7);
	THINH.add("47.01.104.202", "Le Van Thinh", "22/10/2003");
	THINH.addMonHoc(OOP);
	THINH.addMonHoc(LTNC);
	LOPCNTTCK47.add(THINH);
	SINHVIEN TEO(2);
	MONHOC OOP2("2121COMP1017", "Lap trinh huong doi tuong", 3, 6);
	MONHOC LTNC2("2121COMP1013", "Lap trinh nang cao", 3, 7);
	TEO.add("47.01.104.203", "Le Van Teo", "23/01/2003");
	TEO.addMonHoc(OOP2);
	TEO.addMonHoc(LTNC2);
	LOPCNTTCK47.add(TEO);

	LOPCNTTCK47.display();
	cout << endl;
	/*
	//CAU b
	int iPosSinhVien = LOPCNTTCK47.timSinhVien("47.01.104.209");
	if (iPosSinhVien != -1) {
		LOPCNTTCK47.suaHoTen(iPosSinhVien, "Thinh Van Le");
	}
	LOPCNTTCK47.display();
	*/
	//Cau c
	LOPCNTTCK47.insertionSort();
	//Cau d
	/*
	int iPosSinhVien = LOPCNTTCK47.timSinhVienNhiPhan("Le Van Thinh");
	LOPCNTTCK47.removeAt(iPosSinhVien);
	cout << "LIST AFTTER REMOVE" << endl;
	LOPCNTTCK47.display();
	*/
	//Cau e
	LOPCNTTCK47.selectionSort();
	cout << "LIST AFTTER SELECTION SORT" << endl;
	LOPCNTTCK47.display();
	cout << endl;
	cout << "LIST DAT HOC BONG" << endl;
	LOPCNTTCK47.danhSachHocBong();


	


	return 0;
}