AmbientLight.o: src/glUtil/light/AmbientLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
 src/glUtil/light/../../../includes/glUtil/light/AmbientLight.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp
./build/AmbientLight.o: src/glUtil/light/AmbientLight.cpp \
 src/glUtil/light/../../../includes/glUtil/Shader.hpp \
 src/glUtil/light/../../../includes/glUtil/light/AmbientLight.hpp \
 src/glUtil/light/../../../includes/glUtil/light/./LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/./../../math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
