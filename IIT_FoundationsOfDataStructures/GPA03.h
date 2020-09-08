#pragma once
class twoStacks
{
	int* arr;// array has only non negative elements.
	int size;
	int top1;
	/* top1 is index of the topmost element of stack1 and is -1 if stack1 is empty  */
	int top2;
	/* top2 is index of the topmost element of stack2 and is equal to size if stack2 is empty */
public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1; // note this initialization
		top2 = size;// note this initialization
	}
	//push i onto stack 1: |x|x|x| |...| |o|o|o| -> |x|x|x|i|...| |o|o|o|
	bool push1(int i) {
		top1++;
		if (top1 == top2) { top1--;return false; }
		else { arr[top1] = i; return true; };
	};
	//push i onto stack 2: |x|x|x| |...| |o|o|o| -> |x|x|x| |...|i|o|o|o|
	bool push2(int i) {
		top2--;
		if (top1 == top2) { top2++;return false; }
		else { arr[top2] = i;return true; };
	};
	// pop top element from stack 1: |x|x|x|i|...| |o|o|o| -> |x|x|x| |...| |o|o|o|
	int pop1() {
		if (top1 != -1) { top1--;return arr[top1 + 1]; }
		else { return -1; };
	};
	// pop top element from stack 2: |x|x|x| |...|i|o|o|o| -> |x|x|x| |...| |o|o|o|
	int pop2() {
		if (top2 != size) { top2++;return arr[top2 - 1]; }
		else { return -1; };
	};
	// resize the arr to double its current size
	void double_resize() {
		int* arr_=new int[2 * size];

		for (int j = 0;j <= top1;j++) {
			arr_[j] = arr[j];
		}
		for (int j = top2;j < size;j++) {
			arr_[j+size] = arr[j];
		}
		top2 += size;
		size *= 2;
		delete arr;
		arr = arr_;
	};
	void reset_top2() {
		top2 = size;
	}
};