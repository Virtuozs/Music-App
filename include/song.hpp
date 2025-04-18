#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <string>

class Song {
    private:
        std::string title;
        std::string artist;
        std::string album;
        int year;
        int duration;
        std::string genre;
        std::string filePath;
        bool isFavorite;
    public:
    Song(std::string title, std::string artist, std::string album, int year, int duration, std::string genre, std::string filePath )
        : title(title), artist(artist), album(album), year(year), duration(duration), genre(genre), filePath(filePath), isFavorite(false) {}

    // Getter
    std::string getTitle() const;
    std::string getArtist() const;
    std::string getAlbum() const;
    int getYear() const;
    int getDuration() const;
    std::string getGenre() const;
    std::string getFilePath() const;
    bool getIsFavorite() const;

    // Setter
    void setTitle(std::string newTitle);
    void setArtist(std::string newArtist);
    void setAlbum(std::string newAlbum);
    void setYear(int newYear);
    void setDuration(int newDuration);
    void setGenre(std::string newGenre);
    void setFilePath(std::string newFilePath);
    void setIsFavorite(bool newIsFavorite);

    void toggleFavorite();

    void songDetails();

    void play();
    void pause();
    void stop();
};
#endif