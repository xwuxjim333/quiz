CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
ARRAY = "adgjmpsvz"
CHAR := a b c d e f g h i j k l m n o p q r s t u v w x y z
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run_iterative:
	$(foreach var,$(CHAR),./iterative $(ARRAY) $(var) ;)

run_recursive:
	$(foreach var,$(CHAR),./recursive $(ARRAY) $(var) ;)

clean:
	$(RM) $(EXEC) *.o perf.*
	$(RM) iterative.txt recursive.txt
