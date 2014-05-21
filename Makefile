# compiling options
OPTS = -Wall -g -Wno-deprecated
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++
endif

BINARIES = Poker
OBJ_DIR = objects

all: $(OBJ_DIR) $(BINARIES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

Poker: objects/poker.o objects/screen.o objects/mainscreen.o objects/namescreen.o objects/welcomescreen.o objects/card.o objects/hand.o objects/datacontroller.o objects/drawingfunctions.o objects/button.o objects/texture.o
	g++ $(OPTS) -o poker objects/poker.o objects/screen.o objects/mainscreen.o objects/namescreen.o objects/welcomescreen.o objects/card.o objects/hand.o objects/datacontroller.o objects/drawingfunctions.o objects/button.o objects/texture.o $(LIBS)

objects/poker.o: Poker.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c poker.cpp -o objects/poker.o

objects/screen.o:   headers/screen.h definitions/screen.cpp
	g++ $(OPTS) -c definitions/screen.cpp -o objects/screen.o

objects/mainscreen.o:   headers/mainscreen.h definitions/mainscreen.cpp
	g++ $(OPTS) -c definitions/mainscreen.cpp -o objects/mainscreen.o

objects/namescreen.o:	headers/namescreen.h definitions/namescreen.cpp
	g++ $(OPTS) -c definitions/namescreen.cpp -o objects/namescreen.o

objects/welcomescreen.o:   headers/welcomescreen.h definitions/welcomescreen.cpp
	g++ $(OPTS) -c definitions/welcomescreen.cpp -o objects/welcomescreen.o

objects/card.o:	headers/card.h definitions/card.cpp
	g++ $(OPTS) -c definitions/card.cpp -o objects/card.o

objects/hand.o:	headers/hand.h definitions/hand.cpp
	g++ $(OPTS) -c definitions/hand.cpp -o objects/hand.o

objects/datacontroller.o:   headers/datacontroller.h definitions/datacontroller.cpp
	g++ $(OPTS) -c definitions/datacontroller.cpp -o objects/datacontroller.o

objects/drawingfunctions.o:	headers/drawingfunctions.h definitions/drawingfunctions.cpp
	g++ $(OPTS) -c definitions/drawingfunctions.cpp -o objects/drawingfunctions.o

# building.o:   building.h building.cpp
# 	g++ -g -c building.cpp

objects/button.o: headers/button.h definitions/button.cpp
	g++ $(OPTS) -c definitions/button.cpp -o objects/button.o

objects/texture.o: headers/texture.h definitions/texture.cpp
	g++ $(OPTS) -c definitions/texture.cpp -o objects/texture.o

# # sound.o: sound.cpp sound.h
# # 	g++ $(OPTS) -c sound.cpp

# people.o: people.cpp people.h
# 	g++ -g -c people.cpp

clean:
	rm -f $(BINARIES) objects/*.o
