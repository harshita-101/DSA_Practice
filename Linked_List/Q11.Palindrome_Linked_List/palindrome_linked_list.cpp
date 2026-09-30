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

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = NULL;
    ListNode *curr = slow;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *left = head;
    ListNode *right = prev;

    while (right != NULL)
    {
        if (left->val != right->val)
        {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}

int main()
{
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        ListNode *newNode = new ListNode(value);

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

    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}