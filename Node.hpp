#include <iostream>
#include <random>
#include <math.h>

#define MAX_PRINT_DIMENSION 5


/***************************************************************************************/
class Point {
    public:
        int ID;
        int dimension;
        float* coordinates;
        Point();
        Point(int dim, int ID, float* coord);
        ~Point();
        void free_point();

        // euclidian distance between two points
        static float distance_squared(Point &a, Point &b);
        float distance_squared(Point &b);
        static float distance(Point &a, Point &b);
        float distance(Point &b);
        
        // compare two points based on one axis of their coordinates
        static bool compare(Point *a, Point *b, int axis);

        // for easy representation
        friend std::ostream& operator<<(std::ostream&, const Point &point);
};
/***************************************************************************************/


/***************************************************************************************/
class Node {
    public:
        Point* point;
        Node* left;
        Node* right;

        // initializer
        Node() = default;
        Node(Point *p, Node* l, Node* r) : point{p}, left{l}, right{r} {};
        ~Node() = default;
};
/***************************************************************************************/