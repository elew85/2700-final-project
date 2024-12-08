#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>

using namespace std; 

struct song {
  string title;
  string artist;
  string genre; 
  float duration;
  song* next;
  song* prev; 
};

class Playlist {
public:
  Playlist();

  song* initSong(string title, string artist, string genre, float duration);

  void AddNewSong(string title, string artist, string genre, float duration);

  void PlaySong();

  void Pause();

  void NextSong();

  void PrevSong();

  void RemoveSong();

  void Restart();

  void ReadPlaylist(); 

private:
  song* first;
  song* last; 
  float trt; 
};

#endif 