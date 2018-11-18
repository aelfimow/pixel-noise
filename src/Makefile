CXXFLAGS  = -mwindows
CXXFLAGS += -mthreads
CXXFLAGS += -D_MT
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17
CXXFLAGS += -O2
CXXFLAGS += -m64

FILES = $(wildcard *.cpp)
FILES_OBJ = $(FILES:.cpp=.o)

all: $(FILES_OBJ)
	${CXX} *.o -o pixel-noise.exe ${CXXFLAGS}

deps:
	g++ -MM *.cpp > Makefile.files

include Makefile.files
