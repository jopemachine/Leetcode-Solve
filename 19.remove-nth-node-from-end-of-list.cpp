/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 링크드 리스트 문제는 더미 노드를 만들어 놓고 처리하면 더미의 next를 반환하도록 처리하면
        // 길이가 짧은 경우 등을 따로 처리해 줄 필요 없이 간단하게 처리할 수 있음.
        ListNode* dummy =  new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; i++) { 
            first = first->next; 
        }

        while(first) {
            first = first->next; 
            second = second->next;
        }

        second->next = second->next->next;
        return dummy->next;
    }
};
// @lc code=end

