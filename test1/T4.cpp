//
// Created by E0004387 on 2021/8/23.
//

#include <iostream>
#include <stdexcept>
#include "ctime"
#include "cstdlib"
#include "T4.h"
#include "string"
#include "vector"

const int MAX = 3;

using namespace std;

#define PI 3.1415926

int* getRandom(){
    static int r[10];
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }

    return r;
}

double getAverage(int* arr, int size){
    int i, sum = 0;
    double avg;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    avg = sum / size;
    return avg;
}

//get max data
template <typename T>
inline T const& Max(T const& a, T const& b){
    return a > b ? a : b;
}

//template test
template<class T>
class Stack {
private:
    vector<T> elems;
public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
        return elems.empty();
    }
};

template<class T>
void Stack<T>::push(const T& p) {
    elems.push_back(p);
}

template<class T>
void Stack<T> ::pop() {
    if (elems.empty()){
        throw out_of_range("stack empty");
    }
    elems.pop_back();
}

template<class T>
T Stack<T> ::top() const {
    if (elems.empty()){
        throw out_of_range("stack is empty");
    }

    return elems.back();
}

class CopyClassDemo{
public:
        int* ptr;

public:
        CopyClassDemo(int value);
        CopyClassDemo(const CopyClassDemo &obj);
        ~CopyClassDemo();
};

CopyClassDemo::CopyClassDemo(int value) {
    cout << "constructor is called" << endl;
    ptr = new int;
    *ptr = value;
}

CopyClassDemo::CopyClassDemo(const CopyClassDemo &obj) {
    cout << "CopyClassDemo is called" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

CopyClassDemo::~CopyClassDemo() {
    cout << "~ is called" << endl;
    delete ptr;
}

class Line
{
public:
    int getLength( void );
    Line( int len );             // 简单的构造函数
    Line( const Line &obj);      // 拷贝构造函数
    ~Line();                     // 析构函数

private:
    int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "call constructor" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "copy constructor ptr allocate memory" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    cout << "release" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line size : " << obj.getLength() <<endl;
}

int main(){

    int var[MAX] = {1, 2, 3};
    int* ptr = var;

    for (int i = 0; i < MAX; i++){
        cout << "pointer value:" << *ptr << endl;
        ptr++;
    }
    cout << "main is running" << endl;

    cout << "----------------------------" << endl;

    //return pointer
    int* p;
    p = getRandom();
    for (int i = 0; i < 10; ++i) {
        cout << "i:" << i << ", value:" << *(p + i) << endl;
    }

    cout << "---------------------------" << endl;

    int balance[5] = {10, 20, 16, 30, 40};
    double avg = getAverage(balance, 5);
    cout << "average data:" << avg << endl;

    cout << "---------------------" << endl;
    cout << max(23, 12) << endl;
    cout << "---------------------" << endl;

    Stack<int> intStack;
    Stack<string> stStack;
    intStack.push(5);
    cout << intStack.top() << endl;
    stStack.push("abcd");
    cout << stStack.top() << endl;
    stStack.pop();
    try{
        stStack.pop();
    }catch(exception const& exception){
        cout << exception.what() << endl;
//        return -1;
    }

    cout << "------------------" << endl;

    cout << PI << endl;

    cout << "-------------------" << endl;
    CopyClassDemo copyClassDemo(34);
    CopyClassDemo copyClassDemo1 = copyClassDemo;
    cout << "---------------------" << endl;

//    Line line1(10);
//
//    Line line2 = line1; // 这里也调用了拷贝构造函数
//
//    display(line1);
//    display(line2);

    //非0即为true
    return 0;
}
