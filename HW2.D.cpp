// H.w.2
// Abdallah Y Abuasbah 
#include"iostream"
using namespace std;
class node
{
    string name;
    node *next;
    node *prev;
    node *a; //for first node(head).
    node *b; //for last node.
    friend class slist;
    node()
    {
       next=NULL;
       prev=NULL;
       a=NULL;
       b=NULL;
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
        head=NULL;
        n=0;
    }
    ~slist()
    {
        //while(head)
        //removefront();
    }
    void add_front(const string& e)
    {
        node *q=new node;
        q->name=e;
        if(head==NULL)
        {
            head=q;
            head->next=q;
            head->prev=q;
            q->a=q;
            q->b=q; // becouse it's one node...
            n++;
        }
        else
        {
            q->next=head;
            q->prev=head->prev;
            head->prev->next=q;
            head->prev=q;
            head=q;
            node *x=head;
            n++;
            for(int i=0;i<n;i++)
            {
                x->a=head;
                x->b=head->prev;
                x=x->next;
            }
        }
    } // H.
    string get_front() const
    {
        return head->name;
    } // H.
    void remove_front()
    {
        if(head==NULL)
        return;
        else if(n==1)
        {
            node *r=head;
            r->next=NULL;r->prev=NULL;
            r->a=NULL;r->b=NULL;
            delete r;
            n--;
        }
        else
        {
        node *r=head;
        r->next->prev=head->prev;
        head=r->next;
        r->next=NULL;r->prev=NULL;
        r->a=NULL;r->b=NULL;
        delete r;
        n--;
        node *x=head;
        for(int i=0;i<n;i++)
        {
            x->a=head;
            x=x->next;
        }
        }
    } // H.
    void print_reverse()
    {
        node *p=head->prev;
        for(int i=0;i<n;i++)
        {
            cout<<p->name<<" ";
            p=p->prev;
        }
        cout<<endl;
    } // H.
    void print_list()
    {
        node*p=head;
        for(int i=0;i<n;i++)
        {
            cout<<p->name<<" ";
            p=p->next;
        }
        cout<<endl;
    } // H.
    void add_back(const string& e)
    {
        node *q=new node;
        q->name=e;
        if(head==NULL)
        {
            head=q;
            head->next=q;
            head->prev=q;
            q->a=q;
            q->b=q; // becouse it's one node...
            n++;
        }
        else
        {
        q->next=head;
        q->prev=head->prev;
        q->prev->next=q;
        head->prev=q;
        node *x=head;
        n++;
        for(int i=0;i<n;i++)
        {
            x->a=head;
            x->b=head->prev;
            x=x->next;
        }
        }
    } // H.
    string get_back() const
    {
       return (head->prev)->name;
    } // H.
    void remove_back()
    {
        if(head==NULL)
        return;
        else if(n==1)
        {
            node *r=head;
            r->next=NULL;r->prev=NULL;
            r->a=NULL;r->b=NULL;
            delete r;
            n--;
        }
        else
        {
        node*r=head->prev;
        r->prev->next=head;
        head->prev=r->prev;
        r->next=NULL;r->prev=NULL;
        r->a=NULL;r->b=NULL;
        delete r;
        n--;
        node *x=head;
        for(int i=0;i<n;i++)
        {
            x->b=head->prev;
            x=x->next;
        }
        }
    } // H.
    int size()
    {
        return n;
    } //H.
    void get()
    {
        node *x=head;
        cout<<"pointer a: "<<"          "<<"pointer b:   \n";
        for(int i=0;i<n;i++)
        {
            cout<< "            "<<(x->a)->name<<"                "<<(x->b)->name<<endl;
            x=x->next;
        }
        /*
        This fuction is additional for test.
        I wrote  it to make sure of two pointer,
        pointer (a) for head and (b) for last node 
        */
    }
};
int main()
{
    slist obj;
    obj.add_front("red");
    obj.add_front("blue"); 
    obj.add_front("green");
    obj.add_back("black");
    obj.add_back("yellow");
    obj.add_back("pink");
    cout<<"----------------------------------------------------\n";
    cout<<"now list look like: ";
    obj.print_list();
    cout<<"----------------------------------------------------\n";
    obj.get();
    cout<<"----------------------------------------------------\n";
    cout<<"the name in first node is: "<<obj.get_front()<<endl;
    cout<<"the name in last node is: "<< obj.get_back()<<endl;
    cout<<"after remove front and back list will look like: ";
    obj.remove_front();
    obj.remove_back();
    obj.print_list();
    cout<<"print reverse: ";
    obj.print_reverse();
    cout<<"node number: "<<obj.size()<<endl;
    cout<<"----------------------------------------------------\n";
    cout<<"My list: ";
    obj.print_list();
    cout<<"----------------------------------------------------\n";
    obj.get();
    cout<<"----------------------------------------------------\n";
}