CXX = g++
CXXFLAGS = -g -std=c++11

FinalProject: main.o Menu.o inputVal.o Node.o DLL.o GoodDog.o TreatFound.o Home.o LeashPull.o Dog.o 
	$(CXX) $(CXXFLAGS) -o FinalProject main.o Menu.o inputVal.o Node.o DLL.o GoodDog.o TreatFound.o Home.o LeashPull.o Dog.o

main.o: main.cpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Menu.o: Menu.hpp inputVal.hpp Dog.hpp DLL.hpp

inputVal.o: inputVal.hpp

Node.o: Node.hpp

DLL.o: DLL.hpp Node.hpp inputVal.hpp GoodDog.hpp TreatFound.hpp Home.hpp LeashPull.hpp 

GoodDog.o: GoodDog.hpp Node.hpp

TreatFound.o: TreatFound.hpp Node.hpp

Home.o: Home.hpp Node.hpp

LeashPull.o: LeashPull.hpp Node.hpp

Dog.o: Dog.hpp

clean:
	rm *.o FinalProject
