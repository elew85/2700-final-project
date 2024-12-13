#include "playlist.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void Welcome(){
  cout << R"( 
__       __                  _______   __                      __  __              __     
|  \     /  \                |       \ |  \                    |  \|  \            |  \    
| $$\   /  $$ __    __       | $$$$$$$\| $$  ______   __    __ | $$ \$$  _______  _| $$_   
| $$$\ /  $$$|  \  |  \      | $$__/ $$| $$ |      \ |  \  |  \| $$|  \ /       \|   $$ \  
| $$$$\  $$$$| $$  | $$      | $$    $$| $$  \$$$$$$\| $$  | $$| $$| $$|  $$$$$$$ \$$$$$$  
| $$\$$ $$ $$| $$  | $$      | $$$$$$$ | $$ /      $$| $$  | $$| $$| $$ \$$    \   | $$ __ 
| $$ \$$$| $$| $$__/ $$      | $$      | $$|  $$$$$$$| $$__/ $$| $$| $$ _\$$$$$$\  | $$|  \
| $$  \$ | $$ \$$    $$      | $$      | $$ \$$    $$ \$$    $$| $$| $$|       $$   \$$  $$
 \$$      \$$ _\$$$$$$$       \$$       \$$  \$$$$$$$ _\$$$$$$$ \$$ \$$ \$$$$$$$     \$$$$ 
             |  \__| $$                              |  \__| $$                            
              \$$    $$                               \$$    $$                            
               \$$$$$$                                 \$$$$$$  )" << endl << endl; 

  cout << "Your personalized music queue!" << endl << endl;
  cout << "This comes with the following pre-loaded songs:" << endl << endl; 
}

void MainMenu(){
  cout << endl << "D = Display Current Playlist " << endl;
  cout << "E = Open Edit Menu " << endl;
  cout << "S = Start Playlist " << endl;
  cout << "R = Start Playlist in Reverse " << endl;
  cout << "Q = Quit Program " << endl << endl;
}

void EditMenu(){
// to include the editing options
  cout << endl << "EDIT MENU: " << endl; 
  cout << "A = Add New Song " << endl;
  cout << "X = Remove Song " << endl;
  cout << "T = Move song to Top of Playlist " << endl;
  cout << "B = Move song to Bottom of Playlist " << endl;
  cout << "C = Clear Playlist " << endl << endl;
}

Playlist::Playlist(){
  first = NULL;
  last = NULL;
  trt = 0; 
  song_count = 0;
}

song* Playlist::initSong(string title, string artist, string genre, int duration){
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
void Playlist::AppendNewSong(string title, string artist, string genre, int duration){
  song* new_song = initSong(title, artist, genre, duration);
  if(this->first == NULL){
    first = new_song;
    last = new_song;  
    this->trt += duration; 
    this->song_count++; 
    return;
  }
  //add song to end of current list, add duration & point to previous
  else {
   this->last->next = new_song;
   new_song->prev = this->last;
   this->last = new_song; 
   this->trt += duration;
   this->song_count++;  
   cout << "Added " << new_song->title << " by " << new_song->artist << endl << endl; 
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
  //Prints all current songs in playlist
  if(first == NULL){
    cout << endl << "Your playlist is empty. Time to add some music!" << endl << endl;
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

void Playlist::ClearPlaylist(){
//Clears all songs in playlist
  song* cursor = this->last;
  while(cursor != NULL){
    song* temp = cursor;
    cursor = cursor->prev;
    delete temp;
  }
  this->first = NULL;
  this->last = NULL;
  this->trt = 0;
  this->song_count = 0; 
  cout << "Playlist has been cleared!" << endl; 
}

//Play Functions
void Playlist::StartPlaylist(){
  bool completed = false; 
  song* cursor = this->first; 

  int time_remaining = this->trt; 
  int songs_remaining = this->song_count; 
  
  while(!completed){
    cout << "Now Playing: " << cursor->title << " by " << cursor->artist << endl; 
    cout << "Genre: " << cursor->genre << endl;
    cout << "Song Duration: " << cursor->duration/60 << "m" 
         << cursor->duration - (cursor->duration/60 * 60) << "s" << endl << endl;
    cout << "Songs Remaining in List: " << songs_remaining << endl; 
    cout << "Time Remaining in List: " << time_remaining/60 << "m" 
         << time_remaining - (time_remaining/60 * 60) << "s" << endl; 
    songs_remaining--; 
    sleep(5);
    if(cursor->next != NULL){
      cout << "-------------" << endl; 
      cout << "Up Next: " << cursor->next->title << " by " << cursor->next->artist << endl; 
    }
    sleep(cursor->duration/15 - 7);
    time_remaining -= cursor->duration;
    if(cursor->next == NULL){
       string replay; 
       cout << "Do you wish to replay? (Y or N) " << endl;
       cin >> replay;
       if(replay == "y" || replay == "Y"){
         StartPlaylist();
       }
       else {
        completed = true;
        cout << "End of playlist! " << endl;
        cout << "================! " << endl;
       }
    }
    else {
        cursor = cursor->next;
    }
  }
}

void Playlist::PlayReverse(){
  bool completed = false; 
  song* cursor = this->last; 

  int time_remaining = this->trt; 
  int songs_remaining = this->song_count; 
  cout << "Playing in Reverse order!" << endl << endl; 
  while(!completed){
    cout << "Now Playing: " << cursor->title << " by " << cursor->artist << endl; 
    cout << "Genre: " << cursor->genre << endl;
    cout << "Song Duration: " << cursor->duration/60 << "m" 
         << cursor->duration - (cursor->duration/60 * 60) << "s" << endl << endl;
    cout << "Songs Remaining in List: " << songs_remaining << endl; 
    cout << "Time Remaining in List: " << time_remaining/60 << "m" 
         << time_remaining - (time_remaining/60 * 60) << "s" << endl; 
    songs_remaining--; 
    sleep(5);
    if(cursor->prev != NULL){
      cout << "-------------" << endl; 
      cout << "Up Next: " << cursor->prev->title << " by " << cursor->prev->artist << endl; 
    }
    sleep(cursor->duration/15 - 7);
    time_remaining -= cursor->duration;
    if(cursor->prev == NULL){
       string replay; 
       cout << "Do you wish to replay in reverse order? (Y or N) " << endl;
       cin >> replay;
       if(replay == "y" || replay == "Y"){
         PlayReverse();
       }
       else {
        completed = true;
        cout << "End of playlist! " << endl;
        cout << "================! " << endl;
       }
    }
    else {
        cursor = cursor->prev;
    }
  }
}