/***************************************************************************************
 In a computer-operated robotic system, three robot are designed. Each robot gets ACTIVE one by one after particular interval of time. Like robot-1 gets ACTIVE for one minute then robot-2 gets ACTIVE for one minute and then robot-3. After robot-3, again robot-1 gets ACTIVE. Kindly implement the below operation of circular queue using C programming language. Consider, maximum capacity of the circular queue as 3:

insert (ENQUEUE)
delete (DEQUEUE)
display (TRACING)
Note 1: you need to match the input and output format exactly as given in the sample test case

Input 

    In the input, First line will contain 4 elements for the circular queue 
    
Output

In the output, first line will show all 3 elements separated by arrow (->).
Second line will display status of Queue as "!!Full!!", then third line is blank
Fourth line will display front pointer value, fifth line will display queue elements, and sixth line will display rear pointer value.
Seventh line will display deQueue operation and eighth line will show enQueue operation.
Nineth line will display front pointer value, tenth line will display queue elements, and eleventh line will display rear pointer value.
note
Constraints
No constraints

view_list
Examples
Input:
111
222
333
444

Output:
->111->222->333
!!Full!!

Front->0
->111->222->333
Rear->2
DEQ->111
ENQ->444
Front->1
->222->333->444
Rear->0
Explanation:
In the input, First line will contain 4 elements for the circular queue.
In the output, first line will show all 3 elements separated by arrow (->).
Second line will display status of Queue as "!!Full!!", then third line is blank
Fourth line will display front pointer value, fifth line will display queue element, and sixth line will display rear pointer value.
Seventh line will display deQueue operation and eighth line will show enQueue operation.
Nineth line will display front pointer value, tenth line will display queue element, and eleven line will display rear pointer value

Farhan Ashraf
**********************************************************************************************/
#include <stdio.h>

#define SIZE 3

int items[SIZE];
int front = -1, rear = -1;
int kk=0;


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}


int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int element) {
  if (isFull())
    printf("\n!!Full!! \n");
  else {
      if (kk==0)
      {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("->%d", element);
      }
      else
      {
          if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            printf("ENQ->%d", element);
      }
         
      }
}

int deQueue() {
  int element;
  if (isEmpty()) {
    return (-1);
  } else {
    element = items[front];
    printf("DEQ->%d\n", element);
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    else {
      front = (front + 1) % SIZE;
    }
    return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\nFront->%d ", front);
    printf("\n");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("->%d", items[i]);
    }
    printf("->%d", items[i]);
    printf("\nRear->%d \n", rear);
  }
}

int main() {
    kk=0;
    int n=4,i,a[4];
    for(i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<4;i++){
        enQueue(a[i]);
    }
  kk=1;
  display();
  deQueue();
  enQueue(a[3]);
  display();
  return 0;
}