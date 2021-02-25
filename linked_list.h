#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include  <iostream>
using namespace std;
#define DefaultSize 10
enum boolean {FALSE, TRUE};

template <class Type> class Node;  
template <class Type> class List;               /*類別樣板*/
// template <class Type> class List_Interator;  
template <class Type> void equivalence(List<Type>* seq_ptr); /*模板函數宣告(如果不是模板函數的話可以不用提前宣告)*/

template <class Type> 
class Node{                                     /*類別樣板*/
    friend class List<Type>;
    friend void equivalence<Type>(List<Type>* seq_ptr);
    // friend class List_Interator<Type>;
    public:
        Node<Type>(Type k){
            data = k;
            link = NULL;
        };
    private:
        Type data;
        Node<Type>* link;
};

template <class Type> 
class List{                                     /*宣告List類別*/
    // friend class List_Interator <Type>;
    friend void equivalence<Type>(List<Type>* seq_ptr); /*加<Type>在equivalence後面是因為要讓編譯器知道這是一個模板函數*/
    public:
        bool isEmpty() {
            return this->first == NULL;
        }
        int length() {
            return this->size;
        }
        List();
        ~List();                                /*解建構子:前面不需要加任何回傳函數型態*/
        void PushFront(Type data);
        void PushBack(Type data);
        void PrintList();
    private:
        Node<Type>* first;                      /*此List的first address*/
        Node<Type>* last;
        int size;
};

// template <class Type> 
// class List_Interator{
//     public:
//     private:
// };

template <class Type>
class Stack{
    friend class List<Type>;
    friend void equivalence<Type>(List<Type>* seq_ptr);
    public:
        Stack(int MaxStackSize = DefaultSize);
        boolean isfull();
        boolean isempty();
        void  push(const Type& item);
        Type* pop(Type& item);
    private:
        int top;    /*永遠指到最上面那個element*/
        Type *stack;
        int maxsize;
};

#endif
