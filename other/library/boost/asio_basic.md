[toc]
# boost.asio学习
# TCP客户端流程
对于系统的socket API：
1. 创建socket：socket()
2. 连接服务端：connect()
3. write(), read()
4. close()

对于asio，下面是daytime client例子.
```C++
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }

        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(argv[1], "daytime");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);
        //也可以 socket.connect(*endpoint_iterator)

        for (;;)
        {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            std::cout.write(buf.data(), len);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```
流程是：
1. 第一步创建io_service, 用于asio的异步io
2. 创建socket，标识一个套接字
3. 在connect之前，需要获取服务器的地址，所以需要tcp::endpoint ，
    1. 可以通过resolver解析
    2. 也可以直接创建endpoint
4. connect，connect有两种连接方式，参见stackoverflow: difference between socket.connect and boost::asio::connect

# 注意
## difference between socket.connect and boost::asio::connect
http://stackoverflow.com/questions/15687016/difference-between-socket-connect-and-boostasioconnect

boost::asio::connect 是高级别的函数， boost::asio::connect(socket, endpoint_iterator);

通过socket连接endpoint_iterator中的endpoint，直到一个成功为止。

from: stackoverflow, Sam Miller

> boost::asio::connect() is a higher level free function that will invoke boost::asio::ip::tcp::socket::connect(). The documentation is fairly clear here

> This function attempts to connect a socket to one of a sequence of endpoints. It does this by repeated calls to the socket's connect member function, once for each endpoint in the sequence, until a connection is successfully established.
Neither has better behavior, though that is largely a subjective term. It's up to you and your application how you want to handle connection establishment. If you need to provide some sort of feedback to the user, ex: "attempting to connect to host 1 of 10" it might be preferable to use socket.connect() in a loop rather than the connect() free function.

> The connect() free function takes an endpoint iterator so it can connect to all possible endpoints that are resolved. The tcp echo client that you linked to does this
```
tcp::resolver resolver(io_service);
tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
tcp::resolver::iterator iterator = resolver.resolve(query);
tcp::socket s(io_service);
boost::asio::connect(s, iterator);
```