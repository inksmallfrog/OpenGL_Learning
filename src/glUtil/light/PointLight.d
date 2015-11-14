PointLight.o: src/glUtil/light/PointLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
 src/glUtil/light/../../../includes/glUtil/light/PointLight.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/././LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/././../../math/Vector3.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp
./build/PointLight.o: src/glUtil/light/PointLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/PointLight.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/././LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/././../../math/Vector3.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
