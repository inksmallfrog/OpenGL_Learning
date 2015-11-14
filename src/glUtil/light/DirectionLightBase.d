DirectionLightBase.o: src/glUtil/light/DirectionLightBase.cpp \
 src/glUtil/light/../../../includes/glUtil/light/DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/LightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/../../math/Vector3.hpp
./build/DirectionLightBase.o: src/glUtil/light/DirectionLightBase.cpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/DirectionLightBase.hpp \
 src/glUtil/light/../../../includes/glUtil/light/LightBase.hpp \
./build/ src/glUtil/light/../../../includes/glUtil/light/../../math/Vector3.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
