//
//  ClxTcpClient.cpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#include "ClxTcpClient.hpp"

#include <iostream>

using namespace std;


ClxTcpClient::ClxTcpClient(std::string name, boost::asio::io_service &service)
    :
    service_(service),
    name_("[ "+name+" ] --->. ")
{
    
}

ClxTcpClient::~ClxTcpClient() {
    
}



bool ClxTcpClient::connect_sync(std::string ip, int port)
{
    boost::system::error_code error_code;
    
    socket_.reset(new boost::asio::ip::tcp::socket(service_));
    
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip), port);
    
    socket_->connect(endpoint,error_code);
    
    if (error_code) {
        
        std::cout<<name_<<"Connection Failed:"<<error_code.message() <<std::endl;
        
        socket_->close();
        return false;
    }
    
    std::cout << name_ << "Connection Suceed!" << std::endl;
    return true;
    
}




void ClxTcpClient::connect_async(std::string ip, int port,boost::function<void (boost::system::error_code)> handler)
{
    boost::system::error_code error_code;
    
    socket_.reset(new boost::asio::ip::tcp::socket(service_));
    
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip), port);
    
    socket_->async_connect(endpoint, handler);
}


void ClxTcpClient::close()
{
    socket_->close();
}






size_t ClxTcpClient::write_some_sync(std::string &msg)
{
    return socket_->write_some(boost::asio::buffer(msg));
}

void ClxTcpClient::write_some_async(std::string &msg, boost::function<void (const boost::system::error_code& error, std::size_t bytes_transferred)> handler) {
    socket_->async_write_some(boost::asio::buffer(msg), handler);
}

size_t ClxTcpClient::read_until_sync(std::string regex, boost::asio::streambuf &stream) {
    return boost::asio::read_until(*socket_, stream, boost::regex(regex));
}


void ClxTcpClient::read_until_async(std::string regex, boost::asio::streambuf& stream, boost::function<void (const boost::system::error_code& error, size_t bytes_transferred)> handler) {
    boost::asio::async_read_until(*socket_, stream, boost::regex(regex), handler);
}



size_t ClxTcpClient::read_sync(char *buffer, size_t length)
{
    return boost::asio::read(*socket_, boost::asio::buffer(buffer,length));
}

void ClxTcpClient::read_async(char* buffer, size_t length, boost::function<void (const boost::system::error_code& error, size_t bytes_transferred)> handler)
{
    boost::asio::async_read(*socket_, boost::asio::buffer(buffer, length), handler);
}

size_t ClxTcpClient::write_sync(char* buffer, size_t length)
{
    return boost::asio::write(*socket_, boost::asio::buffer(buffer, length));
}

void ClxTcpClient::write_async(char* buffer, size_t length, boost::function<void(const boost::system::error_code& error, size_t bytes_transferred)> handler)
{
    boost::asio::async_write(*socket_, boost::asio::buffer(buffer, length), handler);
}

