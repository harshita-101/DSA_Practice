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

ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int length = 1;
    ListNode *tail = head;

    while (tail->next != NULL)
    {
        length++;
        tail = tail->next;
    }

    k = k % length;

    if (k == 0)
    {
        return head;
    }

    int pos = 1;
    ListNode *current = head;
    while (pos < length - k)
    {
        current = current->next;
        pos++;
    }

    tail->next = head;
    head = current->next;
    current->next = NULL;

    return head;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = rotateRight(head, k);

    cout << "Rotated Linked List: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}

