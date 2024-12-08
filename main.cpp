#include <iostream>
#include "./playlist.h"   

using namespace std;

int main() {
 Playlist my_playlist; 
 
 my_playlist.AddNewSong("Grace", "Jeff Buckley", "Rock", 210.0); 
 my_playlist.ReadPlaylist(); 

 return 0; 
}