#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scheduler.h"

int main(int argc, char const *argv[])
{
  Node *p_head, *p_tail;
  int nums = 0;

  //初始化头结点
  p_head = (Node*)malloc(sizeof(Node));
  //加载文件中的内容
  p_tail = loadf(p_head, &nums);
  // p_tail->next = NULL;
  // printf("head: %p\ntail: %p",p_head,p_tail);
  // printf("%d\n",nums);

  while (1)
  {
    printf("1 - Insert a new event\n");
    printf("2 - Display all events\n");
    printf("3 - Now?\n");
    printf("4 - Delete expired\n");
    printf("0 - Exit\n");
    printf("Please select an option: ");
    char cc[10];
    fgets(cc,sizeof(cc),stdin);
    char c = cc[0];
    if (c=='0')
    {
      break;
    }
    else if (c=='1')
    {
      p_tail = insert(p_tail);
      nums++;
      // printf("tail : %p tail.next : %p\n",p_tail,p_tail->next);
    }
    else if (c=='2')
    {
      display(p_head, nums);
    }
    else if (c=='3')
    {
      now(p_head);
    }
    else if (c=='4')
    {
      deleteExpired(p_head);
    }
    else
    {
      puts("Please type right command!\n");
    }
    if(feof(stdin))
      return 0;
  }

  return 0;
}
