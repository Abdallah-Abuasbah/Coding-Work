#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp; 
}

class sort
{

private : 
	int size; 
	int* Entered_Data; 
	int* Sorted_Data; 
	int RTIME;
	int HTIME; 


public :

	sort()
	{
		size = RTIME = HTIME =  0; 
		Entered_Data = NULL; 
		Sorted_Data = NULL; 
	}

	void readData()
	{
		
		cout << "Please enter number of elements : "; 
		cin >> size; 
		Entered_Data = new int[size]; 
		Sorted_Data = new int[size]; 
		cout << "Enter your elements .... \n"; 
		for (int i = 0;i < size; i++)
		{
			cout << "Element " << i + 1 << " : "; 
			cin >> Entered_Data[i]; 
		}
	}

	
	void heapify(int * A , int N , int K)
		{
			int large= K;
			int l = 2 * K + 1;
			int r = 2 * K + 2;


			if (l < N && A[l] > A[large])
				large = l;


			if (r < N && A[r] > A[large])
				large = r;


			if (large != K ) {

				swap(A[K], A[large]);
				heapify(A, N, large);
			}
		}
	

	void  HEAP()
	{
		time_t start, end;
		time(&start);
		
		for (int j = 0; j < size; j++)
		{
			Sorted_Data[j] = Entered_Data[j]; 
		}
		for (int i = size / 2 - 1 ; i >= 0 ; i--)
			heapify(Sorted_Data, size, i);


		for (int i = size - 1; i >= 0; i--) {

			swap(Sorted_Data[0], Sorted_Data[i]);


			heapify(Sorted_Data, i, 0);
		}


		time(&end);
		HTIME = end - start; 
	}


	void  RADIX()
	{
		time_t start, end;
		time(&start);

		for (int j = 0; j < size; j++)
		{
			Sorted_Data[j] = Entered_Data[j];
		}

		int m = Max(Entered_Data);


		for (int exp = 1; m / exp > 0; exp *= 10)
			countSort(Sorted_Data,size, exp);

		time(&end);
		RTIME = end - start;
	}

	

	int Max(int * A)
	{
		int M = A[0];
		for (int i = 1; i < size ; i++)
			if (A[i] > M)
				M = A[i];
		return M ;
	}



	void countSort(int arr[], int n, int exp)
	{
		int* output = new int[n]; 
		int i, count[10] = { 0 };

		
		for (i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;

	
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		
		for (i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		for (i = 0; i < n; i++)
			arr[i] = output[i];
	}

	
	
	void DISPLAY()
	{
		cout << "Sorted elements is : "; 
		for (int i = 0;i < size; i++)
		{
			cout << Sorted_Data[i] << " ";  
		}
		cout << endl; 
	
		cout << "Actually needed time by radix sort algorithm : " << RTIME << endl; 
		cout << "Actually needed time by heap sort algorithm : " << HTIME << endl; 
	}

	~sort()
	{
		size = RTIME = HTIME = 0;
		delete[] Entered_Data; 
		delete[] Sorted_Data; 
	}

};

int main()
{

	cout << "=====================================================================\n"; 
	
	sort obj; 

	obj.readData(); 


	cout << "=====================================================================\n";


	int choice; 
	cout << " SORTING USING BY ( 1-Heap sort  2-Radix sort ) : " << endl;  
	cin >> choice;

	cout << "============================    RESULT   =============================\n";


	switch (choice)
	{
		case 1 : 
		{

			obj.RADIX();
			obj.HEAP();
			obj.DISPLAY(); 
			
			return 0; 
		}
		case 2 : 
		{
			obj.HEAP();
			obj.RADIX(); 
			obj.DISPLAY();
			
			return 0; 
		}
		default : 
			cout << "sorry , wrong choice , good bye ... " << endl; 
			return 0; 
    }
	

}