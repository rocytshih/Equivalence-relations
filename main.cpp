#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "linked_list.cpp"
using namespace std;



int main(){
    int list_number = 12;
    List<int> *seq = new List<int>[list_number];
    int i, j, x, y;
    for(int i=0; i<9; i++){
        cout<<"��"<<i+1<<"����J"<<endl;
        cout<<"�п�J�����Ʀr1:";
        cin>>x;
        cout<<"�п�J�����Ʀr2:";
        cin>>y;
        seq[x].PushFront(y);
        seq[y].PushFront(x);
    }
    // for(int i = 0;i <list_number; i++){
    //     seq[i].PushFront(i);
    // }
    // for(int i=0; i<12; i++){
    //     equivalence(seq[i]);
    // }
    equivalence(seq);
    cout<<endl;
    // for(int i=0; i<list_number; i++){
    //     cout<<"----------------------"<<"List "<<i+1<<"----------------------"<<endl;  
    //     seq[i].PrintList();
    // }
    system("pause");
    return 0;
}