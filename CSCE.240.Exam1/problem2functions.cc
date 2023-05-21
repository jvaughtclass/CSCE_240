#include "problem2functions.h"

#include <cmath>

double Distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int OnCircle(double x1, double y1, double r, double x2, double y2) {
  double distance = Distance(x1, y1, x2, y2);
  if (distance < r) {
    return -1;
  } else if (distance == r) {
    return 0;
  } else {
    return 1;
  }
}

bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
  double slope1 = (y2 - y1) / (x2 - x1);
  double slope2 = (y3 - y2) / (x3 - x2);
  return slope1 == slope2;
}
