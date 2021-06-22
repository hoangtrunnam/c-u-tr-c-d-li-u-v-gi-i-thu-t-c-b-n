/******************************************************************************

BÀI TẬP DOUBLE LINKED LIST (DANH SÁCH LIÊN KẾT KÉP)

Cho lớp TT&CDTL: 64IT5 - NUCE
Giảng viên: Đoàn Như Tùng

Bài tập này dùng ds liên kết kép để quản lý một danh sách khách hàng, gồm sđt,
họ và tên.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//===============================================================================
// Class này đại diện cho một node trong danh sách liên kết kép`

class Node {
public:
    // các trường dữ liệu
    string sdt;
    string ho;
    string ten;

    // các con trỏ xuôi, ngược
    Node* next;
    Node* previous;

    // hàm khởi tạo
    Node(string sdtMoi, string hoMoi, string tenMoi);

    // in ra node này
    void print();
};

class DBList {
private:
    Node* first;
    Node* last;

public:
    // hàm khởi tạo mặc định
    DBList();

    // Hàm hủy
    ~DBList();

    //------------------------------------------------------------------
    // Các hành vi chính của danh sách liên kết (giao diện lập trình)

    void insertFirst(Node* n);            // chèn node n vào đầu danh sách
    void insertLast(Node* n);             // chèn node n vào cuối danh sách
    void insertBefore(Node* n, Node* at); // chèn node n vào ngay trước node at
    void insertAfter(Node* n, Node* at);  // chèn node n vào ngay sau node at
    void removeAt(Node* at);               // gỡ node at khỏi danh sách

    Node* findSdt(string sdttofind);            // tìm một node có sdt trong tham số

    void print();           // in theo thứ tự xuôi
    void printReversed();   // in theo thứ tự ngược
};

//*******************************************************************
//    CÁC BIẾN GLOBAL

DBList* myList = nullptr;    // biến global này trỏ tới danh sách chúng ta đang quản lý

//*******************************************************************


//===================================================================
//     CÀI ĐẶT CÁC HÀM THÀNH VIÊN (HÀNH VI) CỦA LỚP Node

// Hàm khởi tạo với giá trị khởi tạo của 3 thuộc tính
Node::Node(string sdtMoi, string hoMoi, string tenMoi)
{
    sdt = sdtMoi;
    ho = hoMoi;
    ten = tenMoi;

    next = nullptr;
    previous = nullptr;
}

void Node::print()
{
    cout << "[ " << sdt << " " << ho << " " << ten << " ]" << endl;
}

//===================================================================
//     CÀI ĐẶT CÁC HÀM THÀNH VIÊN (HÀNH VI) CỦA LỚP DBList

// Hàm khởi tạo mặc định
DBList::DBList()
{
    first = nullptr;
    last = nullptr;
}

// Hàm hủy
DBList::~DBList()
{
    // Phải gỡ và hủy tất cả các node trong danh sách
    // chừng nào còn có node trong danh sách thì còn tiếp tục gỡ và hủy

    //************* STUDENT TO DO ****************************
/*
    while(first)// duyet tu dau den cuoi
    {
        Node* ip=first; // luu lai con tro ma no tro den not day
       removeAt(first); // xoa not khoi ds
        delete ip;  // tra lai o nho

    }
*/


//************* END OF STUDENT CODE **********************
}

// Chèn node n vào đầu danh sách
void DBList::insertFirst(Node* n)
{
    if (!n) return;   // node n phải được khởi tạo rồi

    //************* STUDENT TO DO ****************************
    if (!first)
    {
        first = n;
        last = n;
        return;
    }
    n->next = first;
    first->previous = n;
    n->previous = nullptr;
    first = n;




    //************* END OF STUDENT CODE **********************
}

// Chèn node n vào cuối danh sách
void DBList::insertLast(Node* n)
{
    if (!n) return;   // node n phải được khởi tạo rồi

    //************* STUDENT TO DO ****************************
    if (!first)
    {
        first = n;
        last = n;
        return;
    }
    last->next = n;
    n->previous = last;
    n->next = nullptr;
    last = n;

    //************* END OF STUDENT CODE **********************
}

// Chèn node n vào ngay trước node at.
// at phải trỏ tới 1 node hợp lệ trong danh sách (ví dụ từ hàm tìm kiếm)
void DBList::insertBefore(Node* n, Node* at)
{
    if (!n) return;   // node n phải được khởi tạo rồi
    if (!at) return;  // node at phải có giá trị hợp lệ (từ hàm tìm kiếm)

    //************* STUDENT TO DO ****************************
    if (!first)
    {
        first = n;
        last = n;
        return;
    }
    n->next = at;
    n->previous = at->previous;
    if (at->previous)
    {
        at->previous->next = n;
    }
    else
    {
        first = n;
        n->previous = nullptr;
    }
    at->previous = n;


    //************* END OF STUDENT CODE **********************
}

