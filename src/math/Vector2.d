Vector2.o: src/math/Vector2.cpp src/math/../../includes/math/Vector2.hpp
./build/Vector2.o: src/math/Vector2.cpp src/math/../../includes/math/Vector2.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
