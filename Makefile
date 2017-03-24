CC = clang
CFLAGS = -g -Wall 
COMMON_SOURCES = engine.c levenshtein.c/levenshtein.c ../q1/table.c
TARGET_SOURCES = suggest.c
TEST_SOURCES = test.c
COMMON_OBJECTS = $(COMMON_SOURCES:.c=.o)
TARGET_OBJECTS = $(TARGET_SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
EXECUTABLE = prog
TEST_EXECUTABLE = test

.PHONY: all target tests

all: target tests

target: $(EXECUTABLE)

tests: $(TEST_EXECUTABLE)

$(EXECUTABLE): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	$(CC) $^ -o $@

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@