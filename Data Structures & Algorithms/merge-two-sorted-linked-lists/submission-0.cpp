/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* move1=list1;
        ListNode* move2=list2;
        ListNode* ans;
        if(list1->val<=list2->val){
            ans=list1;
            move1=move1->next;
        }
        else{
            ans=list2;
            move2=move2->next;
        }
        ListNode* move3=ans;
        while(move1!=NULL && move2!=NULL){
            if(move1->val<=move2->val){
                move3->next=move1;
                move1=move1->next;
            }
            else{
                move3->next=move2;
                move2=move2->next;
            }
            move3=move3->next;
        }
        if(move1!=NULL){
            move3->next=move1;
            move1=move1->next;
        }
        if(move2!=NULL){
            move3->next=move2;
            move2=move2->next;
        }
        return ans;
    }
};
