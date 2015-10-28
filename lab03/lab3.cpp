#include<iostream>
#include<string>

using namespace std;

class List{

	private:
 		int size_;
 		string *data_;
 		int MAX_LIST_SIZE;
 
	public:
		List();
//		~List(){delete[] string;};
		void push_back(string input);
		int size();
		int at(string input);
		void PrintList();
};

List::List()
{
	data_=new string[10];
	size_=0;
	MAX_LIST_SIZE=10;
}

void List::push_back(string input)
{
	if(size_==MAX_LIST_SIZE)
	{
		string *newdata;
		newdata = new string[size_*2];
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

void List::PrintList()
{
for(int i=0; i<size_; i++)
{
cout<<data_[i]<<" ";
}
cout<<endl;
}

class User{

private:
	string name;
	int age;
	List friends;
public:
	void setName(string input);
	void setAge(int input);
	void setFriends(string input);
	void PrintUser();
	bool at(string input);
	bool FriendCheck(string input);
};

void User::setName(string input)
{
name=input;
}

bool User::at(string input)
{
if(name==input)
	return true;
else
	return false;
}

void User::setAge(int input)
{
age=input;
}

void User::setFriends(string input)
{
friends.push_back(input);
}


void User::PrintUser()
{
	
	cout<<"\nUser name: "<<name<<"\nUser age: "<<age<<endl<<"User friends: ";
	friends.PrintList();
	cout<<endl;
}

bool User::FriendCheck(string input)
{
if(friends.at(input)==-99)
	return true;

else
	return false;
}

int main()
{
	User *userList_;

	userList_=new User[100];
	int size_=0;
	int MAX_LIST_SIZE=100;

	int userAge;
	string userName;

	cout<<"Please enter a user's name followed by their age or 'done' to finish:(ex.Joe 32)\n";
	cin>>userName;
	
	
	
	while(userName!="done")
	{
		cin>>userAge;

		bool flag=false;
		
		for(int i=0;i<size_; i++)
		{
		if(userList_[i].at(userName))
			flag=true;
		}
		
		if(flag)
			cout<<"User already exists. Operation not carried out.\n";
			
		else
		{	
			if(size_==MAX_LIST_SIZE)
			{
				User *newdata;
				newdata=new User[size_*2];
				for (int i; i<size_; i++)
				{
					newdata[i]=userList_[i];
				}
				delete[] userList_;
				userList_=newdata;
				MAX_LIST_SIZE*=2;
			}

			userList_[size_].setName(userName);
			userList_[size_].setAge(userAge);
		
			userList_[size_].PrintUser();
			size_++;
		}
		
		cout<<"Please enter a user's name followed by their age or 'done' to finish:(ex.Joe 32)\n";
		cin>>userName;
	}

	string user, userFriend;
	int userLocation=-1;
	cout<<"Please enter a user's name followed by a friend's name or 'done' to finish:\n";
	cin>>user;
	
	while(user!="done")
	{
		cin>>userFriend;
		for(int i=0; i<size_; i++)
		{
			if(userList_[i].at(user))
				userLocation=i;
		}
		
		if(userLocation==-1)
		{
			cout<<"User not found.\n";
			break;
		}
		
		if(userList_[userLocation].FriendCheck(userFriend))
		{
			userList_[userLocation].setFriends(userFriend);
		}
		else
		{
			cout<<"Friend already exists. Operation not carried out.\n";
		}
		userList_[userLocation].PrintUser();
		
		cout<<"Please enter a user's name followed by a friend's name or 'done' to finish:\n";
		cin>>user;
	}
	
}
