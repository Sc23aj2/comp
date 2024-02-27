#!/bin/bash

#to check wether the correct maze file is working properly or not
echo "Test 1: Correct maze file"
./maze test_data/correct_maze.txt > output.txt
if [ "$(cat output.txt)" == "Congratulations! You have won the game!" ]; then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 2: Invalid maze file (width and height not integers)
echo "Test 2: Invalid maze file (width and height not integers)"
./maze test_data/invalid_maze_1.txt > output.txt
assert_equals "Error: Invalid maze file. Width and height must be integers." "$(cat output.txt)"

# Test 3: Invalid maze file (width and height out of range)
echo "Test 3: Invalid maze file (width and height out of range)"
./maze test_data/invalid_maze_2.txt > output.txt
assert_equals "Error: Invalid maze file. Width and height must be between 5 and 100." "$(cat output.txt)"

# Test 4: Invalid maze file (maze data not valid)
echo "Test 4: Invalid maze file (maze data not valid)"
./maze test_data/invalid_maze_3.txt > output.txt
assert_equals "Error: Invalid maze file. Maze data must be a rectangle with walls (#), paths ( ), starting point (S), and exit (E)." "$(cat output.txt)"

# Test 5: Invalid maze file (maze data not a rectangle)
echo "Test 5: Invalid maze file (maze data not a rectangle)"
./maze test_data/invalid_maze_4.txt > output.txt
assert_equals "Error: Invalid maze file. Maze data must be a rectangle with walls (#), paths ( ), starting point (S), and exit (E)." "$(cat output.txt)"

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