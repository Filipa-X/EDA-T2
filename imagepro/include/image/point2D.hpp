/*
 Class Point2D
*/

#ifndef POINT2D_HPP_
#define POINT2D_HPP_

namespace image {
	class Point2D {
	private:
		int x;
		int y;		
	public:
		Point2D();
		Point2D(int _x, int _y);
        void setX(int _x);
        void setY(int _y);
        int getX();
        int getY();
        virtual ~Point2D(); 		
	};
}

#endif