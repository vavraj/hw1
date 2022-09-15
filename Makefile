CXX = g++
CPPFLAGS = -g -Wall -Ilib

test: ulliststr_test.cpp p2_unit.o
	$(CXX) $(CPPFLAGS) $^ -o $@

p2_unit.o: ulliststr.cpp ulliststr.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp