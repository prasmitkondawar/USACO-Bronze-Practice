#include <iostream>
#include <algorithm>

int main() {
    // For getting input from input.txt file
   freopen("square.in", "r", stdin);
  // Printing the Output to output.txt file
   freopen("square.out", "w", stdout);
    int x1i, y1i, x1f, y1f, x2i, y2i, x2f, y2f;

    std::cin >> x1i >> y1i >> x1f >> y1f >> x2i >> y2i >> x2f >> y2f;

    int xS = std::abs(std::min(x1i, x2i) - std::max(x1f, x2f));
    int yS = std::abs(std::min(y1i, y2i) - std::max(y2f, y1f));

    std::cout << std::max(xS, yS) * std::max(xS, yS) << std::endl;

    return 0;
}
