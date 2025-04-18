#include <song.hpp>
#include <utilities.hpp>

// Getter Implementations
std::string Song::getTitle() const {
    return title;
}

std::string Song::getArtist() const {
    return artist;
}

std::string Song::getAlbum() const {
    return album;
}

int Song::getYear() const {
    return year;
}

int Song::getDuration() const {
    return duration;
}

std::string Song::getGenre() const {
    return genre;
}

std::string Song::getFilePath() const {
    return filePath;
}

bool Song::getIsFavorite() const {
    return isFavorite;
}

// Setter Implementations
void Song::setTitle(std::string newTitle){
    title = newTitle;
}

void Song::setArtist(std::string newArtist){
    artist = newArtist;
}

void Song::setAlbum(std::string newAlbum) {
    album = newAlbum;
}

void Song::setYear(int newYear){
    year = newYear;
}

void Song::setDuration(int newDuration){
    duration = newDuration;
}

void Song::setGenre(std::string newGenre){
    genre = newGenre;
}

void Song::setFilePath(std::string newFilePath){
    filePath = newFilePath;
}

// Other Implementations

void Song::songDetails() {
    std::cout << "Title     : " << title << std::endl;
    std::cout << "Artist    : " << artist << std::endl;
    std::cout << "Album     : " << album << std::endl;
    std::cout << "Year      : " << year << std::endl;
    std::cout << "Duration  : " << duration << " seconds" << std::endl;
    std::cout << "Genre     : " << genre << std::endl;
    std::cout << "File Path : " << filePath << std::endl;
    std::cout << "Favorite  : " << (isFavorite ? "Yes" : "No") << std::endl;
}

void Song::play() {
    std::string playedMessage = "▶️  Now playing: " + title + " by " + artist;
    utilities::pressAnyKeyToContinue(playedMessage);
    // TODO: add audio playback code here
}

void Song::pause() {
    std::string pauseMessage =  "⏸️  Paused: " + title;
    utilities::pressAnyKeyToContinue(pauseMessage);
    // TODO: Add pause logic here
}

void Song::stop() {
    std::string stopMessage = "⏹️  Stopped: " + title;
    utilities::pressAnyKeyToContinue(stopMessage);
    // TODO: Add stop logic here 
}