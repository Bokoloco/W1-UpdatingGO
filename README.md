# Project
This project was made for the course of Programming 4 in the second year of DAE. It was made by Bo Wauters of 2GD10.

# Minigin

Minigin is a very small project using [SDL2](https://www.libsdl.org/) and [glm](https://github.com/g-truc/glm) for 2D c++ game projects. It is in no way a game engine, only a barebone start project where everything sdl related has been set up. It contains glm for vector math, to aleviate the need to write custom vector and matrix classes.

[![Build Status](https://github.com/avadae/minigin/actions/workflows/msbuild.yml/badge.svg)](https://github.com/avadae/msbuild/actions)
[![GitHub Release](https://img.shields.io/github/v/release/avadae/minigin?logo=github&sort=semver)](https://github.com/avadae/minigin/releases/latest)


# Patterns

This engine uses patterns from the book '[Game Programming Patterns](https://gameprogrammingpatterns.com/)':
* Game Loop
* Update method
* Command: To handle inputs of the player
* Observer 
* EventQueue: For the sound
* Component 
* State: For the enemies, so they move around