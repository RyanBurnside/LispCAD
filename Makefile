CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic
OBJS= Shape.o Drawing.o CADCanvas.o CommandLine.o LispCAD.o


LispCAD: $(OBJS)
	$(CXX) $(CXXFLAGS) -o LispCAD $(OBJS) -lfltk -lecl

LispCAD.o: LispCAD.cpp LispCAD.h
	$(CXX) $(CXXFLAGS) -c LispCAD.cpp -lfltk -lecl

CADCanvas.o: CADCanvas.cpp CADCanvas.h
	$(CXX) $(CXXFLAGS) -c CADCanvas.cpp -lfltk

CommandLine.o: CommandLine.cpp CommandLine.h
	$(CXX) $(CXXFLAGS) -c CommandLine.cpp -lfltk

Drawing.o: Drawing.cpp Drawing.h
	$(CXX) $(CXXFLAGS) -c Drawing.cpp

Shape.o: Shape.cpp Shape.h
	$(CXX) $(CXXFLAGS) -c Shape.cpp

clean:
	rm *.o
