#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr), size(0) {}
    size_t get_size() { return size; }
    void add_at_tail(int val);
    void add_at_head(int val); // Новый метод
    void add_at_index(size_t index, int val);
    void delete_at_index(size_t index);
    void print(); // Новый метод
    void reverse(); // Новый метод

private:
    ListNode* head;
    size_t size;
};

void MyLinkedList::add_at_tail(int val) {
    ListNode* newNode = new ListNode(val, nullptr);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* it = head;
    while (it->next != nullptr)
        it = it->next;

    it->next = newNode;
    ++size;
}

void MyLinkedList::add_at_head(int val) {
    ListNode* newNode = new ListNode(val, head);
    head = newNode;
    ++size;
}

void MyLinkedList::delete_at_index(size_t index) {
    if (index >= size) {
        cout << "Index is larger than the size=" << size << "\n";
        return;
    }

    ListNode* prev = head;

    if (index == 0) {
        head = head->next;
        delete prev;
    }

    ListNode* curr = head->next;
    size_t pos = 0;

    while (prev != nullptr && pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }
    prev->next = curr->next;
    delete curr;

    --size;
}

void MyLinkedList::add_at_index(size_t index, int val) {
    if (index > size) {
        cout << "Index is larger than the size=" << size << "\n";
        return;
    }

    ListNode* prev = head;
    ListNode* curr = head;
    size_t pos = 0;

    while (curr != nullptr && pos < index) {
        prev = curr;
        curr = curr->next;
        ++pos;
    }

    ListNode* newNode = new ListNode(val, curr);
    prev->next = newNode;

    ++size;
}

void MyLinkedList::print() {
    ListNode* it = head;
    while (it != nullptr) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;
}

void MyLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    MyLinkedList* obj = new MyLinkedList();
    for (int val : arr) {
        obj->add_at_tail(val);
    }

    cout << "Original List: ";
    obj->print();

    cout << "Adding 10 at head: ";
    obj->add_at_head(10);
    obj->print();

    cout << "Deleting the last element: ";
    obj->delete_at_index(5);
    obj->print();

    cout << "Add at index 3: ";
    obj->add_at_index(2, 20);
    obj->print();

    cout << "Reversed List: ";
    obj->reverse();
    obj->print();

    return 0;
}
