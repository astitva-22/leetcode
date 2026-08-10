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
    private:
    ListNode* merge(ListNode* m1,ListNode* m2){
        ListNode *dumm=new ListNode(-1);
        ListNode* res=dumm;
        while(m1!=NULL && m2!=NULL){
            if(m1->val < m2->val){
                res->next = m1;
                res=m1;
                m1=m1->next;
            }
            else {
                res->next = m2;
                res=m2;
                m2=m2->next;
            }
        }
        if(m1!=NULL) res->next=m1;
        if(m2!=NULL) res->next=m2;

        return dumm->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0) return NULL;
        // ListNode* head= lists[0];
        // for(int i=1;i<lists.size();i++){
        //     head = merge(head,lists[i]);
        // }
        // return head;

        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dum = new ListNode(-1);
        ListNode* ans=dum;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ans->next=it.second;
            ans = it.second;
            if(it.second->next!=NULL) pq.push({it.second->next->val,it.second->next});
        }
        return dum->next;
    }
};