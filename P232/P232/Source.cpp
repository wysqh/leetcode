#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
	stack<int> inorder;
	stack<int> postorder;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		if (inorder.empty())
		{
			while (!postorder.empty())
			{
				int val = postorder.top();
				postorder.pop();
				inorder.push(val);
			}
		}
		inorder.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int val;
		if (postorder.empty())
		{
			while (!inorder.empty())
			{
				int val = inorder.top();
				inorder.pop();
				postorder.push(val);
			}
		}
		val = postorder.top();
		postorder.pop();
		return val;
    }
    
    /** Get the front element. */
    int peek() {
		if (postorder.empty())
		{
			while (!inorder.empty())
			{
				int val = inorder.top();
				inorder.pop();
				postorder.push(val);
			}
		}
		int	val = postorder.top();
		return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return inorder.empty() && postorder.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */