#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

using namespace std; 

//create song metadata object
struct song {
  string title;
  string artist;
  string genre; 
  int duration;
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

  void MoveToBottom(string title);
  
  void ReadPlaylist(); 

  void ClearPlaylist();

  // Player Controls
  void StartPlaylist();

  void Pause();

  void NextSong(song* cursor);

  void PrevSong(song* cursor);

  void Loop(); 

  void Restart();

private:
  song* first;
  song* last; 
  int trt; 
  int song_count; 
};

#endif 