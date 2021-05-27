#pragma once
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Ticket.h"

TEST_CASE("Testing seat") {
    String string = "note";
    Seat seat;
    seat.setNote(string);
    CHECK(seat.getNote() == "note");
    Seat seat2(2, 3);
    Date date(25, 10, 2020);
    CHECK(seat2.isBooked() == false);
}

TEST_CASE("Testing row") {
    Row row(10, 10);
    CHECK(row.getSize() == 10);
}

TEST_CASE("Testing hall") {
    Hall hall(10, 20);
    CHECK(hall.getRows() == 10);
    CHECK(hall.getSeats() == 20);
}

TEST_CASE("Testing event") {
    String name = "pesho";
    String note = "note";
    Date date(25, 10, 2020);
    Event event(name, 10, 10, date, 1);
    CHECK(event.getDate() == date);
    CHECK(event.getBookedSeats() == 0);
    CHECK(event.getBookedButNotBoughtSeats() == 0);
    CHECK(event.getAllSeats() == 100);
    CHECK(event.getColNumber() == 10);
    CHECK(event.getHallNum() == 1);
    CHECK(event.getName() == name);
    CHECK(event.getFreeSeats() == 100);
}
TEST_CASE("Testing date") {
    Date date(25, 10, 2020);
    CHECK(date.getDays() == 25);
    CHECK(date.getMonths() == 10);
    CHECK(date.getYears() == 2020);
}
TEST_CASE("Testing vector") {
    Vector<int> vector;
    vector.PushBack(1);
    CHECK(vector[0] == 1);
}
TEST_CASE("Testing string") {
    String string = "NEW";
    string.tolower();
    CHECK(string == "new");
}

void runtests() {
    doctest::Context().run();
}
