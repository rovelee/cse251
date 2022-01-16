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

  // 获取本地时区，不然mktime函数返回-1
  struct tm tim = *localtime(&(time_t){time(NULL)});
  for(i=0;i<*nums;i++)
  {

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

    if(mktime(&tim)==-1){
      printf("mktime erro\n");
      exit(0);
    }
    p->scheduler.start = mktime(&tim);

    // printf("%d %d %d %s\n",tim.tm_year,tim.tm_hour,tim.tm_min,tim.tm_zone);
    // printf("start buffer : %s\n", buffer);
    // printf("start :%s", ctime(&(p->scheduler.start)));

    //获取end行的值
    fgets(buffer, sizeof(buffer), file);
    if(strlen(buffer)>0)
      buffer[strlen(buffer)-1] = '\0';
    strptime(buffer,"%a %b %d %H:%M:%S %Y",&tim);
    p->scheduler.end = mktime(&tim);
    // printf("end buffer : %s\n", buffer);
    // printf("end :%s\n", ctime(&(p->scheduler.end)));
    
    p->scheduler.date=mktime(&tim);
    // printf("%s", ctime(&(p->scheduler.date)));

    if(i<*nums-1)
    {
      Node *a = (Node*)malloc(sizeof(Node));
      // p->scheduler=&sched;
      p->next = a;
      p = p->next;
    }else{
      p->next=NULL;
    }
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

void insertDes(char* des){
  char buffer[50];
  int v = 1;
  while(v)
  {
    printf("What is the event: ");
    fgets(buffer, sizeof(buffer), stdin);
    if(strlen(buffer) > 0)
    {
      buffer[strlen(buffer)-1] = '\0';
      v = 0;
    }
  }
    strncpy(des, buffer, sizeof(buffer));
}

void insertDate(time_t* t){
  char buffer[100];
    char *result;
    struct tm date = *localtime(&(time_t){time(NULL)});
    do
    {
        printf("Event date: ");

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while(result == NULL);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    // date.tm_isdst = 1;

    *t = mktime(&date);
}
time_t insertTime(time_t date, char* prompt){
  char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while(result == NULL);

    return mktime(&time);
}

Node* insert(Node* tail){
  // printf("insert tail : %p\n",tail);
  Node* a = (Node*)malloc(sizeof(Node));
  tail->next=a;
  a->next=NULL;
  tail=tail->next;
  if(tail==NULL)
  {
    printf("tail is null\n");
    exit(0);
  }
  insertDes(tail->scheduler.description);
  insertDate(&(tail->scheduler.date));
  tail->scheduler.start = insertTime(tail->scheduler.date, "Start time: ");
  tail->scheduler.end =insertTime(tail->scheduler.date, "End time: ");
  return a;
}
int now(Node* head){
  if(head==NULL)
    return 0;
  printf("Currently active events:\n");
  Node *p = head;
  struct tm tim = *localtime(&(time_t){time(NULL)});
  time_t tn = mktime(&tim);
  int count=0;
  while(p!=NULL){
    // printf("%ld\n%ld\n%ld\n",tn,p->scheduler.start,p->scheduler.end);
    if(p->scheduler.start<tn&&p->scheduler.end>tn){
      count++;
      printfScheduler(&(p->scheduler));
    }
    p = p->next;
  }
  if(count == 0)
    printf("no active events.\n");
  return 1;
}
int deleteExpired(Node* head){
  // TODO
  return 1;
}

