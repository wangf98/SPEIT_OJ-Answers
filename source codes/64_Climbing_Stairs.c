#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
  int n,i,t;
  long long int a[50];
  scanf("%d",&n);
  a[0]=1;
  a[1]=2;
  for (i=2;i<44;i++)
    a[i]=2*(a[i-1]+a[i-2]);
  for (i=1;i<=n;i++){
    scanf("%d",&t);
    printf("%lld\n",a[t]);
  }
  printf("END\n");
  return(0);
}
