#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "future.h"

using namespace std;

struct RealData : public Future<string> {
public:
    virtual string call();
};

string RealData::call() {
    sleep(10);
    return "xiwen.yxw";
}

int main(void) {
    Future<string> *future = new RealData();
    future->assemble();
    
    cout<<"1"<<endl;
    sleep(2);
    cout<<"2"<<endl;
    sleep(2);
    cout<<"3"<<endl;
    sleep(2);
    cout<<"4"<<endl;

    cout<<future->getContent()<<endl;
}


