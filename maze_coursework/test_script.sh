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



# Testing, when a player moves off the map
echo "Test 8: Player moves off the map"
./maze test_data/correct_maze2.txt Inputs/moves_out_of_the_map.txt > output.txt
if grep -q "Error: Player out of the map." output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi


# Moving through a correct path
echo "Test 9: Player moves through a correct path"
./maze test_data/correct_maze2.txt Inputs/inputs2.txt > output.txt
if grep -q  "Error: Player out of the map."  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi

# When the player wins the game
echo "Test 10: Player wins the game"
./maze test_data/correct_maze2.txt Inputs/inputs3.txt > output.txt
if grep -q "
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


# 'M' works for veiwing the map
echo "Test 11: Player enters 'M' to view the map"
./maze test_data/correct_maze2.txt > output.txt
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
./maze test_data/correct_maze2.txt Inputs/inputs4.txt > output.txt
if grep -q  "Error: Incorrect commands."  output.txt; then
    echo "PASS"
else
    echo "FAIL" 
fi



