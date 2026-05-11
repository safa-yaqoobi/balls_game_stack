#Research Problem

Sorting problems are common in computer science. This project uses a simple ball sorting game to show how a Stack data structure works. The player moves colored balls between tubes until each tube has only one color.

#Motivation

The goal was to build a small game using the Stack concept learned in class. Instead of just making a regular stack program, turning it into a game makes it more fun and easier to understand how push and pop work in real life.

#Control Flow

The game starts by filling 3 tubes with random colored balls. The 4th tube is empty. The player picks a tube to move from and a tube to move to. The top ball moves if the destination tube is not full. The game keeps going until each tube has all the same color. Then the win message shows up.

#Project Structure

The project has two main classes:
• Stack class — handles the balls inside each tube. Has push, pop, isEmpty, isFull, and allsame functions.
• Game class — controls the game. Has startGame to fill tubes, displayGame to show state, moveBall to move balls, checkWin to check if player won, and start to run the game loop.
Technologies Used
• C++ — main programming language
• Stack data structure — used to store balls in each tube
• OOP (classes) — Stack and Game are separate classes
#How to Run

• Open the file in any C++ compiler like Code::Blocks or VS Code.
• Compile and run the program.
• Enter the tube number to move from, then the tube number to move to.
• Keep moving balls until all tubes are sorted to win!
