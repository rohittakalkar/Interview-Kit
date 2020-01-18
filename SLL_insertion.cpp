//
// Created by rohit on 12/01/20.
//
//1) At the front of the linked list
//2) After a given node.
//3) At the end of the linked list.

//#include <iostream>
//using  namespace std;
//
//class Node {
//public:
//    int data;
//    Node* link;
//};
//
//void insert_Beg(Node ** head, int data){
//    Node * new_node = new Node();
//    new_node->data = data;
//    new_node->link = (*head);
//    (*head) = new_node;
//}
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
//void insert_at(Node ** head, int data, int pos){
//    // go to pos-1 element
//    Node * new_node = new Node();
//    new_node->data = data;
//    if(pos==1){
//        new_node->link = (*head);
//        (*head) = new_node;
//        return;
//    }
//
//    int k=2;
//    Node * temp = (*head);
//    while(k<pos){
//        temp = temp->link;
//        k++;
//    }
//    Node * next_node = temp->link;
//    temp->link = new_node;
//    new_node->link = next_node;
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
////        insert_Beg(&head, data);
//        insert_end(&head, data);
//    }
//
//    traverse(head);
//
//    insert_at(&head, 3, 1);
//
//    traverse(head);
//    return 0;
//}
