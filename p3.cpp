#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
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

    auto start = std::chrono::system_clock::now();
    
    for(i0 = 1 to n step b)
        for (j0 = 1 to n step b)
            for (k0 = 1 to n step b)
                for (i = i0 to min())
                    for (j = j0 to min())
                        for(k = k0 to min())
                            c[i,j] = c[i,j] + a[i,k] * b[k,j] ;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << duration.count() << "s " << std::endl;
    return 0;

}