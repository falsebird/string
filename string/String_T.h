#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class T>
class String_T {
	//重载输入输出
	friend ostream& operator<<(ostream& out, const String_T<T>& st);
	friend istream& operator>>(istream& in, const String_T& st);
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

	//析构
	~String_T<T>() {
		if (_data) {
			delete[] _data;
			_data = nullptr;
		}
	}

	//基础功能
	size_t size() const { return _size; };
	size_t capacity() const { return _capacity; };
	void clear() {
		//删除内容
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

	//尾插 尾删
	void push_back(const T &val) {
		int new_capacity = this->_size + val->_size;
		if (new_capacity > this-> _capacity)
		{
			
			if (new_capacity > _capacity)
			{
				//开空间
				char* tmp = new char[new_capacity + 1];
				//拷贝
				for (int i = 0; i < _size; i++)
				{
					tmp[i] = _str[i];
				}
				//释放原有空间
				delete[] _str;
				//指向新的空间
				_str = tmp;
				//更新
				_capacity = new_capacity;
				_size = new_capacity;
	

			}
			
		}
		strcpy(val + _size, val);
		_size += strlen(str);
	}
	void pop_back();

	//迭代器
	iterator begin();
	iterator end();

	//删除插入
	T* erase(T* pos);//删除指定元素
	T* insert(T* pos, T val);//指定位置插入元素

	//容积操作
	size_t size()const;
	size_t capacity()const;

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
