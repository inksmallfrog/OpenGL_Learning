sources_path = ./src/
objects_path = ./build/

sources = $(wildcard $(sources_path)*.cpp) $(wildcard $(sources_path)*/*.cpp)
cpp_files = $(notdir $(sources))
objects = $(cpp_files:%.cpp=$(objects_path)%.o)
targets = ./bin/test
build = g++ -g
libs = -lGL -lglut -lGLEW
MAGICKPP = `Magick++-config --cppflags --cxxflags --ldflags --libs`

$(targets) : pre $(objects)
	$(build) $(MAGICKPP) $(objects) $(libs) -o $(targets)
	rm -f $(sources_path)/*.d

sinclude $(sources:.cpp=.d)
%.d : %.cpp
	@$(build) -MM $< > $@.temp
	@sed 's/.*o/.\/build\/&/' $@.temp >> $@.temp
	@sed 's,\($*\)\.o[:]*,\1.o $@ ,g' < $@.temp > $@
	@echo -e '\t$(build) $(MAGICKPP) -c $$< -o $$@' >> $@
	@rm -f $@.temp

pre :
	mkdir -p bin
	mkdir -p build

.PHONY:clean
clean:
	rm -f ./build/*
