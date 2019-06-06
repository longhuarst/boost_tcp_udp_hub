//
//  ClxTcpServer.hpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#ifndef ClxTcpServer_hpp
#define ClxTcpServer_hpp

#include <stdio.h>


#include <boost/asio.hpp>



class ClxTcpServer
{
public:
    ClxTcpServer(boost::asio::io_context& io_context, short port);
    ~ClxTcpServer();
    
    
    
private:
    
    void do_accept();
    
    
    boost::asio::ip::tcp::acceptor acceptor_;
    
    
};

#endif /* ClxTcpServer_hpp */
