#include "Queue_usingStacks.h"
using namespace std;

int main() {
    Queue a;
    
    a.enqueue(5);
    a.enqueue(10);
    cout << a.getSize()<< endl;
    cout << a.deque();
    return 0;
}