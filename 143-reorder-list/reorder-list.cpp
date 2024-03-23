class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode*mid=middleNode(head);
        ListNode*revHead=reverseList(mid->next);

        ListNode*start=head;
        ListNode*end=revHead;
        mid->next=NULL;//break the LL 
        while(start && end){
            ListNode*ns=start->next;//ns:next of start
            ListNode*ne=end->next;//ne is next of end
            start->next=end;
            start->next->next=ns;
            start=ns;
            end=ne;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode*prevNode=NULL;
        ListNode*nextNode=head;
        while(head!=NULL){
            nextNode=head->next;
            head->next=prevNode;
            prevNode=head;
            head=nextNode;
        }
        return prevNode;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast ->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next; 
        }
        return slow;
    }
};