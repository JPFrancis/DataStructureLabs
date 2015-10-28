#include <iostream>
#include "llist.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
  Stack<int> myStack;
  Queue<int> myQueue;
 
 	int choice;
 	bool flag=true;
 do
 {
 	cout<<"Select the operation you would like to perform:\n\n";
 	cout<<"1. Push to stack\n";
 	cout<<"2. Print and pop top of stack\n";
 	cout<<"3. Push_back to Queue\n";
 	cout<<"4. Print and pop front of Queue\n";
 	cout<<"5. Quit\n\n";
 	
 	cin>>choice;
 	
 	if(choice==1)
 	{
 		
 		int input;
 		cout<<"Enter the integer you would like to add:\n";
 		cin>>input;
 		myStack.push(input);
 	}	
 		
 	else if(choice==2)
 	{
 		if(!myStack.empty())
 		{
 		int tempInt=myStack.top();
 		cout<<tempInt<<endl;
 		myStack.pop();
 		}
 		else
 			cout<<"List is empty. Function could not be performed.\n\n";
 	}
 	else if(choice==3)
 	{
 		int input;
 		cout<<"Enter the integer you would like to add:\n";
 		cin>>input;
 		myQueue.push_back(input);
 	}
 	else if(choice==4)
 	{
 		if(!myQueue.empty())
 		{
 		int tempInt=myQueue.front();
 		cout<<tempInt<<endl;
 		myQueue.pop_front();
 		}
 		else
 			cout<<"List is empty. Function could not be performed.\n\n";
 	}
 	else if(choice==5)
 		break;
 	else
 		cout<<"Invalid choice. Please try again.\n\n";
 }
 while(flag);
  return 0;
}
