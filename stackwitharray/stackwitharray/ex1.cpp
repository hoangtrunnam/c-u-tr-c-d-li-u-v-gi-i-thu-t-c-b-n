#include <iostream>
using namespace std;
#define maxsize 5
class stackelement
{
public:
    string title;
    string author;

    stackelement(string title, string author);
};
stackelement::stackelement(string title, string author)
{
    this->title = title;
    this->author = author;
}

class stack1
{
public:
    void push(stackelement* e);
    stackelement* pop();
    stackelement* top();
    bool isempty();
    stackelement* a[maxsize];
    int size1 = 0;
    void print();
    stackelement* ptr;
    stack1();
};

stack1::stack1()
{
    ptr ;
}

void stack1::print()
{


        cout << "du lieu dau ra : " << endl;
        for (int i = 0; i < size1; i++)
        {
            cout << a[i]->title << endl;
            cout << a[i]->author << endl;
        }

}

void stack1::push(stackelement* e)
{
    if (size1 > maxsize) return;
    a[size1] = e;
    size1++;
}
stackelement* stack1::pop()
{
    if (size1 <= 0) return nullptr;
    size1--;
    return a[size1];
}
stackelement* stack1::top()
{
    if (size1 <= 0) return nullptr;
    return a[size1 - 1];
}

bool stack1::isempty()
{
    return (!size1);
}
int main()
{

    stack1* ptr1= new stack1;

    stackelement* book1 = new stackelement("dac nhan tam", "hoang trung nam");
    stackelement* book2 = new stackelement("day con lam giau", "nguyen nhat anh");
    ptr1->push(book1);
    ptr1->push(book2);
   // cout<<ptr1->pop()->title;
    //ptr1->print();
    cout<<endl;
    cout<<ptr1->top();
    system("pause");
    return 0;
}
