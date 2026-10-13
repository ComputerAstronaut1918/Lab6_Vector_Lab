#*************************
# @file MakeFile
# @breif MakeFile to compile Lab 6 VectorCalc
# @author Harley Soto
# @date 10/10/26
#
# @version 1.0
#*************************

CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES= VectorCalc.c Vector.c Interface.c Array.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=VectorCalc

all: $(SOURCES) $(EXECUTABLE) 

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o: 
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
	
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d	   
	   
