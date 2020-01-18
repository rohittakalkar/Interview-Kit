////
//// Created by rohit on 15/01/20.
////
//
//#include <iostream>
//using namespace std;
//class Node{
//    public:
//        int data;
//        Node * random;
//        Node * next;
//};
//
//
//void traverse(Node * head){
//    Node * temp = head;
//    while(temp){
//        cout<<temp->data<<"|";
//        if(temp->random)
//            cout<<temp->random->data<<"|";
//        else
//            cout<<"NULL"<<"|";
//
//        if(temp->next)
//            cout<<temp->next->data<<"|\t";
//        else
//            cout<<"NULL"<<"|\t";
//
//        temp = temp->next;
//    }
//    cout<<endl;
//}
//
//void setRandomPointers(Node * head){
//    Node * current  = head;
//    while(current){
//        if(current->random)
//            current->next->random = current->random->next;
//        current = current->next->next;
//    }
////    traverse(head);
//}
//
//void alternativesplitting(Node * head){
//    Node * current = head;
//    Node * temp = current->next;
//    Node * clonedlist = temp;
//    while(temp->next && current->next){
//        current->next = temp->next;
//        temp->next = current->next->next;
//        current = current->next;
//        temp = temp->next;
//    }
//    temp->next = current->next = NULL;
//    cout<<"Original List is :";
//    traverse(head);
//    cout<<"Cloned List is ";
//    traverse(clonedlist);
//
//    cout<<"Original List address is "<<head<<endl;
//    cout<<"Cloned List address is "<<clonedlist<<endl;
//}
//
//void clone_list(Node * head){
//    Node * current = head;
//    Node * temp = NULL;
//    while(current){
//        temp = new Node();
//        temp->data = current->data;
//        temp->random = NULL;
//        temp->next = current->next;
//        current->next = temp;
//        current = current->next->next;
//    }
////    traverse(head);
//    setRandomPointers(head);
//    alternativesplitting(head);
//}
//
//int main()
//{
//    Node * first = NULL, * second = NULL, * third = NULL;
//    first = new Node();
//    second = new Node();
//    third = new Node();
//
//    first->data = 10;
//    first->random = third;
//    first->next = second;
//
//    second->data = 20;
//    second->random = NULL;
//    second->next = third;
//
//    third->data = 30;
//    third->random = second;
//    third->next = NULL;
//
//
//    traverse(first);
//
//    clone_list(first);
//
//    return 0;
//}