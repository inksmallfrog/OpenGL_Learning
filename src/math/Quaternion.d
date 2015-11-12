Quaternion.o: src/math/Quaternion.cpp \
 src/math/../../includes/math/Vector3.hpp \
 src/math/../../includes/math/Quaternion.hpp \
 src/math/../../includes/math/Math3dUtil.hpp
./build/Quaternion.o: src/math/Quaternion.cpp \
./build/ src/math/../../includes/math/Vector3.hpp \
./build/ src/math/../../includes/math/Quaternion.hpp \
 src/math/../../includes/math/Math3dUtil.hpp
	g++ `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
