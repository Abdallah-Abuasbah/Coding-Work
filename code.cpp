#include<iostream>
using namespace std;
void selectionSort(int *array, int s)
{
    int min;
    for (int i = 0; i < s-1; i++)
    {
        min = i;
        for (int j = i+1; j < s; j++)
        
        if (array[j] < array[min])
        
        min = j;
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
} // 1...

void insertionSort(int *array, int s)
{
    int key;
    for (int i = 1; i < s; i++) 
    {
        key = array[i];
        int j = i-1;
        while ( j+1 > 0 && array[j] > key) 
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
} // 2...

void merge(int *array, int left, int mid, int right)
{
    int lside = mid - left + 1;
    int rside =  right - mid;
    
    int L[lside];
    int R[rside];
    for (int i = 0; i < lside; i++)
        L[i] = array[left + i];
        
    for (int j = 0; j < rside; j++)
        R[j] = array[mid + 1 + j];
     
     
       
    int t = left;
    int i,j;
    i=j=0;
    while (i < lside && j < rside)
    {
        if (L[i] <= R[j])
        {
            array[t] = L[i];
            i++;
        }
        else
        {
            array[t] = R[j];
            j++;
        }
        t++;
    }
    while (i < lside)
    {
        array[t] = L[i];
        t++;
        i++;
    }
    while (j < rside)
    {
        array[t] = R[j];
        t++;
        j++;
    }
}
void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
} // 3...

int maxNum(int *array, int s) 
{
	int max = array[1];
	for (int i = 2; i <= s; i++)
	{
		if (max < array[i] )
			max = array[i];
	}
	return max;
}
void countingSort(int *array, int s)
{
    int max=maxNum(array,s);
    int *newArr = new int [max+1];
    
    for (int k = 0; k <= max; k++)
	newArr[k] = 0;
		 
	for (int i = 1; i <= s; i++)
	newArr[array[i]] = newArr[array[i]] + 1;
		 
	for (int k = 1; k <= max; k++)
	newArr[k] = newArr[k] + newArr[k - 1];
		 
		 
	int* lastArr = new int[s + 1];
	
	
	for (int i = s; i >= 1; i--) 
	{
		lastArr[newArr[array[i]]] = array[i];
		newArr[array[i]] = newArr[array[i]] - 1;
	}
	
	for (int i = 1; i <= s; i++) {
		array[i] = lastArr[i];
	}
	
	
} // 4...


int partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i = left-1;
    for (int j = left; j <= right-1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[right];
    array[right] = temp;
    return i+1;
}
void quickSort(int *array, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot-1);
        quickSort(array, pivot+1, right);
    }
} // 5...

void heapify(int *array, int s, int x)
{
    int max = x;
    int left = 2*x + 1;
    int right = 2*x + 2;
    if (left < s && array[left] > array[max])
        max = left;
    if (right < s && array[right] > array[max])
        max = right;
    if (max != x)
    {
        int temp = array[x];
        array[x] = array[max];
        array[max] = temp;
        
        heapify(array, s, max);
    }
}
void heapSort(int *array, int s)
{
    for (int i = s/2-1; i >= 0; i--)
        heapify(array, s, i);
        
    for (int i=s-1; i>=0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        
        heapify(array, i, 0);
    }
} // 6...


void display(int *array, int s)
{
    for(int i=0;i<s;i++)
    cout<<array[i]<<" ";
    cout<<endl;
}

double rand_double()
{
    return ((double)rand() /RAND_MAX)*100+1;
}

int main()
{
    
    int s;
    cout<<"insert array size : ";
    cin>>s;
    int array[s];
    for(int i=0;i<s;i++)
    {
        array[i]= rand()%(100)+1;
    }
    cout<<"your array is...: ";
    for(int i=0;i<s;i++)
    {
        cout<<array[i]<<" ";
    }
    cout << endl;
    
    cout << endl;
    cout << "Please select one of the following: " << endl;
    cout << "1- selectionSort " << endl;
    cout << "2- insertionSort " << endl;
    cout << "3- mergeSort" << endl;
    cout << "4- countingSort" << endl;
    cout << "5- quickSort" << endl;
    cout << "6- heapSort" << endl;
    cout << "7- EXIT...\n" << endl;





    cout << "Please enter your choice: ";
    int choice;
    cin >> choice;
    while (choice != 7) 
    {
        if (choice == 1) 
        {
            clock_t start, end;
            start = clock();
            selectionSort(array,s);
            end = clock();
            cout<<"array after use selection sort: ";
            display(array,s);
            cout<<"time for selection: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl<<endl;
        }
         if (choice == 2) 
        {
            clock_t start, end;
            start = clock();
            insertionSort(array,s);
            end = clock();
            cout<<"array after use insertion sort: ";
            display(array,s);
            cout<<"time for insertion: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl<<endl;
        }
         if (choice == 3) 
        {
            clock_t start, end;
            start = clock();
            mergeSort(array,0,s-1);
            end = clock();
            cout<<"array after use merge sort: ";
            display(array,s);
            cout<<"time for merge sort : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl<<endl;
        }
         if (choice == 4) 
        {
            clock_t start, end;
            start = clock();
            countingSort(array,s);
            end = clock();
            cout<<"array after use counting Sort sort: ";
            for(int i=1;i<s;i++)
            cout<<array[i]<<" ";
            cout<<endl;
            cout<<"time for counting Sort sort : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl;
            cout<<endl;
            
        }
         if (choice == 5)
        {
            clock_t start, end;
            start = clock();
            quickSort(array,0,s-1);
            end = clock();
            cout<<"array after use quick Sort sort: ";
            display(array,s);
            cout<<"time for quick Sort sort : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl<<endl;
        }
        else if (choice == 6)
        {
            clock_t start, end;
            start = clock();
            heapSort(array,s);
            end = clock();
            cout<<"array after use heap Sort sort: ";
            display(array,s);
            cout<<"time for heap Sort sort : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
            cout<<endl<<endl;
        }
            cout << "Please enter your choice: ";
            cin >> choice;
    }
}
