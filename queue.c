#include <stdio.h>

int size = 10;
int queue[10];
int rear = -1;  
int front = -1;

int enqueue(int data)
{
    int x, temp[front], ctr = 0;

    if(front == -1)
        front = 0;
    
    rear++;
    queue[rear] = data;

    // sorts the data
    for(x = front; x <= rear; x++)
    {
        if(queue[x] > queue[rear])
        {
            temp[x] = queue[x];
            queue[x] = queue[rear];
            queue[rear] = temp[x];
        }
    }
   // rear = (rear + 1) % size;    // for circular queue
}

int dequeue() 
{
    int data = queue[front];

    //front += 1;
    //if(front == rear)

    if(front != rear)
        front = (front + 1) % size;    // for circular queue
    else
    {
        front -= 1;
        rear -= 1;
    }

    return data;
}   

void display()
{
    int x;

    printf("Elements in Queue: ");
	if(rear != -2)
    {
        for(x = front; x <= rear; x++)
		printf("%d ", queue[x]);
    }

    /*
        For printing after clearing
        0 - an element not added would still be printed after clearing
        The following line of codes is a fix to this issue
    */
    else
    {
        for(x = front; x < rear; x++)
		printf("%d ", queue[x]);
                    
        rear = -1;  //resetting the rear to the original value
    }
}

int isEmpty() 
{
   if(front == -1)
      return 1;
   else
      return 0;
}

int isFull() 
{
   if(rear == size - 1)
      return 1;
   else
      return 0;
}

int clear()
{
	return front = -1, rear = -2;   
}

int head() 
{
   return queue[front];
}

int tail() 
{
   return queue[rear];
}
