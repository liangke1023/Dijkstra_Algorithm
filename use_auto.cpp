//simple STL vector program
#include<iostream>
#include<vector>
int main()
{
    int how_many;
    std::cout<<"The contents of data?: ";
    for(auto it=data.begin();it!=data.end();it++)
        std::cin>>*it;
}

//auto lets the compiler infer that it is an iterator type

#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>
int main()
{
    ifstream data_file("data.txt");  //text file containing data
    istream_iterator<int> start(data_file),end;
    vector<int> data(start,end);

    int sum = 0;
    for(auto it = start; it!=end; it++)
        sum += *it;
    cout<<"sum = "<<sum<<endl;
    cout<<"average is = "<<1.0 * sum/data.size() <<endl;
}