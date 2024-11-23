#include <iostream>
using namespace std;

template<typename T>
class LL {
    struct node {
        T data;
        struct node* next;
    };
    struct node *head;
    struct node *tail;
    int length;

public:
    LL() : head(NULL), tail(NULL), length(0) {}
    ~LL() {
        Clear();
    }
    node* Init(T);
    bool Is_empty();
    LL& Add(T);
    void Add_begin(T);
    void Add_after(T, T);
    void Del(T);
    void PopEnd();
    void PopBegin();
    void Clear();
    int Count();
    node* Search(T);
    void Display();
    void Reverse();
};

template <typename T>
typename LL<T>::node* LL<T>::Init(T val) {
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}
template <typename T>
bool LL<T>::Is_empty() {
    if (head == NULL) cout << "List is empty";
    return head == NULL;
}
template <typename T>
LL<T>& LL<T>::Add(T val) {
    node* temp = Init(val);
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    length++;
    return *this;
}
template <typename T>
void LL<T>::Add_begin(T val) {
    node *temp = Init(val);
    temp->next = head;
    head = temp;
    length++;
}
template <typename T>
void LL<T>::Add_after(T val, T target) {
    node *cur = Search(target);
    if (cur == NULL) {
        cout << "Target value not found in the list.\n";
        return;
    }
    node *temp = Init(val);
    temp->next = cur->next;
    cur->next = temp;
    if (temp == NULL) tail = temp;
    length++;
}
template <typename T>
void LL<T>::Del(T target) {
    if (Is_empty()) 
        return;
    if (head->data == target) {
        PopBegin();
        return;
    }
    node *cur = head;
    while (cur->next != NULL && cur->next->data != target)
    {
        cur = cur->next;
    }
    if (cur->next == NULL) {
        cout << "Target Value not found in the list\n";
    }
    node *temp = cur->next;
    cur->next = cur->next->next;
    if (temp == tail) tail = cur;
    delete temp;
    length--;
}
template <typename T>
void LL<T>::PopBegin() {
    if (Is_empty()) 
        return;
    node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
    length--;
};
template <typename T>
void LL<T>::PopEnd() {
    if (Is_empty()) 
        return;
    if (head == tail) {
        delete head;
        head = tail = NULL;
        length--;
        return;
    }
    node *cur = head;
    node* temp;
    while (cur->next!=tail) {
        cur = cur->next;
    }
    delete tail;
    cur->next = NULL;
    tail = cur;
    length--;
};
template <typename T>
typename LL<T>::node* LL<T>::Search(T target) {
    node *cur = head;
    while (cur != NULL) {
        if (cur->data == target) {
            break;
        }
        cur = cur->next;
    }
    return cur;
}
template <typename T>
int LL<T>::Count() {
    return length;
}
template <typename T>
void LL<T>::Display() {
    if (Is_empty()) 
        return;
    node *cur = head;
    cout << "List : ";
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}
template <typename T>
void LL<T>::Clear() {
    if (Is_empty()) return;
    while (head != NULL)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    tail = NULL;
    cout << "List cleared\n";
}
template <typename T>
void LL<T>::Reverse() {
    if (Is_empty())
        return;
    node* prev = NULL;
    node* after = NULL;
    node* cur = head;
    
    while (cur != NULL)
    {
        after = cur->next;
        cur->next = prev;
        prev = cur;
        cur = after;
    }
    tail = head;
    head = prev;
}
int main() {
    LL<int> list;
    list.Add(50).Add(40).Add(30).Add(20).Add(10);
    list.Display();
    list.Del(10);
    list.Display();
    list.Add_after(25, 40);
    list.Display();
    list.Add_begin(200);
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}
