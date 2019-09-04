#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#define MAX 100

using namespace  std;
int main()
{
    srand(time(NULL));
    int a[MAX][MAX];
    for(int i=0;i<MAX;++i)
      for(int j=0;j<MAX;++j)
        a[i][j] = rand()%1000;
   
    int b[MAX][MAX];
    for(int i=0;i<MAX;++i)
      for(int j=0;j<MAX;++j)
        b[i][j] = rand()%1000;

    int c[MAX][MAX];
    for(int ci=0;ci<MAX;++ci){
        for(int cj=0;cj<MAX;++cj)
            c[ci][cj]=0;
    }
    int block = MAX/4;

    auto start = std::chrono::system_clock::now();
    
    for(int i0 = 0; i0<MAX; i0+=block)
        for (int j0 = 0;j0<MAX; j0+= block)
            for (int k0 = 0; k0<MAX;k0+=block)
                for (int i = i0; i < min(i0+block,MAX);++i)
                    for (int j = j0; j<min(j0+block,MAX);++j){
                        for(int k = k0; k< min(k0+block,MAX);++k)
                            c[i][j] += (a[i][k]) * (b[k][j]);
                    }
                            
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << duration.count() << "s " << std::endl;
    return 0;
}