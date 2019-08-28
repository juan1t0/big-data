#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>

#define MAX 1000

using namespace std;
unsigned t0, t1;
int main()
{
    srand(0);
    int a[MAX][MAX];
    for(int i=0;i<MAX;++i)
    for(int j=0;j<MAX;++j)
        a[i][j] = rand()%1000;
    int x[MAX]; 
    for(int i=0;i<MAX;++i)
        x[i] = rand()%1000;
    int y[MAX];
    for(int i=0;i<MAX;++i)
        y[i] = 0;

    auto start = std::chrono::system_clock::now();
    for(int i =0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            y[i]+= a[i][j]*x[j];
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << duration.count() << "s " << std::endl;
    
    for(int i=0;i<MAX;++i)
        y[i] = 0;

    auto start2 = std::chrono::system_clock::now();
    for(int j =0;j<MAX;j++)
        for(int i=0;i<MAX;i++)
            y[i]+= a[i][j]*x[j];
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration2 = end2 - start2;
    std::cout << duration2.count() << "s " << std::endl;

    return 0;
}