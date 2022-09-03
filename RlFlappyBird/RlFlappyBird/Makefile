DEBUG       ?= FALSE

CFLAGS      = -std=c++11 -lstdc++
LIBS        = lib/libraylib.a
FRAMEWORKS  = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
CPP_FILES   = src/main.cpp src/pipe.cpp src/bird.cpp src/pipePair.cpp src/stateMachine.cpp src/states/*.cpp
BINARY      = build/main

ifeq ($(DEBUG), TRUE)
	CFLAGS += -g
endif

all: 
	clang \
	$(CFLAGS) \
	$(FRAMEWORKS) \
	$(LIBS) \
	$(CPP_FILES) \
	-Iheaders \
	-o $(BINARY)

clean:
	rm $(BINARY)