class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toBeDel;
        for(auto & num : nums)toBeDel.insert(num);
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *curr = dummyHead, *prev = dummyHead;
        while(curr != NULL){
            ListNode *nextNode = curr->next;
            if(toBeDel.count(curr->val) != 0){
                prev->next = nextNode;
            }else{
                prev = curr;
            }
            curr = nextNode;
        }
        return dummyHead->next;
    }
};
