#include<iostream>
#include<string>

using namespace std;

class List{

	private:
 		int size_;
 		string* data_;
 		int MAX_LIST_SIZE;
 
	public:
		List();
		~List(){delete[] string};
		void push_back(string input);
		int size();
		int at(string input);
};

List::List()
{
	data_=new int[10];
	size_=0;
	MAX_LIST_SIZE=10;
}

void List::push_back(string input)
{
	if(size_==MAX_LIST_SIZE)
	{
		string* newdata = new int(size_*2);
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

int List::size(){
	return size_;
}

int List::at(string input)
{
	for(int i=0; i<size_; i++)
	{
		if(data_[i]==input)
			return i;
	}
	
	cout<<"Value not found\n\n";
	return -99;
}

class User{

private:
	string name;
	int age;
	List friends;
public:
	void setName(string input);
	void setAge(int age);
	void setFriends(List friends);
	bool at(string input);
};

void User::setName(string input)
{
name=input;
}

void User::setAge(int input)
{
age=input;
}

void User::setFriends(List input)
{
push_back(input);
}

bool User::at(string input)
{
	if(input==name)
		return true;
	else
		return false;
}


