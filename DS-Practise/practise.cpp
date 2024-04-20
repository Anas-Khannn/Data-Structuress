// Thing we learned in  Lab 9 
// Todays topic include 
// 1- BST
 // 2 -Sibling


//  class BST{
//     private:
//     Node *root;

//     public:
//     FindSibling(){
        
//     }
//  };

class Node
{
private:
   node *next;
   node *prev;
   int data;
public:

   Node(int value){
      data = value;
      prev = nullptr;
      next = nullptr;
   }
};

class DoublyLinklist
{
private:
Node* head;
   
public:
DoublyLinklist(){

   head = nullptr;
}

 void CreateData(int Data){

   Node *new Node = new Node(Data);
 }
   





};

