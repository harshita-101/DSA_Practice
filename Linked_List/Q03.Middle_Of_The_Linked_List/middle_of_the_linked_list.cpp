#include<iostream>
#include<list>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    // Create a simple linked list for testing
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;
    ListNode* head = NULL;
    ListNode* current = NULL;
    cout<<"Enter the values for each node: ";
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        ListNode* newNode = new ListNode(val);
        if(head == NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }
    }
    ListNode* middle = middleNode(head);
    cout<<"The middle node has the value: "<<middle->val<<endl;
    return 0;
}