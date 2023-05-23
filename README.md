# Fast Mass Spring Simulation

This project will implement the paper "Fast-Simulation of Mass-Spring Systems" by Liu, et al. Work in progress. 

# Dependencies
GLFW (version 3.3.2), GLAD (CORE profile, version 3.3), Visual Studio 2022, Eigen (version 3.4.0)

# Build Instructions
In Visual Studio:

Go to project properties -> Configuration Properties -> VC++ Directories -> Include Directories. Add .\Libraries\include

Go to project properties -> Configuration Properties -> VC++ Directories -> Library Directories. Add .\Libraries\lib

Go to project properties -> Configuration Properties -> Linker -> Additoinal Dependencies -> Add both

glfw3.lib

opengl32.lib

Download Eigen zip file, extract it and rename it eigen. Add it to \Libraries\include

Go to project properties -> Configuration Properties -> C/C++ -> Additional Include Directories -> Add .\Libraries\include\eigen
