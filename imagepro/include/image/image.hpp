/**
 * Class Image
 */

#include <string>
#include <vector>

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "image/listofregion.hpp"

namespace image {
	class Image; 
	typedef unsigned char uchar;
	
	class Image{
	private:
		int width;
		int height;
		int th_value;
		uchar* data;
	public:
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		bool wasVisited(int position, std :: vector<int> visited);
		ListOfRegion getRegions();
		int getWidth();
		int getHeight();
		static Image* readImage(std::string &path);   
		virtual ~Image();      
	};
}

#endif