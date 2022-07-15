#include <iostream>
#define MAX_SIZE 100;
using namespace std;
class ThuVien;
class Sach {
	friend ThuVien;
	string _sMaSach, _sTuaSach;
	int _iNamXuatBan, _iGia;
public:
	Sach();
	~Sach();
	void display();
	void add();

};
Sach::Sach() {

}
Sach::~Sach() {

}
void Sach::add() {
	cin >> _sMaSach >> _sTuaSach >> _iNamXuatBan >> _iGia;
}
void Sach::display() {
	cout << "{" << _sMaSach << "," << _sTuaSach << "," << _iNamXuatBan << "," << _iGia << "}";
}

class ThuVien {
	Sach* _sach;
	int _iSucChuaSach, _iSoLuongSach;
public:
	ThuVien();
	~ThuVien();
	void add(Sach data);
	void display();
	int timKiemTuaSach(string x);
	int timKiemMaSach(string x);
	void suaGiaSauTimKiem(int x, int y);
	void removeSach(int x);
	void sapXepMaSach();
	void sapXepNamXuatBan();
	void sapXepTuaSach();
	void sapXepGia(int left, int right);
};
ThuVien::ThuVien() {
	_iSucChuaSach = MAX_SIZE;
	_sach = new Sach[_iSucChuaSach];
	_iSoLuongSach = 0;
}
ThuVien::~ThuVien() {
	delete[] _sach;
}
void ThuVien::add(Sach data) {
	_sach[_iSoLuongSach++] = data;
}
void ThuVien::display() {
	for (int i = 0; i < _iSoLuongSach; i++) {
		_sach[i].display();
		cout << endl;
	}
}
int ThuVien::timKiemTuaSach(string x) {
	for (int i = 0; i < _iSoLuongSach; i++) {
		if (x == _sach[i]._sTuaSach) {
			return i;
		}
	}
	return -1;
}
int ThuVien::timKiemMaSach(string x) {
	int left = 0;
	int right = _iSoLuongSach - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (_sach[mid]._sMaSach == x) {
			return mid;
		}
		else if (_sach[mid]._sMaSach > x) {
			right = mid - 1;
		}
		else if (_sach[mid]._sMaSach < x) {
			left = mid + 1;
		}
	}
	return -1;
}
void ThuVien::suaGiaSauTimKiem(int x, int y) {
	if (x == -1) {
		return;
	}
	_sach[x]._iGia = y;
}
void ThuVien::removeSach(int x) {
	if (x == -1) {
		return;
	}
	for (int i = x; i < _iSoLuongSach; i++) {
		_sach[i] = _sach[i + 1];
	}
	_iSoLuongSach--;
}

void ThuVien::sapXepMaSach() {
	for (int i = 0; i < _iSoLuongSach - 1; i++) {
		string sachMin = _sach[i]._sMaSach;
		int min = i;
		for (int j = i + 1; j < _iSoLuongSach; j++) {
			if (_sach[j]._sMaSach < sachMin) {
				sachMin = _sach[j]._sMaSach;
				min = j;
			}
		}
		if (min != i) {
			swap(_sach[min], _sach[i]);
		}
	}

}
void ThuVien::sapXepNamXuatBan() {
	for (int i = 1; i < _iSoLuongSach; i++) {
		Sach temp = _sach[i];
		int j;
		for (j = i; j > 0 && _sach[j-1]._iNamXuatBan < temp._iNamXuatBan; j--) {
			_sach[j] = _sach[j - 1];
		}
		_sach[j] = temp;

	}
}
void ThuVien::sapXepTuaSach() {
	for (int i = 0; i < _iSoLuongSach - 1; i++) {
		for (int j = _iSoLuongSach - 1; j > i; j--) {
			if (_sach[j]._sTuaSach < _sach[j - 1]._sTuaSach) {
				swap(_sach[j], _sach[j - 1]);
			}
		}
	}
}
void ThuVien::sapXepGia(int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left;
	int j = right;
	int giaX = _sach[(left + right) / 2]._iGia;
	while (i < j) {
		while (_sach[i]._iGia > giaX) {
			i++;
		}
		while (_sach[j]._iGia < giaX) {
			j--;
		}
		if (i <= j) {
			swap(_sach[i], _sach[j]);
			i++;
			j--;
		}
	}
	sapXepGia(left, j);
	sapXepGia(i, right);
}
int main() {
	ThuVien DHSP;
	int sl;
	cin >> sl;
	for (int i = 0; i < sl; i++) {
		Sach nhap;
		nhap.add();
		DHSP.add(nhap);
	}

	//Hien thi
	DHSP.display();
	//Tim kiem
	cout << "Nhap tua sach can tim va tien can thay doi:" << endl;
	string strTuaSachSearch;
	int iGiaThayDoi;
	cin >> strTuaSachSearch;
	cin >> iGiaThayDoi;
	DHSP.suaGiaSauTimKiem(DHSP.timKiemTuaSach(strTuaSachSearch), iGiaThayDoi);
	DHSP.display();
	cout << "Nhap ma sach can tim de xoa:" << endl;
	string strMaSachSearch;
	cin >> strMaSachSearch;
	DHSP.removeSach(DHSP.timKiemMaSach(strMaSachSearch));
	DHSP.display();
	cout << "XEP THEO MA SACH TANG DAN" << endl;
	DHSP.sapXepMaSach();
	DHSP.display();
	cout << "XEP THEO NAM XUAT BAN GIAM DAN" << endl;
	DHSP.sapXepNamXuatBan();
	DHSP.display();
	cout << "XEP THEO TUA SACH TANG DAN" << endl;
	DHSP.sapXepTuaSach();
	DHSP.display();
	cout << "XEP THEO GIA GIAM DAN" << endl;
	DHSP.sapXepGia(0, sl-1);
	DHSP.display();
	return 0;
}
