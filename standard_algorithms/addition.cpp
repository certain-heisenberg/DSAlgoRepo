    //Addition of binary numbers
    string str="";
    
    int i=A.size()-1;
    int j=B.size()-1;
    int carry=0;
    int sum=0;
    while(i>=0 || j>=0 || carry==1){

        sum = carry+((i>=0) ? A[i] - '0' : 0)+((j>=0) ? B[j] - '0' : 0);
        
        str = char((sum % 2) + '0') + str;
        carry = sum/2;

        i--;
        j--;
    }
    return str;

/**************************************/
    
    //Addition of two linked lists

    if(!l1) return l2;
    if(!l2) return l1;
    
    int sum = l1->val + l2->val;
    int carry = sum / 10;
    ListNode *l3 = new ListNode(sum % 10);
    ListNode *tail = l3;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 || l2 || carry){

        sum = (( l1 ? l1->val : 0) + ( l2 ? l2->val : 0) + carry);
        
        ListNode *t  = new ListNode(sum % 10);
        carry = sum / 10;                                          

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
            
        tail->next = t;
        tail = t;
    }

    return l3;
