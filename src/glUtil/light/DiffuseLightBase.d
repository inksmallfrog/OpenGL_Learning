DiffuseLightBase.o: src/glUtil/light/DiffuseLightBase.cpp \
 src/glUtil/light/../../../includes/glUtil/light/DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/../../math/Vector3.hpp
./build/DiffuseLightBase.o: src/glUtil/light/DiffuseLightBase.cpp \
 src/glUtil/light/../../../includes/glUtil/light/DiffuseLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/../../math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
