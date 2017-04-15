CC=gcc
PRG=pwm_test.out
SRC=pwm_test.cpp
FLAGS=-lwiringPi

all:
	$(CC) -o $(PRG) $(SRC) $(FLAGS)
