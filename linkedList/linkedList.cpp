// 利用哨兵节点可以简化链表的插入和删除操作
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    //  尾部插入 append
    {
        ListNode *node = dummy;
        while(node->next != null)
        {
            node = node->next;
        }
        node->next = new ListNode(val);

        return dummy->next; // head
    }
    

    // 删除
    {
        ListNode *node = dummy;
        while(node->next != null)
        {
            if(node->next->val == val)
            {
                //找到了删除点
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return dummy->next;
    }

}

// 链表中的双指针主要有两种：
// 第一种是前后指针，先让一个指针移动k步，然后两个指针同样的速度移动，等先移动那个移动到尾部，恰好后面指针在倒数第k+1个
// 第二种是快慢指针，一个指针移动两步，一个指针移动一步。通常用于环的检测，如果链表中存在环，
// 在快指针走到头之前（此情形下根本没有头），快慢指针一定会相遇， 而且相遇的位置一定位于环里面。
// 假如*就是下面链表中快慢指针相遇的位置：
// ------------------------------------+--*--+
//                                     |     |
//                                     |____/
// 此时我们让一个指针从相遇点开始走，等再次走到相遇点，可以计算出环中的节点数目m。
// 接着我们使用前后指针从头开始走，一个指针先走m步，然后两个一起走，等到相遇时恰好位于环的入口出。
// 另一种思路是不需要计算环中的节点数，快慢指针相遇时，快指针移动比慢指针多走n圈（n >= 1)，也就是说k步等于n圈。
// 前指针已经走了k步了，此时后指针从头开始，等到和前指针相遇在入口处时，前指针恰好多走了n圈。

// 得到环中相遇节点 // 平分链表
ListNode *getNode(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    // 二者都指向头，然后开始移动
    // 平分链表 slow size >= slow->next size 
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break; // 相较于平分链表的不同之处
    }

    if(fast == nullptr || fast->next == nullptr) return nullptr;
    return fast;
}

// 得到环的入口节点
ListNode *cycleEntry(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    ListNode *fast = getNode(dummy->next);
    ListNode *slow = dummy;
    //*------------*
    //slow        fast
    // 此时slow和fast之间的差距是n圈
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


// 反转链表
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    while(head != nullptr)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}