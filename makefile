include ../makefile
libtrgt = libtest.so
bintrgt := $(libtrgt) test-rnd $(subst .cpp,,$(wildcard Test*.cpp))
currdir = $(shell pwd)

.PHONY: TEST
TEST:
	@echo $(bintrgt)
	@echo $(shell pwd)

libtest.so: failtest.o rnd.o
	$(CXX) -shared -fPIC $^ $(OUTPUT_OPTION)

test-rnd: test-rnd.o libtest.so
	$(CXX) $(CXXFLAGS) $< -L$(currdir) -ltest -lm -o $@

Test5: Test5.o libtest.so
	$(CXX) $(CXXFLAGS) $< -L$(currdir) -ltest -lm -o $@

Test6: Test6.o libtest.so
	$(CXX) $(CXXFLAGS) $< -L$(currdir) -ltest -lm -o $@

.PHONY: failtest rnd

failtest.o: failtest.hpp rnd.hpp
	$(COMPILE.cc) -fPIC $(OUTPUT_OPTION) $(subst .o,.cpp,$(@))

rnd.o: rnd.hpp
	$(COMPILE.cc) -fPIC $(OUTPUT_OPTION) $(subst .o,.cpp,$(@))

#all: $(targets)
#:	$(CXX) $(CXXFLAGS) $< -o $@
