//
// Created by kmurphy on 5/18/2026.
//

#ifndef PLAYLIST_PLAYLISTVECTOR_H
#define PLAYLIST_PLAYLISTVECTOR_H

#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;
using std::make_unique;
using std::ostream;
using std::endl;

class PlaylistVector {
    public:
        PlaylistVector(int cap = 4);

        void push_back(const string& song);

        int getSize() const;
        int getCapacity() const;
        void remove(int);
        string& operator[](int index);

       // const string& operator[](int index) const;
        PlaylistVector& operator+=(const string& song);
        friend ostream& operator<<(ostream& out, const PlaylistVector& list);

    private:
        // Declare a Unique_ptr for the list
        // Declare variables for the size and capacity

        void resize();
};


#endif //PLAYLIST_PLAYLISTVECTOR_H
