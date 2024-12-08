#include "./playlist.h" 
#include "./playlist.cpp"
#include <iostream>

using namespace std;

int main() {
 Playlist my_playlist; 
 
 my_playlist.AddNewSong("Grace", "Jeff Buckley", "Rock", 210); 
 my_playlist.ReadPlaylist(); 

 return 0; 
}