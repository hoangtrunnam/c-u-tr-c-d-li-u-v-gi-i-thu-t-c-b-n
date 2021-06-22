#include <iostream>
#include <string>
using namespace std;
#define queueMaxSize 100
class queueElement
{
public:
	string mssv;
	string name;
	queueElement(string mssv, string name);
};
queueElement::queueElement(string mssv, string name)
{
	this->mssv = mssv;
	this->name = name;
}

class queue
{
private:
	queueElement* a[queueMaxSize];
	int head, last, length;
public:
	queue();
	~queue();
	queueElement* enQueue(queueElement* e);
	queueElement* deQueue();
	queueElement* font();
	bool isempty();
	void print();

};
queue::queue()
{
	length = 0;
	head = -1;
	last = -1;
}

queueElement* queue::enQueue(queueElement* e)
{
	if (length == 0)
	{
		a[0] = e;
		head = 0;
		last = 0;
		length = 1;
		return e;
	}
	if (length >= queueMaxSize)
		return nullptr;

	last++;            // tăng biến last lên 1 đơn vị

	if (last >= queueMaxSize)
		last = 0;

	a[last] = e;
	length++;
	return e;
	
}

queueElement* queue::deQueue()
{
	if (length == 0)
		return nullptr;
	int h = head;
	head++;
	if (head >= queueMaxSize)
		head = 0;
	length--;
	return a[h];
}

bool queue::isempty()
{
	if (length == 0)
		return 1;
	return 0;
}

void queue::print()
{
	// duyet tu cuoi mang 
	for (int i = last; i>=head; i--)
	{
		cout << a[i]->mssv << endl;
		cout << a[i]->name << endl;
	}
	
}

queueElement* queue::font()
{
	if (!length)
		return nullptr;
	return a[head];
}





int main()
{
	queue* ptr = new queue;
	queueElement* sv1 = new queueElement("111", "Hoang trung nam");
	queueElement* sv2 = new queueElement("222", "nguyen minh hoang");
	queueElement* sv3 = new queueElement("333", "vu hong anh");
	queueElement* sv4 = new queueElement("444", "mai van quy");
	ptr->enQueue(sv1);
	ptr->enQueue(sv2);
	ptr->enQueue(sv3);
	ptr->enQueue(sv4);

	// kiem tra xem co rong hay ko
	if (ptr->isempty() == 1)
		cout << "mang rongg " << endl;
	else cout << "ok " << endl;

	// dequeue 
	cout << "phan tu dequeue la: " << endl;
	cout<<ptr->deQueue()->mssv<<endl;
	cout<<ptr->deQueue()->mssv<<endl;
	//cout << ptr->deQueue()->mssv << endl;
	
	//font
	cout << "phan tu dung dau hang la: "<<endl;
	cout<<ptr->font()->mssv<<endl;

	//print xem con lai trong mang bao nhieu phan tu
	cout << "phan tu con lai sau khi thuc hien cac lenh la: "<<endl;
	ptr->print();


	return 0;
}