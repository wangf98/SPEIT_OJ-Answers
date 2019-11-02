#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#include<iostream>
#define maxlongint 2147483647;
using namespace std;

int n=0;

void ins(long int num, long int* heap){
  n++;
  heap[n]=num;
  long int now=n,tmp;
  int finish=1;
  while (now!=1){
    if (heap[now]>heap[now/2]){
      tmp=heap[now];
      heap[now]=heap[now/2];
      heap[now/2]=tmp;
    } else finish=0;
    now=now/2;
    if (finish==0) break;
  }
}

void del(long int* heap){
  long int now=1,tmp;
  tmp=heap[n];
  heap[n]=heap[1];
  heap[1]=tmp;
  heap[n]=maxlongint;
  n--;
  int finish=1;
  while (now*2<=n){
    char lr='l';
    if ((now*2+1<=n)&&(heap[now*2]<heap[now*2+1])) lr='r';
    if (lr=='l') {
      if (heap[now]<=heap[now*2]){
        tmp=heap[now];
        heap[now]=heap[now*2];
        heap[now*2]=tmp;
      } else finish=0;
      now=now*2;
    } else {
      if (heap[now]<=heap[now*2+1]){
        tmp=heap[now];
        heap[now]=heap[now*2+1];
        heap[now*2+1]=tmp;
      } else finish=0;
      now=now*2+1;
    }
    if (finish==0) break;
  }
}


int main(){
  long int time;
  long int num,i,j,nn,m;
  cin>>time;
  long int heap[101];
  for (i=1;i<=time;i++){
    cin>>nn>>m;
    n=0;
    for (j=0;j<=100;j++) heap[j]=maxlongint;
    for (j=1;j<=nn;j++){
      cin>>num;
      ins(num,heap);
    }
    for (j=1;j<=m;j++){
      char c;
      cin>>c;
      //cout<<c<<endl;
      int k;
      if (c=='I') {
        cin>>num;
        ins(num,heap);
        //n++;
      }
      if (c=='P') {
        del(heap);
        //n--;
      }
      cout<<heap[1]<<endl;
      //for (k=1;k<=n;k++) cout<<heap[k]<<" ";
      //cout<<endl;
    }
    //for (j=1;j<=n;j++) cout<<heap[j]<<endl;
  }
  return(0);
}
