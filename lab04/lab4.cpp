#include<iostream>
#include<string>
#include"myList.h"

using namespace std;

class User{

private:
	string name;
	int age;
	myList<string> friends;
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
		
		if(userList_[userLocation].FriendCheck(userFriend)&&user!=userFriend)
		{
			userList_[userLocation].setFriends(userFriend);
		}
		else
		{
			cout<<"Error. Either Friend already exists or User cannot be his own friend. Operation not carried out.\n";
		}
		userList_[userLocation].PrintUser();
		
		cout<<"Please enter a user's name followed by a friend's name or 'done' to finish:\n";
		cin>>user;
	}
	
}
