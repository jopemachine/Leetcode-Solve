/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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

#include <iostream>

using namespace std;

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = nullptr;
        ListNode* start;

        int nodeCnt = 0;
        int roundUp = 0;

        while(l1 || l2) {
            int arg1 = 0;
            int arg2 = 0;

            if(l1) arg1 = l1->val;
            if(l2) arg2 = l2->val;

            int res = arg1 + arg2 + roundUp;

            if(res >= 10) {
                res %= 10;
                roundUp = 1;
            }
            else {
                roundUp = 0;
            }

            if(ptr == nullptr) {
                ptr = new ListNode(res);
                start = ptr;
            } 
            else {
                ListNode* old = ptr;
                ptr = new ListNode(res);
                old->next = ptr;
            }

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(roundUp) {
            ListNode* old = ptr;
            ptr = new ListNode(1);
            old->next = ptr;
        }

        return start;
    }
};
// @lc code=end

