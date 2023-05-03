//  simple stack code with array

#include "iostream"
#include "string"
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