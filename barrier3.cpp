#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
#include <semaphore.h>

using namespace std;

string phra="hello world";

int global_count =0;
int thread_count = 4;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

void threadWork(int id){
    string temp =" ";
    while(temp.size()<5){
        char x = id;
        x+=65;
        temp+=x;
    }
    sort(temp.begin(),temp.end());

    pthread_mutex_lock(&mutex);
    global_count++;
    cout<<id<<" : "<<global_count<<endl;
    if(global_count == thread_count){
        global_count = 0;
        pthread_cond_broadcast(&cond_var);
    }else{
        while(pthread_cond_wait(&cond_var,&mutex)!=0);
    }
    pthread_mutex_unlock(&mutex);

    phra+=temp;
}

int main(){

    thread uno(threadWork,1);
    thread dos(threadWork,2);
    thread tre(threadWork,3);
    thread qua(threadWork,4);
    uno.detach(); dos.detach();tre.detach();qua.detach();

    cout<<endl<<": "<<phra<<endl;

}