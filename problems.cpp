#include <iostream>
using  namespace std;

class Node {
public:
    int data;
    Node* link;
};

void insert_end(Node ** head, int data){
    Node * new_node = new Node();
    new_node->data = data;
    new_node->link = NULL;

    if(*head == NULL){
        (*head) = new_node;
        return;
    }

    Node * temp = (*head);

    while (temp->link){
        temp = temp->link;
    }
    temp->link = new_node;
}

void traverse (Node * head){
    while(head !=NULL){
        cout<< head->data;
        head = head->link;
    }
    cout<<endl;
}

// problem 1 :
// approach : one scan - two pointer at the k distance away. Move both pointer simutaneously
// until the later reaches the last node. The node pointed by the former pointer is the kth node from end
void nth_from_end(Node ** head, int pos){
    Node * ptr1 = NULL;
    Node * ptr2 = NULL;
    ptr1 = (*head);
    ptr2 = (*head);
    int k=1;
    while(k != pos){
        //handling exception case
        if(ptr2->link == NULL){
            cout<<"k<n"<<endl;
            return;
        }
        ptr2 = ptr2->link;
        k++;
    }

    while(ptr2->link != NULL){
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    cout<< ptr1->data<<endl;
}


//problem 2 ;
// approach 1 : hash table -> repetition of next pointers indicates the existence of a loop
// approach 2 : memoryless approach = floyd cycle detection the faster running hare will catch up the tortoise if there is a loop

Node ** loop_Start_Point(Node ** tortoise, Node ** hare){
    while(*tortoise != *hare) {
        *tortoise = (*tortoise)->link;
        *hare = (*hare)->link;
        if (*hare == *tortoise) {
            cout<<"Cycle Exists, Start point is : "<<(*hare)->data<<endl;
            break;
        }
    }
    return hare;
}

int loop_Length(Node ** start){
    Node * temp = *start;
    int count = 1;
    while(temp->link != (*start)){
        temp = temp->link;
        count++;
    }
    return count;
}

void detect_loop(Node * head){
    Node * tortoise = head;
    Node * hare = head;

    while(tortoise && hare && hare->link){
        tortoise = tortoise->link;
        hare = (hare->link)->link;
// this condition if true idicates that loop exists
        if(tortoise == hare){
            tortoise = head;
// finding out the start point of loop
// logic: after finding the loop, we reset the tortoise pointer to the head of the LL. and
// increment both hare and tortoise, point at which they are equal is the start point of loop
            Node ** start = loop_Start_Point(&tortoise, &hare);
// finding loop length
          int loop_length = loop_Length(start);
          cout<<loop_length<<endl;
          return;
        }
    }
    cout<< "cycle not detected"<<endl;
}


// PROBLEM 3: REVERSING THE LL using recursion
void reverse_List(Node ** head){
        Node * prev = NULL;
        Node * current = *head;
        Node * next = NULL;
        while(current!=NULL){
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        *head = prev;
}

// Approach 1 : inplace - no extra space required.
// Approach 2 : hash table : check if the next node pointer already exists in the hash table, if so return the node existsa
Node * intersection_point(Node * head1, int len1, Node * head2, int len2){
        int found =0;
        int diff = abs(len1-len2);
        if(len1>len2){
            while(diff--)
                head1 = head1->link;
        } else {
            while(diff--)
            head2 = head2->link;
        }

        while(head1!=NULL){
            head1 = head1->link;
            head2 = head2->link;
            if(head1 == head2){
                break;
            }
        }
    return  head1;
}


// APPROACH 1 : USING TWO POINTERS : run one pointer twice the speed of other. When the faster pointer reaches last or
// the second last element of the LL, return the slow pointer.
Node * middle_point(Node * head){
    Node * ptr1 = head, * ptr2 = head;

    while(ptr2->link != NULL && (ptr2->link)->link != NULL){
        ptr1 = ptr1->link;
        ptr2 = (ptr2->link)->link;
        if(ptr2 == NULL)
            cout<<"LL is even"<< endl;
        if(ptr2->link == NULL)
            cout<<"LL is odd"<<endl;
    }

    return ptr1;
}

// Approach 1: Call LL nodes recursively
void list_from_end(Node * head){
    if(!head)
        return;
    list_from_end(head->link);
    cout<<head->data<<" ";
}

// PROBLEM 9: MERGE TWO SORTED LINKED LIST
Node * merge_two_sorted_LL(Node * l1, Node * l2){
    Node * head = NULL;
    Node * temp = NULL;

    if(l1->data < l2->data){
        temp = l1;
        head = temp;
        l1 = l1->link;
    }
    else{
        temp = l2;
        head = temp;
        l2 = l2->link;
    }

    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
//            next two lines are very imp
            temp->link = l1;
            temp = temp->link;
            l1 = l1->link;
        } else{
//            next two lines are very imp
            temp->link = l2;
            temp = temp->link;
            l2 = l2->link;
        }
    }

    if(l1 == NULL){
        temp->link = l2;
    }

    if (l2 ==  NULL){
        temp->link = l1;
    }
    return head;
}

