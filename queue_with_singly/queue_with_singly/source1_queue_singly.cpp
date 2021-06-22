#include <iostream>
using namespace std;
class queueElement
{public:

	string mssv;
	string name;
	queueElement(string mssv, string name);
};
queueElement::queueElement(string mssv, string name)
{
	this->mssv = mssv;
	this->name = name;
}

class node
{public:
	node();
	queueElement* d;
	node* next;
};
node::node()
{
	
}

class queue
{public:
	node* first;
	node* last;
	queue();
	~queue();
	queueElement* enqueue(queueElement* e);
	queueElement* dequeue();
	queueElement* font();
	bool isempty();
	void print();
};
queue::queue()
{
	first = nullptr;
	last = nullptr;
}

queueElement* queue::enqueue(queueElement* e)
{
	node* n = new node();
	n->d = e;
	n->next = nullptr;
	if (last)
		last->next = n;
	else
		first = n;
	last = n;
	return e;
}
queueElement* queue::dequeue()
{
	if (!first)
		return nullptr;
	node* n = first;
	first = first->next;
	if (!first)
		last = nullptr;
	queueElement* e = n->d;
	delete n;
	return e;
}
queueElement* queue::font()
{
	if (!first)
		return nullptr;
	return first->d;
}
bool queue::isempty()
{
	if (!first)
		return 1;
	return 0;
}

void queue::print()
{
	node* ip = first;
	while (ip)
	{
		cout << ip->d->mssv << endl;
		cout << ip->d->name << endl;
		ip = ip->next;
	}
}
int main()
{
	queue* ptr = new queue;
	queueElement* sv1 = new queueElement("111", "hoang trung nam");
	queueElement* sv2 = new queueElement("222", "nguyen hoang minh");
	queueElement* sv3 = new queueElement("333", "mai van long");

	ptr->enqueue(sv1);
	ptr->enqueue(sv2);
	ptr->enqueue(sv3);
	if (ptr->isempty() == 1)
		cout << "null"<<endl;
	else
		cout << "not null"<<endl;
	cout << "go node ra khoi danh sach: " << endl;
	cout << ptr->dequeue()->mssv<<endl;
	//cout << ptr->dequeue()->mssv;
	cout << "phan tu dung dau trong danh sach: " << endl;
	cout << ptr->font()->mssv<<endl;
	cout << "danh sach con lai la: " << endl;
	ptr->print();
	return 0;
}