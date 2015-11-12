Camera.o: src/glUtil/Camera.cpp \
 src/glUtil/../../includes/glUtil/Camera.hpp \
 src/glUtil/../../includes/glUtil/../math/Vector3.hpp \
 src/glUtil/../../includes/glUtil/../math/Matrix4.hpp \
 src/glUtil/../../includes/WindowConfig.hpp \
 src/glUtil/../../includes/math/Quaternion.hpp
./build/Camera.o: src/glUtil/Camera.cpp \
 src/glUtil/../../includes/glUtil/Camera.hpp \
./build/ src/glUtil/../../includes/glUtil/../math/Vector3.hpp \
 src/glUtil/../../includes/glUtil/../math/Matrix4.hpp \
./build/ src/glUtil/../../includes/WindowConfig.hpp \
./build/ src/glUtil/../../includes/math/Quaternion.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
