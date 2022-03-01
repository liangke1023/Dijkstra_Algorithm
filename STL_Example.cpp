//simple STL vector program
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(100); //allocate space

    **vector is a template and is a random access container - replace array in c++

    for(int i = 0; i<100;i++)
        v[i]=i; //index thru like an array
    for(vector<int>::iterator p=v.begin();
        p!=v.end();p++)
        cout<<*p<<'\t';
        cout<<endl;
}


**second for used iterators - note the declaration, and it is "safer" - off by 1 errors.
