Vector.o: src/glUtil/Vector.cpp \
 src/glUtil/../../includes/glUtil/Vertex.hpp \
 src/glUtil/../../includes/glUtil/../math/Vector.hpp \
 src/glUtil/../../includes/glUtil/../math/Vector2.hpp \
 src/glUtil/../../includes/glUtil/../math/Vector3.hpp
./build/Vector.o: src/glUtil/Vector.cpp \
 src/glUtil/../../includes/glUtil/Vertex.hpp \
./build/ src/glUtil/../../includes/glUtil/../math/Vector.hpp \
./build/ src/glUtil/../../includes/glUtil/../math/Vector2.hpp \
./build/ src/glUtil/../../includes/glUtil/../math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
