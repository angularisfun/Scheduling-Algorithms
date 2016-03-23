#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

struct process
{
    char name[100];
    int burst;
    struct process *next;
}*START = NULL;

int count;
struct process* newnode;

void Create()
{
    struct process* last;
    newnode = (struct process*)malloc(sizeof(struct process));
    cout<<"\n\n\tEnter Process Name:";
    cin>>newnode->name;
    cout<<"\n\n\tEnter Process Burst";
    cin>>newnode->burst;
    newnode->next = NULL;

    if(START == NULL)
    {
        START = newnode;
        newnode = NULL;
        last = START;
    }
    else
    {
        last->next = newnode;
        last = last->next;
        newnode = NULL;
    }
}

void FCFS()
{
    struct process* show = START;
    cout<<"\n";
    while(show!=NULL)
    {
      cout<<"\n";
      cout<<"\t"<<show->name;
      cout<<"\t"<<show->burst;


      show =show->next;
    }
}

int main()
{
  cout<<"\n\n\tEnter the number of processes";
  cin>>count;
  for(int i=0;i<count;i++)
  {
    Create();
  }
  cout<<"\n\n\tProcesses in FCFS order are:";
  FCFS();
  return 0;
}
