#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
  long i,a,n;
  double t;
  while(scanf("%ld",&a)!=EOF){
    n=0;
    t=sqrt(a);
    for (i=1;i<=t;i++) {
    if (a%i==0)
      if (i==t) n++;
      else n=n+2;
    };
    printf("%ld\n",n);
  }
  return(0);
}
