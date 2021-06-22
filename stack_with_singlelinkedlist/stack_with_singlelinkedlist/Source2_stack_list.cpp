#include <iostream>
using namespace std;
class node
{
public:
	string ten;
	string sach;
	node(string ten, string sach);
	node* next;
	node* previous;
	node();
};
node::node()
{

}
node::node(string ten, string sach)
{
	this->ten = ten;
	this->sach = sach;
}
class stacklist
{ public:
	node* newnode;
	node* head;
	node* last;
	void insertlast(node* newnode);
	void remove(node* at);
	void print();
	stacklist();
};
stacklist::stacklist() 
{
	
	head = nullptr;
	last = nullptr;
}


void stacklist::insertlast(node* newnode)
{
	if (!head)
	{
		head = newnode;
		last = newnode;
	}
	last->next = newnode;
	last = newnode;
	newnode->next = nullptr;
}
void stacklist::remove(node* at)
{
	if (!head)
		return;
	if (at->previous)
	{
		at->previous->next = at->next;
	}
	if (at->next)
	{
		at->next->previous = at->previous;
	}
}

class stack
{
public:
	stacklist* list= new stacklist;
	void push(node* newnode);
	bool isempty();
	node* pop();
	node* top();
	stack* l;
	stack();
};
stack::stack()
{

}


void stack::push(node* newnode)
{
	list->insertlast(newnode); 
}
node* stack::pop()
{
	node* temp = list->last;
	list->remove(list->last);
	return temp;
}

bool stack::isempty()
{
	return l->isempty();
}

node* stack::top()
{
	return list->last;
}






int main()
{
	stack* it5 = new stack;
	node* sv1 = new node("hoang trung nam", "dac nhan tam");
	node* sv2 = new node("nguyen nhat anh", "mua he nam ay");
	node* sv3 = new node("nam cao", "lao hac");
	//cout<<it5->isempty();
	it5->push(sv1);
	it5->push(sv2);
	it5->push(sv3);
	cout<<	it5->pop()->ten<<"   ";
	cout << it5->pop()->sach<<endl;
	system("pause");
	return 0;
}