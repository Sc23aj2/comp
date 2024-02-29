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
if grep -q "Error: Incorrect maze file. Width and height must be integers." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# if height and width are out of range
echo "Test 3: Invalid maze file (width and height out of range)"
./maze test_data/incorrect_maze_2.txt > output.txt
if grep -q "Error: Incorrect maze file. Width and height are out of range."  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Not in a rectangular shape
echo "Test 4: Invalid maze file (maze shape not rectangular)"
./maze test_data/incorrect_maze_3.txt > output.txt
if grep -q "Error: each row and column should be the same length"  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Irregular height
echo "Test 5: Invalid maze file (irregular height)"
./maze test_data/incorrect_maze_4.txt > output.txt
if grep -q "Error: irregular height"  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Irregular width
echo "Test 6: Invalid maze file (irregular width)"
./maze test_data/incorrect_maze_5.txt > output.txt
if grep -q "Error: irregular width"  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# When the player moves into the wall
echo "Test 7: Player moves into a wall"
./maze test_data/correct_maze.txt Inputs/move_into_a_wall.txt > output.txt
if grep -q "Error: Wall detected." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi



# Testing, when a player moves off the map on the right side
echo "Test 8: Player moves off the map"
./maze test_data/correct_maze2.txt Inputs/moves_out_of_the_map_right.txt > output.txt
if grep -q "Error: Player is out of the map." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi


# Moving through a correct path
echo "Test 9: Player moves through a correct path"
./maze test_data/correct_maze2.txt Inputs/inputs2.txt > output.txt
if grep -q  "
##########
#        
#  S####   
#     ##   
#  E  ##   
##########"  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# When the player wins the game
echo "Test 10: Player wins the game"
./maze test_data/correct_maze2.txt Inputs/inputs3.txt > output.txt
if grep -q "Congratulations! You have won the game!"  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi


# 'M' works for veiwing the map
echo "Test 11: Player enters 'M' to view the map"
./maze test_data/correct_maze2.txt Inputs/input_to_view_map.txt > output.txt
if grep -q "
##########
#S        
#  ####   
#     ##   
#  E  ##   
##########" output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi


# for wrong commands given in the input
echo "Test 11: Incorrect command"
./maze test_data/correct_maze2.txt Inputs/input4.txt > output.txt
if grep -q  "Error: Incorrect commands."  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# for no command arguments
echo "Test 12: No arguments provided"
./maze
if [ $# -eq 0 ]; then
  echo "FAIL: no arguments provides"
  exit 1
else
  echo "PASS: more than one arguments provided"
fi

# Successful loading of the map
echo "Test 13: Successful loading of the map file"
./maze test_data/correct_maze.txt > output.txt
if grep -q "
##########
#S      E#
#   #####
#       #
##### # #
#     # #
##### # #
#       #
##### # #
##########" output.txt; then
echo "PASS"
else
  echo "FAIL"
fi

# Failure in loading of an empty file
echo "Test 14: Failure to load an empty file"
./map test_data/empty.txt > output.txt
if grep -q "Error: File is empty."  output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

# the ending is completely blocked
echo "Test 15: Ending is blocked"
./maze test_data/blocked_ending.txt > output.txt
if grep -q "Error: Ending is completely blocked." output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

# the Starting is completely blocked
echo "Test 16: Starting is blocked"
./maze test_data/blocked_starting.txt > output.txt
if grep -q "Error: Starting is completely blocked." output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

# Incorrect maze file with no starting point
echo "Test 17: No starting point"
./maze test_data/no_starting.txt > output.txt
if grep -q "Error: There is no starting point." output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

# Incorrect maze file with no ending point
echo "Test 17: No ending point"
./maze test_data/no_ending.txt > output.txt
if grep -q "Error: There is no ending point." output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

# Testing, when a player moves off the map on the top side
echo "Test 18: Player moves off the map from the top side"
./maze test_data/correct_maze3.txt Inputs/moves_out_of_the_map_top.txt > output.txt
if grep -q "Error: Player is out of the map." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Testing, when a player moves off the map on the left side
echo "Test 19: Player moves off the map from the left side"
./maze test_data/correct_maze4.txt Inputs/moves_out_of_the_map_left.txt > output.txt
if grep -q "Error: Player is out of the map." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Testing, when a player moves off the map on the bottom side
echo "Test 20: Player moves off the map from the bottom side"
./maze test_data/correct_maze5.txt Inputs/moves_out_of_the_map_bottom.txt > output.txt
if grep -q "Error: Player is out of the map." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# Testing for no input
echo "Test 21: No input file"
./maze test_data/correct_maze.txt Inputs/no_input.txt > output.txt
if grep -q "Error: No input file detected" output.txt; then
    echo "PASS"
else
    echo "FAIL"
fi

