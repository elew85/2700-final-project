#include "./playlist.h" 
#include "./playlist.cpp"
#include <iostream>

using namespace std;

int main() {
 Playlist my_playlist; 
 
 my_playlist.AppendNewSong("Grace", "Jeff Buckley", "Rock", 210); 
 my_playlist.AppendNewSong("Blue in Green", "Miles Davis", "Jazz", 337); 
 my_playlist.AppendNewSong("Negative Space", "Queens of the Stone Age", "Rock", 256);
 my_playlist.AppendNewSong("Castles Made of Sand", "Jimi Hendrix", "Rock", 286);
 my_playlist.ReadPlaylist(); 
 my_playlist.RemoveSong("Castles Made of Sand");
 my_playlist.ReadPlaylist();
 my_playlist.RemoveSong("All My Life");
 my_playlist.StartPlaylist(); 

 return 0; 
}