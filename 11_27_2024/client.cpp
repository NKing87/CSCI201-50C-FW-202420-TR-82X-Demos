#include "PracticalSocket.h"
#include <iostream>
#include <limits>
void resetStream();
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server ip address>" << std::endl;
        return 1;
    }

    try
    {
        TCPSocket sock(argv[1], 9431);
        std::string message;
        std::cout << "Enter a message for the server: ";
        std::getline(std::cin >> std::ws, message);
        uint32_t val = htonl(message.length());
        sock.send(&val, sizeof(val));
        sock.send(message.c_str(), message.length());
        if (sock.recvFully(&val, sizeof(val)) == sizeof(val))
        {
            val = ntohl(val);
            char *buffer = new char[val + 1];
            if (sock.recvFully(buffer, val) == val)
            {
                buffer[val] = '\0';
                std::cout << "\033[1m\033[38;5;17m\033[48;5;15m";
                std::cout << "Server Response: " << buffer << std::endl;
            }
            delete[] buffer;
        }
        sock.close();
    }
    catch (SocketException e)
    {
        std::cerr << e.what() << "\n";
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}