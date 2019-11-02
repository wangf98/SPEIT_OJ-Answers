#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

struct node{
  public:
    char val;
    node* ls;
    node* rs;
   // node* fa;
};
void tclear(node* x){
  if (x->ls!=NULL) tclear(x->ls);
  if (x->rs!=NULL) tclear(x->rs);
  delete(x->ls);
  delete(x->rs);
}

int findpos(char c,char* arr){
  int i;
  for (i=0;i<strlen(arr);i++)
    if (c==arr[i]) return(i);
}

int pos=0;
void maketree(node* x, char* preorder,char* inorder,int n,int m){
  if (pos>=strlen(preorder)) return;
  x->val=preorder[pos];

  //x->rs=new(node);
  int tmp=pos;
  if (findpos(preorder[pos],inorder)!=n){
    x->ls=new(node);
    maketree(x->ls,preorder,inorder,n,findpos(preorder[pos++],inorder)-1);
  }
  else x->ls=NULL;
  if (findpos(preorder[tmp],inorder)!=m){
    x->rs=new(node);
    pos++;
    maketree(x->rs,preorder,inorder,findpos(preorder[tmp],inorder)+1,m);
  }
  else x->rs=NULL;
}

void postorder(node* x){

  if (x->ls!=NULL) postorder(x->ls);
  if (x->rs!=NULL) postorder(x->rs);
  cout<<x->val;
}
int main(){
  int n,i,j;
  char preorder[100];
  char inorder[100];
  node* root;

  cin>>n;
  for (i=1;i<=n;i++){
    root=new(node);
    pos=0;
    memset(preorder,0,sizeof(preorder));
    memset(inorder,0,sizeof(inorder));
    cin>>preorder>>inorder;
    maketree(root,preorder,inorder,0,strlen(preorder)-1);
    postorder(root);
    cout<<"\n";
    tclear(root);
    delete(root);
  }
}
