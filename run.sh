echo "compiling program..."
g++ -pthread -std=c++11 main.cpp -o main;
echo "...compiling done. running program:"
sudo ./main;
