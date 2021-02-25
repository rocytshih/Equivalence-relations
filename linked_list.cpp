#include  "linked_list.h"

/*List construct*/
/*List 大小給0, first, last指標都給空指標*/
template <class Type>
List<Type>::List(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

/*List destruct*/
template <class Type>
List<Type>::~List(){
    Node<Type>* next = first;
    Node<Type>* current = nullptr;
    while(next){
        current = next;
        next = current->link;
        delete current;
    }
    cout<<"List deleted!"<<endl;
}

/*PushFront : 把一個node加在list的最前面*/
template <class Type>
void List<Type>::PushFront(Type data){
    Node<Type>* current_node = new Node<Type>(data);
    current_node->link = this->first;
    first = current_node;
    size++;
}

/*PushBack : 把一個node加在list的最後*/
template <class Type>
void List<Type>::PushBack(Type data){
    Node<Type>* current_node = new Node<Type>(data);
    if(!isEmpty()){                         
        Node<Type>* tmp_node = this->first;
        while(tmp_node->link){
            tmp_node = tmp_node->link;
        }
        tmp_node->link = current_node;
        size++;
    }
    else{                                   /*當List裡面是空的時候*/
        this->first = current_node;
        this->last = nullptr;
        size++;
    }
    
}

template <class Type>
void List<Type>::PrintList(){
    Node<Type> *tmp_node = this->first;
    int i = 1;
    if(isEmpty()){
        cout<<"The list is empty!"<<endl;
        return;
    }
    while(tmp_node->link){
        cout<<"Node-"<<i<<" address:"<<tmp_node<<endl;
        cout<<"Node-"<<i<<" data: "<<tmp_node->data<<endl;
        cout<<"Node-"<<i<<" link address: "<<tmp_node->link<<endl;
        tmp_node = tmp_node->link;
        cout<<endl;
        i++;
    }
    cout<<"Node-"<<i<<" address:"<<tmp_node<<endl;
    cout<<"Node-"<<i<<" data: "<<tmp_node->data<<endl;
    cout<<"Node-"<<i<<" link address: "<<tmp_node->link<<endl;
}


template <class Type> 
Stack<Type>::Stack(int MaxStackSize):maxsize(MaxStackSize){  /*引入MaxStackSize初始化Stack的參數maxsize*/
    stack = new Type[maxsize];
    top = -1;   
}

template <class Type>
boolean Stack<Type>::isfull(){
    if(top == maxsize-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

template <class Type>
boolean Stack<Type>::isempty(){
    if(top == -1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

template <class Type>
void Stack<Type>::push(const Type& item){
    if(isfull()){
        cout<<"The stack is full."<<endl;
    }
    else{
        stack[++top] = item;
    }
}

template <class Type>    
Type *Stack<Type>::pop(Type& item){
    if(isempty()){
        cout<<"The stack is empty."<<endl;
        return 0;
    }
    else{
        item = stack[top--];
        return &item;
    }
}

template <class Type>
void equivalence(List<Type>* seq_ptr){
    Stack<Type> stack_ptr;
    int list_number = 12;
    // List<int> *seq = new List<int>[list_number];
    // seq = seq_ptr;
    List<int> *seq = seq_ptr;
    boolean *out = new boolean[list_number];
    for(int i = 0; i<list_number; i++){
        out[i] = FALSE; 
    }
    for(int i = 0; i<list_number; i++){
        if(out[i] == FALSE){
            cout<<endl<< "A new class: "<<i;
            out[i] = TRUE;
            Node<Type> *x = seq[i].first;
            while(1){
                while(x){
                    if(out[x->data] == FALSE){
                        cout<< " , " <<x->data;
                        out[x->data] = TRUE;
                        stack_ptr.push(x->data);
                    }
                    else{
                        x = x->link;
                    }
                }
                if(stack_ptr.isempty()){
                    break;
                }
                else{
                    int top_data;
                    stack_ptr.pop(top_data);
                    x = seq[top_data].first;
                }
            }
        }
    }
} 

