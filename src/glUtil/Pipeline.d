Pipeline.o: src/glUtil/Pipeline.cpp \
 src/glUtil/../../includes/glUtil/Pipeline.hpp \
 src/glUtil/../../includes/glUtil/../math/Vector3.hpp \
 src/glUtil/../../includes/glUtil/../math/Matrix4.hpp \
 src/glUtil/../../includes/glUtil/Camera.hpp \
 src/glUtil/../../includes/glUtil/Shader.hpp
./build/Pipeline.o: src/glUtil/Pipeline.cpp \
 src/glUtil/../../includes/glUtil/Pipeline.hpp \
./build/ src/glUtil/../../includes/glUtil/../math/Vector3.hpp \
 src/glUtil/../../includes/glUtil/../math/Matrix4.hpp \
 src/glUtil/../../includes/glUtil/Camera.hpp \
 src/glUtil/../../includes/glUtil/Shader.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
