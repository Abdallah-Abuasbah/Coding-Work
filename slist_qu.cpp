/*
//  simple qu code with array

#include <iostream>
using namespace std;
template<typename T>
class Queue
{
private:
	T *a;
	int f, n, r, capasity;
public:
	Queue(int cap = 5)
	{
		capasity = cap;
		f = n = r = 0;
		a = new T[capasity];
	}
	~Queue()
	{
		delete[]a;
		a = NULL;
	}
	void dequ() //remove front..
	{
		if (!empty())
		{
			f = (f + 1) % capasity;
			n--;
		}
	}
	T front() const // get front..
	{
		if (empty())
		return 0;
		return a[f];
	}
	void enqu(const T&e) //add back..
	{
		if (n >= capasity)
		{
			cout << "qu is full..\n";
			return;
		}
		a[r] = e;
		r = (r + 1) % capasity;
		n++;  //count
	}
	int size() const
	{
		return n;
	}
	bool empty() const
	{	
		return n == 0;
	}
};
int main()
{
	Queue <int> q;
	q.enqu(10);
	q.enqu(20);
	q.enqu(30);
	q.enqu(40);
	cout << "size: " << q.size() << endl;
	cout << "first element in qu: " << q.front() << endl;
	//	cout << "last element in qu: " << q.back() << endl;
	q.dequ();
	cout << "first element in qu after dequ: " << q.front() << endl;
}

//  simple stack code with array

#include "iostream"
using namespace std;
template <typename T>
class stack_
{
private:
    T *s; 
    int arrs; // array size.
    int t; // top value in array
public:
    stack_(int arrs = 5)
    {
        this->arrs = arrs;
        s = new T[arrs];
        t = -1;
    }
    ~stack_()
    { 
       if (s != NULL)
       delete[]s; 
    }
    const T top() const //get front
    {
        if (empty())
        return "stack is empty..."; // if template is (int) then return 0 
        else
        return s[t];
    }
    void pop(); // remove front
    void push(const T& e); // add front
    bool empty()const 
    {
    return t<=-1;
    }
    int size() const 
    { 
    return t+1; 
    }
};
template<typename T>
void stack_<T>::push(const T& e)
{
    if (t < arrs - 1) 
    {
        s[++t] = e;
    }
    else
    {
        cout << "stack is Full. \n";
    }
}

template<typename T>
void stack_<T>::pop() // delete firs element in stack.
{
    if (empty()) return;
    t--;
}

int main()
{
    stack_ <string>obj;
    obj.push("red");
    obj.push("pink");
    obj.push("yellow");
    obj.push("green");
    obj.push("brown");
    cout<<"first element: "<<obj.top()<<endl;
    obj.pop();
    cout<<"after remove first element. \n";
    cout<<"first element: "<<obj.top();
}
*/
// simple qu code with slist...

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
	void push_back(const T& e); // add back
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
void slist<T>::push_back(const T&e)
{
	node<T>*x = new node<T>;
	x->next = NULL;
	x->v = e;
	if (head == NULL)
	{
		head = x;
		n++;
	}
	node<T>*k=head;
	else
    {
        node<T>*k=head;
        while (k&&k->next !=NULL)
        k=k->next;
        k->next=x;
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
	obj.push_back("red");
	obj.push_back("pink");
	obj.push_back("yellow");
	obj.push_back("black");
	cout << "first element: " << obj.top_front() << endl;
	obj.pop_front();
	cout << "after remove first element. \n";
	cout << "first element: " << obj.top_front() << endl;
	cout << "node number: "<<obj.size();
}

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
