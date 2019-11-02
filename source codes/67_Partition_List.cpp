#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

template <class T>
class ListNode {
public:
  T val;
  int flag;
  ListNode *next;
  ListNode(){}
  ListNode(T& x) : val(x), next(NULL) {}
};

template <class T>
class List {
private:
  ListNode<T>* head;
  ListNode<T>* tail;
  void init() { head = tail = new ListNode<T>(); }
  void removeAll();
public:
  List() {init();}
  ~List() {removeAll();}
  void clear() {removeAll(); init();}
  void push(T elem);
  void printall(){
    ListNode<T>* now;
    now=head->next;
    while(now!=NULL) {
      cout<<now->val<<' ';
      now=now->next;
    }
    //cout<<endl;
  }
  void partition(T x);
};

template <class T>
void List<T>::removeAll(){
  ListNode<T>* now;
  ListNode<T>* tmp;
  now=head;
  while (now->next!=NULL){
    tmp=now;
    now=now->next;
    delete(tmp);
  }
  delete(now);
}

template <class T>
void List<T>::push(T elem){
  ListNode<T>* tmp=new ListNode<T>(elem);
  tail->next=tmp;
  tail=tmp;
  tmp->flag=0;
}

template <class T>
void List<T>::partition(T x){
  int i,j,cnt;
  ListNode<T>* now;
  cnt=0;
  now=head->next;
  while (now!=NULL){
    if (now->val<x){
      if (cnt==0) {cout<<now->val; cnt=1;}
        else cout<<' '<<now->val;
      now->flag=1;
    }
    now=now->next;
  }
  now=head->next;
  while (now!=NULL){
    if (cnt==0) {cout<<now->val; cnt=1;}
        else
    if (now->flag==0)cout<<' '<<now->val;
    now=now->next;
  }
}

int main() {
  int i,n,num,x; // Element in the list
  cin>>n;
  List<int> l;
  for (i=1;i<=n;i++){

    while (cin >> num){
      l.push((int)num);
      if (cin.get() == '\n') break;
    }
   // l.printall();
    cin>>x;
    l.partition(x);
    if (i!=n) cout<<endl;
    l.clear();
  }
}
