#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int x) : val(x), next(NULL), random(NULL) {}
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<Node *, Node *> m;

    // Step 1: Create copy of all nodes
    Node *newHead = new Node(head->val);

    m[head] = newHead;

    Node *oldTemp = head->next;
    Node *newTemp = newHead;

    while (oldTemp != NULL)
    {
        Node *copyNode = new Node(oldTemp->val);

        m[oldTemp] = copyNode;
        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    // Step 2: Connect random pointers
    oldTemp = head;
    newTemp = newHead;

    while (oldTemp != NULL)
    {
        if (oldTemp->random != NULL)
        {
            newTemp->random = m[oldTemp->random];
        }

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "Node: " << temp->val;

        if (temp->random != NULL)
        {
            cout << ", Random: " << temp->random->val;
        }
        else
        {
            cout << ", Random: NULL";
        }

        cout << endl;

        temp = temp->next;
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements in the Linked List: ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    cout << "Enter the elements of the Linked List: ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if (head == NULL)
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

    // Store all nodes for setting random pointers
    Node **nodes = new Node *[n];

    Node *temp = head;

    for (int i = 0; i < n; i++)
    {
        nodes[i] = temp;
        temp = temp->next;
    }

    // Set random pointers
    cout << "\nEnter random pointer position for each node.\n";
    cout << "Use -1 for NULL.\n";

    for (int i = 0; i < n; i++)
    {
        int pos;

        cout << "Random of node " << nodes[i]->val << ": ";
        cin >> pos;

        if (pos >= 0 && pos < n)
        {
            nodes[i]->random = nodes[pos];
        }
    }

    // Create deep copy
    Node *newHead = copyRandomList(head);

    // Print copied list
    cout << "\nCopied Linked List:\n";
    printList(newHead);

    delete[] nodes;

    return 0;
}