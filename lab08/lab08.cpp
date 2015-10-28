#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Item {
  int value;
  Item *next;
};

const int MAXSIZE = 50000;
int list[MAXSIZE];
int tempArray[MAXSIZE];
Item *head;

int arraySequentialSearch( int value ) {
  for ( int loc=0; loc<MAXSIZE; loc++ ) {
    if ( list[loc] == value ) {
      return loc;
    }
  }
  return -1;
}

Item *linkedSequentialSearch( int value ) {
  Item *current = head;

  while ( current != NULL ) {
    if ( current->value == value ) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

int arrayBinarySearch( int value ) {
  //An array-based binary search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  int first=0, last=MAXSIZE-1, mid;

  while ( first <= last ) {
    mid = (first + last) / 2;

    if ( list[mid] == value ) {
      //Found it
      return mid;
    }

    //Haven't found it, yet. Determine which sublist to continue with and
    //adjust first or last
    if ( list[mid] > value ) {
      //Go left, so adjust last to be mid-1
      last = mid - 1;
    } else {
      //Go right, so adjust first to be mid+1
      first = mid + 1;
    }
  }

  return -1;
}


void populateLinkedList() {
  
  Item *temp, *last, *poop;
  
  srand(time(NULL));
  
  int randnum = rand() % 1000000;	
  
  head = new Item;
  head->value = randnum;
  head->next = NULL;
  last = head;
 
  for ( int i=0; i<MAXSIZE; i++ ) {
  
    temp=new Item;
    poop=head;
    
    temp->value = rand() % 1000000;	
 
    if(temp->value < head->value)
    {
    	temp->next= head;
    	head=temp;
    }
    else
    {	
    	while(poop->next!=NULL && temp->value > poop->next->value)
    	{
    		poop=poop->next;
    	}
    	
    	if(temp->next==NULL)
    	{
    		poop->next=temp;
    		last->next=temp;
    		last=temp;
    	}
    	else
    	{
    		temp->next = poop->next;
    		poop->next=temp;
    	}
    }
    }
   
  Item *iterator;
  iterator=new Item;
  iterator=head;
  cout<<endl;
 while(iterator->next!=NULL)
  {
  	if(iterator->value > iterator->next->value)
  	cout<<"PROBLEM\n";
  	
  	iterator=iterator->next;
  }
}

void populateArrayList() {

	srand(time(NULL));
	for ( int i=0; i<MAXSIZE; i++ ) 
	{
    	list[i] = rand() % 1000000;
 	}
}


void SelectionSort()
{
	for(int i=0; i<MAXSIZE-1; i++)
	{
		int min = i;
		for(int j=i+1; j<MAXSIZE; j++)
		{
			if(list[j]<list[min])
				min=j;
		}
		int temp;
		temp=list[i];
		list[i]=list[min];
		list[min]=temp;
	}
}




void merge(int s1, int e1, int s2, int e2)
{
		
	int size=e2-s1;
	
	
	int first=s1;
	int last=e2;
	
	int index = s1;
	
	while((s1 < e1) && (s2 < e2))			
	{
		if(list[s1] <= list[s2])
		{
			tempArray[index]=list[s1];
			s1++;
		}
		else
		{
			tempArray[index]=list[s2];
			s2++;
		}
		
		index++;
	}
	
	while(s1 < e1)					//PROBLEMS
	{
		tempArray[index]= list[s1];
		s1++;
		index++;
	}
	while(s2 < e2)
	{
		tempArray[index]=list[s2];
		s2++;
		index++;
	}
	
	for(index=first;index<last; index++)
	{
		list[index]=tempArray[index];
	}
	
	/*cout<<endl<<"start= "<<first<<endl;

	for(int i=0; i<MAXSIZE; i++)
	{
		cout<<list[i]<<endl;
	}*/
}

void msort(int start, int end)
{ 		
 	int mid = (start+end)/2;
  	
  	if(end>start+2)
  	{
	msort(start, mid);
   	msort(mid, end);  
   	}
	merge(start, mid, mid, end);
}

void mergesort()
{  
	msort(0, MAXSIZE);
}



int other[MAXSIZE];


int main() {
  clock_t start, finish;
  double  duration;
  cout << "List size of " << MAXSIZE << endl;

  //Put data into the two types of lists
  populateArrayList();
  populateLinkedList();
  
  start = clock();

  	// Add your call to either selection or merge sort here.
  	//SelectionSort();
 /*cout<<"before merge sort:\n";
 for(int i=0; i<MAXSIZE; i++)
	{
		cout<<list[i]<<endl;
	}*/
 
  mergesort();

  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Total CPU for sort time: "<<duration<<endl;

	for(int i=0; i<MAXSIZE-1; i++)		// Write a for loop to check that data in your array is in sorted order
	{
		if(list[i]>list[i+1])
			cout<<"WE HAVE PROBLEMS "<<list[i]<<" "<<list[i+1]<<endl;
	}
	
	/*cout<<endl;
	for(int i=0; i<MAXSIZE; i++)
	{
		cout<<list[i]<<endl;
	}*/

  //Let's start off with a value not in the list and see how long it takes.
  int numiters = 100000;
  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arraySequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for array sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    linkedSequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for linked sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arrayBinarySearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU time for array binary searches time: "<<duration/numiters<<endl;


  return 0;
}

