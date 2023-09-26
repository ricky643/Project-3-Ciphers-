/*Ricardo Varona
CPSC 1071
4/3/2023
*/

#ifndef QUEUE_H
#define QUEUE_H

class Queue 
{	// struct created so nodes can easily point to next node and access member variables
	struct QueueNode 
	{
		int value;
		QueueNode *next;
		// constructor for queue node
		QueueNode(int value1, QueueNode *next1 = nullptr) 
		{
			// passes int value to the constructor
			value = value1;
			// points to the nexgt node
			next = next1;
		}
	};
	// These track the front and rear of the queue
	QueueNode *front;
	QueueNode *rear;
 	public:
    	// Constructor and Destructor
    	Queue();
    	~Queue();
	// Member functions
	void enqueue(int);
	void dequeue(int &);
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	private:
	// constant size set to set size in isFull
	const int maxSize = 100;
 };
#endif

