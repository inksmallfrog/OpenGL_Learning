Shader.o: src/glUtil/Shader.cpp \
 src/glUtil/../../includes/glUtil/Shader.hpp
./build/Shader.o: src/glUtil/Shader.cpp \
 src/glUtil/../../includes/glUtil/Shader.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
