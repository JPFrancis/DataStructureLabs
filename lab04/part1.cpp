#include<iostream>
#include<string>
#include"myList.h"

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

intList.PrintList();
stringList.PrintList();

}

