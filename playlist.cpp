#include "playlist.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void Options(){
  cout << endl << "D = Display Current Playlist " << endl;
  cout << "P = Start Playlist " << endl;
  cout << "Q = Quit Program " << endl << endl;
}

Playlist::Playlist(){
  first = NULL;
  last = NULL;
  trt = 0; 
  song_count = 0;
}

// Playlist edit controls
song* Playlist::initSong(string title, string artist, string genre, float duration){
  song* new_song(new song); 
  new_song->title = title;
  new_song->artist = artist;
  new_song->genre = genre; 
  new_song->duration = duration;
  new_song->next = NULL;
  new_song->prev = NULL; 
  return new_song; 
}

void Playlist::AppendNewSong(string title, string artist, string genre, float duration){
  song* new_song = initSong(title, artist, genre, duration);
  song* cursor = first;
  //check if playlist is empty
  if(cursor == NULL){
    first = new_song; 
    this->trt += duration; 
    this->song_count++; 
    return;
  }
  //add song to end of current list, add duration & point to previous
  else {
    while(cursor->next != NULL){
      cursor = cursor->next;
   }
   cursor->next = new_song; 
   cursor->next->prev = cursor; 
   this->last = new_song; 
   this->trt += duration;
   this->song_count++;  
   return;
  }
}

void Playlist::RemoveSong(string title){
   song* cursor = this->first; 
   bool found = false; 

   while(!found){
    if(cursor == NULL){
      cout << "'" << title << "' not found... " << endl;
      return; 
     }
    if(cursor->title == title){
      cursor->prev->next = cursor->next;
      this->trt -= cursor->duration; 
      this->song_count--; 
      delete cursor;
      found = true; 
    }
    else {
      cursor = cursor->next; 
     }
   }
}

void MoveToTop(){}
//moves song to top of list

void MoveToEnd(){}
//moves song to bottom of list

void Playlist::ReadPlaylist(){
  song* cursor = this->first;
  int track_num = 1;   
  cout << "----------" << endl;
  while(cursor != NULL){
    cout << track_num << ". " << cursor->title << " by " << cursor->artist << endl;
    // cout << "Title: " << cursor->title << endl;
    // cout << "Genre: " << cursor->genre << endl; 
    // cout << "Duration: " << cursor->duration << endl;
    // cout << "----------" << endl;
    cursor = cursor->next; 
    track_num++; 
  }
  cout << endl << song_count << " total songs" << endl; 
  cout << "Total Playlist Runtime (sec): " << trt << endl; 
  cout << "----------" << endl;
}

void ClearPlaylist();
//Clears all songs in playlist

//Player Controls 
void Playlist::StartPlaylist(){
  bool completed = false; 
  song* cursor = this->first; 
  string state; 

  float time_remaining = this->trt; 
  int songs_remaining = this->song_count; 

   cout << "++++++++++" << endl;
   cout << "CONTROLS:" << endl;
   cout << "Enter 'P' to Pause/Resume; '<' for Previous; '>' for Next;'R' to restart; 'S' to stop"<< endl; 
   cout << "++++++++++" << endl;
  
  while(!completed){
    state = "P";
    cout << "Now Playing: " << cursor->title << " by " << cursor->artist << endl; 
    songs_remaining--; 
    if(cursor->next != NULL){
      cout << "-------------" << endl; 
      cout << "Up Next: " << cursor->next->title << " by " << cursor->next->artist << endl;
      
    }
    cout << "Songs Remaining: " << songs_remaining << endl; 
    cout << "Time Remaining: " << time_remaining << endl; 

    sleep(cursor->duration/10); //variable play duration, but shortened for demonstration
    time_remaining -= cursor->duration;
    if(cursor->next == NULL){
      completed = true;
      cout << "End of playlist! " << endl; 
    }
    else{
      // cin >> state;
      // state = toupper(state);
      // if(state = '>'){
        cursor = cursor->next;
      // }
      // else if (state = 'S'){
      //   completed = true;
      }
    // }
  }
}

void Playlist::Pause(){}

void Playlist::NextSong(){}

void Playlist::PrevSong(){}

void Playlist::Restart(){}