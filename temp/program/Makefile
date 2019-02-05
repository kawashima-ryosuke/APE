TARGET1 = temp_root_macro

SRCS = $(TARGET).cc
OBJS = $(TARGET).o

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)

CXXFLAGS   = $(ROOTCFLAGS) -Wall -fPIC
CXXLIBS    = $(ROOTLIBS)
CC = g++ 

all:temp_root_macro

temp_root_macro: temp_root_macro.o
	$(CC) $(CXXLIBS) temp_root_macro.o -o $@

# suffix rule
.cc.o:
	$(CC) $(CXXFLAGS) -c $<

# clean
clean:
	rm -f temp_root_macro