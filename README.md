MameUI
======

A simple frontend to MAME (Qt 5 based)

#How To Run
There are a few settings to fill in when setting up MameUI locally:
* Provide the path to a text file containing the game list
  * This can be obtained by running `mame -listfull > game_list.txt`
* Provide the path to the roms
* Provide the path the MAME executable

#How To Build
1. Clone the project: 
  * `git clone git@github.com:IdleEngineers/MameUI.git`
2. Create a build directory for CMake to build in: 
  * `mkdir mameui_build`
3. Change to that directory: 
  *`cd mameui_build`
4. Run CMake: 
  * `cmake -G "Unix Makefiles" ../MameUI/`
  * Note: You will need to know more about ![CMake](http://cmake.org) if you want to use something other than Make files to build.
5. Build the project: 
  * `make`
6. Run MameUI: 
  * `cd src/mui_frontend/` 
  * `./MUI`
