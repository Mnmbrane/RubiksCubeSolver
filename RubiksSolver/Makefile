CXX=g++
CXXFLAGS= -std=c++11 -o

Source: Source.o
	$(CXX) $(CXXFLAGS) Source Source.o

Source.o: Source.cpp
	$(CXX) -c Source.cpp

clean:
	rm *.o