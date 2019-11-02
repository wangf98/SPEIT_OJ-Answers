#include<stdio.h>
#include<string.h>
#define max 2147483647
int getnum(){
  char c;
  int cnt0,cnt,flag1,flag2;
  long long int s,tmp,b;
  cnt=0;
  cnt0=0;
  flag1=1;
  flag2=1;
  b=1;
  s=0;
  scanf("%c",&c);
  while (c!='\n'){
    if (c=='-') flag1=-1;
      else if (flag2==1){
        cnt++;
        tmp=(int)(c)-48;
        if (tmp==0) cnt0++; else cnt0=0;
        if ((cnt-cnt0<=9) || ((cnt-cnt0==10)&&(tmp<=2))){
          s=s+tmp*b;
          if ((flag1==1)&&(s>max) || ((flag1==-1)&&(s-1>max))){
            printf("0\n");
            flag2=0;};
          if (cnt<=9) b=b*10;}
        else{
          printf("0\n");
          flag2=0;
        }
    }
    scanf("%c",&c);
  }
  if (flag2==1) printf("%d\n",(int)(s*flag1));
}

int main(){
  int n,i;
  scanf("%d\n",&n);
  for (i=1;i<=n;i++){
    getnum();
    }
  return(0);
  }
