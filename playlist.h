#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

using namespace std; 

//create song metadata object
struct song {
  string title;
  string artist;
  string genre; 
  float duration;
  song* next;
  song* prev; 
};

void MainMenu();

void EditMenu();

class Playlist {
public:
  Playlist();
 
  song* initSong(string title, string artist, string genre, float duration);
  
  // Playlist edit controls
  void AppendNewSong(string title, string artist, string genre, float duration);

  void RemoveSong(string title);

  void MoveToTop(string title);

  void MoveToEnd(string title);
  
  void ReadPlaylist(); 

  void ClearPlaylist();

  // Player Controls
  void StartPlaylist();

  void Pause();

  void NextSong();

  void PrevSong();

  void Restart();

private:
  song* first;
  song* last; 
  float trt; 
  int song_count; 
};

#endif 