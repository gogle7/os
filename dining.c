#include<stdio.h>
enum{
thinking,eating,hungry}
state[5];
int signal()
 {
  return eating;
  }
int self[5];

int wait()
 {
 return hungry;
 }
void init(int n)
 {
 int i;
 for(i=0;i<n;i++)
 state[i]=thinking;
 }
void test(int i,int n)
 {
 if(state[(i+n-1)%n]!=eating&&state[i]==hungry&&state[(i+1)%n]!=eating)
  {
  state[i]=eating;
  self[i]=signal();
  }
 }
void putdown(int i,int n)
{
 state[i]=thinking;
printf("philosopher %d went to thinking state\n",i+1);
test((i+n-1)%n,n);
test((i+1)%n,n);
}

void pickup(int i,int n)
{
state[i]=hungry;
test(i,n);
if(state[i]!=eating)
 {
self[i]=wait();
printf("philosopher %d is waiting\n",i+1);
 }

else
 printf("philosopher %d is eating\n",i+1);
}

void showstate(int n)
 {
 int i=0;
for(i=0;i<n;i++)
 {
if(state[i]==thinking)
 printf("philosopher %d went to thinking state\n",i+1);
else if(state[i]==hungry)
  printf("philosopher %d is hungry\n",i+1);
else
  printf("philosopher %d is eating\n",i+1);
}
}
int main()
 {
 int i=0,n=0;
 printf("no. of philosophers:");
 scanf("%d",&n);
 init(n);
 while(1)
 {
  printf("\n1.pickup\t2.putdown\t3.show state\t4.exit\n");
  printf("enter choice:");
  scanf("%d",&i);
  switch(i)
   {
    case 1:printf("philosopher no.");
           scanf("%d",&i);
           pickup(i-1,n);
           break;
    case 2:printf("philosopher no.");
           scanf("%d",&i);
           putdown(i-1,n);
           break;
   case 3:showstate(n);
          break;
   case 4:return;
}
}
}

