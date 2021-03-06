#ifndef SCHEDULING_H
#define SCHEDULING_H
#define FileName "schedule.dat"
#define __USE_XOPEN
#include <time.h>

typedef struct Scheduler{
  char description[50];
  time_t date;
  time_t start;
  time_t end;
} Scheduler;

typedef struct Node{
  struct Node* next;
  Scheduler scheduler;
}Node;

Node* loadf(Node* head, int* nums);
int savef(Node* head, int nums);
Node* insert(Node* p);
int display(Node* head, int nums);
int now(Node* head);
int deleteExpired(Node** head);
int check(Node* head, Scheduler in);


#endif
