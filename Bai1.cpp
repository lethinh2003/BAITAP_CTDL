#include <iostream>
#define MAX_SIZE 10;
using namespace std;

template <class DataType>
class ArrayList {
	DataType* _item;
	int _iSize;
	int _iCapacity;
public:
	ArrayList();
	ArrayList(int maxSize);
	~ArrayList();
	bool isFull();
	void add(DataType data);
	void display();
	int linearSearch(DataType x);
	void removeAt(int index);
	void removeElement(DataType x);
};
template <class DataType>
ArrayList<DataType>::ArrayList() {
	_iCapacity = MAX_SIZE;
	_item = new DataType[_iCapacity];
	_iSize = 0;
}
template <class DataType>
ArrayList<DataType>::ArrayList(int maxSize) {
	_iCapacity = maxSize > 0 ? maxSize : MAX_SIZE;
	_item = new DataType[_iCapacity];
	_iSize = 0;
}
template <class DataType>
ArrayList<DataType>::~ArrayList() {
	delete[] _item;
} 
template <class DataType>
bool ArrayList<DataType>::isFull() {
	if (_iSize == _iCapacity) {
		return true;
	}
	else {
		return false;
	}
}
template <class DataType>
void ArrayList<DataType>::add(DataType data) {
	if (!isFull()) {
		_item[_iSize] = data;
		_iSize++;
	}
	else {
		cout << "LIST FULL" << endl;
	}
}
template <class DataType>
void ArrayList<DataType>::display() {
	for (int i = 0; i < _iSize; i++) {
		cout << _item[i] << " ";
	}
}
template <class DataType>
int ArrayList<DataType>::linearSearch(DataType x) {
	for (int i = 0; i < _iSize; i++) {
		if (_item[i] == x) {
			return i;
		}
	}
	return -1;
}
template <class DataType>
void ArrayList<DataType>::removeAt(int index) {
	if (index >= 0 && index < _iSize) {
		for (int i = index + 1; i < _iSize; i++) {
			_item[i - 1] = _item[i];
		
		}
		_iSize--;
	}
}
template <class DataType>
void ArrayList<DataType>::removeElement(DataType x) {
	int iResultSearch = linearSearch(x);
	for (int i = 0; i < _iSize; i++) {
		while (iResultSearch != -1) {
			removeAt(iResultSearch);
			iResultSearch = linearSearch(x);
		}
	}
}
int main() {
	int iN;
	cout << "NHAP SO LUONG PHAN TU:" << endl;
	cin >> iN;
	ArrayList<int> ListNumbers(iN);
	int iX;
	while (cin >> iX) {
		ListNumbers.add(iX);
	}
	ListNumbers.display();
	int iValueSearch = 2;
	ListNumbers.removeElement(iValueSearch);
	cout << endl;
	ListNumbers.display();

	return 0;
}