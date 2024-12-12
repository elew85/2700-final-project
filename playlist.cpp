#include "playlist.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void MainMenu(){
  cout << endl << "D = Display Current Playlist " << endl;
  cout << "E = Open Edit Menu " << endl;
  // cout << "A = Add New Song " << endl;
  // cout << "R = Remove Song " << endl;
  // cout << "T = Move song to Top of Playlist " << endl;
  // cout << "B = Move song to Bottom of Playlist " << endl;
  cout << "S = Start Playlist " << endl;
  cout << "Q = Quit Program " << endl << endl;
}

void EditMenu(){
// to include the editing options
  cout << endl << "EDIT MENU: " << endl; 
  cout << "A = Add New Song " << endl;
  cout << "R = Remove Song " << endl;
  cout << "T = Move song to Top of Playlist " << endl;
  cout << "B = Move song to Bottom of Playlist " << endl << endl;
}

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

// Playlist edit controls
void Playlist::AppendNewSong(string title, string artist, string genre, float duration){
  song* new_song = initSong(title, artist, genre, duration);
  song* cursor = first;
  //check if playlist is empty
  if(cursor == NULL){
    first = new_song;
    last = new_song;  
    this->trt += duration; 
    this->song_count++; 
    return;
  }
  //add song to end of current list, add duration & point to previous
  // FIX: shouldn't need to traverse entire list if only appending to end
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
      if(cursor->next != NULL ){
        cursor->next->prev = cursor->prev;
      }
      if(cursor->prev != NULL){
        cursor->prev->next = cursor->next;
      }
      if(cursor == first){
        first = cursor->next;
      }
      if(cursor == last){
        last = cursor->prev; 
      }
      this->trt -= cursor->duration; 
      this->song_count--; 
      delete cursor;
      found = true; 
      cout << endl << "Successfully removed '" << title << "'" << endl << endl; 
    }
    else {
      cursor = cursor->next; 
     }
   }
}

void Playlist::MoveToTop(string title){
//moves song to top of list
  song* cursor = this->first; 
  while(cursor != NULL){
    if(cursor->title == title){
      cursor->prev->next = cursor->next;
      if(cursor->next != NULL){
        cursor->next->prev = cursor->prev; 
      }
      cursor->next = this->first;
      this->first->prev = cursor; 
      cursor->prev = NULL;  
      this->first = cursor;
      cout << endl << "Successfully moved '" << title << "' to the top!" << endl << endl;
      return; 
    }
    else {
      cursor = cursor->next; 
    }
  }
  return; 
}

void Playlist::MoveToBottom(string title){
//moves song to bottom of list
  song* cursor = this->first;
  while(cursor != NULL){
    if(cursor->title == title){
      if(cursor == first){
        cursor->next->prev = NULL;
        first = cursor->next; 
        cursor->prev = last;
        last->next = cursor;
        cursor->next = NULL;
        last = cursor; 
        cout << "Successfully moved '" << title << "' to the end of list!" << endl;
        return;
      }
      else if(cursor == last){
        cout << "'" << title << "' is already last!" << endl; 
        return;
      }
      else{
        cursor->prev->next = cursor->next;
        cursor->prev = last;
        last->next = cursor; 
        cursor->next = NULL;
        last = cursor;
        cout << "Successfully moved '" << title << "' to the end of list!" << endl;
        return;
      }
    }
    else {
      cursor = cursor->next;
      }
  }
  return; 
}

void Playlist::ReadPlaylist(){
  //FIX: infinite loop when only one song
  if(first == NULL){
    cout << "Playlist is empty!" << endl;
    return; 
  }
  song* cursor = this->first;
  int track_num = 1;   
  cout << "----------" << endl;
  while(cursor != NULL){
    cout << track_num << ". " << cursor->title << " by " << cursor->artist << endl;
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
        cursor = cursor->next;
    }
  }
}

void Playlist::Pause(){}

void Playlist::NextSong(){}

void Playlist::PrevSong(){}

void Playlist::Loop(){}

void Playlist::Restart(){}