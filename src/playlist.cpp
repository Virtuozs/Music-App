#include <playlist.hpp>
#include <utilities.hpp>

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

    current = newNode; 
    utilities::clearScreen();
    std::string addingSongMessage = "Added " + song.getTitle() + " to Fav Playlist.";
    utilities::pressAnyKeyToContinue(addingSongMessage);
}

void Playlist::removeSong(const std::string& title) {
    utilities::clearScreen();
    SongNode* temp = head;

    while (temp) {
        if (temp->song.getTitle() == title) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (current == temp) current = temp->next ? temp->next : temp->prev;
            delete temp;
            std::string removedMessagge = "Removed " + title + " from playlist.";
            utilities::pressAnyKeyToContinue(removedMessagge);
            return;
        }
        temp = temp->next;
    }
    std::string NotFoundMessage = "Song not found: " + title;
    utilities::pressAnyKeyToContinue(NotFoundMessage);
}

void Playlist::displaySongs() const {
    if (isEmpty()) {
        utilities::pressAnyKeyToContinue("Playlist is empty.");
        return;
    }

    utilities::clearScreen();
    std::cout << "Songs in Playlist" << std::endl;
    SongNode* temp = head;
    int index = 1;
    while (temp) {
        std::cout << index++ << ". ";
        std::cout << temp->song.getTitle() << std::endl;
        temp = temp->next;
    }
    std::cout << "---------------------------" << std::endl;
}

void Playlist::selectSong(const std::string& title){
    if (isEmpty()) {
        utilities::pressAnyKeyToContinue("Playlist is empty.");
        return;
    }
    utilities::clearScreen();
    SongNode* temp = head;
    while (temp) {
        if (temp->song.getTitle() == title) {
            current = temp;
            std::string selectedMessage = "Selected: " + title + " as current song.";
            utilities::pressAnyKeyToContinue(selectedMessage);
            return;
        }
        temp = temp->next;
    }
    std::string notFoundMessage = "Song not found: " + title;
    utilities::pressAnyKeyToContinue(notFoundMessage);
}

void Playlist::playCurrent() const {
    if (!current) {
        utilities::pressAnyKeyToContinue("No song is currently selected...");
        return;
    }
    utilities::clearScreen();
    current->song.play();
}

void Playlist::nextSong() {
    if (!current) {
        utilities::pressAnyKeyToContinue("Playlist is empty...");
        return;
    }

    utilities::clearScreen();
    if (current->next) {
        current = current->next;
    } else {
        utilities::pressAnyKeyToContinue("You're at the last song.");
    }

    playCurrent();
}

void Playlist::previousSong() {
    if (!current) {
        utilities::pressAnyKeyToContinue("Playlist is empty.");
        return;
    }

    if (current->prev) {
        current = current->prev;
    } else {
        utilities::pressAnyKeyToContinue("You're at the first song.");
    }

    playCurrent();
}
