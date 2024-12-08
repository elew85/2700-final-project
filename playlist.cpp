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

void Playlist::AddNewSong(string title, string artist, string genre, float duration){
  song* new_song = initSong(title, artist, genre, duration);
  song* cursor = first; 
  this->trt += duration; 
  if(cursor == NULL){
    first = new_song; 
    return;
  }
  return;
}

void Playlist::PlaySong(){}

void Playlist::Pause(){}

void Playlist::NextSong(){}

void Playlist::PrevSong(){}

void Playlist::RemoveSong(){}

void Playlist::Restart(){}

void Playlist::ReadPlaylist(){
  cout << "artist: " << first->artist << endl;
  cout << "title: " << first->title << endl;
  cout << "genre: " << first->genre << endl; 
  cout << "duration: " << first->duration << endl;
}