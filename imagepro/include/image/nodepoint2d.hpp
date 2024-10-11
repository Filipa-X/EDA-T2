/*
 Class NodePoint2D
*/

#ifndef NODEPOINT2D_HPP_
#define NODEPOINT2D_HPP_

#include "image/point2D.hpp"

namespace image {
	class NodePoint2D{
	private:
		Point2D point2D;	
		NodePoint2D* nextPoint2D;	
	public:		
		NodePoint2D();
		NodePoint2D(Point2D point2D, NodePoint2D* nextPoint2D = nullptr);

		void setPoint2D(Point2D _point2D);
		void setNext(NodePoint2D* _nextPoint2D);
		Point2D getPoint2D();
		NodePoint2D* getNext();

		virtual ~NodePoint2D();
	};
}

#endif
