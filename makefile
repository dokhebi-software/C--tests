include ../makefile
bintrgt := test-rnd $(subst .cpp,,$(wildcard Test*.cpp))

.PHONY: TEST
TEST:
	@echo $(bintrgt)

test-rnd: test-rnd.o -ltest -lm
	$(CXX) $(CXXFLAGS) $^ -o $@

Test5: Test5.o -ltest -lm
	$(CXX) $(CXXFLAGS) $^ -o $@

Test6: Test6.o -ltest -lm
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: failtest rnd libtest

libtest.so: failtest.o rnd.o
	$(CXX) -shared -fPIC $^ $(OUTPUT_OPTION)

failtest.o: failtest.hpp rnd.hpp
	$(COMPILE.cc) -fPIC $(OUTPUT_OPTION) $(subst .o,.cpp,$(@))

rnd.o: rnd.hpp
	$(COMPILE.cc) -fPIC $(OUTPUT_OPTION) $(subst .o,.cpp,$(@))

#all: $(targets)
#:	$(CXX) $(CXXFLAGS) $< -o $@
