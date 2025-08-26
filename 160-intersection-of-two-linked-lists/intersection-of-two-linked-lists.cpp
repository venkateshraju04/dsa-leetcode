/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1=headA;
        ListNode* ptr2=headB;
        while(ptr1!=ptr2){
            if(ptr1!=nullptr){
                ptr1=ptr1->next;
            }
            else if(!ptr1){
                ptr1=headB;
            }
            if(ptr2!=nullptr){
                ptr2=ptr2->next;
            }else{
                ptr2=headA;
            }

        }
        return ptr1;
    }
};