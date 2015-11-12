Callback.o: src/glut/Callback.cpp \
 src/glut/../../includes/glut/Callback.hpp \
 src/glut/../../includes/glut/IGlutApplication.hpp
./build/Callback.o: src/glut/Callback.cpp \
 src/glut/../../includes/glut/Callback.hpp \
./build/ src/glut/../../includes/glut/IGlutApplication.hpp
	g++ `Magick++-config --cppflags --cxxflags --ldflags --libs` -c $< -o $@
