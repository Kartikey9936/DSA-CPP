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

REVERSE LINKED LIST by using stack fifo
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;

        
    }
};


reverse linked list 2
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right ) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i = 1; i<left ; i++){
            prev = prev->next;

        }
        ListNode* curr = prev->next;
        ListNode* prevnode = NULL;
        ListNode* currnode = curr;
        for(int i =0;i<right-left+1;i++){
            ListNode* next_node = currnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = next_node;


        }
        prev->next = prevnode;
        curr->next = currnode;

        return dummy->next;

        
    }
    
};

check if linked list has cycle or not
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;

        }
        return false;
        
        

        
    }
    
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                slow = head;
               while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
                }
                return slow;

            }
            
            

        }
        return NULL;

        

        
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL ) return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newhead = reverse(slow->next);
        ListNode* l = head;
        ListNode* r = newhead;
        while(r != NULL){
            if( l->val != r->val){
            reverse(newhead);
            return false;
            }

            l = l->next;
            r = r->next;
        }
        reverse(newhead);
        return true;

        
    }
};

remove nth node from the end of linked list

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* dummy = new ListNode(0);
        
        ListNode* fast = head;
        for(int i = 0;i<n;i++){
            fast = fast->next;
        }
        if(fast == NULL ) return head->next;
        ListNode* slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;

        }
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete(delnode);
        return head;




        
    }
};


fast->next != NULL && fast != NULL   ❌ wrong order → crash

