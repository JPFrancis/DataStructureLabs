#include"llist.h"
template <typename T> 
class Stack : public LList<T>
{
	public:
	
	Stack();
	~Stack();
	int size() const;
	void push(T& value);
	void pop();
	T& top();
	bool empty() const;
};
	
template<typename T> Stack<T>::Stack() : LList<T>()
{
	//this->LList<T>();
}

template<typename T> Stack<T>::~Stack()
{
	LList<T>::clear();
}

template<typename T> int Stack<T>::size() const
{
	return LList<T>::size();
}

template<typename T> void Stack<T>::push(T& value)
{
	push_back(value);
}

template<typename T> void Stack<T>::pop()
{
		LList<T>::remove(size());
}	
template<typename T> T& Stack<T>::top()
{

return at(size());

}

template<typename T> bool Stack<T>::empty() const
{
return LList<T>::empty();
}
