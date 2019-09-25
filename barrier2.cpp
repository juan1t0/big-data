#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
#include <semaphore.h>

using namespace std;

string phra="hello world";

int global_count =0;
int thread_count = 4;
sem_t count_sem;
sem_t barrier_sem ;

void threadWork(int id){
    string temp =" ";
    while(temp.size()<5){
        char x = id;
        x+=65;
        temp+=x;
    }
    sort(temp.begin(),temp.end());

    sem_wait(&count_sem);
    if(global_count == thread_count-1){
        global_count =0;
        cout<<id<<" : "<<global_count<<endl;
        sem_post(&count_sem);
        for(int j=0;j<thread_count-1;++j)
            sem_post(&barrier_sem);
    }else{
        global_count ++;
        cout<<id<<" : "<<global_count<<endl;
        sem_post(&count_sem);
        sem_wait(&barrier_sem);
    }

    phra+=temp;
}

int main(){
    sem_init(&count_sem,0,1);
    sem_init(&barrier_sem,0,0);

    thread uno(threadWork,1);
    thread dos(threadWork,2);
    thread tre(threadWork,3);
    thread qua(threadWork,4);
    uno.detach(); dos.detach();tre.detach();qua.detach();

    cout<<endl<<": "<<phra<<endl;

}