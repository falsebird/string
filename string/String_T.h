#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class T>
class String_T {
	//�����������
	friend ostream& operator<<(ostream& out, const String_T<T>& st);
	friend istream& operator>>(istream& in, const String_T& st);
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
	String_T<T>(size_t size) {
		this->_size = size;
		this->_capacity = size;
		_data = new T[_capacity];
	}

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
	size_t size() const { return _size; };
	size_t capacity() const { return _capacity; };
	void clear() {
		//ɾ������
		if (_data){
			delete[] _data;
			this->_size = 0;
			this->_capacity = 0;
			this->_data[0] = '\0'
		}
		
	}
	bool empty() {
		//
		return this->_size == 0;
	}
	T& at(size_t index);

	//β�� βɾ
	void push_back(const T &val) {
		int new_capacity = this->_size + val->_size;
		if (new_capacity > this-> _capacity)
		{
			
			if (new_capacity > _capacity)
			{
				//���ռ�
				char* tmp = new char[new_capacity + 1];
				//����
				for (int i = 0; i < _size; i++)
				{
					tmp[i] = _str[i];
				}
				//�ͷ�ԭ�пռ�
				delete[] _str;
				//ָ���µĿռ�
				_str = tmp;
				//����
				_capacity = new_capacity;
				_size = new_capacity;
	

			}
			
		}
		strcpy(val + _size, val);
		_size += strlen(str);
	}
	void pop_back();

	//������
	iterator begin();
	iterator end();

	//ɾ������
	T* erase(T* pos);//ɾ��ָ��Ԫ��
	T* insert(T* pos, T val);//ָ��λ�ò���Ԫ��

	//�ݻ�����
	size_t size()const;
	size_t capacity()const;

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
