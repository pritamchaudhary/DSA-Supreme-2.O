// inline functions

#include <iostream>
using namespace std;

inline void numberShow(int num)
{
    cout << num << endl;
}

int main()
{
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);

    return 0;
}