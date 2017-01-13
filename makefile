CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = main.o dynArr.o map.o tile.o playerTile.o envTile.o deathTile.o

SRCS = main.cpp dynArr.cpp map.cpp tile.cpp playerTile.cpp envTile.cpp deathTile.cpp

HEADERS = dynArr.hpp map.hpp tile.hpp playerTile.hpp envTile.hpp deathTile.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} main
