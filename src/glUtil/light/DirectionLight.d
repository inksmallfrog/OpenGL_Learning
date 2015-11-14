DirectionLight.o: src/glUtil/light/DirectionLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
 src/glUtil/light/../../../includes/glUtil/light/DirectionLight.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp
./build/DirectionLight.o: src/glUtil/light/DirectionLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/DirectionLight.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
