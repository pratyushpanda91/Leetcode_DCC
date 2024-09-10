class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while (node2 != nullptr) {
            int gcdValue = calculateGCD(node1->val, node2->val);
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insert gcdNode between node1 and node2
            node1->next = gcdNode;
            gcdNode->next = node2;

            // Move to the next pair of nodes
            node1 = node2;
            node2 = node2->next;
        }

        return head;
    }

private:
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
