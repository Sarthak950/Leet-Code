#include <vector>

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr) return head;
        
        ListNode* tail = head;
        int len = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }

        tail->next = head;
        k = k % len;
        for (int i = 0; i < len - k; i++){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
