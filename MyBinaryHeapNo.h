#ifndef __MYBINARYHEAP_H__
#define __MYBINARYHEAP_H__

#include <iostream>
#include <cstdlib>

#include "MyVector.h"

// ComparableType should be comparable (<, >, ==, >=, <= operators implemented)
// ComparableType should also have +, +=, -, -= operators implemented to support priority adjustment

template <typename ComparableType>
class MyBinaryHeap 
{
  private:
    int currentSize;
	MyVector<ComparableType> data;  // the array that holds the data elements
	

    // moves the data element at the pth position of the array up
    void percolateUp(const size_t p) 
    {
        // code begins
        //p = ++currentSize;        
        
        ////////////////////////////////
        
        
        ComparableType temp = std::move(data[p]);
        int loc = p;
        
        while(loc != 1 && data[loc/2] > data[loc]){
            data[loc] = data[loc/2];
            loc = loc/2;
        }
        data[loc] = std::move(temp);
        /////////////////////////////////
        
                     //elt = data[p]
        /*ComparableType temp = item;
        int tempNum = p;
        
        data[0] = std::move(temp);
        for(; item < data[tempNum/2]; tempNum/=2){
            data[tempNum] = std::move(data[tempNum/2]);
        }
        data[tempNum] = std::move(data[0]);*/
        // code ends
    }

    // moves the data element at the pth position of the array down
    void percolateDown(const size_t p) 
    {
        // code begins
        int child;
        int tempP = p;
        ComparableType temp = std::move(data[p]);
        
        for( ; tempP*2 <= data.size(); tempP = child){
            child = tempP * 2;
            if(child != data.size() && data[child+1] < data[child]){
                ++child;
            }
            if(data[child] < temp){
                data[tempP] = std::move( data[child]);
            }
            else{
                break;
            }
        }
        data[tempP] = std::move(temp);
        // code ends
    }

    // reorders the data elements in the array to ensure heap property
    void buildHeap() 
    {
        // code begins
        for(int i = currentSize / 2; i>0; --i){
            percolateDown(i);
        }
        // code ends
    }	

  public: 

    // default constructor
    explicit MyBinaryHeap() :
        data(1)     // reserve data[0]
    {
        // code begins
        
        // code ends
    }

    // constructor from a set of data elements
    MyBinaryHeap(const MyVector<ComparableType>& items) : 
        data(1)     // reserve data[0]
    {
        // code begins
        for( int i = 0; i < items.size(); i++){
            data[i+1] = items[i];
        }
        buildHeap();
        // code ends
    }

    // copy constructor
    MyBinaryHeap(const MyBinaryHeap<ComparableType>& rhs)
    {
        // code begins

        // code ends
    }

    // move constructor
    MyBinaryHeap(MyBinaryHeap<ComparableType> && rhs)
    {
        // code begins

        // code ends
    }

    // copy assignment
    MyBinaryHeap& operator=(const MyBinaryHeap<ComparableType>& rhs)   
    {
        // code begins
        MyBinaryHeap copy = rhs;
        std::swap(this, copy);
        return this;
        // code ends
    }

    // move assignment
    MyBinaryHeap& operator=(MyBinaryHeap<ComparableType> && rhs)
    {
        // code begins

        // code ends
    }

    // inserts x into the priority queue (copy)
	void enqueue(const ComparableType& x)
    {
        // code begins
        if(currentSize == data.size() - 1){
            data.resize(data.size() * 2);
        }
        
        currentSize++;
        int hole = currentSize;
        percolateUp(hole);
        data[hole] = x;
        
        // code ends
    } 

    // inserts x into the priority queue (move)
    void enqueue(ComparableType && x)
    {
        // code begins
        if(currentSize == data.size() - 1){
            data.resize(data.size() * 2);
        }
        currentSize++;
        int hole = currentSize;
        percolateUp(hole);
        data[hole] = std::move(x);
        
        // code ends
    }

    // accesses the data element with the highest priority
	const ComparableType& front()
    {
        // code begins
        if(!empty()){
            return data[1];
        }
        return 37;
        // code ends
    } 

    // deletes the data element with the highest priority from the queue
    void dequeue()
    {
        // code begins
        if(currentSize == 0){
            return;
        }
        currentSize--;
        int hole = currentSize;
        percolateDown(hole);
        data.pop_back();
        // code ends
    }

    // verifies whether the array satisfies the heap property
    bool verifyHeapProperty(void)
    {
        // code begins
        if(true){
            return true;
        }
        // code ends
    }

    // disrupts heap property by random shuffling
    void disruptHeapProperty(void)
    {
        if(data.size() <= 3)
            return;
        for(size_t i = 0; i < 1000; ++ i)
        {
            size_t p = 1 + ((int) rand()) % data.size();
            size_t q = 1 + ((int) rand()) % data.size();
            std::swap(data[p], data[q]);
        }
        return;
    }

    // merges two heaps; the second heap can be destructed after the merge
    MyBinaryHeap& merge(MyBinaryHeap<ComparableType> && rhs) 
    {
        // code begins
        return rhs;
        // code ends
    }

    // increases the priority measure of an element at a specific position and reorder the heap
	void increaseKey(const size_t p, const unsigned int d)
    {    
        // code begins

        // code ends
    }

    // decreases the priority measure of an element at a specific position and reorder the heap
    // if the current priority is smaller than the requested decrement, assign priority 0
	void decreaseKey(const size_t p, const unsigned int d) 
    {
        // code begins

        // code ends   
    }

    // checks whether the heap is empty
    bool empty()
    {
        // code begins
        return currentSize == 0;
        // code ends
    }

    // removes all data elements from the heap
    void clear()
    {
        // code begins

        // code ends
    }

    // returns the size of the heap
    size_t size()
    {
        // code begins
        return currentSize;
        // code ends
    }

    // prints the data in the array
    void print() 
    {
        const char delim = '\t';
        for (size_t i = 1; i < data.size(); ++ i) {
            std::cout << data[i] << delim;
        }
        std::cout << std::endl;
        return;
    }

};

#endif // __MYBINARYHEAP_H__
