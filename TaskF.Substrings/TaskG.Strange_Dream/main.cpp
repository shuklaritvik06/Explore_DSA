#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

class Point {
 public:
  double x, y, z;

  Point() : x(0), y(0), z(0) {}
  Point(double x, double y, double z) : x(x), y(y), z(z) {}

  double squaredDistance(const Point& other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) +
           (z - other.z) * (z - other.z);
  }

  static double dotProduct(const Point& v1, const Point& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }
};

class Segment {
 public:
  Point p1, q1;

  Segment(const Point& p1, const Point& q1) : p1(p1), q1(q1) {}
};

class SegmentDistanceCalculator {
 public:
  static double calculate(const Segment& seg1, const Segment& seg2) {
    const Point& p1 = seg1.p1;
    const Point& q1 = seg1.q1;
    const Point& p2 = seg2.p1;
    const Point& q2 = seg2.q1;

    Point d1 = {q1.x - p1.x, q1.y - p1.y, q1.z - p1.z};
    Point d2 = {q2.x - p2.x, q2.y - p2.y, q2.z - p2.z};
    Point r = {p1.x - p2.x, p1.y - p2.y, p1.z - p2.z};

    double a = Point::dotProduct(d1, d1);
    double b = Point::dotProduct(d2, d2);
    double e = Point::dotProduct(d1, d2);
    double c = Point::dotProduct(d1, r);
    double f = Point::dotProduct(d2, r);

    double denom = a * b - e * e;

    double sc, sN, sD = denom;
    double tc, tN, tD = denom;

    if (denom < std::numeric_limits<double>::epsilon()) {
      sN = 0.0;
      sD = 1.0;
      tN = f;
      tD = b;
    } else {
      sN = (e * f - b * c);
      tN = (a * f - e * c);

      if (sN < 0.0) {
        sN = 0.0;
        tN = f;
        tD = b;
      } else if (sN > sD) {
        sN = sD;
        tN = f + e;
        tD = b;
      }
    }

    if (tN < 0.0) {
      tN = 0.0;

      if (-c < 0.0) {
        sN = 0.0;
      } else if (-c > a) {
        sN = sD;
      } else {
        sN = -c;
        sD = a;
      }
    } else if (tN > tD) {
      tN = tD;

      if ((-c + e) < 0.0) {
        sN = 0;
      } else if ((-c + e) > a) {
        sN = sD;
      } else {
        sN = (-c + e);
        sD = a;
      }
    }

    sc =
        (std::abs(sN) < std::numeric_limits<double>::epsilon()) ? 0.0 : sN / sD;
    tc =
        (std::abs(tN) < std::numeric_limits<double>::epsilon()) ? 0.0 : tN / tD;

    Point dP = {r.x + sc * d1.x - tc * d2.x, r.y + sc * d1.y - tc * d2.y,
                r.z + sc * d1.z - tc * d2.z};

    return std::sqrt(dP.squaredDistance(Point(0, 0, 0)));
  }
};

int main() {
  Point p1, q1, p2, q2;
  std::cin >> p1.x >> p1.y >> p1.z;
  std::cin >> q1.x >> q1.y >> q1.z;
  std::cin >> p2.x >> p2.y >> p2.z;
  std::cin >> q2.x >> q2.y >> q2.z;

  Segment seg1(p1, q1);
  Segment seg2(p2, q2);

  double distance = SegmentDistanceCalculator::calculate(seg1, seg2);
  std::cout << std::fixed << std::setprecision(6) << distance << std::endl;

  return 0;
}
