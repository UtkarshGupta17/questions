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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* temp1=ans;
        ListNode* temp2=head->next;
        int sum=0;
        // cout<<head->val;
        while(temp2!=nullptr){
            if(temp2->val==0){
                temp1->next=new ListNode(sum);
                temp1=temp1->next;
                sum=0;
            }
            else{
                sum=sum+temp2->val;
            }
            temp2=temp2->next;
        }
        return ans->next;
        
    }
};