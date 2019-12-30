CC = g++
CFLAGS = $(HDR_PATHS) -Wno-deprecated -Wall -std=c++11 
LIB_PATHS= 
HDR_PATHS= 
LDFLAGS = 
SRCS = main.cpp encrypt.cpp caesar.cpp caesar2.cpp
OBJFILES = main.o encrypt.o caesar.o caesar2.o
TARGET = run

all:$(TARGET)

$(TARGET):$(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LIB_PATHS) $(LDFLAGS)

.cc.o:
		${CC} ${CFLAGS} ${INCLUDES} -c $<

clean:
		rm -f $(OBJFILES) $(TARGET)

depend:
		makedepend -I. $(SRCS)

exe: $(TARGET)
		./$(TARGET)
