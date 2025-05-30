#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <song.hpp>

class Playlist
{
private:
    struct SongNode
    {
        Song song;
        SongNode* next;
        SongNode* prev;

        SongNode(Song s) : song(s), next(nullptr), prev(nullptr) {}
    };
    
    SongNode* head;
    SongNode* tail;
    SongNode* current;

    int size;
public:
    Playlist();
    ~Playlist();

    void addSong(const Song& song);
    void removeSong(const std::string& title);
    void displaySongs() const;
    void selectSong(const std::string& title);
    void playCurrent() const;
    void nextSong();
    void previousSong();
    bool isEmpty() const;
};


#endif