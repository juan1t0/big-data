#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
using namespace std;

string phra="hello world";

int global_count =0;
int thread_count = 4;
pthread_mutex_t barrier_mutex;

void threadWork(int id){
    string temp =" ";
    while(temp.size()<5){
        char x = id;
        x+=65;
        temp+=x;
    }
    sort(temp.begin(),temp.end());

    pthread_mutex_lock(&barrier_mutex);
    global_count++;
    pthread_mutex_unlock(&barrier_mutex);
    while (global_count < thread_count){
        cout<<id<<" ";
    }

    phra+=temp;
  //  cout<<phra<<"--"<<endl;
}

int main(){

    thread uno(threadWork,1);
    thread dos(threadWork,2);
    thread tre(threadWork,3);
    thread qua(threadWork,4);
    uno.detach(); dos.detach();tre.detach();qua.detach();

    cout<<endl<<": "<<phra<<endl;

}