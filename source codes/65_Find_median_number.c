#include<stdio.h>
#include<math.h>
#include<string.h>
int getmid(long int a[],long int b[]){
  long int i,posa,posb,posc,l,m;
  long int c[a[0]+b[0]+2];

  l=a[0]+b[0];
  posa=1; posb=1; posc=1;
 // for (i=1;i<=a[0];i++)printf("%ld ",a[i]); printf("\n");
  //for (i=1;i<=b[0];i++)printf("%ld ",b[i]); printf("\n");
  while (posc<=l/2+1){
    if ((a[posa]<=b[posb])&&(posa<=a[0])){
      c[posc]=a[posa];
      posa++;
      posc++;
    }
    else {
      c[posc]=b[posb];
      posb++;
      posc++;
    }
  }
  m=l/2;
//  for (i=1;i<=m+1;i++)printf("%ld ",c[i]); printf("\n");
  if (l % 2==0) printf("%.1f\n",(double)(c[m]+c[m+1])/2);
  else printf("%.1f\n",(double)c[m+1]);
}
int getarr(){
  long int l1,l2,i,m;
  scanf("%ld%ld",&l1,&l2);
  long int a[l1+2];
  long int b[l2+2];
  a[0]=l1;
  b[0]=l2;
  for (i=1;i<=l1;i++) scanf("%ld",&a[i]);
  scanf("\n");
  //printf("jakhfk");
  for (i=1;i<=l2;i++) scanf("%ld",&b[i]);
  getmid(a,b);
}
int main(){
  long int n,i;
  scanf("%ld",&n);
  for (i=1;i<=n;i++) getarr();
  return(0);
}
