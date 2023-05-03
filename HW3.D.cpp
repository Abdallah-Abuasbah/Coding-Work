// H.w.3
// Abdallah Y Abuasbah 
#include"iostream"
using namespace std;
class node
{
	int key;
	int data;
	node *next;
	node *prev;
	friend class slist;
	node()
	{
		next = NULL;
		prev = NULL;
		key = 0;
		data = 0;
	}
	~node()
	{

	}
};
class slist
{
private:
	int n;
	node *head;
public:

	slist()
	{
		head = NULL;
		n = 0;
	}
	~slist()
	{
		//while(head)
		//Pop();
	}
	void Push(const int &d, const int &k)
	{
		node *Q = new node;
		Q->key = k;
		Q->data = d;
		Q->next = Q->prev = NULL;
		node *A = head; // pointer to check oll node...
		node *B = NULL; // pointr to save last location for pointer A...
		if (head == NULL)     head = Q;

		while (A && A->key < k)
		{
			A = A->next;
			B = A->prev;
		}
		if (!A && B || A && B)
		{
			Q->next = A;
			A->prev = Q;
			B->next = Q;
			Q->prev = B;
			n++;
		}
		else
		{
			Q->next = head;
			head->prev = Q;
			head = Q;
			n++;
		}
	}
	int Top() 
	{
		int t = head->data;
		Pop();
		return t;
		
	}
	void Pop() /* removeMin() */
	{
		if (head == NULL)     return;
		else
		{
			node *r = head;
			head = r->next;
			r->next = r->prev = NULL;
			delete r;
			n--;
		}
	}
	void print()
	{
		node *p = head;
		for (int i = 0; i < n; i++)
		{
			cout << "( " << p->data << " " << p->key << " )" << " ";
			p = p->next;
		}
		cout << endl;
	}
	int size()
	{
		return n;
	}
};
int main()
{
	slist Q;
	Q.Push(11, 8);
	Q.Push(3, 2);
	Q.Push(8, 7);
	Q.Push(9, 4);
	Q.Push(7, 1);
	cout << "My list look like: ";
	Q.print();
	cout << "----------------------------------------------------\n";
	cout << "data in first node is: " << Q.Top() << endl;
	cout << "after removeMin ,list will look like: ";
	Q.print();
	cout << "data in first node is: " << Q.Top() << endl;
	cout << "node number: " << Q.size() << endl;
	cout << "----------------------------------------------------\n";
}