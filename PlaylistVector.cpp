//
// Created by kmurphy on 5/18/2026.
//

#include "PlaylistVector.h"
PlaylistVector::PlaylistVector(int cap) {
    capacity = cap;
    size = 0;
    songs = make_unique<string[]>(capacity);
}

void PlaylistVector::push_back(const string& song) {
    if (size >= capacity) {
        resize();
    }

    songs[size] = song;
    size++;
}

void PlaylistVector::resize() {
    capacity *= 2;

    unique_ptr<string[]> newSongs =
            make_unique<string[]>(capacity);

    for (int i = 0; i < size; i++) {
        newSongs[i] = songs[i];
    }

    songs = move(newSongs);
}

void PlaylistVector::remove(int index) {

    // basic bounds check
    if (index < 0 || index >= size) {
        return;
    }

    // shift elements left
    for (int i = index; i < size - 1; i++) {
        songs[i] = songs[i + 1];
    }

    // reduce logical size
    size--;
}

int PlaylistVector::getSize() const {
    return size;
}

int PlaylistVector::getCapacity() const {
    return capacity;
}

string& PlaylistVector::operator[](int index) {
    return songs[index];
}

PlaylistVector& PlaylistVector::operator+=(const string& song) {
    push_back(song);
    return *this;
}


ostream& operator<<(ostream& out,
                    const PlaylistVector& list) {

    for (int i = 0; i < list.size; i++) {
        out << i << ": " << list.songs[i] << endl;
    }

    return out;
}