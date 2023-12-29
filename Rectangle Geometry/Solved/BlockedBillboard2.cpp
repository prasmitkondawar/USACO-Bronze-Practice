#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // For getting input from input.txt file
   freopen("billboard.in", "r", stdin);
  // Printing the Output to output.txt file
   freopen("billboard.out", "w", stdout);
    vector<int> b1(4);
    vector<int> b2(4);

    //inputting the values
    cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];
    cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];

    // //checking if billboards are shared vertically (x bounded)
    // if((b1[0] >= b2[0]) && (b1[2] <= b2[2])) {
    //     int yi = max(b1[1], b2[1]);
    //     int yf = min(b1[3], b2[3]);
    //     if(yf >= yi) {
    //         int length = (b1[3] - b1[1]) - (yf - yi);
    //         int width = b1[2] - b1[0];
    //         cout << length * width << "\n";
    //     } else {
    //         int length = b1[2] - b1[0];
    //         int width = b1[3] - b1[1];
    //         cout << length * width << "\n"; 
    //     }
    // } 
    // //checking if the billboards are shared horizontally
    // else if (b1[1] >= b2[1] && b1[3] <= b2[3]) {
    //     int xi = max(b1[0], b2[0]);
    //     int xf = min(b1[2], b2[2]);
    //     if(xf >= xi) {
    //         int length = b1[3] - b1[1];
    //         int width = (b1[2] - b1[0]) - (xf - xi);
    //         cout << length * width << "\n";
    //     } else {
    //         int length = b1[2] - b1[0];
    //         int width = b1[3] - b1[1];
    //         cout << length * width << "\n";
    //     }
    // } else {
    //     int length = b1[2] - b1[0];
    //     int width = b1[3] - b1[1];
    //     cout << length * width << "\n";
    // }

    bool boundedx = (b1[0] >= b2[0]) && (b1[2] <= b2[2]);
    bool boundedy = (b1[1] >= b2[1]) && (b1[3] <= b2[3]);

    if(boundedx && boundedy) {
        cout << "0" << "\n";
    } else if(!boundedx && !boundedy) {
        cout << (b1[2] - b1[0]) * (b1[3] - b1[1]) << "\n";
    } else if(boundedx) {
        if(b1[3] >= b2[3] && (b1[1] >= b2[1] && b1[1] <= b2[3])) {
            cout << (b1[2] - b1[0]) * (b1[3] - b2[3]) << "\n";
        } else if (b1[1] <= b2[1] && (b1[3] >= b2[1] && b1[3] <= b2[3])) {
             cout << (b1[2] - b1[0]) * (b2[1] - b1[1]) << "\n";
        } else {
            cout << (b1[2] - b1[0]) * (b1[3] - b1[1]) << "\n";
        }
    } else {
        if(b1[2] >= b2[2] && (b1[0] >= b2[0] && b1[0] <= b2[2])) {
            cout << (b1[3] - b1[1]) * (b1[2] - b2[2]) << "\n";
        } else if (b1[0] <= b2[0] && (b1[2] >= b2[0] && b1[2] <= b2[2])) {
             cout << (b1[3] - b1[1]) * (b2[0] - b1[0]) << "\n";
        } else {
            cout << (b1[2] - b1[0]) * (b1[3] - b1[1]) << "\n";
        }
    }
} 