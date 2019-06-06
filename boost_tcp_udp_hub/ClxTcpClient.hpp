//
//  ClxTcpClient.hpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#ifndef ClxTcpClient_hpp
#define ClxTcpClient_hpp

#include <stdio.h>



#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/regex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/thread/thread.hpp>





class ClxTcpClient{
    
    
public:
    
    ClxTcpClient(std::string name, boost::asio::io_service &service);
    
    ~ClxTcpClient();
    
    bool connect_sync(std::string ip, int port);
    
    
    
    
    void connect_async(std::string ip, int port,boost::function<void (boost::system::error_code)> handler);
    
    void close();
    
    size_t write_some_sync(std::string &msg);
    
    void write_some_async(std::string &msg, boost::function<void (const boost::system::error_code& error, std::size_t bytes_transferred)> handler);
    
    size_t read_until_sync(std::string regex, boost::asio::streambuf &stream);
    
    
    void read_until_async(std::string regex, boost::asio::streambuf& stream, boost::function<void (const boost::system::error_code& error, size_t bytes_transferred)> handler);
    
    
    
    size_t read_sync(char *buffer, size_t length);
    
    void read_async(char* buffer, size_t length, boost::function<void (const boost::system::error_code& error, size_t bytes_transferred)> handler);
    
    size_t write_sync(char* buffer, size_t length);
    
    void write_async(char* buffer, size_t length, boost::function<void(const boost::system::error_code& error, size_t bytes_transferred)> handler);
    
    
    
    
    
    
    
private:
    boost::shared_ptr<boost::asio::ip::tcp::socket> socket_;
    boost::asio::io_service &service_;
    std::string name_;
};










#endif /* ClxTcpClient_hpp */
