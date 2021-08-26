//
// Created by E0004387 on 2021/8/10.
//

#include <iostream>
#include "T13.h"

int T13::getAge() {
    return this->age;
}

void T13::setAge(int source) {
    this->age = source;
}

void T13::setFirstName(string source) {
    this->firstName = source;
}

string T13::getFirstName() {
    return this->firstName;
}

void T13::setLastName(char * source) {
    this->lastName = source;
}

char * T13::getLastName() {
    return this->lastName;
}

//static properties
int T13::value = 23;

int T13::getValue() {
    return T13::value;
}

void T13::addValue() {
    T13::value++;
}

//带参默认赋值构造函数
T13::T13(int src1, string src2, char * src3) : age(src1), firstName(src2), lastName(src3) {

}

T13::~T13() {

}

//define father's virtual function
void Child2::virtualFunc() {
    cout << "virtual Func is running" << endl;
}

//define child's pure virtual function
void Child1_Child1::pureVirtualFunc() {
    cout << "pure virtual func is called" << endl;
}

//inherit
void Child1_Child1::accessBack() {
    cout << "parent's value:" << ::Child1::back << endl;
}

void Child1_Child1::accessGain() {
    //can't access properties with privately modify
}




typedef struct Chair{
    int color;
    int years;
    char material[20];
    char owner[20]; //为什么是指针的话，就输出不出来？
} Chair;

int main(){
    T13 t13(12, "ac");

    //test info
    cout << "age:" << t13.getAge() << ", firstName:" << t13.getFirstName() + ", lastName:" << t13.getLastName() << endl;

    cout << "---------------" << endl;
    cout << "static properties" << endl;
    cout << "value:" << T13::value << ", getValue:" << T13::getValue() << endl;

    //指针常量和常量指针
    cout << "---------------" << endl;
    const char b = 'Z';
    const char * b1 = &b;
    char const * b2 = &b;
//    *b1 = 'X';//compile error, Read-only variable is not assignable, reason : can't reassign value
    char c = 'q';
    char * const c1 = &c;
    char c2 = 'c';
//    c1 = &c2;//Compile error, Cannot assign to variable 'c1' with const-qualified type 'char *const' variable 'c1' declared const here

    cout << "-------------------" << endl;
    cout << "array's access" << endl;
    float fl1[] = {1, 2, 3, 4, 5};
    float * fl2 = fl1;
    for (int i = 0; i < sizeof(fl1) / sizeof(float); ++i, fl2++) {
        cout << "index:" << i << ", access1, " << fl1[i] << ", access2, " << *fl2 << "; ";
    }
    cout << endl;

    cout << "-----------------" << endl;

    cout << "struct start" << endl;
    Chair chair;
    chair.color = 345;
    chair.years = 20;
    strcpy(chair.material, "mood");
    strcpy(chair.owner, "Doger");
    printf(chair.owner);
    cout << "owner : " << chair.owner << ", material: " << chair.material << ", color: " << chair.color << endl;
    cout << "-----------------------" << endl;

    char const * testCase1 = "dsadwq";
    cout << "testCase1:" << testCase1 << endl;
    testCase1 = "dsad";
    cout << "testCase1:" << testCase1 << endl;

    cout << "--------------------" <<endl;
    cout << "virtual function test" << endl;
    //call test
    Child1_Child1 child1Child1;
    child1Child1.pureVirtualFunc();
    child1Child1.virtualFunc();
    cout << "---------------------" << endl;

}