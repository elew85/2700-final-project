Eric Lewis
CU ID: erle6256
Github: elew85
CSPB 2270 Final Project - Fall 2024

Program: "MY PLAYLIST"

The contents of the "My Playlist" program demonstrates a faux music playlist that is implemented with a doubly-linked list. A Playlist class has been created containing linked "song" structures and Public and Private member functions and variables, respectively.
This does not actually play audio media, however it demonstrates how a user could create and make commonly used edits their own personalized music collection.

In a doubly-linked list, the song nodes link both to the next and to the previous song. This can allow for more efficient access of list elements than a singly-linked list which can only link to the next item or playing in reverse order as demonstrated. With an actual 
media player or additional libraries, a user could also more easily navigate through their songs in real time. Because most songs are an average of ~3 min in duration and the count of songs in a playlist likely is < 100, I decided that the O(N) traverse limitations of a
doubly-linked list would not present a major concern for this use case. 

HOW TO RUN PROGRAM:
First compile "main.cpp" and output with designated filename. 
// IMPORTANT NOTE: may need to add -std=c++11 to compiler like example: g++ -std=c++11 main.cpp -o playlist.exe to avoid errors from ASCII string literal. 
Once you run the executable, the program will prompt you as the user with various menu options to edit and run through an abridged demonstration of how it may work.
5 songs are pre-loaded for you as a starting point, but you can either add new music or else clear entirely and start freshly from scratch.

Enjoy!

Credits: 
ZyBooks - Doubly Linked Lists: https://learn.zybooks.com/zybook/COLORADOCSPB2270Fall2024/chapter/5/section/7
ASCII Art Generator https://patorjk.com/software/taag/#p=display&f=Ogre&t=Goodbye%0A
C++ Library Functions: https://cplusplus.com/doc/tutorial/
