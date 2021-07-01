#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class T>
class String_T {
	//�����������
	friend ostream& operator<<(ostream& out, const String_T<T>& st)
	{

		for (int i = 0; i < st._size; i++)
		{
			out << st._data[i];
		}
		return out;
	}
	//friend istream& operator>>(istream& in, const String_T& st);
public:
	T* _data;
	size_t _capacity;
	size_t _size;

	//����һ��������
public:
	typedef T* iterator;

public:
	//��ʼ��
	String_T<T>() {

	}

	//��ʼ���ݻ�
	String_T<T>(size_t capacity) {
		this->_size = 0;
		this->_capacity = capacity;
		this->_data = new T[_capacity];
	}
	//String_T<T>(const T *val){
	//	if (val) {
	//		this->_capacity = 10000;
	//		int len = sizeof(*val) / sizeof(val[0]);
	//		this->_size = len;
	//		this->_data = new T[_capacity];
	//		for (int i = 0; i < len; i++) {
	//			push_back(val[i]);
	//		}
	//	}
	//	else {
	//		this->_size = 0;
	//		this->_capacity = 10000;
	//		this->_data = new T[_capacity];
	//	}
	//	
	//}

	String_T<T>(const String_T& obj) {
		this->_size = obj._size;
		this->_capacity = obj._capacity;
		_data = new T[_capacity];
		for (size_t i = 0; i < obj._size; i++) {
			_data[i] = obj._data[i];
		}
	}

	//����
	~String_T<T>() {
		if (_data) {
			delete[] _data;
			_data = nullptr;
		}
	}

	//��������

	//�ݻ�����
	size_t size() const { return _size; };
	size_t capacity() const { return _capacity; };

	//������
	iterator begin() { return &_data[0]; };
	iterator end() { return &_data[this->_size]; };
	void clear() {
		//ɾ������
		if (_data){
			delete[] _data;
			this->_size = 0;
			this->_capacity = 0;
			this->_data = nullptr;
		}
		
	}
	bool empty() {
		//
		return this->_size == 0;
	}
	T& at(const size_t &index) {
		if (empty() || index > _capacity)
			return (T)NULL;
		return _data[index];
	}


	//β�� 
	void push_back(const T val) {
		int new_capacity = this->_size + 1;
		//�ռ䲻����չ�ռ�
		if (new_capacity > this->_capacity)
		{
			//���ռ�
			T* tmp = new T[2 * this->_capacity];

			//����
			for (int i = 0; i < _size; i++)
			{
				tmp[i] = this->_data[i];
			}
			//�ͷ�ԭ�пռ�
			if (this->_data)
				delete[] this->_data;
			//ָ���µĿռ�
			this->_data = tmp;
			this->_capacity = 2 * this->_capacity;
			//����
		}
			

		this->_data[new_capacity - 1] = val;
		this->_size = new_capacity;

	}
	// βɾ
	T pop_back() {
		if (!empty()) {
			int nsize = this->_size;
			T v = this->_data[nsize - 1];
			this->_data[nsize - 1] = NULL;
			this->_size = nsize - 1;
			return v;
		}
		else {
			return NULL;
		}
	}

	

	//ɾ������
	//ɾ��ָ��Ԫ��
	T* erase(T* pos) {
		T* _pos = pos;
		if (pos >= begin() && pos < end() ){
			while (_pos+1 != end()) {
				*_pos = *(_pos + 1);
				_pos++;
			}
			pop_back();
			return pos;
		}
		else {
			return end();
		}
	}
	T* insert(T* pos, T val);//ָ��λ�ò���Ԫ��

	


	//��ֵ
	String_T<T>& operator=(const String_T<T>& obj) {
		if (_data != nullptr) {
			delete[] _data;
			_data = NULL;
			_size = 0;
		}
		_size = obj._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			_data[i] = obj._data[i];
		}
		return *this;
	}

};
