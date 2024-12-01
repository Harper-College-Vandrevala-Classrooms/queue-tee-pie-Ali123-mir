#include <iostream>
#include <string>
using namespace std;

class Cutie {
public:
    virtual string description() = 0;    
    virtual int cuteness_rating() = 0;    
    virtual ~Cutie() = default;           
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }

    int cuteness_rating() override {
        return 11; 
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A fluffy kitten playing with a ball of yarn";
    }

    int cuteness_rating() override {
        return 10;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny monkey with expressive eyes";
    }

    int cuteness_rating() override {
        return 9;
    }
};


class QueueTees {
private:
    Cutie* queue[10];  
    int front;         
    int rear;          
    int count;         

public:
    QueueTees() : front(0), rear(-1), count(0) {}

    void enqueue(Cutie& cutie) {
        if (count == 10) {
            cout << "Queue is full. Cannot add: " << cutie.description() << endl;
            return;
        }
        rear = (rear + 1) % 10;
        queue[rear] = &cutie;
        count++;
    }

    Cutie* dequeue() {
        if (count == 0) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return nullptr;
        }
        Cutie* dequeued = queue[front];
        front = (front + 1) % 10;
        count--;
        return dequeued;
    }

    int size() const {
        return count;
    }
};

int main() {
    
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    QueueTees queue;

    cout << "Queue size: " << queue.size() << endl;

    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    cout << "Queue size after enqueueing: " << queue.size() << endl;

    Cutie* cutie = queue.dequeue();
    if (cutie) {
        cout << "Dequeued: " << cutie->description() << endl;
    }

    cutie = queue.dequeue();
    if (cutie) {
        cout << "Dequeued: " << cutie->description() << endl;
    }

    cutie = queue.dequeue();
    if (cutie) {
        cout << "Dequeued: " << cutie->description() << endl;
    }

    
    queue.dequeue();

    return 0;
}