// REVERSE IN PAIRS
Node * reverse_pairs(Node * head){
    Node * temp1 = NULL, * temp2 = NULL, * current = head;
    while(current && current->link){
        if(temp1)
            temp1->link->link = current->link;
        temp1 = current->link;
        current->link = temp1->link;
        temp1->link = current;
        if(temp2 == NULL)
            temp2 = temp1;
        current = current->link;
    }
    return temp2;
}

void splitEvenOddList(Node * head){
    Node * originalHead = head;
    Node * evenHead = NULL,  * evenTemp = NULL;
    Node * oddHead = NULL,  * oddTemp = NULL;

    while(originalHead){
        if(originalHead->data % 2 == 0){
            if(evenHead == NULL){
                evenHead =  new Node;
                evenHead->data = originalHead->data;
                evenHead->link = NULL;
                evenTemp = evenHead;
            } else{
                evenTemp->link = new Node();
                evenTemp->link->data = originalHead->data;
                evenTemp->link->link = NULL;
                evenTemp = evenTemp->link;
            }
        }else{
            if(oddHead == NULL){
                oddHead =  new Node;
                oddHead->data = originalHead->data;
                oddHead->link = NULL;
                oddTemp = oddHead;
            } else{
                oddTemp->link = new Node();
                oddTemp->link->data = originalHead->data;
                oddTemp->link->link = NULL;
                oddTemp = oddTemp->link;
            }
        }
        originalHead = originalHead->link;
    }
    oddTemp->link = evenHead;
    cout<<"odd's first even's later : ";
    traverse(oddHead);
}

void addtwoLL(Node * number1, Node * number2){
    reverse_List(&number1);
    reverse_List(&number2);
    Node * result = NULL;
    Node * itr = NULL;

    int carry = 0;
    while(number1 && number2){
        int value = number1->data + number2->data;
        if(!result){
            result = new Node();
            carry = (value + carry) / 10;
            int num = (value + carry) % 10;
            result->data = num;
            result->link = NULL;
            itr = result;
        } else {
                Node * newnode = new Node();
                carry = (value + carry) / 10;
                int num = (value + carry) % 10;
                newnode->data = num;
                newnode->link = NULL;
                itr->link = newnode;
                itr = itr->link;
        }
        number1 = number1->link;
        number2 = number2->link;
    }
    if(carry){
        Node * newnode = new Node();
        newnode->data = carry;
        newnode->link = NULL;
        itr->link = newnode;
    }
    reverse_List(&result);
    traverse(result);
}

