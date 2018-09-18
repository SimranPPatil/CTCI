/* Queue from two stacks */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
                 stack_newest_on_top.push(x);
        }

        void pop() {
            if(stack_oldest_on_top.empty()){
                while(!stack_newest_on_top.empty()){
                    int elem = stack_newest_on_top.top();
                    stack_newest_on_top.pop();
                    stack_oldest_on_top.push(elem);
                }
            }

             stack_oldest_on_top.pop();
        }

        int front() {
            int elem;
            if(stack_oldest_on_top.empty()){
                while(!stack_newest_on_top.empty()){
                    elem = stack_newest_on_top.top();
                    stack_newest_on_top.pop();
                    stack_oldest_on_top.push(elem);
                }
            }

            return stack_oldest_on_top.top();

        }
};

int main() {
    /* The input format is from hackerrank as follows:
      Then process  queries, where each query is one of the following  types:

      1 x: Enqueue element  into the end of the queue.
      2: Dequeue the element at the front of the queue.
      3: Print the element at the front of the queue.
    */
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }

    return 0;
}
