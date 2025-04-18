#include <playlist.hpp>

// Constructor
Playlist::Playlist(){
    head = tail = current = nullptr;
}

// Deconstructor
Playlist::~Playlist(){
    SongNode* temp = head;
    while (temp) {
        SongNode* next = temp->next;
        delete temp;
        temp=next;
    }
}

bool Playlist::isEmpty() const {
    return head == nullptr;
}

void Playlist::addSong(const Song& song) {
    SongNode* newNode = new SongNode(song);
    if (!head) {
        head = tail = current = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    std::cout << "Added: " << song.getTitle() << std::endl;
}

void Playlist::removeSong(const std::string& title) {
    SongNode* temp = head;

    while (temp) {
        if (temp->song.getTitle() == title) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (current == temp) current = temp->next ? temp->next : temp->prev;
            delete temp;
            std::cout << "Removed: " << title << std::endl;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Song not found: " << title << std::endl;
}

void Playlist::displaySongs() const {
    if (isEmpty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SongNode* temp = head;
    int index = 1;
    while (temp) {
        std::cout << index++ << ". ";
        temp->song.songDetails();
        std::cout << "---------------------------\n";
        temp = temp->next;
    }
}

void Playlist::playCurrent() const {
    if (!current) {
        std::cout << "No song is currently selected.\n";
        return;
    }

    current->song.play();
}

void Playlist::nextSong() {
    if (!current) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    if (current->next) {
        current = current->next;
    } else {
        std::cout << "You're at the last song.\n";
    }

    playCurrent();
}

void Playlist::previousSong() {
    if (!current) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    if (current->prev) {
        current = current->prev;
    } else {
        std::cout << "You're at the first song.\n";
    }

    playCurrent();
}

void Playlist::markFavorite(const std::string& title) {
    SongNode* temp = head;
    while (temp) {
        if (temp->song.getTitle() == title) {
            temp->song.toggleFavorite();
            std::cout << "Toggled favorite: " << title << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Song not found.\n";
}

void Playlist::listFavorites() const {
    std::cout << "Favorite Songs:\n";
    SongNode* temp = head;
    bool found = false;
    while (temp) {
        if (temp->song.getIsFavorite()) {
            std::cout << "Title: " << temp->song.getTitle() << std::endl;
            std::cout << "---------------------------\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) std::cout << "No favorite songs.\n";
}
