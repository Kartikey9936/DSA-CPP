#include<isostream>
using namespace std;

class Node{
    
}

// add two linked lists 


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while (t1 != NULL || t2 != NULL){
            int sum = carry;
            if(t1) sum= sum + t1->val; //if t1 is there 
            if(t2) sum = sum +t2->val;
            ListNode* newN = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newN;
            curr = curr->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        //if any carry is left
        if(carry){
            ListNode* node = new ListNode(carry);
            curr->next = node;
        } 

        return dummy->next;
        
    }
};


// delete node without head pointer
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
        
    }

};

middle node of linked list
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Step 1: Find the length of the linked list
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Step 2: Calculate middle index
        int mid = len / 2;

        // Step 3: Traverse to the middle node
        temp = head;

        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        // Step 4: Return the middle node
        return temp;
    }
};


SLOW AND FAST POINTER APPROACH

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;


    }
};
