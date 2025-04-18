## 🎵 C++ Music App

This is a dummy terminal-based Music Application built with C++ to better understand **List** and **LinkedList**. This project using Object-Oriented Programming principles. You can create multiple playlists, add or remove songs, navigate songs, and select songs manually — all through a simple menu.

## 📁 Features

✅ Create and switch between multiple playlists

✅ Add songs with title, artist, duration

✅ Remove songs by title

✅ Play current song

✅ Navigate to next or previous song

✅ Select a song manually

✅ CLI-based navigation


## 🧠 Classes & Structure

### Song
Represents a song with details like title, artist, and duration.

Key Methods:
- play() — Simulates playing the song
- songDetails() — Displays song info

### Playlist
Handles one double linked list of songs.

Key Methods:
- addSong(const Song&) — Adds a new song
- removeSong(const std::string&) — Deletes a song by title
- playCurrent() — Plays the current song
- nextSong() / previousSong() — Navigate
- selectSong(const std::string&) — Set current song manually
- displaySongs() — Shows all songs
- isEmpty() — Checks if playlist is empty

### PlaylistManager
Handles multiple playlists with names.

Key Methods:
- createPlaylist(name) — Create new Playlist 
- switchToPlaylist(name) — Swicth to already existing Playlist
- getCurrentPlaylist() — Returns pointer to selected playlist
- getCurrentPlaylistName — Return a string of selected playlist name

## 🖥️ How It Works
- Start the program.
- Create a playlist and give it a name.
- Add songs to the playlist.
- Manage songs (play, next, previous, select, remove).
- Switch between playlists as needed.
- Exit the program.

## 🧪 Example Input Flow

```text
1. Create Playlist
> Enter name: Favorites

2. Add Song
> Title: Daylight
> Artist: Joji
> Duration: 210

3. Play Current
> ▶️  Now playing:  Daylight by Joji

4. Mark Favorite

5. Display All Songs
> 1. Daylight

```

## 🛠️ Requirements
- C++17 or later
- g++ compiler
- Terminal/console environment
- make (for using the provided Makefile)

## 🧼 Future Improvements
- Real Audio playback
- File saving/loading for persistent playlists
