//
//  ClxTcpServer.cpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#include "ClxTcpServer.hpp"

#include "ClxTcpServerSession.hpp"

#include <iostream>
#include <boost/asio.hpp>





ClxTcpServer::ClxTcpServer(boost::asio::io_context & io_context, short port)
: acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    do_accept();
}


ClxTcpServer::~ClxTcpServer()
{
    
    
    
}

void ClxTcpServer::do_accept()
{
    acceptor_.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
        if (!ec) {
            
            std::cout << "[accept] - " << socket.remote_endpoint().address().to_string()  << "(" << socket.remote_endpoint().port() << ")" << std::endl;
            
            
            std::make_shared<ClxTcpServerSession>(std::move(socket))->start();
        }
        do_accept();
    });
}
