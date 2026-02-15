struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *new_head = reverseFirstK(head, k);
        while (head->next)
        {
            auto indirect = &head->next;
            head = head->next;
            *indirect = reverseFirstK(head, k);
            if (head == *indirect)
            {
                // fail to reverse k nodes
                // because the number remaining nodes < k
                break;
            }
        }
        return new_head;
    }

    ListNode *reverseFirstK(ListNode *head, int k)
    {
        ListNode *node = head;
        ListNode *prev_node = nullptr;
        ListNode *next_node = nullptr;
        while (k-- && node)
        {
            next_node = node->next;
            node->next = prev_node;
            prev_node = node;
            node = next_node;
        }
        head->next = next_node;

        if (k < 0)
            return prev_node;

        return reverseList(prev_node);
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev_node = nullptr;
        ListNode *next_node = nullptr;
        while (head)
        {
            next_node = head->next;
            head->next = prev_node;
            prev_node = head;
            head = next_node;
        }
        return prev_node;
    }
};
