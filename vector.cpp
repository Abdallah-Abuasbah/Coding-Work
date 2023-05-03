#include <iostream>
using namespace std;
template <typename T>
class My_vector
{
private:
    T *a;
    int capacity; // max size..
    int n; // count for element
public:
    
    My_vector()
    {
        capacity=5;
        a=new T[capacity];
        n=0;
    }
    ~My_vector()
    {
        delete []a;
        a=NULL;
    }
    void add_front(T e)
    {
        if(n>=capacity-1)
        resize();
        else
        {
        a[]=e;
        n++;
        }
    }
    void resize()
    {
        T *r=new T [capacity*2] // new size for array = last size * 2
        for(int i=0;i<capacity;i++)
        r[i]=a[i];
        delete [] a;
        a=b;
        capacity=capacity*2;
    }
    void add_back(T e)
    {
        if(n>=capacity-1)
        resize();
        else
        {
        a[n]=e;
        n++;
        }
    }
    T get_front()
    {
        return a[0];
    }
    T get_back()
    {
        return a[n];
    }
    
  
  
    
};
int main()
{
    My_vector <int> x;

}
