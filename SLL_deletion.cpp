////
//// Created by rohit on 12/01/20.
////
//
////
//// Created by rohit on 12/01/20.
////
////1) At the front of the linked list
////2) After a given node.
////3) At the end of the linked list.
//
//#include <iostream>
//using  namespace std;
//
//class Node {
//public:
//    int data;
//    Node* link;
//};
//
//void insert_end(Node ** head, int data){
//    Node * new_node = new Node();
//    new_node->data = data;
//    new_node->link = NULL;
//
//    if(*head == NULL){
//        (*head) = new_node;
//        return;
//    }
//
//    Node * temp = (*head);
//
//    while (temp->link){
//        temp = temp->link;
//    }
//    temp->link = new_node;
//}
//
//void del_Beg(Node ** head){
//    Node * temp = (*head);
//    (*head) = (*head)->link;
//    delete  temp;
//}
//
//void del_at(Node ** head, int pos){
//    int k = 1;
//    Node * prev = NULL;
//    Node * temp = (*head);
//    Node * next = NULL;
//
//    if(pos == 1){
//        del_Beg(head);
//        return;
//    }
//
//    while(k<pos){
//        prev = temp;
//        temp = temp->link;
//        next = temp->link;
//        k++;
//    }
//    prev->link = next;
//    delete temp;
//}
//
//void traverse (Node * head){
//    while(head !=NULL){
//        cout<< head->data;
//        head = head->link;
//    }
//    cout<<endl;
//}
//
//int main() {
//    Node * head = NULL;
//    int n;
//    cin>>n;
//    while(n--){
//        int data;
//        cin>>data;
//        insert_end(&head, data);
//    }
//    traverse(head);
//
////  del_Beg(&head);
//
//    del_at(&head, 1);
//    traverse(head);
//
//    return 0;
//}