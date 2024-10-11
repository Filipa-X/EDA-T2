/*
 Class ListOfPoint2D
*/

#ifndef LISTOFPOINT2D_HPP_
#define LISTOFPOINT2D_HPP_

#include "include/image/nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:
		NodePoint2D* headPoint2D;		
	public:
		ListOfPoint2D();

		void insertFirst(Point2D point2D);

		virtual ~ListOfPoint2D();		
	};
}

#endif