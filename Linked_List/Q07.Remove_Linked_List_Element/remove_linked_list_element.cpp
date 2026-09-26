#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *current = dummy;

    while (current->next != NULL)
    {
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    return dummy->next;
}

int main()
{
    int n, val;
    cout<<"Enter the number of elements in the linked list: ";
    cin>>n;
    ListNode *head = nullptr;
    ListNode  *tail = nullptr;
    cout<<"Enter the elements of the linked list: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        ListNode *newNode = new ListNode(x);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout<<"Enter the value to be removed: ";
    cin>>val;
    head = removeElements(head, val);
    return 0;
}