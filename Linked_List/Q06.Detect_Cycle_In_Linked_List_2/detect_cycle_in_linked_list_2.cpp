#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};


int main()
{
    int n;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    ListNode *head = NULL;
    ListNode *curr = NULL;

    cout << "Enter the values of the nodes: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

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

    int pos;

    cout << "Enter the position where cycle should start (-1 for no cycle): ";
    cin >> pos;

    // Create cycle
    if (pos >= 0 && pos < n)
    {
        ListNode *cycleNode = head;

        for (int i = 0; i < pos; i++)
        {
            cycleNode = cycleNode->next;
        }

        curr->next = cycleNode;
    }

    Solution obj;

    ListNode *cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL)
    {
        cout << "Cycle starts at node with value: "
             << cycleStart->val << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }

    return 0;
}