#include <iostream>
using namespace std;
class secoundclass
{
    int x;
};
class practice
{
    secoundclass *temp;
    public:
    practice(secoundclass *te)
    {
        temp = te;
    }
};
int main()
{
    secoundclass *x1 = new secoundclass;
    practice x2(x1);

    return 0;
}