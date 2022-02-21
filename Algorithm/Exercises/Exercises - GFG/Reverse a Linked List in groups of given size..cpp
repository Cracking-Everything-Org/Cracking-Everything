class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if (!head) return head;
        
        node *current = head;
        node *prev = NULL;
        node *next = NULL;
        int count = 0;
        
        // reverse first k nodes of list
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        
        if (next) {
            head->next = reverse(next, k);
        }
        
        return prev;
    }
};