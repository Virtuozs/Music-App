#ifndef PLAYLIST_MANAGER_HPP
#define PLAYLIST_MANAGER_HPP

#include <unordered_map>
#include <iostream>
#include <playlist.hpp>

class PlaylistManager {
    private:
        std::unordered_map<std::string, Playlist> playlists;
        std::string currentPlaylistName;

    public:
        void createPlaylist(const std::string& name);
        void deletePlaylist(const std::string& name);
        void switchToPlaylist(const std::string& name);
        Playlist* getCurrentPlaylist();
        std::string getCurrentPlaylistName();

        void listPlaylists() const;
        bool isEmpty() const;
};
#endif