// Chèn node n vào ngay sau node at.
// at phải trỏ tới 1 node hợp lệ trong danh sách (ví dụ từ hàm tìm kiếm)
void DBList::insertAfter(Node* n, Node* at)
{
    if (!n) return;   // node n phải được khởi tạo rồi
    if (!at) return;  // node at phải có giá trị hợp lệ (từ hàm tìm kiếm)

    //************* STUDENT TO DO ****************************
    if (!first)
    {
        first = n;
        last = n;
        return;
    }
    n->next = at->next;
    n->previous = at;
    if (at->next)
    {
        at->next->previous = n;
    }
    else
    {
        last = n;
        n->next = nullptr;
    }
    at->next = n;


    //************* END OF STUDENT CODE **********************
}

// Gở node at khỏi danh sách.
// at phải trỏ tới 1 node hợp lệ trong danh sách (ví dụ từ hàm tìm kiếm)
void DBList::removeAt(Node* at)
{
    if (!at) return;  // node at phải có giá trị hợp lệ (từ hàm tìm kiếm)

    //************* STUDENT TO DO ****************************

    if (at->previous) at->previous->next = at->next;
    else if (!at->previous)
    {
        first = at->next;
        at->next->previous = nullptr;

    }

    if (at->next)  at->next->previous = at->previous;
    else if (!at->next)
    {
        last = at->previous;
        at->previous->next = nullptr;
    }

    //************* END OF STUDENT CODE **********************
}

// Tìm node với sđt trong tham số
// Trả về con trỏ tới node tìm được, trả về nullptr nếu ko tìm thấy.
Node* DBList::findSdt(string sdttofind)
{
    //************* STUDENT TO DO ****************************

    Node* ip = first;
    if (!first)
        return nullptr;
    while (ip)
    {
        if (ip->Node::sdt == sdttofind) return ip;
        ip = ip->next;
    }
    return nullptr;
    //************* END OF STUDENT CODE **********************
}

// In danh sách theo thứ tự xuôi
void DBList::print()
{
    //************* STUDENT TO DO ****************************
    Node* ip = first;
    while (ip)
    {
        ip->Node::print();
        ip = ip->next;
    }

    //************* END OF STUDENT CODE **********************
}

// In danh sách theo thứ tự ngược
void DBList::printReversed()
{
    //************* STUDENT TO DO ****************************
    Node* ip = last;
    while (ip)
    {
        ip->Node::print();
        ip = ip->previous;
    }

    //************* END OF STUDENT CODE **********************
}


//========================================================================
// Tùy vào giá trị của testNum mà ta sẽ chạy test tương ứng

