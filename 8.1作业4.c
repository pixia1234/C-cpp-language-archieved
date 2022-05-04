#include<stdio.h>
int ans=0;
void queen(int k,int shu[],int h[],int up[],int down[],int an[])
{
  int i;
  if(k==7)
  {
    for(i=0;i<8;i++)
    {
      if(shu[i]==0)
      {
        ans++;
        an[k]=i;
        for(i=0;i<7;i++) printf("%d ",an[i]);
        printf("\n");
      }
      return ;
    }
  }
  for(i=0;i<8;i++)
  {
    if(shu[i]==0)
    {
      int shu_[8]={0},h_[8]={0},up_[8]={0},down_[8]={0},j;
      h[i]=1;
      up[i]=1;
      down[i]=1;
      an[k]=i;
      for(j=0;j<8;j++) if(h[j]==1){ h_[j]=1;shu_[j]=1;}
      for(j=0;j<7;j++) if(up[j]==1) {up_[j+1]=1;shu_[j+1]=1;}
      for(j=1;j<8;j++) if(down[j]==1) {down_[j-1]=1;shu_[j-1]=1;}
      queen(k+1,shu_,h_,up_,down_,an);
    }
  }
}
int main()
{
  int shu[8]={0},h[8]={0},up[8]={0},down[8]={0},an[8]={0};
  queen(0,shu,h,up,down,an);
  printf("%d",ans);
  return 0;
}
