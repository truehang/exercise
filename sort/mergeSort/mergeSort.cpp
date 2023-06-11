// mergeSort 归并排序
// 分治法，适合链表的排序
ListNode* sortList(ListNode* head) {
    // dfs
    if(head == nullptr || head->next == nullptr) return head;
    auto h2 = split(head);
    auto l = sortList(head);
    auto r = sortList(h2);
    return mergeList(l, r);
}

// 比常规的数组排序多了一个切分链表的操作
ListNode *split(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    while(fast != nullptr && fast ->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto tmp = slow->next;
    slow->next = nullptr;
    return tmp;
}

ListNode *mergeList(ListNode *head1, ListNode *head2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->val < head2->val)
        {
            cur->next = head1;
            head1 = head1->next;
        }else{
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }
    // 因为head1和head2都是已经排好序的链表了
    cur->next = head1 == nullptr ? head2 : head1;
    
    return dummy->next;
}