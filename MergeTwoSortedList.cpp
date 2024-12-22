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
        ListNode* merged;
        ListNode* merged_start = merged;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1 < list2)
        {
            merged = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            merged = new ListNode(list2->val);
            list2 = list2->next;
        }

        while(1)
        {
            if(list1 == nullptr)
            {
                if(list2 != nullptr)
                {
                    merged->next = list2;
                }
                return merged_start;
            }

            if(list2 == nullptr)
            {
                if(list1 != nullptr)
                {
                    std::cout << list1->val << std::endl;
                    merged->next = list1;
                }
                
                return merged_start;
            }

            if(list1->val < list2->val)
            {
                merged->next = new ListNode(list1->val);
                list1 = list1->next;
                merged = merged->next;
            }
            else
            {
                merged->next = new ListNode(list2->val);
                list2 = list2->next;
                merged = merged->next;
            }
        }

        return merged_start;
    }
};
