//打印楼梯，同时在楼梯上方打印两个笑脸。
#include "stdio.h"
#include "conio.h"
int main(int argc,char *argv[])
{
  int i,j;
  printf("\1 \1\n");/*输出两个笑脸*/
  for(i=1;i<11;i++)
  {
    for(j=1;j<=i;j++)
      printf("%c%c",220,220);
    printf("\n");
  }
  return 0;
}