# endpoint
boost::asio::ip::tcp::endpoint endpoint; 

标识一个连接的一端，比如IP地址加端口

有两种方法构建endpoint：
1. 通过endpoint的构造函数构造
```
boost::asio::ip::address add;  
add.from_string("127.0.0.1");  
tcp::endpoint endpoint(add, short(9000));  
socket.connect(endpoint, error);  
```
```
namespace ip = boost::asio::ip;
ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 20015);
```
构造函数接受ip address和端口，不接收string
2. 通过resolver
```
boost::asio::io_service io_service;
tcp::resolver resolver(io_service);
tcp::resolver::query query(argv[1], "daytime");
tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
```
argv[1]是string类型

另外，参见 StackOverflow：

[Difference between resolving a query and creating an endpoint with IP and port (in boost asio)]
(http://stackoverflow.com/questions/17442179/difference-between-resolving-a-query-and-creating-an-endpoint-with-ip-and-port)

> In the end, use:
> - resolver when you want to support hostname resolution or IP conversions. 
> - This is especially convenient when IPs may change but hostnames remain the same, or when a single hostname may resolve to multiple IPs.
ip::address::from_string() to create an address from an IP.