#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

struct node{
  node* l;
  node* r;
  int c;
  int time;
};

int val[27];

void qsort(node** nd,int* a,int l,int r){
  int tmp,i,j,mid;
  node* tmpn;
  i=l;
  j=r;
  mid=a[(l+r)/2];
  while (i<j){
    while (a[i]<mid) i=i+1;
    while (a[j]>mid) j=j-1;
    if (i<=j){
      tmp=a[i];
      a[i]=a[j];
      a[j]=tmp;
      tmpn=nd[i];
      nd[i]=nd[j];
      nd[j]=tmpn;
      i=i+1;
      j=j-1;
    }
  }
  if (l<j) qsort(nd,a,l,j);
  if (i<r) qsort(nd,a,i,r);
}


void visit(node* x,int n){

  if (x->l!=NULL) visit(x->l,n+1);
  if (x->r!=NULL) visit(x->r,n+1);
  if (x->c!=-1) val[x->c]=n;
}

void huffman(node** now,int* time,int l,int r){
  while(l!=r){
    node* fa=new(node);
    fa->l=now[l];
    fa->r=now[l+1];
    fa->c=-1;
    fa->time=fa->l->time+fa->r->time;
    time[l+1]=fa->time;
    now[l+1]=fa;
    l++;
    qsort(now,time,l,r);
  }
}

int main(){
  char s[102];//ss[102];
  int numa,numh,l,i,j;
  int time[28],timei[28];
  int sum[28];
  node* fa;
  node* team[28];
  while(cin >> s){
    memset(time,0,sizeof(time));
    memset(timei,0,sizeof(timei));
    memset(val,0,sizeof(val));
    memset(sum,0,sizeof(sum));
    if (strcmp(s, "END") == 0) break;
  //  l=0;
    for (i=0;i<strlen(s);i++){
      if (s[i]>='A'&&s[i]<='Z') {
        time[(int)(s[i])-64]++;
      }
      else if (s[i]='_') time[27]++;
    }
    j=0;
    for (i=1;i<=27;i++){
      team[i]=new(node);
      team[i]->c=i;
      team[i]->time=time[i];
      team[i]->l=NULL;
      team[i]->r=NULL;
    }
    for (i=1;i<=27;i++)timei[i]=time[i];
    qsort(team,time,1,27);
    while (time[j+1]==0) j++;
    numa=strlen(s)*8;
    if (j==26) printf("%d %d 8.0\n",numa,l); else{


     // for (i=j+1;i<=27;i++) cout<<team[i]->time<<' ';
     // cout<<endl;
      huffman(team,time,j+1,27);
      fa=team[27];
      //cout<<fa->time<<endl;
      visit(fa,0);
      numh=0;
      for (i=1;i<=27;i++) numh=numh+val[i]*timei[i];
      //cout<<endl;
      printf("%d %d %.1f\n",numa,numh,(float)(numa)/(float)numh);
    }
  }

}
