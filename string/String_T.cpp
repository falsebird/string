#pragma once
#pragma once
#include<iostream>
#include "String_T.h"


//自定义构造函数
template <class T>
String_T<T>::String_T(size_t capacity) {
	this->_size = 0;
	this->_capacity = capacity;
	this->_data = new T[_capacity];
}
// 复制构造函数
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
//----------------功能函数

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
	 //空间不够扩展空间
	 if (new_capacity > this->_capacity)
	 {
		 //开空间
		 T* tmp = new T[2 * this->_capacity];

		 //拷贝
		 for (int i = 0; i < _size; i++)
		 {
			 tmp[i] = this->_data[i];
		 }
		 //释放原有空间
		 if (this->_data)
			 delete[] this->_data;
		 //指向新的空间
		 this->_data = tmp;
		 this->_capacity = 2 * this->_capacity;
		 //更新
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
	 //空间不够扩展空间
	 if (new_capacity > this.capacity())
	 {
		 //开空间
		 T* tmp = new T[2 * this.capacity()];
		 this->_capacity = 2 * this.capacity();
		 //拷贝
		 for (int i = 0; i <size(); i++)
		 {
			 tmp[i] = this->_data[i];
		 }
		 //释放原有空间
		 if (this->_data)
			 delete[] this->_data;
		 //指向新的空间
		 this->_data = tmp;
		 //更新
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

 //--------------------重载运算--------------------
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