int main() {
    Node * head = NULL;
    int n;
    cin>>n;
    while(n--){
        int data;
        cin>>data;
//        insert_Beg(&head, data);
        insert_end(&head, data);
    }
    traverse(head);

//   PROBLEM 1:  NTH FROM END CODE STARTS HERE
    nth_from_end(&head, 3);
//  NTH FROM END ENDS HERE

/* ********    PROBLEM 2 : CYCLE DETECTION, LOOP START POINT AND LOOP LENGTH CODE START HERE ******* */
    Node * first = new Node();
    Node * second = new Node();
    Node * third = new Node();
    Node * fourth = new Node ();

    first->link = second;
    first->data = 10;

    second->link = third;
    second->data = 20;

    third->link = fourth;
    third->data = 30;

    fourth->link = second;
//    fourth->link = NULL;
    fourth->data = 40;

//    cout<<"Address of the LL nodes are :" << first<<" "<< second<< " "<< third<< " "<< fourth<< " "<< fourth->link<<endl;
    detect_loop(first);
/* ********   CYCLE DETECTION CODE ENDS HERE ********/

//  PROBLEM 3 : REVERSE SINGLY LINKED LIST STARTS HERE
//    reverse_List(&head);
//    traverse(head);
//  REVERSE LINKED LISTS ENDS HERE

// PROBLEM 4 : INTERSECTION POINT OF TWO LL STARTS HERE
    Node * head1, *two, *three, *four, *head2, *six, *seven;
    head1 = new Node();
    two = new Node();
    three = new Node();
    four = new Node();
    head2 = new Node();
    six = new Node();
    seven = new Node();
    head1->data = 1;
    head1->link = two;
    two->data = 2;
    two->link = three;
    three->data = 3;
    three->link = NULL;

    four->data = 4;
    four->link = head2;
    head2->data = 5;
    head2->link = six;
    six->data = 6;
    six->link = seven;
    seven->data = 7;
    seven->link = NULL;
    Node * inter_point = intersection_point(head1, 3, four, 4);
    if(inter_point == NULL){
        cout<< "No intersection point found"<<endl;
    } else{
        cout<< inter_point->data<<endl;
    }
//  PROBLEM 4 : INTERSECTION POINT OF TWO LL ends HERE

//  PROBLEM 5 : FINDING MIDDLE OF THE LL and checking even or odd starts here
    Node * mid_point = middle_point(head);
    cout<< "Mid point of the LL is : "<<mid_point->data<<endl;
//  PROBLEM 5 : FINDING MIDDLE OF THE LL and checking even or odd ends here

// PROBLEM 6 : PRINTING LL FROM THE END STARTS HERE
//    cout<<"Printing List from end using recursion :";
//    list_from_end(head);
//    cout<<endl;
// PRINTING LL FROM THE LL ENDS HERE

// PROBLEM 7 : IF HEAD OF THE POINTER POINTS TO THE KTH NODE IN THE LL, FIND THE ELEMENT BEFORE THE KTH NODE
// SOLUTION : USE XOR LIST - MEMORY EFFICIENT LL.

// PROBLEM 8 : MERGE TWO SORTED LL STARTS HERE
    Node * l1 = NULL;
    Node * l2 = NULL;
    insert_end(&l1, 1);
    insert_end(&l1, 2);
    insert_end(&l1, 4);

    insert_end(&l2, 3);
    insert_end(&l2, 5);
//    traverse(l1);
//    traverse(l2);
    cout<<"Merged List is :";
    traverse(merge_two_sorted_LL(l1, l2));
// MERGE TWO SORTED LL ENDS HERE

// PROBLEM 13 : REVERSE LL IN PAIRS STARTS HERE
//    Node * ListHead = reverse_pairs(head);
//    cout<<"List after reversing pairwise is : ";
//    traverse(ListHead);
// PROBLEM 13 : REVERSE LL IN PAIRS ENDS HERE

// PROBLEM 10 : SPLITTING THE CLL - WRITTEN IN CLL_insertion_deletion.cpp

// PROBLEM 11 : CHECK WHETHER THE LL IS PALINDROME OR NOT STARTS HERE
    Node * midnode = middle_point(head);
    Node * List2 = midnode->link;
    midnode->link = NULL;
    reverse_List(&List2);
    Node * temp2 = List2;
    Node * temp1 = head;
    int flag = 0;
    while(temp1 && temp2){
        if(temp1->data == temp2->data){
            flag = 1;
            temp1 = temp1->link;
            temp2 = temp2->link;
        } else{
            flag = 0;
            break;
        }
    }
    if(flag)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;

    reverse_List(&List2);
    midnode->link = List2;
    cout<<"Converted to original LL again :";
    traverse(head);
// PROBLEM 11 : CHECK WHETHER THE LL IS PALINDROME OR NOT ENDS HERE

// PROBLEM 12 : CLONE LIST IN cloneList.cpp file starts here
// PROBLEM 12 : CLONE LIST IN cloneList.cpp file ends here

// PROBLEM 13 : EVEN ODD IN MODIFIED LIST starts here
    splitEvenOddList(head);
// PROBLEM 13 : EVEN ODD IN MODIFIED LIST ends here

// PROBLEM 14 : Adding the two Linked List starts here
    Node * number1 = NULL;
    int n1;
    cin>>n1;
    while(n1--){
        int data;
        cin>>data;
//        insert_Beg(&head, data);
        insert_end(&number1, data);
    }

    Node * number2 = NULL;
    int n2;
    cin>>n2;
    while(n2--){
        int data;
        cin>>data;
//        insert_Beg(&head, data);
        insert_end(&number2, data);
    }

    addtwoLL(number1, number2);
// PROBLEM 14 : Adding the two Linked List ends here

    return 0;


}