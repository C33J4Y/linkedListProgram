#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
Node* next;
int data;
};

bool isEmpty(Node* head);
char menu();
void insertAsFirstElement(Node* &head, Node* &last, int data);
void insert(Node* &head, Node* &last, int data);
void remove(Node* &head, Node* &last);
void showList(Node* current);

bool isEmpty(Node* head){
  if(head == NULL){
    return true;
  }else return false;

}

char menu(){
  char choice;

  cout << "Menu\n";
  cout << "1. Add an item.\n";
  cout << "2. Remove an item.\n";
  cout << "3. Show the list.\n";
  cout << "4. Exit.\n";

  cin >> choice;

  return choice;

}

void insertAsFirstElement(Node* &head, Node* &last, int data){
  Node* temp = new Node;
  temp->data = data;
  temp->next = NULL;
  head = temp;
  last = temp;
}

void insert(Node* &head, Node* &last, int data){
  if(isEmpty(head)){
    insertAsFirstElement(head, last, data);
  }else{
      Node* temp = new Node;
      temp->data = data;
      temp->next = NULL;
      last->next = temp;
      last = temp;

  }
}

void remove(Node* &head, Node* &last){
  if(isEmpty(head)){
    cout << "The list is already empty! \n";
  }else if(head == last){
    delete head;
    head = NULL;
    last = NULL;
  }else {
    Node *temp = head;
    head = head->next;
    delete temp;

  }
}

void showList(Node* current){
  if(isEmpty(current)){
    cout << "The list is empty.\n";
  }else{
    cout << "The list contains: \n";

    while(current != NULL){
    cout << current->data << "->";
    current = current->next;

    }
    cout << "NULL" << endl;
  }
  

}


int main() {
  Node* head = NULL;
  Node* last = NULL;

  char choice;
  int number;

  do{
    choice = menu();
    switch(choice){
      case '1': cout << "Please enter a number: ";
                cin >> number;
                insert(head, last, number);
                break; 
      case '2': remove(head, last);
                break;
      case '3': showList(head);
                break;
      case '4': cout << "GoodBye!\n";
                
    }

  }while(choice != '4');

  return 0;
}