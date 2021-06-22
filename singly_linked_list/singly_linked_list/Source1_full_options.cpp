#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int mssv;
    string name;
    node* next;
    node* previous= nullptr;
    node(int mssv, string name);
};
node::node(int mssv, string name)
{
    previous = nullptr;
    this->mssv = mssv;
    this->name = name;
}

class list_A
{
public:
    node* head;
    node* last;
    list_A();// hàm khởi tạo. định nghĩa hàm này ở bên dưới
    void print();// hàm in kết quả ra màn hình
    void inserth(node* newnode);
    void insertl1(node* newnode);
    void insertl2(node* newnode);
    void insertafter(node* at, node* newnode);
    node* lookup(int mssvtofind);
    void insertpre(node* at, node* newnode);
    node* removed(node* at);
    void print_reversed();
};

// định nghĩa hàm khởi tạo:
list_A::list_A()
{
    head = nullptr;
    last = nullptr;
}
// dinh nghia ham print nguoc
void list_A::print_reversed()
{
    node* ip = last;
    while (ip)
    {
        cout << ip->mssv << endl;
        cout << ip->name << endl;
        ip = ip->previous;
    }
    if (ip->previous == head)
        return;
}
// định nghĩa hàm print xuoi
void list_A::print()
{
    node* ip;
    ip = head;
    while (ip)// ip!=null ptr
    {
        cout << ip->mssv << endl;
        cout << ip->name << endl;
        ip = ip->next;
    }
}
// định nghĩa hàm insert. hàm insert ở đây là insert vào đầu dslk
void list_A::inserth(node* newnode)
{
    // ở đây có thể thêm 1 điều kiện để kiểm tra xem ram còn bộ nhớ để cấp phát cho newnode hay ko:
     if(!newnode)
         return;
     if (!head)
     {
         head = newnode;
         last = newnode;
         return;
     }
     newnode->next = head;
     head->previous = newnode;
     head = newnode;
       
}
// định nghĩa hàm insert vao cuối dslk. làm theo cách này thì phải duyệt từ đầu
void list_A::insertl1(node* newnode)
{
    node* ip = head;

    if (!head)// head= nullptr . kiểm tra xem ds có rỗng hay ko
    {
        head = newnode;
        newnode->next = nullptr;
        newnode->previous = nullptr;
        return;
    }

    while (ip)
    {
        last = ip;
        ip = ip->next;
    }
    last->next = newnode;
    newnode->previous = last;
    last = newnode;
    newnode->next = nullptr;

}
// đây cũng là insert vào cuối danh sách nhưng ko cần duyệt từ đầu
void list_A::insertl2(node* newnode)
{


    if (!head)// kiem tra xem danh sach co rong hay ko.
    {
        head = newnode;
        last = newnode;
        last->next = nullptr;

    }
    last->next = newnode;
    newnode->previous = last;
    last = newnode;// phần này thầy dạy thiếu
    newnode->next = nullptr;
}

void list_A::insertafter(node* at, node* newnode)
{
    if (!head)
    {
        head = newnode;
        last=newnode;  //có hay ko cũng ok. nhưng nếu dùng last thì phải có
        return;
    }
    newnode->next = at->next;
    at->next = newnode;
}

node* list_A::lookup(int mssvtofind)
{
    node* ip = head;
    while (ip)
    {
        if (ip->mssv == mssvtofind) return ip;// chỉ tìm theo mssv, có thể thêm các dữ liệu tìm kiếm khác
        ip = ip->next;
    }
    return nullptr;
}

// chèn vào giua dslk - chèn phía trước 1 phần tử nào đó
void list_A::insertpre(node* at, node* newnode)
{
    if (!head)
    {
        head = newnode;
        
        return;
    }
    else
    {
        newnode->next = at;
        newnode->previous= at->previous; //tại sao at->pre =null ??? 
        if (at->previous)
        {
            at->previous->next = newnode;
        }
       // else head = newnode; // dùng khi sử dụng insert head
        at->previous = newnode;
    }

}
node* list_A::removed(node* at)
{
    if (!head)
        return nullptr;
    if (at->previous)
        at->previous->next = at->next;
    if (at->next)
        at->next->previous = at->previous;
}
int main()
{
    list_A* it5 = new list_A;
    node* sv1;
    node* sv2;
    node* sv3;
    node* sv4;
    node* sv5;
    sv1 = new node(111, "nam");
    
    sv2 = new node(222, "hoang");
    sv3 = new node(333, "trung");
    sv4 = new node(444, "64it5");
    sv5 = new node(555, "1535864");
    it5->inserth(sv1);
    it5->inserth(sv5);
    it5->insertl2(sv2);
   // it5->insertafter(sv1,sv3);// thêm cái sv3 vào sau cái sv1
    //it5->insertpre(sv2, sv4); // thêm sv4 vào trước sv2
   // it5->removed(sv5);


    sv1 = it5->lookup(222);
    if (sv1)// sv1!= nullptr
    {
        cout << "ket qua sau khi tim duoc la: " << endl;
        cout << sv1->mssv << endl;
        cout << sv1->name << endl << endl;
    }
    else // sv1= nullptr
    {
        cout << "ko tim duoc" << endl;
    }


    it5->print();
     system("pause");
    return 0;
}
