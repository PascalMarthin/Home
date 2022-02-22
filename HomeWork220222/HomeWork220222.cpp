// Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "GameVector.h"

GameVector<int> ReturnVector()
{
    GameVector<int> NewArr;

    NewArr.resize(20);

    return NewArr;
}

int main()
{
    ////std::list<int> NewList;
    ////NewList.remove(1);

    //// vector는
    //// 시퀀스 배열 자료구조

    //// 자료를 넣는 함수
    //// 자료를 접근하는 함수
    //// 자료를 삭제하는 함수

    //// [3][2][1][10][20]

    //// 이때 내부에서
    //// 동적 배열을 만들어냅니다.
    //std::vector<int> Vector;

    //for (size_t i = 0; i < 20; i++)
    //{
    //    Vector.push_back(i);
    //    std::cout << "Capa" << Vector.capacity() << std::endl;
    //    std::cout << "Size" << Vector.size() << std::endl;
    //    std::cout << "-----------------------------------" << std::endl;
    //}

    //for (size_t i = 0; i < 20; i++)
    //{
    //    std::cout << Vector[i] << std::endl;
    //}

    //
    //Vector.push_back(2); 
    //Vector.push_back(1); 
    //Vector.push_back(10);
    //Vector.push_back(20);


    //// [][][][][]
    //// vector 

    //std::cout << Vector[2] << std::endl;

    {
        GameVectorSort<int> MyVector = GameVectorSort<int>();


        MyVector.push_back(5);
        MyVector.push_back(10);
        MyVector.push_back(5);
        MyVector.push_back(1);
        MyVector.push_back(2);
        MyVector.push_back(8);
        MyVector.push_back(99);
        for (size_t i = 0; i < MyVector.size(); i++)
        {
            std::cout << MyVector[i] << std::endl;
        } // 테스트

    }

    //{
    //    std::vector<int> Arr;
    //    Arr.resize(20);

    //    // Arr.reserve(20);

    //    GameVector<int> MyVector;
    //    MyVector.resize(20);
    //    MyVector.reserve(20);


    //    // unsigned __int64
    //    for (size_t i = 0; i < 40; i++)
    //    {
    //        MyVector.push_back((int)i);
    //        std::cout << "Capa" << MyVector.capacity() << std::endl;
    //        std::cout << "Size" << MyVector.size() << std::endl;
    //        std::cout << "-----------------------------------" << std::endl;
    //    }


    //    for (size_t i = 0; i < 40; i++)
    //    {
    //        std::cout << MyVector[i] << std::endl;
    //    }
    //}

}
