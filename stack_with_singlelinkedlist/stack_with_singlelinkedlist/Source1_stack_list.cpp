#include <iostream>
#include <string>
using namespace std;

class node
{public:
	node();
	node* next;
	node* previous;
	string mssv;
	string name;
	node(string mssv, string name);
	void setmssv(string mssv)
	{
		this->mssv = mssv;
	}
		
	string getmssv()
	{
		return mssv;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
		
};
node::node(string mssv, string name)
{
	this->mssv = mssv;
	this->name = name;
}
node::node()
{

}
class list
{public:
	node* head;
	node* last;
	list();
	void insertlast(node* newnode);
	void remove(node* at);
	void print();
};
list::list()
{
	head = nullptr;
	last = nullptr;
}
void list::insertlast(node* newnode)
{
	if (!newnode) return;   
	if (!head)
	{
		head = newnode;
		last = newnode;
		return;
	}
	last->next = newnode;
	newnode->previous = last;
	newnode->next = nullptr;
	last = newnode;
}
void list::remove(node* at)
{
	if (!head) return;
	if (!at) return;
	if (at->previous) at->previous->next = at->next;
	else if (!at->previous)
	{
		head = at->next;
		at->next->previous = nullptr;

	}

	if (at->next)  at->next->previous = at->previous;
	else if (!at->next)
	{
		last = at->previous;
		at->previous->next = nullptr;
	}
}
void list::print()
{
	node* ip = head;
	while(ip)
	{
		cout << ip->mssv << "		";
		cout << ip->name << endl;
		ip = ip->next;
	}
}
class stack
{public:
	stack();
	list* l;
	void push(node* newnode);
	node* pop();
	node* top();
	bool isempty();
	
};
stack::stack()
{
	l = new list;
}
void stack::push(node* newnode)
{
	node* p = newnode;
	l->insertlast(p);
}
node* stack::pop()
{
	node* temp = l->last;
	l->remove(l->last);
	return temp;
}
node* stack::top()
{
	return l->last;
}

int main()
{
	stack* ptr = new stack;
	node* sv1 = new node("111", "Hoang Trung Nam");
	node* sv2 = new node("222", "Nguyen Huu Hoang");
	node* sv3 = new node("333", "Nguyen Nhat Minh");
	ptr->push(sv1);
	ptr->push(sv2);
	ptr->push(sv3);
	ptr->l->print();
	//node* sv = ptr->pop();
	//cout << sv->mssv << "      " << sv->name << endl;
	cout << ptr->pop()->mssv <<	endl;
	//cout << ptr->pop()->name << endl;
	ptr->l->print();
	cout << ptr->top()->mssv<<endl;
	system("pause");
	return 0;
}