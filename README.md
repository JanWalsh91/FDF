# FDF

FDF - making elevations maps more beautiful that ever

Covered concepts:
- using a graphics library
- handling windows and images
- handling the user's keyboard and mouse inputs
- line rasterization
- creating a basic GUI
- using matrices for rotations and other transormations!
- creating an isometric porjection
- working with RGB
- banishing segfaults and memory leaks to the nether

FDF (Fil de fer, or wirefram) is takes a file which may look like this:

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0  3  3  0  0  3  3  0  0  0  3  3  3  3  3  0  0  0

0  0  3  3  0  0  3  3  0  0  0  0  0  0  0  3  3  0  0

0  0  3  3  0  0  3  3  0  0  0  0  0  0  0  3  3  0  0

0  0  3  3  3  3  3  3  0  0  0  0  3  3  3  3  0  0  0

0  0  0  3  3  3  3  3  0  0  0  3  3  0  0  0  0  0  0

0  0  0  0  0  0  3  3  0  0  0  3  3  0  0  0  0  0  0

0  0  0  0  0  0  3  3  0  0  0  3  3  3  3  3  3  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0


Each number represents the height coordinate of a point at the 2D position in the table. Our task was to translate this into a visual height map. The map above produced the following output:

![42 with instructions](https://github.com/JanWalsh91/FDF/blob/master/screenshots/42_with_instruction.png "42 with instructions")

Each number can also be followed by a color code, and additional color palettes are availble by hitting 'c'.

![Elem1](https://github.com/JanWalsh91/FDF/blob/master/screenshots/Elem1.png "more colors!")

You can rotate about each axis, translate and scale the map:

![Rotations](https://github.com/JanWalsh91/FDF/blob/master/screenshots/Elem1_with_rotation_scale_and_translate.png "rotationings!")

Here are some more screenshots:

![Mars Elevation Map](https://github.com/JanWalsh91/FDF/blob/master/screenshots/Mars.png "Mars Elevation Map")
![Julia Factal](https://github.com/JanWalsh91/FDF/blob/master/screenshots/Julia_Factal.png "Julia Factal")


Should you have any questions or suggestions, feel free to send me an email at **jwalsh@student.42.fr**.
