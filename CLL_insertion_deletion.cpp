////
//// Created by rohit on 12/01/20.
////
//
//#include <iostream>
//using namespace std;
//
//class Node{
//    public:
//    int data;
//    Node * link;
//};
//
//void insert_End(Node ** head, int data){
//    Node * temp = (*head);
//    Node * new_node = new Node();
//    new_node->data = data;
//    if(!(*head)){
//        new_node->link = new_node;
//        (*head) = new_node;
//        return;
//    }
//
//    while(temp->link != (*head)){
//        temp = temp->link;
//    }
//    temp->link = new_node;
//    new_node->link = (*head);
//
//}
//
//void insert_Beg(Node ** head, int data){
//    Node * temp = (*head);
//    Node * new_node = new Node();
//    new_node->data = data;
//    if(!(*head)){
//        new_node->link = new_node;
//        (*head) = new_node;
//        return;
//    }
//
//    new_node->link = (*head);
//
//    while(temp->link != (*head)){
//        temp = temp->link;
//    }
//    temp->link = new_node;
//    (*head) = new_node;
//}
//
//void del_At(Node ** head,int pos){
//    int k=1;
//    Node * temp = (*head);
//    Node * prev = NULL;
//    if(pos == 1){
//        do{
//            prev = temp;
//            temp = temp->link;
//        }while(temp != (*head));
//        prev->link = (temp->link);
//        (*head) = prev->link;
//        return;
//    }
//
//    do{
//        prev = temp;
//        temp = temp->link;
//        k++;
//    }while(k<pos && (temp->link!=(*head)));
//    prev->link = temp->link;
//    delete temp;
//
//}
//
//void traverse(Node * head){
//    Node * temp = head;
//    if(!head){
//        return;
//    }
//
//    do{
////        cout<<temp<<" "<<temp->link<<endl;
//        cout<<temp->data<<" ";
//        temp  = temp->link;
//    }while(temp != head);
//
//    cout<<endl;
//
//}
//
////  PROBLEM 10 : SPLITTING THE CLL
//void split(Node * head){
//    Node * ptr1 = NULL, * ptr2 = NULL;
//    ptr1 = head;
//    ptr2 = ptr1->link;
//    while(ptr2->link!=head){
//        ptr1 = ptr1->link;
//        ptr2 = (ptr2->link)->link;
//        if(ptr2 == head){
//            break;
//        }
//    }
////    splitting starts based on middle element found
//    Node * head2 = ptr1->link;
//    ptr1->link = head;
//    traverse(head);
//    Node * temp = head2;
//    while(temp->link!=head){
//        temp = temp->link;
//    }
//    temp->link = head2;
//
//    traverse(head2);
//
//    cout<<"middle element is : "<< ptr1->data;
//}
//
//int main(){
//    Node * head = NULL;
//    int n;
//    cin>>n;
//
//    while(n--){
//        int data;
//        cin>>data;
////        insert_End(&head, data);
//        insert_Beg(&head, data);
//    }
//    traverse(head);
//
////    del_At(&head, 3);
////    traverse(head);
//
////    PROBLEM 10 : SPLITTING THE CLL starts here
//    split(head);
////     PROBLEM 10 : SPLITTING THE CLL ends here
//    return  0;
//}