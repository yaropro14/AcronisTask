OBJ = solution.o
PROG = solution
CFLAGS += -Wall

all: $(PROG)

$(PROG): $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

clean: 
	$(RM) $(OBJ) $(PROG)