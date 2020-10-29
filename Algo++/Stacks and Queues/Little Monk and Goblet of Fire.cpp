/*
https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/little-monk-and-goblet-of-fire/

Albus Dumbledore announced that the school will host the legendary event known as Wizard Tournament where four magical schools are going to compete 
against each other in a very deadly competition by facing some dangerous challenges. Since the team selection is very critical in this deadly competition.
Albus Dumbledore asked Little Monk to help him in the team selection process. There is a long queue of students from all the four magical schools.
Each student of a school have a different roll number. Whenever a new student will come, he will search for his schoolmate from the end of the queue.
As soon as he will find any of the schoolmate in the queue, he will stand behind him, otherwise he will stand at the end of the queue. 
At any moment Little Monk will ask the student, who is standing in front of the queue, to come and put his name in the Goblet of Fire and remove him 
from the queue. There are Q operations of one of the following types:

E x y : A new student of school x (1<=x<=4) whose roll number is y (1<=y<=50000) will stand in queue according to the method mentioned above.

D: Little Monk will ask the student, who is standing in front of the queue, to come and put his name in the Goblet of Fire and remove him from the queue


Now Albus Dumbledore asked Little Monk to tell him the order in which student put their name. 
Little Monk is too lazy to that so he asked you to write a program to print required order.

Note: Number of dequeue operations will never be greater than enqueue operations at any point of time.

Input Format:
First line contains an integer Q 
(1<=Q<=100000), denoting the number of operations. Next Q lines will contains one of the 2 types of operations.

Output Format:
For each 2nd type of operation, print two space separated integers, the front student's school and roll number.

SAMPLE INPUT 
5
E 1 1
E 2 1
E 1 2
D
D
SAMPLE OUTPUT 
1 1
1 2
Explanation
After first operation, student of 
1st school with roll number 1, will stand in the front of the queue as the queue is empty initially.

In the image the student is represented by 
(x,y), which means that student is in x school and his roll number is y, and rightmost cell is the front of the queue.

After second operation, student of 
2nd school with roll number 1, will stand behind the first student as there is no other member of the same in the queue.
 
After third operation, student of 
1st school with roll number 2, will stand behind the member of his school in the queue.
 
After fourth operation, the student in the front will put his name in the Goblet of Fire and move out of the queue.
 
After fifth operation, the student in the front will put his name in the Goblet of Fire and move out of the queue.
*/
#include <iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    queue<int> q[5], queueOfSchools;
    int n, temp, a, b;
    char c;
    cin >> n;

    while (n--)  {
        cin >> c;

        if (c == 'E')  {
            cin >> a >> b;

            if (q[a].empty())
                queueOfSchools.push (a);

            q[a].push (b);
        }
        else  {
            temp = queueOfSchools.front();
            cout << temp << " " << q[temp].front() << "\n";
            q[temp].pop();

            if (q[temp].empty() )
                queueOfSchools.pop();
        }
    }

    return 0;
}

