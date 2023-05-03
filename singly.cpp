#include "iostream"
using namespace std;
class node
{
    int data; node*next;
    friend class slist;
};
class slist
{
    private:
    int n; node*head;
    public:
    slist() // constructor.
    {
        head=NULL;
        n=0;
    }
    ~slist() // destructor.
    {
        //while(head)
        //removefront();
    }
    void addfront(int item)
    {
        node*x=new node; // step 1 to prepare node(allocate)...
        x->next=NULL; // step 2 to prepare node(nullefecation))...
        x->data=item; // step 3 to prepare node(store data))...
        if (head==NULL) //step 4 to prepare node(Connect head pointer with new node(x)))...
        {
            head=x;
            n++;
        } // to add one node...
        else
        {
            x->next=head;
            head=x;
            n++;
        } // to add many node...
    }
    int getfront() const
    {
        if(head==NULL)
        return 0;
        else
        return head->data;
    } // to get the valu in first node...
    bool removefront()
    {
        node *r=head;
        if(r==NULL) return false;
        head=head->next;
        r->next=NULL;
        delete r;
        n--;
        return true;
    }
    void printlist()
    {
        node *p=head;
        while(p)
        {
        cout<<p->data<<" ";
        p=p->next;
        }
        cout<<endl;
    }
    void addback(const int& item)
    {
        node*c=new node;
        c->data=item;
        c->next=NULL;
        node *k=head;
        if(head==NULL)
        {
            head==c;
            n++;
        }
        else
        {
        while (k&&k->next !=NULL)
        k=k->next;
        k->next=c;
        n++;
        }
    }
    int getback() const
    {
        node *b=head;
        while(b && b->next !=NULL)
        b=b->next;
        if(b==NULL) return 0;
        return b->data;
    }
    void removeback()
    {
        node *rb=head;
        node *prev=head;
        while(rb->next)
        {
            prev=rb;
            rb=rb->next;
        }
        prev->next=NULL;
        delete rb;
        n--;
    }
    int size()
    {
        return n;
    }
    bool empty()const
    {
    return head==NULL;
    }
    node *find(const int& item) const
    {
        node*f=head;
        while(f&&f->data !=item)
        f=f->next;
        return f;  
    }
    bool removee(const int &item)
    {
        if(empty())return false; // for empty list.
        else
        {
        if(head->next==NULL&&head->data==item) // for one node
        {
            delete head;
            head=NULL;
            n--;
            return true;
        }
        else
        {
        // more than one node.
        node*a=find(item);
        if(a==NULL) return false;
        else
        {
        if(head==a)
        {
            removefront();
            return true;
        }
        node*q=head;
        while(q->next!=a)
        q=q->next;
        q->next=a->next;
        a->next=NULL;
        delete a;
        n--;
        return true;
        }
        }
        }
    }
    bool removeafter(const int &item)
    {
       if(n==1)return false;
       if(empty())
       return false;
       node *r=find(item);
       if(r==NULL)return false;
       else
       {
           node *a=head;
           a=r->next;
           r->next=a->next;
           delete a;
           n--;
           return true;
       }
    }
    bool removebefore(const int &item)
    {
       if(empty())return false;
       if(n==1)return false;
        node*r=find(item);
        if(head==r)return false;
        node*b=head;
        node*a=NULL;
        if(b->next==r) 
        {
        removefront();
        n--;
        return true;
        }
        else
        {
            while(b->next!=r)
            {
                a=b;
                b=b->next;
            }
            a->next=r;
            delete b;
            n--;
            return true; 
        }
        
    }
};
int main()
{
    slist obj;
    obj.addfront(10); // head will point to 10.
    obj.addfront(20); // head will point to 20, data list will be like ... 20--->10.
    obj.addfront(30); // head will point to 30, data list will be like ... 30--->20--->10.
    obj.addfront(50);
    obj.addfront(70);
    obj.addfront(90);
    cout<<"now list look like: ";
    obj.printlist();
    cout<<"the value of first node is: "<<obj.getfront()<<endl;
    obj.removefront(); 
    cout<<"first element has been removed...\n";
    cout<<"the value of first node is: "<<obj.getfront()<<endl; 
    cout<<"the value of last node is: "<< obj.getback()<<endl;
    cout<<"after addback, list will look like: ";
    obj.addback(5);
    obj.printlist();
    obj.removeback();
    cout<<"after remove back, list will look like: ";
    obj.printlist();
    cout<<"Enter a number to search if it exists in list or not: ";
    int ss;cin>>ss;
    cout<<"value adress: "<<obj.find(ss)<<endl; //find...if found will print value adress else 0
    cout<<"befor delete: ";
    obj.printlist();
    cout<<"choose node: ";
    int x;cin>>x;
    obj.removee(x); // choose node and delete it.
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
    cout<<"node number: "<<obj.size();
    
}

