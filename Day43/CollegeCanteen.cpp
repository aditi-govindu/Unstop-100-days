#include<bits/stdc++.h>
using namespace std;

/*
Description: The College Canteen offers triangular and rectangular-shaped sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers triangular or rectangular sandwiches.

The number of sandwiches in the canteen is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.

Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue).

You have to tell the number of students that are unable to eat lunch.
*/

int countStudents(vector<int>& students, vector<int>& sandwiches) 
{
    int cnt0 = 0; //for storing the number of students who like sandwiches of 0 type
    for(auto it : students)
    {
        if(it == 0)
            cnt0++;
    }
    int cnt1 = students.size() - cnt0; //for storing the number of students who like sandwiches of 1 type
    for(int i=0; i<sandwiches.size(); i++) //traversing in the sandwiches stack
    {
        if(sandwiches[i]) //if the current sandwich is 1 
        {
            if(cnt1) cnt1--; //if we have a student available we decrement total cnt
            else break;
        }
        else
        {
            if(cnt0) cnt0--; //if we have a students available we decrement total cnt
            else break; 
        }
    }
    return (cnt0 + cnt1); //overall count left is returned
}


int main()
{
    int n;
    cin>>n;
    vector<int> students(n), sandwiches(n);
    for(int i=0; i<n; i++)
        cin>>students[i];
    for(int i=0; i<n; i++)
        cin>>sandwiches[i];
    cout<<countStudents(students, sandwiches)<<endl;
    return 0;
}