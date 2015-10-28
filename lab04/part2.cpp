#include<iostream>
#include<string>
#include"myList.h"
#include<sstream>

using namespace std;

int main(){

myList<int> intList;
myList<string> stringList;
int tempInt;
string tempString;

bool flag;

char choice;

cout<<"Would you like to create a list ints or strings? Enter i for int or s for string:\n";
cin>>choice;

if(cin.fail()||(choice!='s'&&choice!='i'))
{
	cout<<"invalid entry. program terminated\n\n";
	return 0;
}

else if(choice=='i')
{

	do
	{
	cout<<"please enter a value to add to your list or enter 'done' to exit:\n";
	cin>>tempInt;
	
	if(!cin.fail()){
		intList.push_back(tempInt);	
		flag=true;
		}
	else 
		flag=false;
	}

	while(flag);
}

else if(choice=='s')
{

	do
	{
	cout<<"Please enter a value to add to your list or enter 'done' to exit:\n";
	cin>>tempString;

	if(tempString!="done"){
		stringList.push_back(tempString);	
		flag=true;
		}
	else
		flag=false;
	}

	while(flag);
}

intList[0]=9;
intList.PrintList();
stringList.PrintList();

cin.clear();
cin.ignore(1000,'\n');



char choice2;

while(1)
{

cout<<"If you would like to edit the list, enter 'v' to remove a certain value or 'l' to remove the value at a certain location. Otherwise enter'0':\n";
cin>>choice2;

if(cin.fail()||(choice2!='v'&&choice2!='l'||choice2==0))
	return 0;

else if(choice2=='v')
{
	
	cout<<"Enter a value you would like to remove:\n";
	if(choice=='s')
	{
	string temp;
	cin>>temp;
		try
		{
			stringList.remove(temp);
		}
		catch(invalid_argument &ex)
		{
			cout<<"Value does not exist in the string list\n\n";
		}
	}
	else if(choice=='i')
	{
	int temp;
	cin>>temp;
		try
		{
			intList.remove(temp);
		}
		catch(invalid_argument &ex)
		{
			cout<<"Value does not exist in int list";
		}
	}
	cout<<endl;
}

else if(choice2=='l')
{
	int location;
	cout<<"Enter the location that you would like to erase:\n";
	cin>>location;
	if(choice=='s')
	{
		try
		{
			stringList.pop(location);
		}
		catch(out_of_range &ex)
		{
			cout<<"Location is out of the list's range.\n\n";
		}
	}
	else if(choice=='i')
	{
		try
		{
			intList.pop(location);
		}
		catch(out_of_range &ex)
		{
			cout<<"Location is out of the list's range.\n\n";
		}
	}
}
	intList.PrintList();
	stringList.PrintList();
	cout<<endl;
}
	return 0;

}

