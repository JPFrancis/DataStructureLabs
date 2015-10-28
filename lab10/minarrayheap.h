#ifndef MINARRAYHEAP_H
#define MINARRAYHEAP_H

#include "minheap.h"
#include <vector>
#include <iostream>

using namespace std;
/**
 * MinArrayHeap implements a min-heap using a vector as 
 * its container of data
 *
 * \note Location 0 of the heap array/vector will be empty
 *  
 */
template <typename T>
class MinArrayHeap : public MinHeap<T>
{ public:
   MinArrayHeap();
   MinArrayHeap(int *data, int size);
   void push(const T& item);
   T& top();
   void pop();
   int size() const;
   bool empty() const;
   bool decreaseKey(const T& val, const T& newval);
   
   
   void printHeap() const;
 private: // member functions
   				/// heapify is called rebuildHeap() in the textbook
   void heapify(int loc);
 private: // data members
   std::vector<T> items_;
};

template <typename T>
MinArrayHeap<T>::MinArrayHeap() : items_(1)
{

}

/** items_ is initialized with the values in the data array
 * \pre data[0] will serve as the empty value, so don't
 *             expect that value to be part of the heap
 */
template <typename T>
MinArrayHeap<T>::MinArrayHeap(int *data, int size) : 
       items_(data, data+size)
{ 
	for(int index=items_.size()-1 /2; index > 0; index--)
	{
		//cout<<endl<<items_[index]<<" about to be heapified\n\n";
		heapify(index);
	}
  							//***************** Complete me ***********************
 							// Implement code that will convert the values in the items_
  							// array/vector to a valid heap using calls to heapify()
  							// Take care not to try to heapify the value at location 0
}

template<typename T>
bool MinArrayHeap<T>::decreaseKey(const T& val, const T& newval)
{
	bool flag=false;
	for(int i=1; i<=size(); i++)
	{
		if(items_[i]==val)
		{
			items_[i]=newval;
			flag=true;
			 for(int t=i; ((t)/2) > 0; t-=((t)/2))
  			 {
  				//printHeap();
  				//cout<<"t = "<<t<<endl;
 	 			if(items_[t] < items_[(t)/2] && t!=2)
  				{	
  					//cout<<"\nEnter switch\n";
  					int placeholder = items_[t];
  					items_[t]=items_[(t)/2];
  					items_[(t)/2]=placeholder;
  				}
  				else
  				{
  					if(items_[2] < items_[1])
  					{
  						//cout<<"\nEnter Switch\n";
  						int placeholder = items_[2];
  						items_[2]=items_[1];
 						items_[1]=placeholder;
  					}
  				}
  				if(t%2==1&&t!=1)
  					t--;
  			}
			
		}
	}
	return flag;
}

template <typename T>
void MinArrayHeap<T>::push(const T& item)
{
  // New data always gets put at the next empty location
  // in the heap (which is always the end of the array)
  // and then we'll move it to its correct heap locaiton
  items_.push_back(item);
  //printHeap();
  //cout<<items_[size()]<<" Newly added"<<endl;
  for(int i=size(); ((i)/2) > 0; i-=((i)/2))
  {
  	//printHeap();
  	//cout<<"I = "<<i<<endl;
  	if(items_[i] < items_[(i)/2] && i!=2)
  	{	
  		//cout<<"\nEnter switch\n";
  		int placeholder = items_[i];
  		items_[i]=items_[(i)/2];
  		items_[(i)/2]=placeholder;
  	}
  	else
  	{
  		if(items_[2] < items_[1])
  		{
  			//cout<<"\nEnter Switch\n";
  			int placeholder = items_[2];
  			items_[2]=items_[1];
  			items_[1]=placeholder;
  		}
  	}
  	if(i%2==1&&i!=1)
  		i--;
  }
  //printHeap();
  //cout<<endl;
  //***************** Complete me ***********************
  // Now move it into the right location to make a valid heap
}

template <typename T>
T& MinArrayHeap<T>::top()
{
  return items_[1];
}

template <typename T>
void MinArrayHeap<T>::pop()
{
  items_[1] = items_.back();
  items_.pop_back();
  heapify(1);
}

template <typename T>
int MinArrayHeap<T>::size() const
{
  return items_.size()-1;
}

template <typename T>
bool MinArrayHeap<T>::empty() const
{
  return (items_.size()-1) == 0;
}

template <typename T>
void MinArrayHeap<T>::heapify(int loc)
{
	if(2*loc <= size())
	{
		int smallerChildIndex = 2*loc;
		//cout<<"Smaller child: "<<items_[smallerChildIndex]<<endl;
		//cout<<"Loc: "<<items_[loc]<<endl;
		if(smallerChildIndex+1<=size())
		{
			int rightChildIndex = smallerChildIndex+1;	
			if(items_[rightChildIndex] < items_[smallerChildIndex])
				smallerChildIndex = rightChildIndex;
		}
			
		if(items_[loc] > items_[smallerChildIndex])
		{
			//cout<<"SWITCH\n\n";
			int placeholder = items_[loc];
			items_[loc] = items_[smallerChildIndex];
			items_[smallerChildIndex] = placeholder;
			//printHeap();
			heapify(smallerChildIndex);	
		}
	}
}

template <typename T>
void MinArrayHeap<T>::printHeap() const
{
  std::cout << "Heap array contents are: " << std::endl;
  for(unsigned int i=1; i < items_.size(); i++){
    std::cout << i << ": " << items_[i] << std::endl;
  }

}



#endif
