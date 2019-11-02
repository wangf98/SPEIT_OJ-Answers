#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

int n=0;

void ins(long int num, long int* heap){
  n++;
  heap[n]=num;
  long int now=n,tmp;
  int finish=1;
  while (now!=1){
    if (heap[now]<heap[now/2]){
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
  heap[n]=0;
  n--;
  int finish=1;
  while (now*2<=n){
    char lr='l';
    if ((now*2+1<=n)&&(heap[now*2]>heap[now*2+1])) lr='r';
    if (lr=='l') {
      if (heap[now]>=heap[now*2]){
        tmp=heap[now];
        heap[now]=heap[now*2];
        heap[now*2]=tmp;
      } else finish=0;
      now=now*2;
    } else {
      if (heap[now]>=heap[now*2+1]){
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
  long int num,i,nn,k;
  cin>>nn>>k;
  long int heap[k+1];
  for (i=1;i<=k;i++){
    cin>>num;
    ins(num,heap);
  }
  for (i=k+1;i<=nn;i++){
    cin>>num;
    if (num>heap[1]){
      del(heap);
      ins(num,heap);
    }
  }
  cout<<heap[1]<<endl;
  return(0);
}
