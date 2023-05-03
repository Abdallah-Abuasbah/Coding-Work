// simple stack code with slist...

#include <iostream>
#include <string>
using namespace std;
template <typename T>
class node
{
	T v; // node value 
	node<T>*next;
	template <typename T>
	friend class slist;
};
template <typename T>
class slist
{
private:
	int n; //count
	node<T>*head;
public:
	slist() // constructor.
	{
		head = NULL;
		n = 0;
	}
	~slist() // destructor.
	{
		//while(head)
		//pop_front();
	}
	const T top_front(); // get front
	void push_front(const T& e); // add front
	void pop_front(); // remove front
	bool empty()const; 
	int size();
};

template <typename T>
const T slist<T>::top_front()
{
	if (head == NULL)
	return 0;
	else
	return head->v;
}

template <typename T>
void slist<T>::push_front(const T&e)
{
	node<T>*x = new node<T>;
	x->next = NULL;
	x->v = e;
	if (head == NULL)
	{
		head = x;
		n++;
	}
	else
	{
		x->next = head;
		head = x;
		n++;
	}
}

template <typename T>
void slist<T>::pop_front()
{
	node<T>*r = head;
	head = head->next;
	r->next = NULL;
	delete r;
	n--;
}

template <typename T >
bool slist<T>::empty()const
{
	return head == NULL;
}
template <typename T >
int slist<T>:: size()
{
	return n;
}
int main()
{
	slist <string> obj;
	obj.push_front("red");
	obj.push_front("pink");
	obj.push_front("yellow");
	obj.push_front("black");
	cout << "first element: " << obj.top_front() << endl;
	obj.pop_front();
	cout << "after remove first element. \n";
	cout << "first element: " << obj.top_front() << endl;
	cout << "node number: "<<obj.size();
}