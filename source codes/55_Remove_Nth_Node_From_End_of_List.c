#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct point{
  long int val;
  struct point *nxt;
  struct point *pre;
};
typedef struct point pnt;

void clear(pnt *head){
  if (head->nxt==NULL) free(head); else {
    clear(head->nxt);
    free(head);}
}

void del(pnt *tail, long int m){
  long int cnt=1;
  pnt *now;
  now=tail;
  while (cnt<m){
    now=now->pre;
    cnt++;
  }

  now->pre->nxt=now->nxt;
  if (now->nxt!=NULL) now->nxt->pre=now->pre;
  free(now);
}

void getnum(){
  long int i,m;
  pnt *heada,*tail;
  pnt *now,*last;
  char c;
  heada=(pnt*)malloc(sizeof(pnt));
  last=heada;
  heada->nxt=NULL;
  scanf("%c",&c);
  while ((c!='\n')&&(c!=' ')){
    now=malloc(sizeof(pnt));
    now->nxt=NULL;
    if (heada->nxt==NULL) heada->nxt=now;
    now->val=(int)c-48;
    now->pre=last;
    last->nxt=now;
    last=now;
    scanf("%c",&c);
  }
  scanf("%ld",&m);
  getchar();
  if (m!=0) del(last,m);
  now=heada->nxt;
  while (now!=NULL){
    printf("%d",now->val);
    now=now->nxt;
  }
  printf("\n");
  clear(heada);
}

int main(){
  long int n,i,j;
  scanf("%ld\n",&n);
  for (i=1;i<=n;i++) getnum();
  return(0);
}
