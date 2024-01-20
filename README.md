# Computer Graphics 2D Basics with GLUT

This repository contains a simple C program demonstrating 2D graphics using the OpenGL Utility Toolkit (GLUT). The program creates a window and draws a square that can be manipulated using keyboard input. The primary features include:

- **Square Manipulation:** Use keyboard inputs ('w', 'a', 's', 'd', arrow keys) to move and scale a green square on the screen.
- **Visual Feedback:** A label at the top of the window displays information about the last pressed key and its corresponding action.
- **Rotation Animation:** The square rotates continuously, adding a dynamic visual element to the graphics.

![2dbasicsglut](https://github.com/kodiidok/glut-computer-graphics-2d-primitives-and-basics/assets/88420631/ed24517d-f7c0-4ec5-b1b8-4e42718f5404)

## Features

- **Square Drawing:** Utilizes OpenGL to draw a simple green square on a black background.
- **Circle Drawing:** Implements a function to draw a green circle with specified radius and segments.
- **Axes Drawing:** Renders red (x-axis) and blue (y-axis) lines to represent coordinate axes.
- **Keyboard Interaction:** Responds to both regular and special (arrow keys) keyboard inputs for square movement and scaling.
- **Label Display:** Shows a label indicating the last pressed key and its associated action.
- **Rotation Animation:** Implements a timer function for continuous rotation of the square.

## Usage

1. Clone the repository to your local machine.
   ```bash
   git clone https://github.com/your-username/computer-graphics-2d-basics-glut.git
   ```

2. Open the project in an OpenGL/GLUT compatible development environment, such as Visual Studio.

3. Build and run the project to see the 2D graphics window with interactive square manipulation.

**Note:** Make sure to have the necessary GLUT and OpenGL dependencies installed to run the program successfully.
