/* implementation of the class NodeRegion
 */

#include <iostream>

#include "include/image/noderegion.hpp"

namespace image {

    NodeRegion :: NodeRegion(): region(), nextRegion(nullptr) { 

    }

    NodeRegion :: NodeRegion(Region _region, NodeRegion* _nextRegion): region(_region), nextRegion(_nextRegion) {

    }

    void NodeRegion :: setRegion(Region _region) {
        region = _region;
    }

    void NodeRegion :: setNext(NodeRegion* _nextRegion) {
        nextRegion = _nextRegion;
    }

    Region NodeRegion :: getRegion() {
        return region;
    }

    NodeRegion* NodeRegion :: getNext() {
        return nextRegion;
    }

    NodeRegion :: ~NodeRegion() {

    }

}