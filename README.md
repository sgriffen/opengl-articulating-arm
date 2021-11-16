Theodore Davis  tcdavis  
Sean Griffen    griffens

# opengl-articulating-arm
Articulating Arm in OpenGL for ComS 336

## Project Description
The scene will default to a projection view of the scene. You will be able to see the red upper arm, green lower arm, and blue hand. We made the hand a cone rather than a cylinder for stylistic reasons.

## How to use
Run the following commands in the top directory to compile the program and then run it. Assuming you have the follow libraries preinstalled and ready to link: GLUT, GLU, and OpenGL.
```bash
make release
./release/gl-arm
```

To interact with the scene he is a list of commands that will affect the shapes on screen and a description of their effect.

- `x` : Translate the arm in the world-space -x direction
- `X` : Translate the arm in the world-space +x direction
- `y` : Translate the arm in the world-space -y direction
- `Y` : Translate the arm in the world-space +y direction
- `z` : Translate the arm in the world-space -z direction
- `Z` : Translate the arm in the world-space +Z direction
- `u` : Rotate the arm at the shoulder about the upper arm's x axis in the positive direction
- `U` : Rotate the arm at the shoulder about the upper arm's x axis in the negative direction
- `v` : Rotate the arm at the shoulder about the upper arm's y axis in the positive direction
- `V` : Rotate the arm at the shoulder about the upper arm's y axis in the negative direction
- `w` : Rotate the arm at the shoulder about the upper arm's z axis in the positive direction
- `W` : Rotate the arm at the shoulder about the upper arm's z axis in the negative direction
- `c` : Curl the forearm at the elbow about the forearm's x axis in the positive direction
- `C` : Curl the forearm at the elbow about the forearm's x axis in the negative direction
- `r` : Rotate the forearm at the elbow about the forearm's z axis in the positive direction
- `R` : Rotate the forearm at the elbow about the forearm's z axis in the negative direction
- `p` : Pitch the hand at the wrist about the hand's x axis in the positive direction
- `P` : Pitch the hand at the wrist about the hand's x axis in the negative direction
- `a` : Yaw the hand at the wrist about the hand's y axis in the positive direction
- `A` : Yaw the hand at the wrist about the hand's y axis in the negative direction
- `o` : Toggle orthographic/perspective projection - The window title will let you know which mode you're in
- space: Toggle the drawing style for the cylinders. Switch between line, silhouette, point, and fill
- esc: exit the program
