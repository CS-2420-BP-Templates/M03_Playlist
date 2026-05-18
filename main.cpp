#include <iostream>

#include <iostream>
#include <fstream>
#include "PlaylistVector.h"

using namespace std;

int main() {

    PlaylistVector playlist;
    ifstream fin("../playlist.txt");
    int choice;

    if (!fin) {
        cout << "Error opening Playlist. "  << endl;
        return 0;
    }
    string song;
    while (getline(fin, song)) {
        playlist += song;
    }
    fin.close();

    do{
        cout << "=== Playlist ===" << endl;
        cout << playlist << endl;
        cout << "1. Add Song\n2. Remove by Index\n3. Quit\nEnter Choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter the song to add to the Playlist\n";
            cin.ignore();
            getline(cin, song);
            playlist += song;
        }
        else if(choice == 2){
            cout << "Enter the index of the song to remove from the playlist\n";
            int pos;
            cin >> pos;
            playlist.remove(pos);
        }
        ofstream fout ("../playlist.txt", ios::out);
        for(int i = 0; i < playlist.getSize(); i++){
            string temp = playlist[i];
            fout << temp << endl;
        }
        fout.close();
    }while(choice > 0 && choice < 3);








    return 0;
}