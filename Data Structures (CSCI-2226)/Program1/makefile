CC=g++
binaries = main.o Car.o Reservation.o UnsortedCarList.o UnsortedReservationList.o

main: $(binaries)

main.o: main.cpp Car.hpp Reservation.hpp
	$(CC) -c main.cpp

Car.o: Car.cpp Car.hpp
	$(CC) -c Car.cpp

Reservation.o: Reservation.cpp Reservation.hpp
	$(CC) -c Reservation.cpp

UnsortedCarList.o: UnsortedCarList.cpp UnsortedCarList.hpp
	$(CC) -c UnsortedCarList.cpp

UnsortedReservationList.o: UnsortedReservationList.cpp UnsortedReservationList.hpp
	$(CC) -c UnsortedReservationList.cpp

clean: 
	rm main $(binaries)
