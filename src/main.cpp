#include <iostream>
#include <map>
#include <playlist.hpp>
#include <utilities.hpp>
#include <playlistManager.hpp>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

void printMainMenu() {
    std::cout << "\n=== Playlist Manager ===\n";
    std::cout << "1. Create Playlist\n";
    std::cout << "2. Select Playlist\n";
    std::cout << "3. List All Playlists\n";
    std::cout << "4. Manage Current Playlist\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

void printPlaylistMenu(const std::string& name) {
    std::cout << "\n--- Managing Playlist: " << name << " ---\n";
    std::cout << "1. Add Song\n";
    std::cout << "2. Display Songs\n";
    std::cout << "3. Select Song\n";
    std::cout << "4. Play Current Song\n";
    std::cout << "5. Next Song\n";
    std::cout << "6. Previous Song\n";
    std::cout << "7. Remove Song\n";
    std::cout << "8. Back to Main Menu\n";
    std::cout << "Choice: ";
}

// TODO: Change this implementation when using real I/O for music file
Song inputSongDetails() {
    std::string title, artist, album, genre, filePath;
    int year, duration;

    std::cout << "Adding new Song to Playlist" << std::endl;
    std::cout << "Enter title: "; std::getline(std::cin, title);
    std::cout << "Enter artist: "; std::getline(std::cin, artist);
    std::cout << "Enter album: "; std::getline(std::cin, album);
    std::cout << "Enter year: "; std::cin >> year;
    std::cout << "Enter duration (seconds): "; std::cin >> duration;
    std::cin.ignore();
    std::cout << "Enter genre: "; std::getline(std::cin, genre);
    std::cout << "Enter file path: "; std::getline(std::cin, filePath);

    return Song(title, artist, album, year, duration, genre, filePath);
}

void managePlaylist(Playlist& playlist, const std::string& name) {
    int choice;
    do {
        utilities::clearScreen();
        printPlaylistMenu(name);
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                utilities::clearScreen();
                playlist.addSong(inputSongDetails());
                break;
            case 2:
                playlist.displaySongs();
                utilities::pressAnyKeyToContinue("");
                break;
            case 3: {
                utilities::clearScreen();
                playlist.displaySongs();
                std::string title;
                std::cout << "Enter selected song title: ";
                std::getline(std::cin, title);
                playlist.selectSong(title);
                break;
            }
            case 4:
                playlist.playCurrent();
                break;
            case 5:
                playlist.nextSong();
                break;
            case 6:
                playlist.previousSong();
                break;
            case 7: {
                utilities::clearScreen();
                playlist.displaySongs();
                std::string title;
                std::cout << "Enter song title to remove: ";
                std::getline(std::cin, title);
                playlist.removeSong(title);
                break;
            }
            case 8:
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 8);
}

int main()
{
    PlaylistManager playlistManager;
    std::map<std::string, Playlist> playlists;
    std::string currentPlaylistName;
    int mainChoice;

    do {
        utilities::clearScreen();
        printMainMenu();
        std::cin >> mainChoice;
        std::cin.ignore();

        switch (mainChoice) {
            case 1: {
                std::string name;
                std::cout << "Enter new playlist name: ";
                std::getline(std::cin, name);
                utilities::clearScreen();
                playlistManager.createPlaylist(name);
                break;
            }
            case 2: {
                utilities::clearScreen();
                if(playlistManager.isEmpty()){
                    utilities::pressAnyKeyToContinue("No playlist available");
                    break;
                }
                playlistManager.listPlaylists();
                std::string name;
                std::cout << "Enter playlist name to select: ";
                std::getline(std::cin, name);
                playlistManager.switchToPlaylist(name);
                break;
            }
            case 3: {
                utilities::clearScreen();
                playlistManager.listPlaylists();
                utilities::pressAnyKeyToContinue("");
                break;
            }
            case 4: {
                utilities::clearScreen();
                std::string currentPlaylistName = playlistManager.getCurrentPlaylistName();
                Playlist* currentPlaylist = playlistManager.getCurrentPlaylist();
                managePlaylist(*currentPlaylist, currentPlaylistName);
                break;
            }
            case 5:
                utilities::pressAnyKeyToContinue("Exiting...");
                utilities::clearScreen();
                break;
            default:
                utilities::pressAnyKeyToContinue("Invalid option ...");
                utilities::clearScreen();
        }

    } while (mainChoice != 5);

    return 0;
}
