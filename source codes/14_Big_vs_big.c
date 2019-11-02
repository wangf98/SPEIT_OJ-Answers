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

void clear(pnt * head){
  if (head->nxt==NULL) free(head); else {
    clear(head->nxt);
    free(head);}
}

int mult(pnt *ha,pnt *hb){
  pnt *tmp,*nowans,*nowa,*nowb,*headans,*nowheadans;
  nowa=ha->nxt;
  headans=(pnt *)malloc(sizeof(pnt));
  headans->nxt=NULL;
  headans->pre=NULL;
  nowheadans=headans;
  while (nowa!=NULL){
    nowb=hb->nxt;
    if (nowheadans->nxt==NULL) {

      tmp=(pnt *)malloc(sizeof(pnt));
      tmp->val=0;
      tmp->nxt=NULL;
      if (nowheadans!=headans) tmp->pre=nowheadans; else tmp->pre=NULL;
      nowheadans->nxt=tmp;
    };
    nowans=nowheadans->nxt;
    while (nowb!=NULL){
      nowans->val=nowans->val+(nowa->val)*(nowb->val);
      tmp=nowans;
      while ((tmp->pre!=NULL)&&(tmp->val>=10)){
        (tmp->pre)->val=tmp->pre->val+tmp->val/10;
        tmp->val=tmp->val%10;
        tmp=tmp->pre;
      }
      if ((nowans->nxt==NULL) &&(nowb->nxt!=NULL)){
        nowans->nxt=(pnt *)malloc(sizeof(pnt));
        (nowans->nxt)->val=0;
        (nowans->nxt)->pre=nowans;
        (nowans->nxt)->nxt=NULL;
      }
      nowans=nowans->nxt;
      nowb=nowb->nxt;
    }
    nowa=nowa->nxt;
    nowheadans=nowheadans->nxt;
  }
  nowans=headans->nxt;
  if (nowans->val==0) printf("0");
  else while (nowans!=NULL){
    printf("%d",nowans->val);
    nowans=nowans->nxt;
  }
  clear(headans);
  printf("\n");
}

void getnum(){
  long int i;
  pnt *heada,*headb;
  pnt *now,*last;
  char c;
  heada=(pnt*)malloc(sizeof(pnt));
  last=heada;
  heada->nxt=NULL;
  scanf("%c",&c);
  while (c!='\n'){
    now=malloc(sizeof(pnt));
    now->nxt=NULL;
    if (heada->nxt==NULL) heada->nxt=now;
    now->val=(int)c-48;
    now->pre=last;
    last->nxt=now;
    last=now;
    scanf("%c",&c);
  }
  headb=(pnt*)malloc(sizeof(pnt));
  headb->nxt=NULL;
  last=headb;
  scanf("%c",&c);
  while (c!='\n'){
    now=(pnt*)malloc(sizeof(pnt));
    now->nxt=NULL;
    if (headb->nxt==NULL) headb->nxt=now;
    now->val=(int)c-48;
    now->pre=last;
    last->nxt=now;
    last=now;
    scanf("%c",&c);
  }
  mult(heada,headb);
  clear(heada); clear(headb);
}

int main(){
  long int n,i,j;
  scanf("%ld\n",&n);
  for (i=1;i<=n;i++) getnum();
  return(0);
}
