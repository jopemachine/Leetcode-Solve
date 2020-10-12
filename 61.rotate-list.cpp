/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

// #define DEBUG

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        int len = 0;
        ListNode* ptr = head;
        ListNode* lastNode;
        while (1) {
            if (ptr->next == nullptr) {
                lastNode = ptr;
                ++len;
                break;
            }
            ptr = ptr->next;
            ++len;
        }

#ifdef DEBUG
        cout << len << "\n";
#endif
        int rotateCnt = k % len;
        if (rotateCnt == 0) return head;

#ifdef DEBUG
        cout << rotateCnt << "\n";
#endif

        ptr = head;
        int idx = 0;
        ListNode* prevPtr;
        while(1) {
            if (idx == len - rotateCnt - 1) {
                prevPtr = ptr;
                ptr = prevPtr->next;
                break;
            }
            ptr = ptr->next;
            ++idx;
        }
        prevPtr->next = nullptr;
        lastNode->next = head;

        return ptr;
    }
};
// @lc code=end

