#!/bin/bash

# Cores para output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}  SO_LONG - PARSING TEST SUITE${NC}"
echo -e "${BLUE}================================${NC}\n"

# Compila o programa
echo -e "${YELLOW}Compiling...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}✗ Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}✓ Compilation successful${NC}\n"

# Contador de testes
TOTAL=0
PASSED=0
FAILED=0

# Função para testar mapa válido
test_valid_map() {
    TOTAL=$((TOTAL + 1))
    echo -e "${BLUE}Test $TOTAL: $1${NC}"
    ./so_long_test "$2" > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ PASSED - Map is valid${NC}\n"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ FAILED - Expected valid map${NC}\n"
        FAILED=$((FAILED + 1))
    fi
}

# Função para testar mapa inválido
test_invalid_map() {
    TOTAL=$((TOTAL + 1))
    echo -e "${BLUE}Test $TOTAL: $1${NC}"
    ./so_long_test "$2" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${GREEN}✓ PASSED - Map correctly identified as invalid${NC}\n"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ FAILED - Invalid map was accepted${NC}\n"
        FAILED=$((FAILED + 1))
    fi
}

echo -e "${YELLOW}========== VALID MAPS ==========${NC}\n"

test_valid_map "Easy Small (10x10)" "maps/map_easy_small.ber"
test_valid_map "Easy Large (50x50)" "maps/map_easy_large.ber"
test_valid_map "Hard Maze" "maps/map_hard_maze.ber"
test_valid_map "Hard Spiral" "maps/map_hard_spiral.ber"
test_valid_map "Hard Rooms" "maps/map_hard_rooms.ber"

echo -e "${YELLOW}========== INVALID MAPS ==========${NC}\n"

test_invalid_map "No Exit" "maps/map_invalid_no_exit.ber"
test_invalid_map "Not Rectangular" "maps/map_invalid_not_rectangular.ber"
test_invalid_map "No Valid Path" "maps/map_invalid_no_path.ber"

# Testes extras
echo -e "${YELLOW}========== EXTRA TESTS ==========${NC}\n"

TOTAL=$((TOTAL + 1))
echo -e "${BLUE}Test $TOTAL: Non-existent file${NC}"
./so_long_test "nonexistent.ber" > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASSED - Correctly handles missing file${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAILED - Should reject missing file${NC}\n"
    FAILED=$((FAILED + 1))
fi

TOTAL=$((TOTAL + 1))
echo -e "${BLUE}Test $TOTAL: Wrong extension${NC}"
echo "111
1P1" > test.txt
./so_long_test "test.txt" > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASSED - Correctly rejects non-.ber file${NC}\n"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAILED - Should reject non-.ber file${NC}\n"
    FAILED=$((FAILED + 1))
fi
rm -f test.txt

# Resumo
echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}         TEST SUMMARY${NC}"
echo -e "${BLUE}================================${NC}"
echo -e "Total tests: $TOTAL"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "\n${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}\n"
    exit 0
else
    echo -e "\n${RED}❌ SOME TESTS FAILED ❌${NC}\n"
    exit 1
fi
