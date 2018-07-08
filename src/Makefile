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

OBJ_FILES  = a.o
OBJ_FILES += b.o
OBJ_FILES += c.o
OBJ_FILES += d.o

all:
	${CXX} -c WM_COMMAND_Handler.cpp -o d.o ${CXXFLAGS}
	${CXX} -c WM_DESTROY_Handler.cpp -o c.o ${CXXFLAGS}
	${CXX} -c MainWindow.cpp -o b.o ${CXXFLAGS}
	${CXX} -c main.cpp -o a.o ${CXXFLAGS}
	${CXX} ${OBJ_FILES} -o pixel-noise.exe ${CXXFLAGS}
