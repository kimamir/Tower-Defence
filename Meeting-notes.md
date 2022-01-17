# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any

# Meeting 8.12.2021 14:00

**Participants**
1. Kim
2. Meeri
3. Sanni
4. Matias

## Summary of works
All of the group members worked on perfecting the program. Created new maps, difficulty levels, enemy colours, armoured enemy type, tower colours. Finalizing the git repository and polishing it.

## Challenges
We encountered minor challenges with moving the CMakeLists.txt-file into the root folder as we had to change the project source files withing the CMakeLists-file. 

## Actions
Everyone wrote parts of the documentiation and readme-files.

## Project status 
The game works as intended.

### TODOs
Finish the documentation and make sure that the downloadable zip-file (from the git repo) works.

# Meeting 1.12.2021 14:00

**Participants**
1. Kim
2. Meeri
3. Sanni

## Summary of works
Sanni has begun working on a wavespawner in Game.cpp.
Kim and Matias created pushButtons for buying towers and linked them to a handleClick-function.
Meeri made it so towers can be bought and sold (and they appear on the map).

## Challenges
We started working on a wavespawner and a QGraphicsItem to represent 
a tower's range but ran into issues because it would cover the tower's graphics item, preventing the user from interacting with it. Once we resolve
these issues, the enemy waves will generate and start moving along the path. We will start implementing the projectile class once these issues are fixed.

## Actions
1. Kim and Meeri worked on the QGraphicsItem representing a tower's range
2. Sanni worked on the wave spawner

## Project status 
The game map can be generated from a txt-file and towers can be bought, placed and sold via pushButtons.
Difficulty level and enemy waves are read from a txt-file as well.

### TODOs
1. Kim and Meeri will finalize the tower's range object
2. Sanni will finish the wave spawner
3. Matias will work on the projectile class and tower shooting algorithms

# Meeting 24.11.2021 14:00

**Participants**: 
1. Kim
2. Matias
3. Sanni 
4. Meeri

## Summary of works
Learned more about Qt. Finished enemy classes (will add more methods later on), finished some graphicsItem-classes for map tiles.
Running the project now opens up a menu.

## Challenges

1. We had issues gaining access to resource files such as images and .txt files we needed. We finally learned that in Qt Creator,
there must be a special Resource.qrc file that contains all resources for easy access.
2. We experienced challenges with git when all four of us were programming at the same time. Pulling, merging, adding and committing proved troublesome

## Actions

1. Kim wrote tileGraphicsItems and some enemy classes. Created a resource.qrc file to store resources.
2. Matias wrote enemy classes and started working or tower classes
3. Meeri started working on projectile classes
4. Sanni created a start game button for the manu and a text field to import a map from. She also imported a picture for the menu.


## Project status 
A menu opens up when running the application. A map can be imported by writing its name in a text field.

### TODOs
1. Kim and Matias will add tileGraphicsItems to the scene so that the game map will show on the screen when a map is generated.
2. Sanni will start working on enemyGraphicsItems.
3. Meeri will finish the projectile class and start working on towerGraphicsItems.

# Meeting 17.11.2021 14:00

**Participants**: 
1. Kim
2. Matias
3. Sanni 
4. Meeri

## Summary of works
We installed Qt Creator and the needed programs to run the project. We created classes, main and a graphicsl interface.

## Challenges

1. Learning how Qt works. I took us some time to realize that everything we had learned
during the modules was almost useless in Qt. Qt has its own classes and libraries and so we spent a good portion of the week learning
the new development environment.

## Actions
Everyone should learn as much as possible about Qt and get the project started.
1. Kim and Matias created Map-class and wrote a function that reads a .txt-file from which it then saves 
to a 2D vector (private variable) that represents the game map. The function also saves the coordinates of the enemies' path into 
a private member of the class Map.
2. Sanni familiarized herself with the graphical interface and started creating a main window for the game.
3. Meeri wrote the Tile-class which represents game tiles withing the map.


## Project status 
A map and enemy path can be read and generated from a .txt-file.

### TODOs
1. Kim will start writing enemy and tower classes
2. Matias will start writing enemy and tower classes
3. Sanni will link the graphical interface to the previously written Map
4. Meeri will start working on a projectile class that will represent the towers' bullets

# Meeting 9.11.2021 14:00

**Participants**: 
1. Kim
2. Meeri
3. Matias
4. Sanni 

## Summary of works
All of us tried to install the SFML-libraries in order to get started with the project.
After hours of trying, we decided to set up a meeting with our project assistant so he can help us out.
Even with the help of our assistant we could not make it work so we decided to write the project using Qt.

## Challenges

1. Setting up SFML libraries

## Actions
All of the members are going to install Qt Creator and start working on the project


## Project status 
Not started

### TODOs
Everyone should install Qt Creator, clone the git repository and setup the needed programs to run the project.




