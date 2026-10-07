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

ListNode *reverseBetween(ListNode *head, int left, int right)
{

    if (head == NULL || left == right)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    // left position se just pehle tak jao
    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    ListNode *current = prev->next;

    // left se right tak reverse karo
    for (int i = 0; i < right - left; i++)
    {
        ListNode *nextNode = current->next;

        current->next = nextNode->next;

        nextNode->next = prev->next;

        prev->next = nextNode;
    }

    return dummy->next;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        ListNode *newNode = new ListNode(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int left, right;

    cout << "Enter left position: ";
    cin >> left;

    cout << "Enter right position: ";
    cin >> right;

    head = reverseBetween(head, left, right);

    cout << "Linked List after reversing: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}