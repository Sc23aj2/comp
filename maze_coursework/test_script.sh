#!/bin/bash

#to check wether the correct maze file is working properly or not with the right inputs
echo "Test 1: Correct maze file with right inputs"
./maze maze_coursework/test_data/correct_maze.txt Inputs/correct_input.txt > output.txt
if grep -q "Congratulations! You have won the game!" output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi


# to check wether height and width are integers
echo "Test 2: Invalid maze file (width and height not integers)"
./maze test_data/incorrect_maze1.txt > output.txt
if [ "$(cat output.txt)" == "Error: Invalid maze file. Width and height must be integers." ]; then
    echo "PASS"
else
    echo "FAIL" 
fi

# if height and width are out of range
echo "Test 3: Invalid maze file (width and height out of range)"
./maze test_data/incorrect_maze_2.txt > output.txt
if [ "$(cat output.txt)" == "Error: Invalid maze file. Width and height are out of range." ]; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Not in a rectangular shape
echo "Test 4: Invalid maze file (maze shape not rectangular)"
./maze test_data/incorrect_maze_3.txt > output.txt
if [ "$(cat output.txt)" == "Error: each row and column should be the same length" ]; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Irregular height
echo "Test 5: Invalid maze file (irregular height)"
./maze test_data/incorrect_maze_4.txt > output.txt
if [ "$(cat output.txt)" == "Error: irregular height" ]; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Irregular width
echo "Test 5: Invalid maze file (irregular width)"
./maze test_data/incorrect_maze_5.txt > output.txt
if [ "$(cat output.txt)" == "Error: irregular width" ]; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Test 6: Player moves into a wall
echo "Test 6: Player moves into a wall"
./maze test_data/valid_maze.txt <<EOF
W
W
EOF
assert_equals "Error: You cannot move in that direction." "$(cat output.txt)"

# Test 7: Player moves off the edge of the map
echo "Test 7: Player moves off the edge of the map"
./maze test_data/valid_maze.txt <<EOF
W
W
EOF
assert_equals "Error: You cannot move in that direction." "$(cat output.txt)"

# Test 8: Player moves through a valid path
echo "Test 8: Player moves through a valid path"
./maze test_data/valid_maze.txt <<EOF
W
S
EOF
assert_equals "  # #\n #S#\n # #\n   E" "$(cat output.txt)"

# Test 9: Player wins the game
echo "Test 9: Player wins the game"
./maze test_data/valid_maze.txt <<EOF
W
S
D
A
E
EOF
assert_equals "Congratulations! You have won the game." "$(cat output.txt)"

# Test 10: Player enters 'M' to view the map
echo "Test 10: Player enters 'M' to view the map"
./maze test_data/valid_maze.txt <<EOF
M
EOF
assert_equals "  # #\n #S#\n # #\n   E" "$(cat output.txt)"

# Test 11: Invalid command
echo "Test 11: Invalid command"
./maze test_data/valid_maze.txt <<EOF
X
EOF
assert_equals "Error: Invalid command." "$(cat output.txt)"

# Test 12: Maze with multiple paths
echo "Test 12: Maze with multiple paths"
./maze test_data/multiple_paths.txt <<EOF
W
W
D
S
EOF
assert_equals "  # #\n # #\nS # #\n #E #" "$(cat output.txt)"

# Test 13: Maze with multiple paths (player wins)
echo "Test 13: Maze with multiple paths (player wins)"