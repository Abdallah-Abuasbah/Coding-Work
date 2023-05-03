
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
	q.dequ();
	cout << "first element in qu after dequ: " << q.front() << endl;
}
