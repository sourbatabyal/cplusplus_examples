#include <iostream>
#include <queue.h>

int main(int argc, const char** argv) {
    queue q(5); 
  
    // Inserting elements in Circular Queue 
    q.enQueue(14); 
    q.enQueue(22); 
    q.enQueue(13); 
    q.enQueue(-6); 
  
    // Display elements present in Circular Queue 
    q.displayQueue(); 
  
    // Deleting elements from Circular Queue 
    printf("\nDeleted value = %d", q.deQueue()); 
    printf("\nDeleted value = %d", q.deQueue()); 
  
    q.displayQueue(); 
  
    q.enQueue(9); 
    q.enQueue(20); 
    q.enQueue(5); 
  
    q.displayQueue(); 
  
    q.enQueue(20); 
    return 0; 
}