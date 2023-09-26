/*Ricardo Varona
CPSC 1071
4/3/2023
*/

#include <iostream>
#include "Queue.h"
#include <cstdlib>
using namespace std;

// Queue default constructer which initalizes the front and rear node to null
Queue::Queue()
{
	front = nullptr;
    	rear = nullptr;
}

// Queue destructor created for the purpose 
Queue::~Queue()
{
	// pointer garbage created which points to front 
	QueueNode * garbage = front;
	// while there is still stuff in the queue
	while (garbage != nullptr)
	{
		// front points to next node
		front = front->next;
		// garbage points to next which is set to nullptr
		garbage->next = nullptr;
		// deletes garabe
		delete garbage;
		// resets garbage back to front
		garbage = front;
	}
}
 
 // Function enqueue inserts the value in num to the rear of the queue.                 
void Queue::enqueue(int num)
{
	// if isFull, prints out the queue is full 
	if(isFull()) {
		cout<<"The queue is full";
        }
	// checks if front and rear pointers are null/empty
	else if (isEmpty())
	{
		// new node is created and assinged to front pointer
		front = new QueueNode(num);
		// rear is set to same node
		rear = front;
	}
	// else, queuenode is added to the end of the queue 
	else 
	{
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
 }

// dequeues purpose is to remove a node at the end of a queue
void Queue::dequeue(int &num)
{
	QueueNode *temp = nullptr;
	// if is empty, prints out is empty
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
	}
	else
	{
		// num is set to the front value
		num = front->value;
		// temp s et to front
		temp = front;
		// front set to next value
		front = front->next;
		// deletes temp and effectively dequeues the que
		delete temp;
	}
}
 
// Function isEmpty returns true if the queue 
// is empty, and false otherwise.             
bool Queue::isEmpty() const
{
	if (front == nullptr)
		return true;
	else
		return false;
}

bool Queue::isFull () const
{
	// initiates count to keep track of current spot in queue	
	int count = 0; 
	// creates a pointer called current which points towards the front of the queue	
	QueueNode * current = front;
	// while current is not null pointer
        while (current != nullptr) {
		// count increases and current becomes the value of the next node
		count++;
		current = current ->next;	
	}
	// if count is = to one hundred, returns true to show maxSize
	if (count == maxSize) {
		return true;
	} 
	// else, returns false
	else {
		return false;
	}
}

 
 // Function clear dequeues all the elements  *
 // in the queue.                             *
void Queue::clear()
{
	int value;   // Dummy variable for dequeue
	while (!isEmpty())
       	dequeue(value);
}
