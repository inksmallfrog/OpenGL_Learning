Matrix4.o: src/math/Matrix4.cpp src/math/../../includes/math/Vector3.hpp \
 src/math/../../includes/math/Matrix4.hpp \
 src/math/../../includes/math/Quaternion.hpp \
 src/math/../../includes/math/Math3dUtil.hpp \
 src/math/../../includes/glUtil/Camera.hpp \
 src/math/../../includes/glUtil/../math/Vector3.hpp \
 src/math/../../includes/glUtil/../math/Matrix4.hpp
./build/Matrix4.o: src/math/Matrix4.cpp src/math/../../includes/math/Vector3.hpp \
 src/math/../../includes/math/Matrix4.hpp \
./build/ src/math/../../includes/math/Quaternion.hpp \
 src/math/../../includes/math/Math3dUtil.hpp \
 src/math/../../includes/glUtil/Camera.hpp \
./build/ src/math/../../includes/glUtil/../math/Vector3.hpp \
 src/math/../../includes/glUtil/../math/Matrix4.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
