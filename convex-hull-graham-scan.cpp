#include <iostream>

struct Point {
    int x;
    int y;

    bool operator<(const Point &other) const {
        if (x == other.x) {
            return y < other.y;
        }

        return x < other.x;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

void print(const std::vector<Point> &c, const std::string &sep = " ") {
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != c.end()) std::cout << sep;
    }
    std::cout << "\n";
}

bool isLastTurnRight(const std::vector<Point> &c) {
    if (c.size() < 3) return false;

    const Point p = *(c.end() - 1);
    const Point q = *(c.end() - 2);
    const Point r = *(c.end() - 3);

    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y) < 0;
}

void convexHull(std::vector<Point> points) {
    const int N = static_cast<int>(points.size());

    std::cout <<"Step 0 |   ";
    print(points);

    // Step 1: Sort points by x
    std::sort(points.begin(), points.end());

    std::cout <<"Step 1 |   ";
    print(points);

    std::vector upperHull= { points[0], points[1] };
    std::vector lowerHull = { *(points.end() - 1), *(points.end() - 2)};

    for (int i = 2; i < N; i++) {
        upperHull.push_back(points[i]);

        while (upperHull.size() > 2 && !isLastTurnRight(upperHull)) {
            upperHull.erase(upperHull.end() - 2);
        }
    }

    std::cout <<"Step 2 |   ";
    print(upperHull);

    for (int i = N-2; i >= 0; i--) {
        lowerHull.push_back(points[i]);

        while (lowerHull.size() > 2 && !isLastTurnRight(lowerHull)) {
            lowerHull.erase(lowerHull.end() - 2);
        }
    }

    std::cout <<"Step 3 |   ";
    print(lowerHull);

    lowerHull.erase(lowerHull.begin());
    lowerHull.pop_back();

    std::cout <<"Step 4 |   ";
    print(lowerHull);

    upperHull.insert(upperHull.end(), lowerHull.begin(), lowerHull.end());

    std::cout<<"Answer |   ";
    print(upperHull);
}

int main() {
    const std::vector<Point> points = {
        {0, 3},
        {1, 1},
        {2, 2},
        {4, 4},
        {0, 0},
        {1, 2},
        {3, 1},
        {3, 3}
    };

    convexHull(points);

    return 0;
}
