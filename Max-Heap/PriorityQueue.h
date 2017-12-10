#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define MAX_SIZE 300

class PriorityQueue {
	public: 
		PriorityQueue(void);

		void push(const int given);
		int pop(void); 
		int top(void) const; 
		int getSize(void) const;
		bool isEmpty(void) const;

	private:
		int size; 
		int items[MAX_SIZE];
};

#endif
