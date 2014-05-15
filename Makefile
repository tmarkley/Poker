# FMOD_DIR = /usr/local/dept/apps/fmod
# FMOD_INCLUDE = -I$(FMOD_DIR)/api/inc -I$(FMOD_DIR)/examples/common
# FMOD_LIB = $(FMOD_DIR)/api/lib/libfmodex64.so

OPTS = -Wall -g -Wno-deprecated
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif
Poker: poker.o screen.o welcomescreen.o datacontroller.o drawingfunctions.o button.o texture.o
	g++ $(OPTS) $(MACOSX_DEFINE) -o Poker poker.o screen.o welcomescreen.o datacontroller.o drawingfunctions.o button.o texture.o $(LIBS)

poker.o: poker.cpp
	g++ $(OPTS) -c poker.cpp 

screen.o:   screen.cpp screen.h
	g++ $(OPTS) -c screen.cpp

# mainscreen.o:   mainscreen.cpp mainscreen.h
# 	g++ -g -c mainscreen.cpp

welcomescreen.o:   welcomescreen.h welcomescreen.cpp
	g++ $(OPTS) -c welcomescreen.cpp

# levelscreen.o:   levelscreen.h levelscreen.cpp
# 	g++ -g -c levelscreen.cpp

# generalscreen.o:   generalscreen.h generalscreen.cpp
# 	g++ -g -c generalscreen.cpp

# professor.o:   professor.h professor.cpp
# 	g++ -g -c professor.cpp

# academicbuilding.o:   academicbuilding.h academicbuilding.cpp
# 	g++ -g -c academicbuilding.cpp

# foodbuilding.o:   foodbuilding.h foodbuilding.cpp
# 	g++ -g -c foodbuilding.cpp

# entertainmentbuilding.o:   entertainmentbuilding.h entertainmentbuilding.cpp
# 	g++ -g -c entertainmentbuilding.cpp

datacontroller.o:   datacontroller.h datacontroller.cpp
	g++ $(OPTS) -c datacontroller.cpp

drawingfunctions.o: drawingfunctions.cpp
	g++ $(OPTS) -c drawingfunctions.cpp

# building.o:   building.h building.cpp
# 	g++ -g -c building.cpp

button.o: button.cpp button.h
	g++ $(OPTS) -c button.cpp

texture.o: texture.cpp texture.h
	g++ $(OPTS) -c texture.cpp

# # sound.o: sound.cpp sound.h
# # 	g++ $(OPTS) -c sound.cpp

# people.o: people.cpp people.h
# 	g++ -g -c people.cpp

clean:
	rm -f *.o Poker
