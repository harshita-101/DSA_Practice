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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *current = dummy;

    while (current->next != NULL)
    {
        if (current->next->next != NULL &&
            current->next->val == current->next->next->val)
        {
            int duplicate = current->next->val;

            while (current->next != NULL &&
                   current->next->val == duplicate)
            {
                current->next = current->next->next;
            }
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
    int n;
    cout << "Enter the value of nodes in List: ";
    cin >> n;

    if (n < 0)
    {
        cout << "List is empty.";
        return 0;
    }

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
    head = deleteDuplicates(head);

    cout << "Linked List after removing duplicates.";

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}