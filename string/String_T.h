#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class T>
class String_T {
	//重载输入输出
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

	//定义一个迭代器
public:
	typedef T* iterator;

public:
	//初始化
	String_T<T>() {

	}

	//初始化容积
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

	//析构
	~String_T<T>() {
		if (_data) {
			delete[] _data;
			_data = nullptr;
		}
	}

	//基础功能

	//容积操作
	size_t size() const { return _size; };
	size_t capacity() const { return _capacity; };

	//迭代器
	iterator begin() { return &_data[0]; };
	iterator end() { return &_data[this->_size]; };
	void clear() {
		//删除内容
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


	//尾插 
	void push_back(const T val) {
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
	// 尾删
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

	

	//删除插入
	//删除指定元素
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
	T* insert(T* pos, T val);//指定位置插入元素

	


	//赋值
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
