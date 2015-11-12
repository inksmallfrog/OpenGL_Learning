Vector3.o: src/math/Vector3.cpp \
 src/math/../../includes/math/Math3dUtil.hpp \
 src/math/../../includes/math/Vector3.hpp
./build/Vector3.o: src/math/Vector3.cpp \
 src/math/../../includes/math/Math3dUtil.hpp \
./build/ src/math/../../includes/math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
