#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(void) : size (0) { }

int PriorityQueue::getSize(void) const {
	return size;
}

bool PriorityQueue::isEmpty(void) const {
	return size == 0; 
}

int PriorityQueue::top(void) const {
	return items[0];
}

void PriorityQueue::push(const int given) {
	if ( size == MAX_SIZE )
		return;
	
	items[size] = given;

	int current = size; 
	int parent  = ((size - 1) >> 1);
	
	// trickle up
	while ((current > 0) && items[current] > items[parent]) {
		int temp = items[parent];
		items[parent] = items[current]; 
		items[current] = temp;

		current = parent; 
		parent = ((current -1) >> 1);
	}
	
	size++; 
}

int PriorityQueue::pop(void) {
	int topItem = top();

	if (!isEmpty()) {
 		items[0] = items[--size];

		int current = 0;
		
		// iterative trickle down
		while (1) {
			int left = (current << 1) + 1; 
			int right = (current << 1) + 2;
			
			if (left >= size  && right >= size)
				break; 

			if ((right < size) && (items[current] < items[left] || items[current] < items[right])) {
				if (items[right] > items[left]) {
					int temp = items[right]; 
					items[right] = items[current];
					items[current] = temp;
					current = right;
				}
				else {
					int temp = items[left];
					items[left] = items[current]; 
					items[current] = temp;
					current = left;
				}
			}
			else if (items[left] > items[current]) {
				int temp = items[left];
				items[left] = items[current];
				items[current] = temp; 
				current = left;
			}
			else break; 
		} 
	}

	return topItem;
}	
