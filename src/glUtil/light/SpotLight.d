SpotLight.o: src/glUtil/light/SpotLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
 src/glUtil/light/../../../includes/glUtil/light/SpotLight.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/././LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/math/Math3dUtil.hpp
./build/SpotLight.o: src/glUtil/light/SpotLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/SpotLight.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./PointLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/././LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/math/Math3dUtil.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
