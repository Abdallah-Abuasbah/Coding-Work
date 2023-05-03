#include < stdio.h>
#include <iostream>
#include <string>

#pragma warning(disable : 4996)

using namespace  std;


class  String
{
private:
    char* s;


public:

    String() :s(NULL)
    {
        setString("hello");
    }

    String(char* a) :s(NULL)
    {
        setString(a);
    }

    String(char A) :s(NULL)
    {
        char t[2] = { A,NULL };

        setString(t);

    }

    String(int A) : s(NULL)
    {
        char t[2] = { (char)A,NULL };

        setString(t);
    }

    String(String& R) :s(NULL) {//member-wise copier      ... deep copying ...  copy constructor.

        setString(R.getString());

    }
    ~String()
    {

        if (s)
            delete[]s;

        s = NULL;

    }

    inline char* getString() const
    {
        return s;
    }

    inline void setString(char* A = "boo")
    {
        this->~String();

        //  s = new char[strlen(A) + 1];
        //strcpy(s, A);

        s = strdup(A);

    }

    friend ostream& operator << (ostream& out, String& R)
    {

        out << endl << "String -- >" << R.getString();

        return out;
    }

    friend istream& operator >> (istream& in, String& R)
    {
        char* p = new char[10000];

        cout << endl << "Enter a string..";

        gets_s(p, 1000);

        R.setString(p);

        delete[]p;

        return in;
    }


    String& operator = (const  String& R)
    {
        if (this != &R)
            this->setString(R.getString());

        return *this;

    }

    String& operator = (char* R)
    {
        String Temp(R);
        *this = Temp;

        return *this;

    }

    String& operator = (const char  R)
    {
        String Temp(R);

        *this = Temp;

        return *this;

    }

    String& operator = (const int  R)
    {
        String Temp(R);

        *this = Temp;

        return *this;

    }


    String  operator + (String& R)
    {

        char* p = NULL;
        p = new char[strlen(getString()) + strlen(R.getString()) + 1];

        strcpy(p, getString());
        strcat(p, R.getString());


        String temp = p;

        delete[]p;

        return temp;

    }

    String operator + (char* R)
    {
        String T = R;

        T = *this + T;

        return T;

    }

    String operator + (char R)
    {
        String T = R;

        T = *this + T;

        return T;

    }

    String operator + (int  R)
    {
        String T = R;

        T = *this + T;

        return T;
    }

    String operator +=(String R)
    {
        *this = *this + R;

        return *this;
    }

    String operator += (char* R)
    {
        *this = *this + R;

        return *this;

    }

    String operator += (char R)
    {
        *this = *this + R;

        return *this;
    }

    String operator += (int R)
    {
        *this = *this + R;

        return *this;

    }


    String operator - (String& R)
    {
        char* p = strdup(getString());

        char* m = R.getString();

        char* q = NULL;

        while ((q = strstr(p, m)) != NULL) {

            char* z = q + strlen(m);

            strcpy(q, z);

        }

        String Temp = p;

        delete[]p;


        return Temp;


    }

    String operator -(char* R)
    {
        String T = R;

        T = *this - T;

        return T;

    }

    String operator -(char  R)
    {
        String T = R;

        T = *this - T;

        return T;

    }

    String operator -(int  R)
    {
        String T = R;

        T = *this - T;

        return T;

    }

    String operator -=(String  R)
    {
        return *this = *this - R;

    }


    String operator -=(char* R)
    {
        return *this = *this - R;

    }
    String operator -=(char  R)
    {
        return *this = *this - R;

    }

    String operator -=(int  R)
    {
        return *this = *this - R;

    }

    int operator == (String& R)
    {

        return stricmp(getString(), R.getString()) == 0;
    }

    int operator == (char* R)
    {
        String T = R;
        return stricmp(getString(), T.getString()) == 0;
    }

    int operator != (char* R)
    {

        return !(*this == R);
    }

    int operator != (String& R)
    {

        return !(*this == R);
    }

    int operator > (String& R)
    {

        return stricmp(getString(), R.getString()) > 0;
    }


    int operator >= (String& R)
    {

        return *this > R || *this == R;
    }

    int operator < (String& R)
    {

        return !(*this > R || *this == R);
    }

    int operator <= (String& R)
    {

        return !(*this > R);
    }
    int Len() {
        return strlen(getString());
    }

};


void display(String* a, int count)
{

    cout << endl << endl << " here it goes.....\n";


    for (int i = 0; i < count; i++)
        cout << endl << *a++;

}

void sort(String* a, int count)
{


    for (int i = 0; i < count; i++)

        for (int j = i + 1; j < count; j++)
        {
            if (a[i] > a[j])
            {
                String T = a[i];

                a[i] = a[j];
                a[j] = T;

            }
        }
}
void Long(String* St, int count)
{

    String max;
    for (int i = 0; i < count; i++) {
        if (St[i].Len() > max.Len())
        {
            max = St[i];
        }
    }
    cout << endl << "max length" << max << endl;
}
 
void Short(String* St, int count)
{

    String min;
    for (int i = 0; i < count; i++) {
        if (St[i].Len() < min.Len())
        {
            min = St[i];
        }
    }
    cout << endl<< "min length=" << min;
}

void mergerString(String* a, int count)
{
    String merge = " ";
    for (int i = 0; i < count; i++)
    {
        merge += a[i];
    }
    cout << endl << " array merge " << merge;
}
void sum(String* arr, int count)
{
    double sum=0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i].Len();
    }
    cout << "sum lenght of array=" << sum << endl;
}

int main(void)

{


    String arr[100];
    int count = 0;

    String S = "";

    cout << endl << "please enter words or <quit> to end..";

    cin >> S;

    while (S != "quit" && count < 100)
    {

        arr[count++] = S;


        cout << endl << "please enter words or <quit> to end..";

        cin >> S;

    }

    display(arr, count);

    sort(arr, count);

    display(arr, count);

    cout << endl;
    Long(arr, count);
    cout << endl;
    Short(arr, count);

    cout << endl;

    mergerString(arr, count);
    cout << endl;
    sum(arr, count);


}