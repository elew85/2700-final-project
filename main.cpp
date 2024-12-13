#include "./playlist.h" 
#include "./playlist.cpp"
#include <iostream>

using namespace std;

int main() {
 bool end_program = false; 
 string state;

 Welcome(); 
 
 Playlist my_playlist; 
 
 //Pre-loaded playlist 
 my_playlist.AppendNewSong("Grace", "Jeff Buckley", "Rock", 210); 
 my_playlist.AppendNewSong("Blue in Green", "Miles Davis", "Jazz", 337); 
//  my_playlist.AppendNewSong("Negative Space", "Queens of the Stone Age", "Rock", 256);
//  my_playlist.AppendNewSong("Castles Made of Sand", "Jimi Hendrix", "Rock", 286);
//  my_playlist.AppendNewSong("Broken Man", "St. Vincent", "Rock", 234);
 my_playlist.ReadPlaylist();

 while(!end_program){
    cout << "Enter a command ('M' for main menu): " << endl;
    cin >> state;
    if(state == "m"){
        MainMenu(); 
    }
    else if(state == "p" || state == "P"){
       my_playlist.StartPlaylist();
    }
    else if(state == "d" || state == "D"){
      my_playlist.ReadPlaylist(); 
    }
    else if(state == "e" || state == "E"){
      EditMenu(); 
    }
    else if(state == "t"|| state == "T"){
       string title;
       cout << "Enter the title you wish to move to TOP of list (case-sensitive): " << endl;
       cin.ignore();
       getline(cin, title);  
       my_playlist.MoveToTop(title); 
    }
   else if(state == "b" || state == "B"){
       string title;
       cout << "Enter the title you wish to move to BOTTOM of list (case-sensitive): " << endl;
       cin.ignore();
       getline(cin, title);  
       my_playlist.MoveToBottom(title); 
   }   
   else if(state == "a"|| state == "A"){
       string title, artist, genre, duration;
       float flt_duration;
       cout << "Let's add new music! " << endl;
       cout << "First, enter the song title: " << endl;
       cin.ignore();
       getline(cin, title);
       cout << "Enter the artist name: " << endl;
       cin.ignore();
       //This truncates the first letter of artist name for some reason...
       getline(cin, artist);
       cout << "What is the genre? " << endl;
       cin.ignore();
       getline(cin, genre);
       cout << "How long is the song? (sec) " << endl;
       cin.ignore();
       getline(cin, duration);
       flt_duration = stof(duration);
       my_playlist.AppendNewSong(title, artist, genre, flt_duration); 
   }   
   else if(state == "r"|| state == "R"){
       string title;
       cout << "Enter the title you wish remove (case-sensitive): " << endl;
       cin.ignore();
       getline(cin, title);  
       my_playlist.RemoveSong(title);
    }
    else if(state == "c"|| state == "C"){
       my_playlist.ClearPlaylist(); 
    }
    else if(state == "s"|| state == "S"){
       my_playlist.StartPlaylist(); 
    }
    else if(state == "q"|| state == "Q"){
       end_program = true;
       cout << "==========================================";
       cout << R"(   
   ___                _ _                
  / _ \___   ___   __| | |__  _   _  ___ 
 / /_\/ _ \ / _ \ / _` | '_ \| | | |/ _ \
/ /_\\ (_) | (_) | (_| | |_) | |_| |  __/
\____/\___/ \___/ \__,_|_.__/ \__, |\___|
                              |___/   )" << endl; 
       cout << "==========================================" << endl;
    }
    else {
        cout << "Not a valid option..." << endl;
    }
 }
 return 0; 
}