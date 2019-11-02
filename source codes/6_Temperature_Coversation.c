#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
  int n,i;
  char type;
  double t;
  scanf("%d\n",&n);
  for (i=1;i<=n;i++){
    scanf("%c %lf",&type,&t);
    getchar();
    if (type=='C')
      printf("%0.2lf\n",t*1.8+32);
    else
      printf("%0.2lf\n",(t-32)/1.8);
    };
  return(0);
  }