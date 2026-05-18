# Playlist
## Description
In this lab, you will build your own dynamic array class in C++ called SongList.

This project is designed to help you understand how containers such as vector work internally by managing memory manually using pointers and smart pointers.

Your SongList class will dynamically store songs entered by the user. Since the number of songs is unknown ahead of time, the program must resize the array automatically whenever it becomes full.

Learning Objectives
- Store data dynamically using heap memory
- Use unique_ptr to safely manage arrays
- Resize arrays when capacity is reached
- Overload [] for indexing
- Overload << for displaying the list
- Optionally overload additional operators such as +=

## Required Class
Create a class called PlaylistVector with the following methods

### Constructor: 

`PlaylistVector(int cap = 4);`

Initializes the playlist with an initial capacity.  The size starts at 0.

### Adding to the Vector

`void push_back(const string& song);`

The push_back method will add the song at the back of the array.  If the capacity has been reached, it will resize the list to double the current capacity.

### Getter Methods
Create getter methods for the Size and Capacity of the list
```
        int getSize() const;        //return the number of items in the list
        int getCapacity() const;    //return the max number of items the list can store before a resize  
```
### Overloaded Operators
Overload the following operators
```
        string& operator[](int index);                  //Returns a modifiable reference to the string
        PlaylistVector& operator+=(const string& song); //Adds a value to the list (calls push_back)
```
### Output Operator
`friend ostream& operator<<(ostream& out, const PlaylistVector& list);`

Displays the list of songs in the format of index: song

```angular2html
0: House of the Rising Sun
1: Smells Like Teen Spirit
2: Die With a Smile
```


### Remove: 
`void remove(int index);`

This function will remove the value at position index.  The function will move the values back in the list so there is not an empty position

Given:
```angular2html
0: House of the Rising Sun
1: Smells Like Teen Spirit
2: Die With a Smile
3: I just Might
```
remove(1); would leave the list as such

```angular2html
0: House of the Rising Sun
1: Die With a Smile
2: I just Might
```

## Write the Main method
Write a program that reads a file named `playlist.txt`.  Each line will be stored as a new song in the PlaylistVector. Display the playlist.  

Allow the user to choose if they want to add to a song, remove a song, or quit.  

Don't Forget: to allow the user to enter a sentence instead of a word, use the getline function

```
string sentence;
getline(cin, sentence);
```

If the getline follows a cin statement, the endl character must be ignored or the cin statement will not function correctly.
```
int num;
string sentence;
cin >> num;
cin.ignore();
getline(cin, sentence);
```

## Sample Output
```angular2html
=== Playlist ===
0: Bohemian Rhapsody
1: Shes Country
2: Smells like teen Spirit

1. Add Song
2. Remove by Index
3. Quit
Enter Choice:1

Enter the song to add to the Playlist
November Rain

=== Playlist ===
0: Bohemian Rhapsody
1: Shes Country
2: Smells like teen Spirit
3: November Rain

1. Add Song
2. Remove by Index
3. Quit
Enter Choice:1

Enter the song to add to the Playlist
Enter Sandman

=== Playlist ===
0: Bohemian Rhapsody
1: Shes Country
2: Smells like teen Spirit
3: November Rain
4: Enter Sandman

1. Add Song
2. Remove by Index
3. Quit
Enter Choice:2

Enter the index of the song to remove from the playlist
1

=== Playlist ===
0: Bohemian Rhapsody
1: Smells like teen Spirit
2: November Rain
3: Enter Sandman

1. Add Song
2. Remove by Index
3. Quit
Enter Choice:3
```