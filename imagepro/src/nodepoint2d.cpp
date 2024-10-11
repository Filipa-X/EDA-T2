/* implementation of the class NodePoint2D
 */

#include <iostream>

#include "image/nodepoint2d.hpp"

namespace image {

    NodePoint2D :: NodePoint2D(): point2D(), nextPoint2D(nullptr) { 

    }

    NodePoint2D :: NodePoint2D(Point2D _point2D, NodePoint2D* _nextPoint2D): point2D(_point2D), nextPoint2D(_nextPoint2D) {

    }

    void NodePoint2D :: setPoint2D(Point2D _point2D) {
        point2D = _point2D;
    }

    void NodePoint2D :: setNext(NodePoint2D* _nextPoint2D) {
        nextPoint2D = _nextPoint2D;
    }

    Point2D NodePoint2D :: getPoint2D() {
        return point2D;
    }

    NodePoint2D* NodePoint2D :: getNext() {
        return nextPoint2D;
    }

    NodePoint2D :: ~NodePoint2D() {

    }

}