#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void inverse_partie(char *ch1, char *ch2){
  char str;
  while (ch1 < ch2){
    str = *ch1;
    *ch1 = *ch2;
    *ch2= str;
    ch1++;
    ch2--;
  }
}
void reverse_complet(char *myArray){
  char *start = myArray;
  char *end = myArray;
  while (*start){
    if (*start == ' '){
      start++;
      end++;
    }
    else if (*end == ' '||*end == '\0'){
      inverse_partie(start, --end);
      start = ++end;
    }else end++;
  }
}
int main(void)
{
  int k,n;
  scanf("%d",&n);
  getchar();
  for (k=0;k<n;k++){
    char str[200];
    scanf("%[^\n]",&str);
    getchar();
    reverse_complet(str);
    printf("%s\n",str);
  }
}
