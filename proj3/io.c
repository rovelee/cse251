#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_XOPEN
#include <time.h>

#include "scheduler.h"

Node* loadf(Node* h, int* nums)
{
  FILE* file;
  
  if((file=fopen(FileName, "r")) == NULL)
  {
    puts("Fail to open file!");
    exit(0);
  }

  char buffer[100];
  int i;
  
  //创建指针指向头结点
  Node *p = h;
  
  //获取第一行，第一行为events总数
  fgets(buffer, sizeof(buffer), file);
  sscanf(buffer, "%d", nums);
  printf("nums: %d\n", *nums);

  for(i=0;i<*nums;i++)
  {
    // 获取本地时区，不然mktime函数返回-1
    struct tm tim = *localtime(&(time_t){time(NULL)});

    //获取description行的值
    fgets(buffer, sizeof(buffer), file);
    if(strlen(buffer)>0)
      buffer[strlen(buffer)-1] = '\0';
    strncpy(p->scheduler.description, buffer, 50 * sizeof(char));
    // printf("%s\n",p->scheduler.description);

    //获取start行的值
    fgets(buffer, sizeof(buffer), file);
    if(strlen(buffer)>0)
      buffer[strlen(buffer)-1] = '\0';
    strptime(buffer,"%a %b %d %H:%M:%S %Y",&tim);
    // printf("buffer : %s\n", buffer);
    // printf("%d %d %d %s\n",tim.tm_year,tim.tm_mon,tim.tm_yday,tim.tm_zone);

    if(mktime(&tim)==-1){
      printf("mktime erro\n");
      exit(0);
    }

    p->scheduler.start = mktime(&tim);
    // printf("%s", ctime(&(p->scheduler.start)));

    //获取end行的值
    fgets(buffer, sizeof(buffer), file);
    if(strlen(buffer)>0)
      buffer[strlen(buffer)-1] = '\0';
    strptime(buffer,"%a %b %d %H:%M:%S %Y",&tim);
    p->scheduler.end = mktime(&tim);
    // printf("%s", ctime(&(p->scheduler.end)));
    
    p->scheduler.date=mktime(&tim);
    // printf("%s", ctime(&(p->scheduler.date)));

    Node *a = (Node*)malloc(sizeof(Node));
    // p->scheduler=&sched;
    p->next = a;
    p = p->next;
  }

  fclose(file);
  return p;
}

char* tim2str(time_t* tt, char* fmt)
{
  char str[100];
  char* result = str;
  struct tm tim;
  tim = *localtime(tt);
  strftime(str,sizeof(str),fmt,&tim);
  return result;
}

int printfScheduler(Scheduler* sched){
  if(sched==NULL)
  {
    printf("scheduler is null\n");
    exit(0);
  }
  printf("%s ",tim2str(&(sched->date),"%m/%d/%Y"));
  printf("%s ",tim2str(&(sched->start),"%I:%M%p"));
  printf("%s ",tim2str(&(sched->end),"%I:%M%p"));
  printf("%s\n",sched->description);
  return 1;
}

int display(Node* h, int nums){
  Node* p = h;
  // printf("nums:%d\n",nums);
  while(nums>0){
    nums--;
    // printf("nums:%d\n",nums);
    printfScheduler(&(p->scheduler));
    p = p->next;
  }
  return 1;
}

int insertDes(char* des){
  // TODO
  return 1;
}
int insertDate(time_t* t){
  // TODO
  return 1;
}
int insertTime(time_t* t, char* prompt){
  // TODO
  return 1;
}
int insert(Node* tail){
  // TODO
  return 1;
}
int now(Node* head){
  // TODO
  return 1;
}
int deleteExpired(Node* head){
  // TODO
  return 1;
}

