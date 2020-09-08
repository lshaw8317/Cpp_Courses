// GPA04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Node {
public:
    Node* next;
    Node* prev;
    int value;
};

class Stack {
    Node* top;
    Node* mid;
    int size;
public:
    //Constructor
    Stack() {
        top = NULL;mid = NULL;
        size = 0;
    };
    //push
    void push(int i) {
        Node* n = new Node; //use new so n survives function call
        if (top != NULL) { top->next = n; }
        n->value = i;
        n->prev = top;
        n->next = NULL;
        top = n;
        if (size == 0) { mid = n; }//initialise mid on first push
        if (size%2==0 and size!=0) { mid = mid->next; } //advance if push onto even stack and not first push
         //else stay still if push onto odd stack
        size++;
    }
    //pop
    int pop() {
        if (size != 0) {
            size--;
            int val = top->value;
            if (size != 0) {
                top = top->prev;
                delete top->next; //since used new have to de-allocate
                //Move mid down one if popping makes an even stack
                if (size % 2 == 0) { mid = mid->prev; } //else do nothing
                top->next = NULL;
            }
            //popping off single element stack
            else{top = mid = NULL;}
            return val;
        }
        else { return -1; }
    }
    //get middle value
    int findMiddle() { if (size != 0) { return mid->value; } }
    //remove middle value - still have to sort
    int deleteMiddle() {
        if (size != 0) {
            int val = mid->value;
            mid->next->prev = mid->prev; //cut out mid from top
            mid->prev->next = mid->next; //cut out mid from bottom
            if (size % 2 == 0) { mid = mid->next;} //if deleting from even stack, move mid up
            else { mid = mid->prev;} //else move mid down
            size--;
            return val;
        }
    }
};

int main()
{
    Stack s = Stack();
    s.push(11);
    s.push(12);
    s.push(14);
    s.push(18);
    std::cout<<s.findMiddle();
    std::cout << s.pop();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
