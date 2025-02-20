# Assignment_03

**Moving Rectangles**

In this assignment we'll get a better understanding of our game loop as well as SDL Rendering. You will be rendering multiple rectangles of differing sizes and different starting movement directions in your SDL window. The rectangles should bounce off the walls of the window and never go past the edges of the window.

**Requirements**

**1. Modularize Your Code**

Your directory structure should include a bin, src, and include directory inside of this Assignment Directory. Your bin folder will hold your executable, your include folder will hold your header files, and your src folder will hold your source code.

**2. Application Class**

Your application class should have input, update, render, and loop functions. Your update and render functions will be responsible for rendering ALL of the rectangles.

**3. Rectangle Class**

Create a new class "Rectangle". This class will store all data about a single rectangle as well as functionality for updating the rectangles position and rendering the rectangle. This class will be responsible for updating and rendering a single rectangle (itself).

**4. Rectangle Functionality**

As mentioned above, each rectangle should have a randomized size (within a reasonable limit) and a randomized movement direction. Your rectangles should bounce off the walls of the SDL window in the opposite direction and never move past the edges of the SDL window. You will likely need to look up how SDL Primitives are drawn in order to better understand how to keep the rectangles within the SDL window.

**5. Command-line Functionality**

Your program should add functionality for handling a single command-line input to change the number of rectangles being rendered when your program starts.

A sample command-line would be: ./bin/prog 30 -- This would render 30 rectangles.

**No specifics required, but keep them reasonable**
* Window dimensions
* Rectangle movement velocity
* Rectangle size ranges
* Frame rate (not required at all as it will be discussed later)
* Rectangle spawn locations

**How to compile and run your program**

Your code may compile with different commands based on your architecture, but a sample compilation command may look like: g++ -std=c++20 ./src/*.cpp `pkg-config --cflags --libs sdl2` -o /bin/prog.

Note: Your triangles may move at random speeds throughout your application running. They may slow down or speed up randomly. This is okay as long as they continue to move.

**Submission/Deliverables**

Submission

Commit all of your files to github, including any additional files you create.
Do not commit any binary files unless told to do so.
Do not commit any 'data' files generated when executing a binary.
Submit your GitHub link on Canvas.

Deliverables

You need to commit your code to this repository.

Q: Can I do more than is required?
A: Sure, have as much fun with it as you like!

Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

![](../Media/MovingRectangles.mov)
