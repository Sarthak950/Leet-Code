#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
        
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            
            ListNode *sorted = nullptr;
            ListNode *unsorted = head;
            
            while (unsorted != nullptr) {
                ListNode *curr = unsorted;
                unsorted = unsorted->next;
                
                if (sorted == nullptr || curr->val < sorted->val) {
                    curr->next = sorted;
                    sorted = curr;
                } else {
                    ListNode *tmp = sorted;
                    while (tmp->next != nullptr && curr->val > tmp->next->val) {
                        tmp = tmp->next;
                    }
                    curr->next = tmp->next;
                    tmp->next = curr;
                }
            }
            
            return sorted;

        }
};


int main (int argc, char *argv[]) {
    
    return 0;
}
