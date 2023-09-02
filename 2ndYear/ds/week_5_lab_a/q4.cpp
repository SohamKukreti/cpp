#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
private:
int data[MAX_SIZE];
int top;
public:
Stack()
{
top = -1;
}
void push(int value)
{
if (top < MAX_SIZE - 1)
{
data[++top] = value;
}
}
int pop()
{
if (top >= 0)
{
return data[top--];
}
return -1;
}
bool isEmpty()
{
return top == -1;
}
};
void towerOfHanoi(int n, Stack &source, Stack &auxiliary, Stack &destination)
{
if (n == 1)
{
int disk = source.pop();
destination.push(disk);
cout << "Move disk " << disk << " from source to destination" << endl;
return;
}
towerOfHanoi(n - 1, source, destination, auxiliary);
int disk = source.pop();
destination.push(disk);
cout << "Move disk " << disk << " from source to destination" << endl;
towerOfHanoi(n - 1, auxiliary, source, destination);
}
int main()
{
int numDisks;
cout << "Enter the number of disks: ";
cin >> numDisks;
Stack source, auxiliary, destination;
for (int i = numDisks; i >= 1; i--)
{
source.push(i);
}
towerOfHanoi(numDisks, source, auxiliary, destination);
return 0;
}
