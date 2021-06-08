#include "Node.hpp"


Point::Point() = default;
Point::~Point() = default;


Point::Point(int dim, int id, float* coord) : ID{id}, dimension{dim}, coordinates{coord}{}


void Point::free_point(){
    free(this->coordinates);
}


std::ostream& operator<<(std::ostream &strm, const Point &point) {
    strm << "Point(ID=" << point.ID << ", dimension=" << point.dimension << ", coordinates=[";
    for(int d = 0; d < point.dimension - 1; ++d){
        strm << point.coordinates[d] << ", ";

        if (d >= MAX_PRINT_DIMENSION - 1){
            strm << ", ..., ";
            break;
        }
    }
    strm << point.coordinates[point.dimension - 1] << "])";
    return strm;
}


float Point::distance_squared(Point &b){
    return Point::distance_squared(*this, b);
}


float Point::distance(Point &a, Point &b){
    return sqrt(Point::distance_squared(a, b));
}


float Point::distance(Point &b){
    return Point::distance(*this, b);
}


bool Point::compare(Point *a, Point *b, int axis){
    return a->coordinates[axis] < b->coordinates[axis];
}
