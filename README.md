# COMPUTER-GRAPHICS
OpenGL with C++

Setup:

https://github.com/zamansheikh/OpenGLWithVsCodeWin-Linux<br/>
or,<br/>
for Debian,
```
sudo apt install freeglut3-dev mesa-common-dev libxi-dev
```
for Fedora,
```
sudo dnf install freeglut mesa-libGL-devel mesa-libGLU-devel libXi-devel
```
for Arch,
```
sudo pacman -S freeglut-devel sudo pacman -S freeglut sudo pacman -S glu
```
This installs FreeGLUT, OpenGL development libraries, and XInput2 headers.<br/><br/>
https://www.youtube.com/watch?v=bi-NvsFKcZg (Windows)
<br/><br/>
## Compile and run 
Linux:
```
g++ test.cpp -o test -lglut -lGLU -lGL && ./test
```
Windows:
```
g++ minar.cpp -o minar -lopengl32 -lfreeglut -lglu32 -lglew32 -lglfw3 -lgdi32 -lmingw32
```
```
./minar
```
