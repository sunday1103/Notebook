class Solution {
 public:
  void push(int node) {
    if (stack1.empty()) {
      stack1.push(node);
      return;
    }

    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }

    stack1.push(node);

    while (!stack2.empty()) {
      stack1.push(stack2.top());
      stack2.pop();
    }

    return;
  }

  int pop() {
    int a = stack1.top();
    stack1.pop();
    return a;
  }

 private:
  stack<int> stack1;
  stack<int> stack2;
};