#include<bits/stdc++.h>
using namespace std;

/*
Description: You have to design a stack which supports some additional functions.

Implement the given Derived Stack class:

DerivedStack(int capacity) :-Initialize the object with capacity which is the maximum number of elements possible in stack or do nothing if the stack reaches the capacity.
void push(int x) :-this is the same as the normal stack. Add the element at the top of the stack if it doesn’t reach its capacity.
int pop() :- This function is also the same as the normal stack .Pop and return top of the element or -1 if stack is empty.
void increment(int k,int inc):- This is an additional function. It increments the bottom k elements of stack by inc. If there are less than k elements there ,then increment all the elements.
*/

class DerivedStack
{
    int cap;
    vector<int> st;
    public:
    
    // Set capacity of stack
    DerivedStack(int capacity)
    {
     cap=capacity;   
    }

    // Add item to stack
    void push(int x)
    {
        if(st.size()<cap)
            st.push_back(x);
    }

    // Remove item from stack
    int pop()
    {
        // Cannot remove from empty stack
        if(st.size()==0)
            return -1;
        else
        {
            int res=st.back();
            st.pop_back();
            return res;
        }
    }

    // Add constant to stack items
    void increment(int k,int inc)
    {
        int x = k;
        
        // If stack has less than k elements, increment all items
        if(st.size() < k)
            x = st.size();
        for(int i = 0; i < x; i++)
            st[i]+=inc;
    }
};

int main()
{
    int cap;
    cin >> cap;
    DerivedStack *obj = new DerivedStack(cap);
    cout << "null" << " ";
    int noq;
    cin >> noq;

    while(noq--)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
            int val;
            cin>>val;
            obj->push(val);
            cout<<"null ";
        }
        else if(s=="pop")
        {
            int ans=obj->pop();
            cout<<ans<<" ";
        }
        else 
        {
            int k,inc;
            cin>>k>>inc;
            obj->increment(k,inc);
            cout<<"null ";
        }
    }
    return 0;
}