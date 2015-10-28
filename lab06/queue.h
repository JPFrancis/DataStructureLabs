#include"llist.h"
#include<iostream>

using namespace std;

template <typename T> 
class Queue : public LList<T>
{
	public:
	
	Queue();
	~Queue();
	int size() const;
	void push_back(T& value);
	void pop_front();
	T& front() const;
	T& back();
	bool empty() const;
};

template<typename T> Queue<T>::Queue() : LList<T>()
{
	//this->LList<T>();
}

template<typename T> Queue<T>::~Queue()
{
	LList<T>::clear();
}

template<typename T> int Queue<T>::size() const
{
	return size();
}

template<typename T> void Queue<T>::push_back(T& value)
{
	LList<T>::push_back(value);
}

template<typename T> void Queue<T>::pop_front()
{
	if(!empty())
		LList<T>::pop_front();
	else
		cout<<"List is empty. Operation cannot be performed.\n";
}	
template<typename T> T& Queue<T>::front() const
{
	return LList<T>::peek_front(); 
}

template<typename T> T& Queue<T>::back()
{
return at(size());
}

template<typename T> bool Queue<T>::empty() const
{
return LList<T>::empty();
}
