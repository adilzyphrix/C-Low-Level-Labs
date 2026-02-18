/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };


 Over-compllicated code written by me :)

 The idea was to get the list ->
 reverse it ->
 store those list values in two different arrays ->
 add the two different arrays into one single array ->
 create a list with those array elements as nodal values ->
 reverse the list.

 */
struct ListNode *create(int *arr,int n){
    struct ListNode *head = NULL;
    struct ListNode **indirect = &head;
    for(int i=0;i<n;i++){
        struct ListNode *new_node = malloc(sizeof(*new_node));
        new_node->val = arr[i];
        new_node->next = NULL;

        *indirect = new_node;
        indirect = &new_node->next;
    }
    return head;
}

struct ListNode* reverse(struct ListNode *head){ //reversing the list
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *tmp = NULL;
    while(curr){
        tmp = curr->next;
        curr->next = prev;
        prev = curr;

        curr = tmp;
    }
    return prev;
}

int count(struct ListNode *head){ //counting no of nodes in the linked list
    struct ListNode *p = head;
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

struct ListNode *add_array_then_list(int *arr1,int n1,int *arr2,int n2){
    int i = n1-1,j = n2-1,carry = 0,k = 0,sum = 0;
    int max_len = (n1 > n2) ? n1 : n2; //largest of the two arrays
    int *tmp_result = malloc((max_len+1) * sizeof(int));
    while(i>=0 || j>=0 || carry){
        sum = carry;
        if(i >= 0){
            sum += arr1[i];
            i--;
        }
        if(j >= 0){
            sum += arr2[j];
            j--;
        }
        tmp_result[k] = sum % 10; //last digit of sum
        carry = sum / 10;
        k++;
    }
    int result_size = k;
    int *result_arr = malloc(sizeof(int) * result_size);
    for(int l = 0;l<result_size;l++)
        result_arr[l] = tmp_result[result_size - 1 - l];

    //resulting array is ready
    struct ListNode *head = create(result_arr,result_size); //now make a linked list from the array values
    struct ListNode *rev_head = reverse(head);
    return rev_head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l_l1 = l1;
    struct ListNode *l_l2 = l2;
    struct ListNode *p1 = reverse(l_l1); //head of the reversed list
    struct ListNode *p2 = reverse(l_l2);
    
    int n1 = count(p1),n2 = count(p2);
    int arr1[n1];
    int arr2[n2];
    struct ListNode *q1 = p1; //copy of the head of the reversed linked list
    struct ListNode *q2 = p2;
    int i=0;
    while(q1){
        arr1[i] = q1->val;
        i++;
        q1 = q1->next;
    }//storing the node values in the array
    i=0;
    while(q2){
        arr2[i] = q2->val;
        i++;
        q2 = q2->next;
    }

    //now i wanna add these two arrays
    return add_array_then_list(arr1,n1,arr2,n2); //add the arrays and then convert it to linked list and then reverse it then return it's  head
}
