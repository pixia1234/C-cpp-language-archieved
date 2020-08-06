#include <stdio.h>
int main(int argc, char const *argv[]) {
  int n[4][4],i,j;
  for(i=0;i<=3;i++) for(j=0;j<=3;j++) n[i][j]=10*i+j;
  printf("%d\n",(*(n+1))[1] );
  printf("%d\n",*(*(n+1)+1) );
  printf("%d\n",*(n+1)[1]);
  printf("%d\n",*((n+1)[1]) );
  printf("%d\n",*(*((n+1)+1)) );
  printf("%d\n", **(n+2));
  return 0;
}
