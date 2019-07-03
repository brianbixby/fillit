# Fillit: Solving for the Smallest Square of Tetrominoes

“Given a set of Tetrominoes, find a way to assemble them in the smallest possible square”

I decided to use recursive backtracking to solve this challenge. I chose this approach because fillit requires repeating actions like placing a tetromino, removing a tetromino and increasing the solution square size over and over again until a solutions is found. I’ve split the parts of the project into understanding the problem, validating the input, choosing a data structure and finding a solution.

# The Problem

A Tetrimino block is a shape made up of 4 consecutive characters. You’ve probably seen Tetrominoes in the popular game, Tetris. For the purpose of this puzzle, Tetrominoes are considered fixed, meaning that they cannot be rotated and there are a total of 19 possible pieces that can be provided as input.

The goal of the puzzle is to find the smallest possible square board that the tetrominoes can fit in. When there are multiple solutions possible within the same size square, the solution with the pieces placed in the order they are provided at their top-most left-most positions is correct.

# Validating the Input

The first step was to validate the input. Tetrominoes needed to be passed into my program as a file in the following format.

After writing the basic validation such as checking if the newlines were in the right place, I moved on to the more difficult checks. Specifically, I needed to validate the individual tetromino pieces:

Although I had a complete list of all 19 valid tetrominoes, checking every piece against that list isn’t efficient so I had to come up with a way to validate blocks. I decided the easiest implementation was to count the total number of sides touching:


If I find a single character with zero adjacent blocks, I can discard the tetromino input immediately. As long as there are 6 sides total touching between the characters, I can be sure that the input piece is, in fact, a valid tetromino.

Once I validated the tetrominoes, I was ready to start placing them on a board.

# Choosing Data Structures

The elements I needed to solve this problem were a list of tetrominoes and a square board to try and place the tetrominoes on. I chose to represent each tetrimino as a structure that contained a height, width and integer array that stored the coordinates. For example a vertical tetrimino with a height of 4 and a width of one would have the coordinates [0, 10, 20, 30]. Each coordinate's row equates to coordinate / 10 and the column is coordinate % 10.  I knew I could use recursion while placing the pieces so a singly linked list (queue) was a good option to avoid a stack overflow.

# Solving the Puzzle

To come up with an algorithm to solve the board, I tried manually solving a few simple boards with small pieces. I broke the overall problem down into three smaller problems:

1. Check if a single piece fits on a board, and if so, place that piece on the first available spot on the board. Repeat until the board is full.

2. If the board is full and a solution has not been found, undo the last piece placed on the board and try a different position for it. Repeat until all possible positions for all tetromino pieces have been tried.

3. If all possible solutions on a board have been tried, increase the size of the board and start over with placing the first tetromino. Note that the board starting size = sqrt(# of tetrominoes * 4 characters per tetromino).

# How do I use it?

Alright, so first of all, download/clone this repo:

	git clone https://github.com/brianbixby/fillit.git fillit
	
CD into it and build the executable:
	
	cd fillit
	make

Run the test files

  ./fillit ./tests/valid_0