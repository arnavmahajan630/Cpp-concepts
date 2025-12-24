# ================= Compiler =================
CXX := g++
CXXFLAGS := -std=c++17 -Wall -g

# ================= Directories =================
OBJ_DIR := build/obj
BIN_DIR := build/bin

# ================= Shared main =================
MAIN_SRC := OOP/main.cpp
MAIN_OBJ := $(OBJ_DIR)/main.o

# ================= Operator Overloading =================
OP_SRC := OOP/Operator_Overloading/Mystring.cpp
OP_HDR := OOP/Operator_Overloading/Mystring.hpp
OP_OBJ := $(OBJ_DIR)/mystring.o
OP_BIN := $(BIN_DIR)/overload_test

# ================= Inheritance =================
INH_SRC := OOP/Inheritance/account.cpp
INH_HDR := OOP/Inheritance/account.hpp
INH_OBJ := $(OBJ_DIR)/account.o

SAV_SRC := OOP/Inheritance/savings_account.cpp
SAV_HDR := OOP/Inheritance/savings_account.hpp
SAV_OBJ := $(OBJ_DIR)/savings_account.o

INH_BIN := $(BIN_DIR)/inheritance_test

# ================= Directories =================
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: all overloading inheritance run_overloading run_inheritance clean

all: overloading inheritance

# ================= Compile =================
$(MAIN_OBJ): $(MAIN_SRC) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OP_OBJ): $(OP_SRC) $(OP_HDR) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INH_OBJ): $(INH_SRC) $(INH_HDR) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SAV_OBJ): $(SAV_SRC) $(SAV_HDR) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ================= Link =================
overloading: $(MAIN_OBJ) $(OP_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(OP_BIN)

inheritance: $(MAIN_OBJ) $(INH_OBJ) $(SAV_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(INH_BIN)

# ================= Run =================
run_overloading: overloading
	./$(OP_BIN)

run_inheritance: inheritance
	./$(INH_BIN)

# ================= Clean =================
clean:
	rm -rf build
