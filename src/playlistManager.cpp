#include <playlistManager.hpp>
#include <utilities.hpp>

void PlaylistManager::createPlaylist(const std::string& name){
    if(playlists.find(name) != playlists.end()){
        std::string alreadyExistMessage = "Playlist '" + name + "' already exists.\n";
        utilities::pressAnyKeyToContinue(alreadyExistMessage);
        return;
    }

    playlists[name] = Playlist();
    currentPlaylistName = name;
    std::string createdMessage = "Created and switched to playlist: " + name + "\n";
    utilities::pressAnyKeyToContinue(createdMessage);
}

void PlaylistManager::deletePlaylist(const std::string& name){
    if (playlists.erase(name)) {
        std::string deletedMessage = "Deleted playlist: " + name + "\n";
        utilities::pressAnyKeyToContinue(deletedMessage);
        if (currentPlaylistName == name) {
            currentPlaylistName = "";
        }
    } else {
        std::string notFoundMessage = "Playlist not found: " + name + "\n";
        utilities::pressAnyKeyToContinue(notFoundMessage);
    }
}

void PlaylistManager::switchToPlaylist(const std::string& name) {
    if (playlists.find(name) != playlists.end()) {
        currentPlaylistName = name;
        std::string switchedMessage = "Switched to playlist: " + name + "\n";
        utilities::pressAnyKeyToContinue(switchedMessage);
    } else {
        std::string notFoundMessage = "Playlist not found: " + name + "\n";
        utilities::pressAnyKeyToContinue(notFoundMessage);
    }
}

Playlist* PlaylistManager::getCurrentPlaylist() {
    if (currentPlaylistName.empty()) {
        std::string playlistEmptyMessage = "No playlist selected";
        utilities::pressAnyKeyToContinue(playlistEmptyMessage);
        return nullptr;
    }

    return &playlists[currentPlaylistName];
}

std::string PlaylistManager::getCurrentPlaylistName(){
    if (currentPlaylistName.empty()) {
        std::string playlistEmptyMessage = "No playlist selected";
        utilities::pressAnyKeyToContinue(playlistEmptyMessage);
        return nullptr;
    }

    return currentPlaylistName;
}

void PlaylistManager::listPlaylists() const {
    if (playlists.empty()) {
        std::string playlistEmptyMessage = "No playlist available";
        utilities::pressAnyKeyToContinue(playlistEmptyMessage);
        return;
    }

    std::cout << "Available Playlists:\n";
    for (const auto& pair : playlists) {
        std::cout << "- " << pair.first << "\n";
    }
}

bool PlaylistManager::isEmpty() const {
    return playlists.empty();
}