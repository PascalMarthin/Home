#include <iostream>

int CountLen(const char* _String) // Char 크기 계산
{
    int Len = 0;
    for (int i = 0; _String[i] != 0; i += 1)
    {
        Len += 1;
    }
    return Len;
}

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int _FindStrLen = CountLen(_FindStr);
    bool find = false;
    for (int i = _Start; _Text[i] != 0; i += 1)
    {
        find = true;
        for (int j = i, k = 0; k != _FindStrLen && find != false; j += 1, k += 1)
        {
            if (_Text[j] != _FindStr[k])
            {
                find = false;
            }
        }
        if (find == true)
        {
            return i;
        }
    }
    return -1;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int _FindStrLen = CountLen(_FindStr);
    bool find = false;
    for (int i = _End - _FindStrLen; i >= 0; i -= 1)
    {
        find = true;
        for (int j = i, k = 0; k != _FindStrLen && find != false; j += 1, k += 1)
        {
            if (_Text[j] != _FindStr[k])
            {
                find = false;
            }
        }
        if (find == true)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    // 실패
    {
        int Count = CountFirst("aaa eee ttt asdfasd eee", 15, "eee");
    }
    {
        int Count = CountLast("aaa eee asdfasd eee", 15, "eee");
    }

}