class MyCircularQueue {
public:
    MyCircularQueue(int k) {
       data.resize(k);
       maxSize=k;
    }
    bool enQueue(int value) {
      if (isFull()) return false;
        tail = (tail + 1) % maxSize;
        data[tail] = value;
        return true; 
    }
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) head = 0, tail = -1;
        else head = (head + 1) % maxSize;
        return true; 
    }
    int Front() {
      return isEmpty() ? -1 : data[head];  
    }
    int Rear() {
      return isEmpty() ? -1 : data[tail]; 
    }
    bool isEmpty() {
      return tail==-1;  
    }
    bool isFull() {
      return !isEmpty() && (tail + 1) % maxSize == head;
    }
    private:
    int maxSize, head = 0, tail = -1;
    vector<int> data;
};
 

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */