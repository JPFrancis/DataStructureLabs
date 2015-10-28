#ifndef ADD_MYLIST
#define ADD_MYLIST
#include<iostream>

using namespace std;

template<typename T> class myList{

	private:
 		int size_;
 		T *data_;
 		int MAX_LIST_SIZE;
 
	public:
		myList();
//		~myList(){delete[] string;};
		void push_back(T input);
		int size();
		int at(T input);
		void PrintList();
		bool remove(T val);
		T pop(int location);
};

template <typename T> myList<T>::myList()
{
	data_=new T[10];
	size_=0;
	MAX_LIST_SIZE=10;
}

template <typename T> void myList<T>::push_back(T input)
{
	if(size_==MAX_LIST_SIZE)
	{
		T *newdata;
		newdata = new T[size_*2];
		for (int i; i<size_; i++)
		{
			newdata[i]=data_[i];
		}
		delete[] data_;
		data_=newdata;
		MAX_LIST_SIZE*=2;
	}
	data_[size_]=input;
	size_++;
}

template<typename T> int myList<T>::size(){
	return size_;
}

template <typename T> int myList<T>::at(T input)
{
	for(int i=0; i<size_; i++)
	{
		if(data_[i]==input)
			return i;
	}
	
	cout<<"Value not found\n\n";
	return -99;
}

template <typename T> void myList<T>::PrintList()
{
for(int i=0; i<size_; i++)
{
cout<<data_[i]<<" ";
}
cout<<endl;
}

template <typename T> bool myList<T>::remove(T val)
{
	int location;
	at(val)=location;
	if(location!=-99)
	{
		for(int i=location; i<size_; i++)
		{
			data_[i]=data_[i+1];
		}
		size_--;
		return true;
	}
	else
		return false;
}

template <typename T> T myList<T>::pop(int location)
{
	T temp=data_[location];
	if(location<size_&&location>0)
	{
		for(int i=location; i<size_; i++)
		{
			data_[i]=data_[i+1];
		}
		size_--;
		return temp;
	}

	else
	{
		cout<<"invlaid location. Value not removed.\n\n";
		return temp;
	}
}
#endif

