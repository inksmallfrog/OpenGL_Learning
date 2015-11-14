PointLightBase.o: src/glUtil/light/PointLightBase.cpp \
 src/glUtil/light/../../../includes/glUtil/light/PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp
./build/PointLightBase.o: src/glUtil/light/PointLightBase.cpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
