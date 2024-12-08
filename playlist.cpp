#include "playlist.h"

using namespace std;

Playlist::Playlist(){
  first = NULL;
  last = NULL;
  trt = 0; 
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
  if(cursor == NULL){
    first = new_song; 
    this->trt += duration; 
    return;
  }
  else {
    while(cursor->next != NULL){
      cursor = cursor->next;
   }
   cursor->next = new_song; 
   cursor->next->prev = cursor; 
   this->last = new_song; 
   this->trt += duration; 
   return;
  }
}

void Playlist::StartPlaylist(){}

void Playlist::Pause(){}

void Playlist::NextSong(){}

void Playlist::PrevSong(){}

void Playlist::RemoveSong(){}

void Playlist::Restart(){}

void Playlist::ReadPlaylist(){
  song* cursor = this->first;
  while(cursor != NULL){
    cout << "----------" << endl;
    cout << "Artist: " << cursor->artist << endl;
    cout << "Title: " << cursor->title << endl;
    cout << "Genre: " << cursor->genre << endl; 
    cout << "Duration: " << cursor->duration << endl;
    cout << "----------" << endl;
    cursor = cursor->next; 
  }

  
}