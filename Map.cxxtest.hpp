#ifndef MAP_CXXTEST_H
#define MAP_CXXTEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "Room.h"

class MapTestSuite : public CxxTest::TestSuite
{
public:
	Room * r1;
	Room * r2;

	void setUp() {
	    r1 = new Room();
	    r2 = new Room();
	  }

	  //tests the swap function
	  void test_() {
		  TS_ASSERT(r1->connectRoom(r2));
	  }
};

#endif
