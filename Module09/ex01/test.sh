#!/bin/bash

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

RPN="./RPN"

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}           RPN CALCULATOR TEST         ${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Counter
total=0
passed=0

run_test() {
    local input="$1"
    local expected="$2"
    
    total=$((total + 1))
    echo -e "Input: \"$input\""
    
    output=$($RPN "$input" 2>&1)
    exit_code=$?
    
    echo "Output: $output"
    
    if [[ "$expected" == "ERROR" ]]; then
        if [[ $exit_code -ne 0 ]] || [[ "$output" == *"Error"* ]]; then
            echo -e "${GREEN}✓ PASS${NC} (Expected error)\n"
            passed=$((passed + 1))
        else
            echo -e "${RED}✗ FAIL${NC} (Should have failed)\n"
        fi
    else
        if [[ "$output" == "$expected" ]]; then
            echo -e "${GREEN}✓ PASS${NC}\n"
            passed=$((passed + 1))
        else
            echo -e "${RED}✗ FAIL${NC} (Expected: $expected)\n"
        fi
    fi
}

echo -e "${GREEN}========== VALID INPUTS ==========${NC}\n"

# Basic operations
run_test "5 5 +" "10"
run_test "8 2 -" "6"
run_test "3 4 *" "12"
run_test "8 4 /" "2"

# Single number
run_test "7" "7"

# Complex expressions
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 + 3 + 4 +" "10"
run_test "9 8 7 + +" "24"
run_test "2 3 + 4 5 + *" "45"

# Zero handling
run_test "0 5 +" "5"
run_test "5 0 -" "5"
run_test "0 5 *" "0"

echo -e "${RED}========== INVALID INPUTS ==========${NC}\n"

# Empty/No input
run_test "" "ERROR"

# Not enough operands
run_test "5 +" "ERROR"
run_test "+" "ERROR"
run_test "5 5 + +" "ERROR"

# Too many operands
run_test "5 5 5 +" "ERROR"
run_test "1 2 3 4 +" "ERROR"

# Invalid characters
run_test "5 5 a" "ERROR"
run_test "5 5 @" "ERROR"
run_test "5 a +" "ERROR"

# Multi-digit numbers
run_test "10 5 +" "ERROR"
run_test "42 1 -" "ERROR"
run_test "100 50 +" "ERROR"

# Invalid operators
run_test "5 5 %" "ERROR"
run_test "5 5 ^" "ERROR"
run_test "5 5 &" "ERROR"

# Starting with operator
run_test "+ 5 5" "ERROR"
run_test "* 3 4" "ERROR"

# Only numbers
run_test "5 5" "ERROR"
run_test "1 2 3" "ERROR"

# Only operators
run_test "+ -" "ERROR"
run_test "+ - * /" "ERROR"

# Missing spaces
run_test "5+5" "ERROR"
run_test "12+34" "ERROR"

# Division by zero
run_test "5 0 /" "ERROR"
run_test "1 0 /" "ERROR"

# Negative numbers (if not supported)
run_test "-5 5 +" "ERROR"

# Decimal numbers (if not supported)
run_test "5.5 2 +" "ERROR"

# Extra spaces (valid - stringstream skips whitespace)
run_test "5  5  +" "10"

# Invalid sequence
run_test "5 + 5" "ERROR"

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}      Results: $passed/$total tests passed${NC}"
echo -e "${BLUE}========================================${NC}"

if [ $passed -eq $total ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed.${NC}"
    exit 1
fi
