include config.mk

LIB_SRC = sll.c
LIB_OBJ = sll.o
LIB_NAME = libsll.a
TEST_SRC = test.c
TEST_BIN = test

.PHONY: all clean

all: $(LIB_NAME) $(TEST_BIN)

$(LIB_NAME): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(TEST_BIN): $(TEST_SRC) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(TEST_SRC) -L. -lsll

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(LIB_NAME) $(TEST_BIN)rm -f *.o $(LIB_NAME) $(TEST_BIN)
