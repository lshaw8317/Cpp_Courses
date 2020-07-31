#pragma once
#include <list>
using namespace std;
//Funcs for PracProgs//

//BasicProg1
void get_area_perim()
{
    int l, w;
    cout << "Enter the length of the rectangle : " << endl;
    cin >> l;
    cout << "Enter the width of the rectangle : " << endl;
    cin >> w;
    cout << "The area of rectangle is (l x w) = " << l * w << endl;
    cout << "The perimeter of rectangle is 2(l + w) = " << 2 * (l + w) << endl;
}
//BasicProg2
void print_ASCII()
{
    char c;
    cout << "Enter a character : " << endl;
    cin >> c;
    cout << "ASCII values of character " << c << " is " << int(c) << endl;
}
//BasicProg3
void get_frac()
{
    double num;
    cout << "Enter a floating point number : " << endl;
    cin >> num;
    cout << "Fractional part of the number " << num << " is " << num-int(num) << endl;
}
//BasicProg4
void print_expans()
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "(" << a << "+" << b << ")^2\n= " << a << "^2 + 2*" << a << "*" << b << " + " << b << "^2\n= " << a * a
        << " + " << 2 * a * b << " + " << b * b << "\n= " << a * a + b * b + 2 * a * b << endl;
}
//////////////////////////////
//CondProg1
void swap()
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    int temp = a;
    a = b;
    b = temp;
    cout << "The modified values after swapping are :\na : " << a << "\nb : " << b << endl;
}
//CondProg2
void tablet_select()
{
    int num;
    cout << "Enter a number : " << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "You have chosen to buy an iPad!" << endl;
        break;
    case 2:
        cout << "You have chosen to buy a Nokia tablet!" << endl;
        break;
    case 3:
        cout << "You have chosen to buy a Samsung Tablet!" << endl;
        break;
    default:
        cout << "Ah!You seem to want an Aakash Tablet. Great choice!" << endl;
        break;
    }
}
//CondProg3
void right_angle_check()
{
    int a, b, c, res;
    cout << "Enter length for Side 1 : " << endl;
    cin >> a;
    cout << "Enter length for Side 2 : " << endl;
    cin >> b;
    cout << "Enter length for Side 3 : " << endl;
    cin >> c;

    if (a < b)
    {
        if (b < c) { res = a * a + b * b - c * c; }
        else { res = a * a + c * c - b * b; }
    }
    else
    {
        if (a<c){ res = a * a + b * b - c * c; }
        else{ res = -a * a + b * b + c * c; }
    }
    if (res == 0) { cout << "The given triangle is a right angled triangle." << endl; }
    else{ cout << "The given triangle is not a right angled triangle." << endl; }


}
//CondProg4
void leap_year()
{
    int year;
    cout << "Enter year :" << endl;
    cin >> year;
    if (year < 1000 || year > 9999)
    {
        cout << "Negative or non-4-digit years are invalid" << endl;
        return;
    }
    else
    {
        switch (year % 4)
        {
        case 0:
            cout << "The year entered is a leap year." << endl;
            break;
        default:
            cout << "The year entered is not a leap year." << endl;
            break;
        }
    }
}
//CondProg5
void check_vowel()
{
    char c;
    cout << "Enter a character : " << endl;
    cin >> c;
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
    {
        cout << "Printing 1 since it is a vowel." << endl;
    }
    else
    {
        cout << "Printing 0 since it is not a vowel." << endl;
    }

}
/////////////////////////////
//IterProg1
void print_rect()
{
    int l, h;
    cout << "Enter the length of the rectangle : " << endl;
    cin >> l;
    cout << "Enter the height of the rectangle : " << endl;
    cin >> h;
    for (int j = 1;j <= h;j++)
    {
        cout << '*';
        for (int i = 2;i < l;i++)
        {
            if (j == 1 || j == h) { cout << '*'; }
            else { cout << ' '; }
        }
        cout << '*' << endl;
    }
}
//IterProg2
void enter_nums()
{
    int n,numbers=0,maxnum1,maxnum2,num;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Enter " << n << " positive numbers :";
    do{
        cin >> num;
        if (numbers == 0) { maxnum2 = num; maxnum1 = num; }
        else if (num > maxnum1) { maxnum2 = maxnum1; maxnum1 = num; }
        else if (num > maxnum2) { maxnum2 = num; }
        numbers++;
    } while (numbers < n);

    cout << "From the " << n << " given numbers, the second highest number is : " << maxnum2 << endl;
}
//IterProg3
void print_pattern()
{
    for (int i = 1;i < 8;i += 2)
    {
        for (int j = 1;j <= (7 - i) / 2;j++)
        {
            cout << " ";
        }
        for (int k = 1;k <= i;k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
//IterProg4
void palind()
{
    int num,rem;
    cout << "Enter a number :" << endl;
    cin >> num;
    int newnum = num;
    int palind = 0;
    int n = 1;
    while (newnum!=0)
    {
        rem = newnum % 10; //Get next digit times n
        newnum -= rem; //update newnum with zeros to right of (i+1)th digit
        newnum /= 10;
        n *= 10;
    }
    //final rem is largest digit of num, times final n
    n /= 10;
    newnum = num;
    for(int i=1;i<=n;i*=10) //Increment i
    {
        rem = newnum % 10; //Get next digit
        newnum -= rem; //update newnum with zeros to right of (i+1)th digit
        newnum /= 10;
        rem *= (n/i); 
        palind += rem;
    }

    if (palind == num) { cout << "The number entered is a palindrome." << endl; }
    else { cout << "Reversed number is: "<<palind<<". The number entered is not a palindrome." << endl; }
}
//IterProg5
//FuncProg4
bool check_prime(int m)
{
    bool out = true;
    for (int k = 2;k <= m / 2;k++)
    {
        if (m % k == 0) { out = false; break; }
    }
    return out;
}
void print_primes()
{
    int num, n = 1;
    int prime=1;
    cout << "Enter a number :" << endl;
    cin >> num;
    cout << "First "<<num<<" prime numbers are :" << endl;
    while (n <= num)
    {
        for (int i = prime+1;;i++)
        {
            if (check_prime(i)) { prime = i; cout << prime << endl; break; }
        }
        n++;
    }
}
//IterProg6A
void C_to_Fa()
{
    cout << "\nCentigrade   Fahrenheit" << endl;
    for (int c = 10;c <= 30;c++)
    {
        double f = 32 + 9 * c / 5.0;
        cout << "    " << c << "          " << f << endl;
    }
}
//IterProg6B
void C_to_Fb()
{
    cout << "\nCentigrade   Fahrenheit" << endl;
    int c = 10;
    while (c <= 30)
    {
        double f = 32 + 9 * (c / 5.0);
        cout << "    " << c << "          " << f << endl;
        c++;
    }
}
//IterProg7
void reverse()
{
    int num, reversed=0;
    cout << "Enter a number :" << endl;
    cin >> num;
    int n = num;
    while (n!=0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    cout << "The reverse of " << num << " is " << reversed << endl;
}
//IterProg8
void print_seq()
{
    //Declaring initial variables
    int a, d, n;
    //Input the variables
    cout << "Enter a: "; cin >> a;
    cout << "Enter d: "; cin >> d;
    cout << "Enter n: "; cin >> n;

    cout << "Substituting value of 'a', 'd', and 'n' in the sequence {a, a+d, a+2d, ..., a+nd}" << endl;
    cout << "= {" << a << ", " << a << " + " << d << ", ";
    for (int i = 2;i <= n;i++)
    {
        cout << a << " + " << i << "*" << d<<", ";
    }
    cout << "}" << endl;

    cout << "= {";
    for (int i = 0;i < n;i++)
    {
        cout << a + i*d << ", ";
    }
    cout << a + n * d << "}" << endl;
}
//////////////////////////
//FuncProg1
int fact(int n)
{
    if (n==0|| n == 1) { return 1; }
    else {return n*fact(n - 1);}
}
//FuncProg2
int nCr(int n, int r)
{
    if (r > n||r<0) { cout << "r must be less than or equal to n and non-negative"; return 0; }
    else { return fact(n) / (fact(r) * fact(n - r)); }
}
//FuncProg3
bool check_perfect(int num)
{
    int sum = 1;
    bool out = false;
    for (int k = 2;k <= num / 2;k++)
    {
        if (num % k == 0) { sum +=k; }
    }
    if (sum == num) { out = true; }
    return out;

}
/////////////////////////
//PPA05//
//Func1
int comparator(float marksarray[][2], int index1, int index2)
{
    double rms1, rms2;
    double msem1 = marksarray[index1][0], esem1 = marksarray[index1][1];
    double msem2 = marksarray[index2][0], esem2 = marksarray[index2][1];

    rms1 = 0.5 * sqrt(msem1 * msem1 + esem1 * esem1);
    rms2 = 0.5 * sqrt(msem2 * msem2 + esem2 * esem2);

    if (rms1 > rms2) { return -1; }
    else if (rms2 > rms1) { return 1; }
    else
    {
        if (esem1 > esem2) { return -1; }
        else if (esem2 > esem1) { return 1; }
        else { return 0; }
    }
}
//Func2
int selectionSort2(float array[][2], int numElements)
{
    int break_point = numElements - 1;
    for (int i = numElements - 1;i>0;i--)
    {
        if (comparator(array, i, i - 1) != 1) { break_point = i; break; }
    }
    int currIndex = 0;

    while (currIndex < break_point)
    {
        for (int j = currIndex; j < break_point;j++)
        {
            if (comparator(array, currIndex, j) == -1)
            {
                float temp1 = array[currIndex][0];
                float temp2 = array[currIndex][1];
                array[currIndex][0] = array[j][0]; //update minimums
                array[currIndex][1] = array[j][1];
                array[j][0] = temp1;
                array[j][1] = temp2;
            }
        }
        currIndex++;
    }
    return break_point;
}
//Func3
int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements)
{
    for (int i = 0;i < break_point;i++)
    {
        for (int j = break_point; j < numElements;j++)
        {
            if (comparator(sortedarray,i,j)==0)
            {
                numElements--;
                break_point--;
                for (int m = i;m < numElements;m++)
                {
                    sortedarray[m][0] = sortedarray[m+1][0];
                    sortedarray[m][1] = sortedarray[m+1][1];
                }
                numElements--;
                for (int n = j-1 ; n < numElements; n++)
                {
                    sortedarray[n][0] = sortedarray[n + 1][0];
                    sortedarray[n][1] = sortedarray[n + 1][1];
                }
                i--;
                break;
            }
        }
    }
    int index = 0;
    for (int i = 0, j = numElements-1;((i < break_point) || (j >= break_point));)
    {
        if ((i < break_point) && (j >= break_point))
        { // None of the two subarrays fully seen yet
            if (comparator(sortedarray,i,j) == -1) 
            { 
                mergedarray[index][0] = sortedarray[j][0];
                mergedarray[index][1] = sortedarray[j][1];
                j--; 
            }
            else 
            {
                mergedarray[index][0] = sortedarray[i][0];
                mergedarray[index][1] = sortedarray[i][1];
                i++; 
            }
        }
        else {
            if (i < break_point)
            {
                mergedarray[index][0] = sortedarray[i][0];
                mergedarray[index][1] = sortedarray[i][1];
                i++;
            } // A[mid] … A[end-1] seen
            else 
            {
                mergedarray[index][0] = sortedarray[j][0];
                mergedarray[index][1] = sortedarray[j][1];
                j--;
            } // A[start] … A[mid-1] seen
        }
        index++;
    }
    return numElements;

}
/////////////////////////
//PPA06//
//Func1
int* getArray1D(int n)
{
    int* A;
    A=new int [n];
    for (int i = 0;i < n;i++)
    {
        A[i] = 1;
    }

    if (A != NULL) { return A; }
    else
    {
        cout << "'new' failed, will not return valid pointer'" << endl;
        return A;
    }
}
int** getArray2D(int m, int n, int** Aptr)
{
    for (int j = 0;j < m;j++)
    {
        Aptr[j] = getArray1D(n);
    }
    return Aptr;
}
////////////////////////
//PPA07//
struct LinkedNodes {
    int nodeId;
    LinkedNodes* next;
};
struct myNode {
    int id;
    LinkedNodes* outgoing;
    LinkedNodes* incoming;
};
void initNodes(myNode* nodes, int numNodes)
{
    if (nodes != NULL)
    {
        for (int i = 0;i < numNodes;i++)
        {
            nodes[i].id = i+1;
            nodes[i].outgoing = NULL;
            nodes[i].incoming = NULL;
        }
    }
    else { cout << "Memory allocation failed in function initNodes." << endl; }
}
void addEdge(myNode* nodes, int start, int end)
{
    LinkedNodes* endNode;
    endNode = new LinkedNodes;
    LinkedNodes* startNode;
    startNode = new LinkedNodes;
    if (startNode != NULL && endNode != NULL)
    {
        endNode->nodeId = end;
        if (nodes[start-1].outgoing == NULL) { nodes[start-1].outgoing = endNode; endNode->next = NULL; }
        else { endNode->next = nodes[start-1].outgoing; nodes[start-1].outgoing = endNode; }
        startNode->nodeId = start;
        if (nodes[end-1].incoming == NULL) { nodes[end-1].incoming = startNode; startNode->next = NULL; }
        else { startNode->next = nodes[end-1].incoming; nodes[end-1].incoming = startNode; }
    }
    else { cout << "Memory allocation failure in function addEdge." << endl; }
}
void getOutgoingNodes(myNode* nodes, int i, int* nodesArray, int& num)
{
    if (nodes[i-1].outgoing == NULL) { nodesArray[0] = NULL; num = 0; }
    else
    {
        int edges = 0;
        LinkedNodes* currPtr = nodes[i-1].outgoing;
        while (currPtr != NULL)
        {
            nodesArray[edges] = (currPtr)->nodeId;
            edges++; //Next loop
            currPtr = (currPtr)->next; //Next loop
        }
        num = edges;
    }
}
void getIncomingNodes(myNode* nodes, int i, int* nodesArray, int& num)
{
    if (nodes[i-1].incoming == NULL) { nodesArray[0] = NULL; num = 0; }
    else
    {
        int edges = 0;
        LinkedNodes* currPtr = nodes[i - 1].incoming;
        while (currPtr != NULL)
        {
            nodesArray[edges] = (currPtr)->nodeId;
            edges++; //Next loop
            currPtr = (currPtr)->next; //Next loop
        }
        num = edges;
    }
}

