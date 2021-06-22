#include <iostream>
#include <string>
#define maxlength 5
using namespace std;
class data
{
public:
    string name;
    string mssv;

    data(string name,string mssv);

};
data::data(string name,string mssv)
{
    this->mssv=mssv;
    this->name=name;
}

class Stack
{
    public:
    int length=0;
    Stack();
    void push(data* e);
    data* pop();
    data* top();
    void print();
    data* a[maxlength];
    data* ptr;


};
Stack::Stack()
{
    ptr ;
}
void Stack::push(data* e)
{
    if(length>maxlength) return ;
    a[length]=e;
    length++;
}
data* Stack::pop()
{
    if(length<=0) return nullptr;
    length--;
    return a[length];
}
data* Stack::top()
{
    if(length<0) return nullptr;
    return a[length-1];
}
void Stack::print()
{
    for(int i=0;i<length;i++)
    {
        cout<<a[i]->mssv<<endl;
        cout<<a[i]->name<<endl;
    }
}
int main()
{
    Stack* ptr= new Stack;
    data* sv1= new data("hoang trung nam","1535864");
    data* sv2= new data("nguyen hong hanh","1122364");
    ptr->push(sv1);
    ptr->push(sv2);
   // ptr->print();
    cout<<endl;
    cout<<ptr->top()->mssv;
    return 0;
}