void runTest(int testNum)
{
    Node* n, * at;
    string s1, s2, s3, s4;

    switch (testNum) {
    case 1:
        cout << "----- Đầu danh sách -----\n";
        myList->print();
        cout << "--------------------------\n";
        break;

    case 2:
        cout << "----- Cuối danh sách -----\n";
        myList->printReversed();
        cout << "--------------------------\n";
        break;

    case 3:
        cin >> s1 >> s2 >> s3;
        n = new Node(s1, s2, s3);
        myList->insertFirst(n);
        cout << "\n>>> Đã chèn thành công.\n";
        break;

    case 4:
        cin >> s1 >> s2 >> s3;
        n = new Node(s1, s2, s3);
        myList->insertLast(n);
        cout << "\n>>> Đã chèn thành công.\n";
        break;

    case 5:
        cin >> s1;
        n = myList->findSdt(s1);
        if (n) {
            cout << "\n>>> Tìm thấy:\n";
            n->print();
            cout << endl;
        }
        else {
            cout << "\n>>> Khong tim thay sdt nay.\n";
        }
        break;

    case 6:
        cin >> s1 >> s2 >> s3 >> s4;
        at = myList->findSdt(s4);
        if (at) {
            n = new Node(s1, s2, s3);
            myList->insertAfter(n, at);
            cout << "\n>>> Đã chèn thành công.\n";
        }
        else {
            cout << "\n>>> Không tìm thấy sđt này.\n";
        }
        break;

    case 7:
        cin >> s1 >> s2 >> s3 >> s4;
        at = myList->findSdt(s4);
        if (at) {
            n = new Node(s1, s2, s3);
            myList->insertBefore(n, at);
            cout << "\n>>> Đã chèn thành công.\n";
        }
        else {
            cout << "\n>>> Khong tim thay sđt này.\n";
        }
        break;

    case 8:
        cin >> s1;
        n = myList->findSdt(s1);
        if (n) {
            myList->removeAt(n);
            cout << "\n>>> Đã gỡ khỏi danh sách: ";
            n->print();
            cout << endl;

            delete n;
            n = nullptr;
        }
        else {
            cout << "\n>>> Không tìm thấy sđt này.\n";
        }
        break;

    case 9:
        n = new Node("098.123.4444", "Trần", "Kiên");
        myList->insertFirst(n);
        n = new Node("03.12.34.1111", "Lê", "Hoàng");
        myList->insertFirst(n);
        n = new Node("097.999.8888", "Nguyễn", "Thắng");
        myList->insertLast(n);
        myList->print();
        myList->printReversed();
        delete myList;
        myList = nullptr;
        myList = new DBList();
        break;

    case 10:
        n = new Node("098.123.4444", "Trần", "Kiên");
        myList->insertFirst(n);
        n = new Node("03.12.34.1111", "Lê", "Hoàng");
        myList->insertFirst(n);
        n = new Node("097.999.8888", "Nguyễn", "Thắng");
        myList->insertLast(n);
        n = new Node("03.5555.1111", "Hoàng", "Minh");
        at = myList->findSdt("097.999.8888");
        myList->insertAfter(n, at);
        n = new Node("09.2222.3333", "Phạm", "Vân");
        myList->insertBefore(n, at);
        myList->print();
        myList->printReversed();
        delete myList;
        myList = nullptr;
        myList = new DBList();
        break;

    case 11:
        n = new Node("098.123.4444", "Trần", "Kiên");
        myList->insertFirst(n);
        n = new Node("03.12.34.1111", "Lê", "Hoàng");
        myList->insertFirst(n);
        n = new Node("097.999.8888", "Nguyễn", "Thắng");
        myList->insertLast(n);
        n = new Node("024.5556.7777", "Đỗ", "Lan");
        at = myList->findSdt("03.12.34.1111");
        myList->insertBefore(n, at);
        n = new Node("099.1234.5678", "Lý", "Sơn");
        myList->insertAfter(n, at);
        myList->print();
        myList->printReversed();
        delete myList;
        myList = nullptr;
        myList = new DBList();
        break;

    case 12:
        n = new Node("098.123.4444", "Trần", "Kiên");
        myList->insertFirst(n);
        n = new Node("03.12.34.1111", "Lê", "Hoàng");
        myList->insertFirst(n);
        n = new Node("097.999.8888", "Nguyễn", "Thắng");
        myList->insertLast(n);
        n = new Node("03.5555.1111", "Hoàng", "Minh");
        at = myList->findSdt("097.999.8888");
        myList->insertAfter(n, at);
        n = new Node("09.2222.3333", "Phạm", "Vân");
        myList->insertBefore(n, at);
        n = new Node("024.5556.7777", "Đỗ", "Lan");
        at = myList->findSdt("03.12.34.1111");
        myList->insertBefore(n, at);
        n = new Node("099.1234.5678", "Lý", "Sơn");
        myList->insertAfter(n, at);

        at = myList->findSdt("024.5556.7777");
        myList->removeAt(at);
        at = myList->findSdt("03.5555.1111");
        myList->removeAt(at);
        at = myList->findSdt("098.123.4444");
        myList->removeAt(at);
        myList->print();
        myList->printReversed();
        delete myList;
        myList = nullptr;
        myList = new DBList();
        break;

    default:
        cout << "\nERROR: Unhandled test number!\n";
        break;
    }
}

int main()
{
    // vì myList là con trỏ nên phải khởi tạo danh sách mới và gán vào myList
    myList = new DBList();

    /*------- CÁCH CHẠY CHƯƠNG TRÌNH : CÁC MÃ LỆNH --------------------------------

    0                     --> Kết thúc.
    1                     --> In danh sách (thứ tự xuôi).
    2                     --> In danh sách (thứ tự ngược)..
    3 sdt ho ten          --> Chèn đầu.
    4 sdt ho ten          --> Chèn cuối.
    5 sdt                 --> Tìm và in ra node có sdt này.
    6 sdt ho ten sauSdt   --> Chèn sau node này.
    7 sdt ho ten truocSdt --> Chèn trước node.
    8 sdt                 --> Tìm node và gỡ khỏi danh sách.
    9  --> Test case 1.
    10 --> Test case 2.
    11 --> Test case 3.
    12 --> Test case 4.
    --------------------------------------------------------------------------------*/

    // liên tục nhận lệnh và chạy test tùy theo mã lệnh
    while (true) {
        int cmd;

        cout << "\n------------------------\n";
        cout << "Your command: ";

        cin >> cmd;
        if (1 <= cmd && cmd <= 12)
            runTest(cmd);
        else
            break;
    }


    // Phải nhớ hủy những cấu trúc dữ liệu đã khỏi tạo

    delete myList;     // xem thêm hàm hủy của DBList

    return 0;
}


