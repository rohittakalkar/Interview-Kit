////
//// Created by rohit on 12/01/20.
////
//#include <iostream>
//using namespace std;
//class Node{
//    public:
//    int data;
//    Node * prev;
//    Node * next;
//};
//
//void insert_end(Node ** head, int data){
//    Node * new_node = new Node();
//    new_node->data = data;
//    if((*head) == NULL){
//        new_node->next = (*head);
//        new_node->prev = NULL;
//        (*head) = new_node;
//        return;
//    }
//
//    Node * temp = (*head);
//
//    while(temp->next){
//        temp = temp->next;
//    }
//
//    temp->next = new_node;
//    new_node->prev = temp;
//    new_node->next = NULL;
//}
//
//void insert_at(Node ** head, int data, int pos){
//    int k = 2;
//
//    Node * temp = (*head);
//    while(k<pos){
//        temp = temp->next;
//        k++;
//    }
//
//
//    Node * new_node = new Node();
//    new_node->data = data;
//    new_node->next = temp->next;
//    temp->next = new_node;
//    new_node->prev = temp;
//
//}
//
//void del_at(Node ** head, int pos){
//    int k = 1;
//
//    Node * temp = (*head);
//
//    if(pos == 1){
//        (*head) = (*head)->next;
//        (*head)->prev = NULL;
//        delete  temp;
//        return;
//    }
//
//    while(k<pos){
//        temp = temp->next;
//        k++;
//    }
//    (temp->prev)->next = temp->next;
////    handling if the node next to the node to be deleted exists or not.
//    if(temp->next != NULL)
//        (temp->next)->prev = temp->prev;
//    delete temp;
//}
//
//void traverse(Node * head){
//    while(head){
////        cout<<head->prev<< " " << head  << " "<< head->next<< endl;
//        cout << head->data;
//        head = head->next;
//    }
//    cout<<endl;
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
//        insert_end(&head, data);
//    }
//    traverse(head);
//
//    insert_at(&head, 4, 4);
//    traverse(head);
//
//    del_at(&head, 6);
//    traverse(head);
//
//    return 0;
//}
