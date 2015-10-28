#ifndef LLIST_H
#define LLIST_H

#include<stdio.h>
#include<iostream>

using namespace std;

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void push_back(T& new_val);
  void pop_front();
  T& peek_front() const;
  T& at(int loc) const;
  void remove(int loc);
  void clear();
 private:
  Item<T> *getNodeAt(int loc) const;

 private:
  Item<T>* head_;
  int size_;
};

// Write the constructor here
template <typename T>
LList<T>::LList() 
{
	size_=0;
}

template <typename T>
LList<T>::~LList()
{
  clear();
}

template <typename T>
bool LList<T>::empty() const
{
return size_==0;
}

template <typename T>
int LList<T>::size() const
{
return size_;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
		Item<T>* itemSifter=head_;
		
		for(int i=0; i<loc-1; i++)
		{
			itemSifter = itemSifter->next;
		}
		
		return itemSifter;	
}

template <typename T>
void LList<T>::push_back(T& new_val)
{
	if(empty())
	{
		cout<<"List is empty\n\n";
		Item<T> *nodePtr;
		nodePtr= new Item<T>;
		head_=nodePtr;
		
		
		head_->val=new_val;
		head_->next=NULL;
		size_++;
	}
	else
	{
		Item<T>* itemSifter=head_;
		
		for(int i=0; i<size_-1; i++)
		{
			itemSifter = itemSifter->next;
		}
		
		Item<T> *nodePtr;
		nodePtr= new Item<T>;
		itemSifter->next=nodePtr;
		itemSifter = itemSifter->next;
		
		itemSifter->val=new_val;
		itemSifter->next=NULL;
		size_++;	
	}
} 

template <typename T> void LList<T>::pop_front()
{
		head_=head_->next;
		size_--;
}

template <typename T>
T& LList<T>::peek_front() const
{
	return head_->val;

}

template <typename T>
void LList<T>::remove(int loc)
{
	size_--;
}

template <typename T>
T& LList<T>::at(int loc) const
{
	Item<T>* tempItem=getNodeAt(loc);
	return tempItem->val;
}


template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL)
  {
    Item<T> *temp = head_->next;
    delete head_;
    head_= temp;
  }
}


#endif
