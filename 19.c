struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* current = head;
    struct ListNode* runner = current;

    //Send a runner out n spaces ahead
    for (int i = 0; i < n; i++) {
        runner = runner->next;
    }

    //if runner is at the end, n must be equal to the length of he list, meaning remove the first element
    if (!runner) {
        return head->next;
    }

    //otherwise push forward until the end of the list, with current trailing n places behind
    while (runner->next) {
        current = current->next;
        runner = runner->next;
    }
    
    //remove node after current
    current->next = current->next->next;
    return head;
}
