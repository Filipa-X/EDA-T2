/**
 * Class Image
 */

#include <string>

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "include/image/listofregion.hpp"

namespace image {
	class Image; 
	typedef unsigned char uchar;
	
	class Image{
	private:
		int width;
		int height;
		int th_value;
		uchar* data;
		ListOfRegion regions;
	public:
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		ListOfRegion getRegions();
		static Image* readImage(std::string &path);   
		virtual ~Image();      
	};
}

#endif