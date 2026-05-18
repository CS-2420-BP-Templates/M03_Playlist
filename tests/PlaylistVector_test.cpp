

#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlaylistVector.h"


#include <sstream>

#include "../PlaylistVector.h"

using namespace std;

TEST_CASE("Default constructor initializes correctly") {

    PlaylistVector playlist;

    REQUIRE(playlist.getSize() == 0);
    REQUIRE(playlist.getCapacity() > 0);
}

TEST_CASE("push_back adds songs correctly") {

    PlaylistVector playlist;

    playlist.push_back("Song A");
    playlist.push_back("Song B");

    REQUIRE(playlist.getSize() == 2);

    REQUIRE(playlist[0] == "Song A");
    REQUIRE(playlist[1] == "Song B");
}

TEST_CASE("operator+= adds songs correctly") {

    PlaylistVector playlist;

    playlist += "Africa";
    playlist += "Numb";

    REQUIRE(playlist.getSize() == 2);

    REQUIRE(playlist[0] == "Africa");
    REQUIRE(playlist[1] == "Numb");
}

TEST_CASE("resize doubles capacity when full") {

    PlaylistVector playlist(2);

    playlist.push_back("Song 1");
    playlist.push_back("Song 2");

    REQUIRE(playlist.getCapacity() == 2);

    playlist.push_back("Song 3");

    REQUIRE(playlist.getCapacity() == 4);
    REQUIRE(playlist.getSize() == 3);

    REQUIRE(playlist[2] == "Song 3");
}

TEST_CASE("operator[] allows modification") {

    PlaylistVector playlist;

    playlist.push_back("Old Song");

    playlist[0] = "New Song";

    REQUIRE(playlist[0] == "New Song");
}

TEST_CASE("remove deletes middle element correctly") {

    PlaylistVector playlist;

    playlist += "Song A";
    playlist += "Song B";
    playlist += "Song C";

    playlist.remove(1);

    REQUIRE(playlist.getSize() == 2);

    REQUIRE(playlist[0] == "Song A");
    REQUIRE(playlist[1] == "Song C");
}

TEST_CASE("remove deletes first element correctly") {

    PlaylistVector playlist;

    playlist += "Song A";
    playlist += "Song B";
    playlist += "Song C";

    playlist.remove(0);

    REQUIRE(playlist.getSize() == 2);

    REQUIRE(playlist[0] == "Song B");
    REQUIRE(playlist[1] == "Song C");
}

TEST_CASE("remove deletes last element correctly") {

    PlaylistVector playlist;

    playlist += "Song A";
    playlist += "Song B";
    playlist += "Song C";

    playlist.remove(2);

    REQUIRE(playlist.getSize() == 2);

    REQUIRE(playlist[0] == "Song A");
    REQUIRE(playlist[1] == "Song B");
}

TEST_CASE("operator<< prints playlist correctly") {

    PlaylistVector playlist;

    playlist += "Africa";
    playlist += "Numb";

    stringstream sout;

    sout << playlist;

    REQUIRE(sout.str() ==
            "0: Africa\n"
            "1: Numb\n");
}

TEST_CASE("multiple resizes preserve data") {

    PlaylistVector playlist(2);

    for (int i = 0; i < 10; i++) {
        playlist.push_back("Song " + to_string(i));
    }

    REQUIRE(playlist.getSize() == 10);

    REQUIRE(playlist[0] == "Song 0");
    REQUIRE(playlist[5] == "Song 5");
    REQUIRE(playlist[9] == "Song 9");

    REQUIRE(playlist.getCapacity() >= 10);
}