Texture.o: src/glUtil/Texture.cpp \
 src/glUtil/../../includes/glUtil/Texture.hpp
./build/Texture.o: src/glUtil/Texture.cpp \
 src/glUtil/../../includes/glUtil/Texture.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
