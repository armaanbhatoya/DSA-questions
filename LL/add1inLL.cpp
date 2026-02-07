#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Class as used in LeetCode */
class Solution {
public:
    int helper_func(ListNode* temp){
        if(temp == nullptr) return 1;
        int carry = helper_func(temp->next);
        temp->val = temp->val + carry;
        if(temp->val<10){
            return 0;
        }
        temp->val = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
       int carry = helper_func(head);
       if(carry == 1){
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        return newHead;
       }
       return head;
    }
};

/* -------- Helper Functions (Already Implemented) -------- */

// Create linked list from vector
ListNode* createList(const vector<int>& digits) {
    if (digits.empty()) return NULL;

    ListNode* head = new ListNode(digits[0]);
    ListNode* curr = head;

    for (int i = 1; i < digits.size(); i++) {
        curr->next = new ListNode(digits[i]);
        curr = curr->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* -------------------- Main Function -------------------- */
int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    ListNode* head = createList(digits);

    Solution sol;
    head = sol.addOne(head);

    cout << "Result: ";
    printList(head);

    return 0;
}
