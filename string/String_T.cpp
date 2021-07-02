#pragma once
#pragma once
#include<iostream>
#include "String_T.h"


//�Զ��幹�캯��
template <class T>
String_T<T>::String_T(size_t capacity) {
	this->_size = 0;
	this->_capacity = capacity;
	this->_data = new T[_capacity];
}
// ���ƹ��캯��
template <class T>
String_T<T>::String_T(const String_T& obj) {
	this->_size = obj.size();
	this->_capacity = obj.size();
	this->_data = new T[this.capacity()];
	for (size_t i = 0; i < obj._size; i++) {
		_data[i] = obj._data[i];
	}
}

template <class T>
String_T<T>::~String_T() {
	if (_data) {
		delete[] _data;
		_data = nullptr;
	}
}
//----------------���ܺ���

 template <class T>
 void String_T<T>::clear() {
	 if (_data) {
		 delete[] _data;
		 this->_size = 0;
		 this->_capacity = 0;
		 this->_data = nullptr;
	 }
 }
 template <class T>
 T& String_T<T>::at(const size_t& index) {
	 if (empty() || index > this.size())
		 return (T)NULL;
	 return this-> _data[index];
 }

 template <class T>
 void String_T<T>::push_back(const T val) {
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

 template <class T>
 T String_T<T>::pop_back() {
	 if (!empty()) {
		 int nsize = this->size();
		 T v = this->_data[nsize - 1];
		 this->_data[nsize - 1] = NULL;
		 this->_size = nsize - 1;
		 return v;
	 }
	 else {
		 return NULL;
	 }
 }
 template <class T>
 T* String_T<T>::erase(T* pos) {
	 T* _pos = pos;
	 if (pos >= begin() && pos < end()) {
		 while (_pos + 1 != end()) {
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

 template <class T>
 T* String_T<T>::insert(T* pos, T val) {
	 int new_capacity = _size + 1;
	 //�ռ䲻����չ�ռ�
	 if (new_capacity > this.capacity())
	 {
		 //���ռ�
		 T* tmp = new T[2 * this.capacity()];
		 this->_capacity = 2 * this.capacity();
		 //����
		 for (int i = 0; i <size(); i++)
		 {
			 tmp[i] = this->_data[i];
		 }
		 //�ͷ�ԭ�пռ�
		 if (this->_data)
			 delete[] this->_data;
		 //ָ���µĿռ�
		 this->_data = tmp;
		 //����
	 }

	 T* p = end();

	 while (p != pos)
	 {
		 cout << "p:" << *p << endl;
		 *p = *(p - 1);
		 --p;
	 }
	 *p = val;
	 ++_size;
	 return *this;
 }

 //--------------------��������--------------------
 template <class T>
 String_T<T>& String_T<T>::operator=(const String_T<T>& obj) {
	 if (_data != nullptr) {
		 delete[] _data;
		 _data = NULL;
		 _size = 0;
	 }
	 _size = obj.size();
	 _data = new T[_size];
	 for (size_t i = 0; i < this.size(); i++) {
		 _data[i] = obj._data[i];
	 }
	 return *this;
 }

 template <class T>
 ostream& operator<<(ostream& out, const String_T<T>& st)
 {

	 for (int i = 0; i < st._size; i++)
	 {
		 out << st._data[i];
	 }
	 return out;
 }