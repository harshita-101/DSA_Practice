#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the no of nodes in the linked list: ";
    cin>>n;

    ListNode *head = NULL;
    ListNode *curr = NULL;

    cout<<"Enter the values of the nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        ListNode *newNode = new ListNode(val);
        if (head == NULL)
        {
            head = newNode;
            curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }

    // Create a cycle for testing (optional)
    // Uncomment the following lines to create a cycle
    // curr->next = head->next->next;

    if (hasCycle(head))
    {
        cout<<"The linked list has a cycle."<<endl;
    }
    else
    {
        cout<<"The linked list does not have a cycle."<<endl;
    }

    return 0;
}