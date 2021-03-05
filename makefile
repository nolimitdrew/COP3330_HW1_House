driver_executable: driver.o house.o
	g++ -g -o driver driver.o house.o
	chmod 755 driver

house.o: house.cpp house.h
	g++ -g -c house.cpp 

driver.o: driver.cpp house.h
	g++ -g -c driver.cpp    

clean:
	rm -f *.o





