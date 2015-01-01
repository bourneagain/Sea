#include <iostream>
#include <stack>
using namespace std;

class Queue{
private:
    stack<int> stack1;
    stack<int> stack2;
    int data;
public:
    int deque();
    bool enqueue(int newData);
    int getSize();
    int size;
    
    
};

int Queue::deque(){
    int data;
    if ( !stack2.empty() )	{
    } else {
        while(!stack1.empty()){
            data=stack1.top();
            stack2.push(data);
            stack1.pop();
        }
    }
    data=stack2.top();
    stack2.pop();
    return data;
}

bool Queue::enqueue(int newData ){
    try {
        stack1.push(newData);
    }
    catch(...){
        cout << endl << "ER";
        return false;
    }
    return true;
}

int Queue::getSize(){
    return stack1.size() + stack2.size();
}
