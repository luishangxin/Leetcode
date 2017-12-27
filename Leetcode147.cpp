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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp=head,*l=head,*r;
        while(temp){
            r=temp->next;
            while(r&&l!=r){
                if(r->val<l->val){
                    auto t = l->val;
                    l->val = r->val;
                    r->val =t;
                }
                l = l->next;
            }
            l=head;
            temp =temp->next;
        }
        return head;
    }
};