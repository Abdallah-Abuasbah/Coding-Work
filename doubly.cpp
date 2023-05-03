#include<iostream>
using namespace std;
/* header                  trailer
    [/]   [1]   [2]   [3]   [/]
*/ // My list will look like:
class node
{
    int data;
    node* next;
    node* prev;
    friend class slist;
};
class slist
{
    private:
    int n;
    node* header;
    node* trailer;
    public:
    slist() // constructor.
    {
        header=new node;
        trailer=new node;
        header->next=trailer;
        trailer->prev=header;
        n=0;
    }
    ~slist() // destructor.
    {
        //while(header->next)
        //removefront();
    }
    void addfront(const int& item)
    {
       node *a=new node;
       a->data=item;
       a->next=header->next;
       header->next->prev=a;
       a->prev=header;
       header->next=a;
       n++;
    } // D.
    int getfront() const
    {
        return (header->next)->data;
    } // D.
    void removefront()
    {
        node *r=header->next;
        header->next=r->next;
        r->next->prev=r->prev;
        r->next=NULL;r->prev=NULL;
        delete r;
        n--;
    } // D.
    void printreverse()
    {
        if(empty()) return;
        node *p=trailer->prev;
        while(p!=header)
        {
            cout<<p->data<<" ";
            p=p->prev;
        }
        cout<<"\n";
    } // D.
    void printlist()
    {
        node *p=header->next;
        while(p!=trailer)
        {
        cout<<p->data<<" ";
        p=p->next;
        }
        cout<<endl;
    } // D.
    void addback(const int& item)
    {
        node*a=new node;
        a->data=item;
        a->prev=trailer->prev;
        trailer->prev->next=a;
        a->next=trailer;
        trailer->prev=a;
        n++;
    } // D.
    int getback() const
    {
       return (trailer->prev)->data;
    } // D.
    void removeback()
    {
        node*r=trailer->prev;
        trailer->prev=r->prev;
        r->prev->next=r->next;
        r->next=NULL;r->prev=NULL;
        delete r;
        n--;
    } // D.
    int size()
    {
        return n;
    } // D.
    bool empty()const
    {
        return header->next==trailer;
    } // D.
    node *find(const int& item) const
    {
        node*f=header->next;
        while(f&&f->data !=item)
        f=f->next;
        return f;  
    } // D.
    void removee(const int &item)
    {
        if(empty())return;
        node* r=find (item);
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r->next=NULL;r->prev=NULL;
        delete r;
        n--;
    } // D.
    bool removeafter(const int &item)
    {
        if(n==1) return false;
        if(empty()) return false;
        node *r=find(item);
        if(r->next==trailer) return false;
        r=r->next;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r->next=NULL;r->prev=NULL;
        delete r;
        n--;
    } // D.
    bool removebefore(const int &item)
    {
        if(n==1) return false;
        if(empty()) return false;
        node *r=find(item);
        if(r->prev==header) return false;
        r=r->prev;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r->next=NULL;r->prev=NULL;
        delete r;
        n--;
    } // D.
};
int main()
{
    slist obj;
    obj.addfront(30); 
    obj.addfront(40); 
    obj.addfront(50);
    obj.addfront(60);
    obj.addfront(70);
    obj.addfront(80);
    obj.addback(20);
    obj.addback(10);
    cout<<"now list look like: ";
    obj.printlist();
    cout<<"the value of first node is: "<<obj.getfront()<<endl;
    obj.removefront(); 
    cout<<"first element has been removed...\n";
    cout<<"after remove front, list will look like: ";
    obj.printlist();
    cout<<"the value of last node is: "<< obj.getback()<<endl;
    obj.removeback();
    cout<<"after remove back, list will look like: ";
    obj.printlist();
    cout<<"find value adress: ";
    int f;cin>>f;
    cout<<obj.find(f)<<endl;
    cout<<"remove any node: ";
    obj.printlist();
    cout<<"choose node: ";
    int x;cin>>x;
    obj.removee(x); 
    cout<<"after delete node "<<x<<" list will be: ";
    obj.printlist();
    cout<<"chosse node to remove after: ";
    int y;cin>>y;
    obj.removeafter(y);
    obj.printlist();
    cout<<"chosse node to remove before: ";
    int z;cin>>z;
    obj.removebefore(z);
    obj.printlist();
    cout<<"-----------------------------------------------\n";
    cout<<"print reverse: ";
    obj.printreverse();
    cout<<"node number: "<<obj.size();
}
