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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* resultList;
        if (lists.size() == 0) return NULL;
        resultList = new ListNode(-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) minHeap.push(make_pair(lists[i]->val, i));
        }
        
        ListNode* start = resultList;
        while (!minHeap.empty()) {
            pair<int,int> top = minHeap.top();
            minHeap.pop();
            ListNode* min = new ListNode(top.first);
            resultList->next = min;
            resultList = resultList->next;
            if (lists[top.second]) {
                lists[top.second] = lists[top.second]->next;
                if (lists[top.second])
                    minHeap.push(make_pair(lists[top.second]->val, top.second));
            }
        }
        return start->next;
    }
};