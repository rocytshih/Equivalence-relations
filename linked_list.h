#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include  <iostream>
using namespace std;
#define DefaultSize 10
enum boolean {FALSE, TRUE};

template <class Type> class Node;  
template <class Type> class List;               /*���O�˪O*/
// template <class Type> class List_Interator;  
template <class Type> void equivalence(List<Type>* seq_ptr); /*�ҪO��ƫŧi(�p�G���O�ҪO��ƪ��ܥi�H���δ��e�ŧi)*/

template <class Type> 
class Node{                                     /*���O�˪O*/
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
class List{                                     /*�ŧiList���O*/
    // friend class List_Interator <Type>;
    friend void equivalence<Type>(List<Type>* seq_ptr); /*�[<Type>�bequivalence�᭱�O�]���n���sĶ�����D�o�O�@�ӼҪO���*/
    public:
        bool isEmpty() {
            return this->first == NULL;
        }
        int length() {
            return this->size;
        }
        List();
        ~List();                                /*�ѫغc�l:�e�����ݭn�[����^�Ǩ�ƫ��A*/
        void PushFront(Type data);
        void PushBack(Type data);
        void PrintList();
    private:
        Node<Type>* first;                      /*��List��first address*/
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
        int top;    /*�û�����̤W������element*/
        Type *stack;
        int maxsize;
};

#endif
