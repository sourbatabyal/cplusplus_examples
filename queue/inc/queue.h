#pragma once

#ifndef queue_h
#define queue_h

#include <iostream>

class queue
{
private:
    // Initialize front and rear 
    int rear, front; 
  
    // Circular Queue 
    int size; 
    int *arr;
public:
    queue(int size);
    ~queue();
    
    void enQueue(int value); 
    int deQueue(); 
    void displayQueue();
};

#endif // !queue_h