//
// Created by E0004387 on 2021/8/10.
//

#include "string"
#include "cstring"

using namespace std;

#ifndef DEMO1_T13_H
#define DEMO1_T13_H


class T13 {

    //访问修饰符
private:
    int age;
    string firstName;
    char* lastName;

public:
    //构造函数
    T13(int, string, char* lastName = "like");
    int getAge();
    void setAge(int);

    void setFirstName(string);
    string getFirstName();

    void setLastName(char *);
    char* getLastName();

    //析构函数
    ~T13();

    static int value;
    static void addValue();
    static int getValue();
};

class Father{
private:
    int gain;
public:
    float back;
};

class Child1 : public Father{

};

class Child2 : public Father{
public:
    virtual void virtualFunc();
    virtual void pureVirtualFunc() = 0;
};

//1.Allow multiply inherit,
//2.default is privately inherit, can not access parent's properties,
class Child1_Child1 : public Child1, public Child2{

public:
    void accessGain();
    void accessBack();
    void pureVirtualFunc();
};



#endif //DEMO1_T13_H
