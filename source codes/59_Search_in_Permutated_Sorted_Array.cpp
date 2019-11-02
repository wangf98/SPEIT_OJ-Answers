#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class node{
  public:
    int num;
    node* lc,*rc;
    node(int data){
      num=data;
      lc=NULL;
      rc=NULL;
    }
    ~node(){
      delete(lc);
      delete(rc);
    }
};

class bst{
  public:
    node *root;
    void insert(node *t, int num);
    node* find(node *t, int num);
    node* findans(node* t, int a, int b);
};

void bst::insert(node *t, int num){
  if (num<=t->num){
    if (t->lc==NULL){
      t->lc=new node(num);
      return;
    }
    insert(t->lc,num);
  } else{
    if (t->rc==NULL){
      t->rc=new node(num);
      return;
    }
    insert(t->rc,num);
  }
}

node* bst::find(node* t, int num){
  if (t->num==num) return(t);
  if (num<t->num) return(find(t->lc,num));
  if (num>t->num) return(find(t->rc,num));
}

node* bst::findans(node* t, int a, int b){
  int cmp;
  cmp=t->num;
  if (a<=cmp && b>=cmp) return(t);
  if (b<=cmp) return(findans(t->lc,a,b));
  return(findans(t->rc,a,b));
}

int main(){
  int n,i,j,a,b;
  cin>>n;
  int m,v,tmp;
  bst tree;
  node* ans;
  for (i=1;i<=n;i++){
    tree.root=NULL;
    cin>>m;
    //cout<<"m="<<m<<endl;
    for (j=1;j<=m;j++){
      cin>>v;
      if (j==1) tree.root=new node(v);
        else tree.insert(tree.root,v);
      //cout<<j<<' '<<v<<endl;
    }
    //cout<<"ok"<<endl;
    cin>>a>>b;
    if (a>b){
      tmp=a;
      a=b;
      b=tmp;
    }
    ans=tree.findans(tree.root,a,b);
    cout<<ans->num<<endl;
  }
}
