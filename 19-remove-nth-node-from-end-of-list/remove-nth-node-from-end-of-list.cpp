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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* temp = head;
      int len = 0;
      while(temp){
        len++;
        temp = temp->next;
      }
      int pos = len-n;
      temp = head;
      if(pos==0) return head->next;
      for(int i = 0; i<pos-1; i++){
        temp= temp->next;
      }
      temp->next = temp->next->next;
      return head;
    }
    

};