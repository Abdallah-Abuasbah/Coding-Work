#include <iostream>
#include<string>
using namespace std;
class Queue
{
private:
	int *a;
	int f, n, r, capasity;
public:
	Queue(int cap = 5)
	{
		capasity = cap;
		f = n = r = 0;
		a = new int[capasity];
	}
	~Queue()
	{
		delete[]a;
		a = NULL;
	}
	int front() const // get front..
	{
		if (empty())
			return 0;
		return a[f];
	}
	void dequ() //remove front..
	{
		if (!empty())
		{
			f = (f + 1) % capasity;
			n--;
		}
	}
	void enqu(const int&e) //add back..
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
class stack_
{
private:
	int *s;
	int arrs; // array size.
	int t; // top value in array
public:
	stack_(int arrs = 5)
	{
		this->arrs = arrs;
		s = new int[arrs];
		t = -1;
	}
	~stack_()
	{
		if (s != NULL)
			delete[]s;
	}
	int top()  //get front
	{
		if (empty())
			return 1;

		else
			return s[t];
	}
	void pop() // remove front  (delete firs element in stack.)
	{
		if (empty()) return;
		t--;
	}
	void push(const int& e) // add front
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
	bool empty()const
	{
		return t <= -1;
	}
	int size() const
	{
		return t + 1;
	}
};

void Palindrome()
{
	Queue obj1;
	stack_ obj2;
	int k, t;
	string x;
	cout << " Enter number to check if it's palindrome or not:  \n";
	cin >> x;
	int i;
	for (i = 0; x[i] != NULL; i++);
	int count = i;
	int j;

	if (count % 2 == 0)
	{
		for (j = 0; j < count / 2; j++) {
			obj1.enqu(x[j]);
		}
		int z = j;
		for (z; j < count; j++) {
			obj2.push(x[j]);
		}
		for (i = 0; i < count / 2; i++)
		{

			t = obj1.front();
			k = obj2.top();
			if (t != k) {

				cout << "It's not palindrome\n"; break;
			}
			obj1.dequ();
			obj2.pop();
			cout << "It's Palindrome\n";
			break;
		}
	}

	else {
		count--;
		for (j = 0; j < count / 2; j++) {
			obj1.enqu(x[j]);
		}
		int z = j + 1;
		count++;
		for (z; j < count; j++) {
			obj2.push(x[j]);
		}
		for (i = 0; i < count / 2; i++)
		{

			t = obj1.front();
			k = obj2.top();
			if (t != k) {

				cout << "It's not palindrome\n"; break;
			}
			obj1.dequ();
			obj2.pop();
			cout << "It's Palindrome\n";
			break;
		}

	}
}
int main()
{
	Palindrome();

	return 0;
}



