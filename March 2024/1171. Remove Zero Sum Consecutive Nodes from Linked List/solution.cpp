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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* zeroSumNode = new ListNode(0);
        zeroSumNode->next = head;

        unordered_map<int, ListNode*> mp;

        ListNode* it = zeroSumNode;
        int prefixSum = 0;

        mp[prefixSum] = zeroSumNode;

        while (head != nullptr) {
            prefixSum += head->val;

            if (mp.find(prefixSum) != mp.end()) {
                ListNode* temp = mp[prefixSum]->next;
                int pSum = prefixSum;
                while (temp != head) {
                    pSum += temp->val;
                    mp.erase(pSum);
                    temp = temp->next;
                }
                mp[prefixSum]->next = head->next;
            } else {
                mp[prefixSum] = head;
            }
            head = head->next;
        }

        return zeroSumNode->next;
    }
};