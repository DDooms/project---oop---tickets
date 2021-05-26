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
    CHECK(seat2.isBooked() == false);
}

void runtests() {
    doctest::Context().run();
}
