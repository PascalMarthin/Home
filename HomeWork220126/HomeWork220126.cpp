#include <iostream>

class MyInt
{
public:
    int Value;

public:
    MyInt(int _Value)
        : Value(_Value)
    {

    }
    MyInt operator ++()
    {
        Value += 1;
        return *this;
    }
    MyInt operator ++(int _idx)
    {
        MyInt Idx(this->Value);
        this->Value += 1;
        return Idx;
    }
};

int main()
{
    int Value = 0;
    int Result = 0;

    Result = ++Value;
    Result = 0;
    Result = Value++;


    MyInt MyValue = 0;
    MyInt MyResult = 0;

    // ++ 쓰지마세요
    //MyResult = ++MyValue;
    //MyResult = 0;
    //MyResult = MyValue++;
}