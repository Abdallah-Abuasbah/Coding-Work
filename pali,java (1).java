import java.util.Scanner;

class Queue
{
	 private int a[] = null;
	 private int f, n, r, capasity;
	 public Queue(int cap)
	        {
		        capasity = cap;
		        f = n = r = 0;
		        a = new int[capasity];
	        }
	public int front() // get front.
	{
		if (empty())
			return 0;
			else
		return a[f];
	}
	public void dequ() //remove front..
	{
		if (!empty())
		{
			f = (f + 1) % capasity;
			n--;
		}
	}
	public void enqu( int e) //add back..
	{
		if (n >= capasity)
		{
			System.out.println("qu is full..");
			return;
		}
		a[r] = e;
		r = (r + 1) % capasity;
		n++;  //count
	}
	public boolean empty()
	{
		return n == 0;
	}
};
class stack_
{

	private int s[]=null;
	private int arrs; // array size.
	private int t; // top value in array

	public stack_(int arrs)
	{
		this.arrs = arrs;
		s = new int[arrs];
		t = -1;
	}
	
	public int top()  //get front
	{
		if (empty())
			return 1;

		else
			return s[t];
	}
	public void pop() // remove front  (delete firs element in stack.)
	{
		if (empty()) 
		return ;
		t--;
	}
	public void push(int e) // add front
	{
		if (t < arrs - 1)
		{
			s[++t] = e;
		}
		else
		{
			System.out.println("stack is Full.");
		}
	}
	public boolean empty()
	{
		return t <= -1;
	}
};
public class Main
{
	public static void main(String[] args)
	{
	    
	Queue obj1 = new Queue (20);
	stack_ obj2 = new stack_ (20);
	
	int count=0 , s=0 , n=0; 
	
	System.out.println("Enter number to check if it's palindrome or not: ");
	
	Scanner insert = new Scanner(System.in);
	
	n = insert.nextInt();

	while (n!=0)
	{
		count++;
		obj2.push(n % 10);
		obj1.enqu(n % 10);
		n = n / 10;
	}
	while (!obj1.empty())
	{
		if (obj2.top() == obj1.front() ) 
		s++;
		obj1.dequ();
		obj2.pop ();
	}
	if (s == count)
	System.out.println("It's Palindrome ");
	else
	System.out.println("It's not palindrome");
	}
}
