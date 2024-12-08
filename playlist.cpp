#include "playlist.h"
#include <unistd.h>

using namespace std;

Playlist::Playlist(){
  first = NULL;
  last = NULL;
  trt = 0; 
  song_count = 0;
}

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

void Playlist::StartPlaylist(){
  bool completed = false; 
  song* cursor = this->first; 
  float time_remaining = this->trt; 
  
  while(!completed){
    cout << "Now Playing: " << cursor->title << " by " << cursor->artist << endl;
    time_remaining -= cursor->duration; 
    if(cursor->next != NULL){
      cout << "-------------" << endl; 
      cout << "Up Next: " << cursor->next->title << " by " << cursor->next->artist << endl;
      
    }
    cout << "Time Remaining: " << time_remaining << endl; 
    sleep(20); 
    if(cursor->next == NULL){
      completed = true;
      cout << "End of playlist! " << endl; 

    }
    else{
      cursor = cursor->next; 
    }
  }
}

void Playlist::Pause(){}

void Playlist::NextSong(){}

void Playlist::PrevSong(){}

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

void Playlist::Restart(){}

void Playlist::ReadPlaylist(){
  song* cursor = this->first;
  cout << "----------" << endl;
  while(cursor != NULL){
    cout << "Artist: " << cursor->artist << endl;
    cout << "Title: " << cursor->title << endl;
    cout << "Genre: " << cursor->genre << endl; 
    cout << "Duration: " << cursor->duration << endl;
    cout << "----------" << endl;
    cursor = cursor->next; 
  }
  cout << song_count << " total songs" << endl; 
  cout << "Total Playlist Runtime (sec): " << trt << endl; 
  cout << "----------" << endl;
}