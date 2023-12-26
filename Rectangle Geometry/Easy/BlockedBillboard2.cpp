#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> b1(4);
    vector<int> b2(4);

    //inputting the values
    cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];
    cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];

    //checking if billboards are shared vertically
    if((b1[0] == b2[0]) && (b1[2] == b2[2]))
}