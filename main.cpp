#include "./playlist.h" 
#include "./playlist.cpp"
#include <iostream>

using namespace std;

int main() {
 bool end_program = false; 
 string state;
 
 Playlist my_playlist; 
 
 //Pre-loaded playlist 
 my_playlist.AppendNewSong("Grace", "Jeff Buckley", "Rock", 210); 
 my_playlist.AppendNewSong("Blue in Green", "Miles Davis", "Jazz", 337); 
 my_playlist.AppendNewSong("Negative Space", "Queens of the Stone Age", "Rock", 256);
 my_playlist.AppendNewSong("Castles Made of Sand", "Jimi Hendrix", "Rock", 286);
 my_playlist.ReadPlaylist(); 
 my_playlist.RemoveSong("Castles Made of Sand");
 my_playlist.ReadPlaylist();
 my_playlist.RemoveSong("All My Life");
 my_playlist.AppendNewSong("Broken Man", "St. Vincent", "Rock", 234);
 my_playlist.ReadPlaylist();

 my_playlist.MoveToTop("Negative Space");
 my_playlist.ReadPlaylist(); 

 my_playlist.MoveToTop("Blue in Green");
 my_playlist.ReadPlaylist(); 

 while(!end_program){
    cout << "Enter a command ('M' displays menu): " << endl;
    cin >> state;
    if(state == "m"){
        Options(); 
    }
    if(state == "p"){
       my_playlist.StartPlaylist();
    }
    if(state == "q"){
       end_program = true; 
       cout << "Goodbye!" << endl;
    }
    else {
        cout << "Not a valid option..." << endl;
    }
 }
 return 0; 
}