
sudo yum install git;
sudo yum install -y gcc-c++;
git clone https://github.com/jspranklemusic/C-Hello-World-Server.git;
cd C-Hello-World-Server;
git clone https://github.com/yhirose/cpp-httplib.git;
echo "compiling program..."
g++ -pthread -std=c++11 main.cpp -o main;
echo "...compiling done. running program:"
sudo ./main;
