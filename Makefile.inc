# Some simple constants.
CXXFLAGS = -Wall
CXX = g++
#CC = gcc
MKDIR := mkdir -p
RM = rm -f

# Internal variables.
sources = $(wildcard *.cpp)
objects = $(subst .cpp,.o,$(sources))
lexsrcs = $(wildcard *.l)
lextrgt = $(subst .l,.cpp,$(lexsrcs))
bintrgt = $(subst .cpp,,$(sources))

# A function or two.
maybe-make-dir = $(if $(wildcard $1),,$(MKDIR) $1)
assert-not-null = $(if $1,,$(error Illegal null value.))

# Some targets.
.PRECIOUS: $(lextrgt)
MAKEFLAGS += --no-builtin-rules

#.SUFFIXES:
.SUFFIXES: .cpp

.PHONY: all
all: $(bintrgt)

.PHONY: .cpp.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(objects) $(bintrgt) $(lextrgt)
