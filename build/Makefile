#My makefileш

CC 		= g++
CFLAGS 		= -c -Wall
LDFLAGS 	= 

SRC_DIR		= Source
HEAD_DIR	= Header

INCPATH		= -I/usr/include/eigen3 \
		  -I/usr/local/include/opencv4 \
		  -I../$(HEAD_DIR) \
		  -I../zcm_types/service/cpp_types \
		  -I ../

SOURCES 	= ../main.cpp \
		  ../$(SRC_DIR)/myclass.cpp \
		  ../$(SRC_DIR)/videoParser.cpp

HEADERS		= ../$(HEAD_DIR)/myclass.h \
		  ../

#OBJECTS 	= $(SOURCES:.cpp=.o) 
OBJECTS		= main.o \
		  myclass.o \
		  videoParser.o

EXECUTABLE	= hello


all: $(EXECUTABLE)

hello: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS):
	$(CC) $(CFLAGS) $(SOURCES) $(INCPATH) -link_pkgconfig




#main.o: 
#	$(CC) $(CFLAGS) ../main.cpp $(INCPATH)

#myclass.o: 
#	$(CC) $(CFLAGS) ../Source/myclass.cpp $(INCPATH)


#all: $(SOURCES) $(EXECUTABLE)

#$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDLAGS) $(OBJECTS) -o $@ $(INCPATH)

#$(OBJECTS): $(SOURCES)
#	$(CC) $(CFLAGS) $< -o $@ $(INCPATH) 



#$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(INCPATH)

#.cpp.o: $(HEADERS)
#	$(CC) $(CFLAGS) $< -o $@ $(INCPATH)



run: clean all
	./$(EXECUTABLE)

rebuild: clean all

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
