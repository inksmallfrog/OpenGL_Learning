IGlutApplication.o: src/glut/IGlutApplication.cpp \
 src/glut/../../includes/glut/IGlutApplication.hpp \
 src/glut/../../includes/glut/Callback.hpp
./build/IGlutApplication.o: src/glut/IGlutApplication.cpp \
./build/ src/glut/../../includes/glut/IGlutApplication.hpp \
 src/glut/../../includes/glut/Callback.hpp
	g++ -g `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
