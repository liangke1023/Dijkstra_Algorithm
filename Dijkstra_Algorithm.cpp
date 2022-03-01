#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

#define INF 0x7fffffff
#define maxN 50
#pragma warning(disable:4996)

#define USE_C 1
#define NOT_USE_C 0

#define USE_CPP 1

int matrix[maxN][maxN];
void Dijkstra_cpp(vector<vector<int>>&vec, vector<int>& result, int v0){
    vector<int> visitied(vec.size(),0); //0: vertice is not choosed, 1: vertice is choosed
    int last_visited = 0;
    visitied[v0]=1; //vertice is choosed
    result[0]=0;

    for(int i=0; i<vec.size()-1; ++i){ //N vertices and N-1 loops
        //vertices around search
        for(int j=0;j<vec.size();j++){//go through all vertices 
            if(visited[j]==0){ //new vertice is not visited
                if(vec[v0][j]!=0){ //current vertice(V0) has edage with new vertice(j)
                    int dist = vec[v0][j] + last_visited; //distance between V0 and J
                    if(dist<result[j])result[j]=dist; //replace old edage with new edege
                }
            }
        }

        //find the min distance
        int minIndex = 0;
        while(visited[minIndex]==1)minIndex++; //find the first not choosed vertice
        for(int j=minIndex; j<vec.size();j++){
            if(visited[j]==0 && result[j] < result[minIndex]){
                minIndex = j;
            }
        }

        last_visited = result[minIndex]; //update the min
        visited[minIndex]=1; //choose the min vertice
        v0 = minIndex; //next time start from min
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
    freopen("Dijkstra2Data.txt","r",stdin);
    int result[maxN];
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;N++){
        for(j=0;j<N;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    Dijkstra_c(result,N,0);

    for(i=0;i<N;i++){
        if(result[i]==INF)printf("INF\n");
        else printf("%d",result[i]);
    }
#endif

    freopen("Dijkstra2Data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    vector<vector<int>> vec(n,vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> vec[i][j];
        }
    }

    vector<int> result(n,INF); 
    Dijkstra_cpp(vec,result,0);

    for(int i = 0; i<n; i++){
        if(result[i]==INF)printf("INF\n");
        else printf("%d\n", result[i]);
    }

return 0;
}