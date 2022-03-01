//simple STL vector program
#include<iostream>
#include<vector>
int main()
{
    int how_many;
    std::cout<<"how many ints in data?: " <<endl;
    std::cin>>how_many;
    std::vector<int> data(how_many);
    std::cout<<"The contents of data:";
    for(std::vector<int>::iterator it=data.begin(); it!= data.end();it++)
        std::cin>>*it;
}

//construct a container with how_many elements
//fill it from std::in