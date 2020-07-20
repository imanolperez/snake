cd build
g++ -c ../src/*.cpp -std=c++11 -lcurses
cd ../run
g++ run.cpp ../build/*.o -std=c++11 -o run.o -lcurses
./run.o
