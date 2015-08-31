This is my submission for my programming class. The task was to create a program, that had some sort of menu.
Bonus points were given if the program recreated the classic top menu programs from the DOS era had (i.e. Free Pascal).
Of course, I decided to do that, and venture into the unknown (read - C++11) while at it. Of course it isn't a complete
implementation, as I value my sanity, but the only thing that I didn't really implement were hotkeys.

The project, as it is, can be controlled by arrow keys. As for how to set the menus up, ProgVal.cpp (the entry point
for the project) displays that quite nicely. The classes are defined in MenuClasses.h.

colours.h contains #defines for some colours used. Note that this uses the Win32 API way of setting console colours and
moving the cursor (found in HelperFunctions.cpp). As far as the code goes though, it has no documentation of any sort
(comments etc.) The class' function names _SHOULD_ be enough to understand what a specific function does. Crappy, I know.

I'm putting this up to perhaps helps someone in the future who has similar coursework. Of course I advise to only use this
as a reference (sure will beat trying to understand the code that I haven't commented), but hey, you're the boss.
 
Code licensed under Beerware license. Go nuts with it.
