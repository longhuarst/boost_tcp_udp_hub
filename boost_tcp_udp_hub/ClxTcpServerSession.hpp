//
//  ClxTcpServerSession.hpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#ifndef ClxTcpServerSession_hpp
#define ClxTcpServerSession_hpp

#include <stdio.h>



#include <iostream>

#include <boost/asio.hpp>

class ClxTcpServerSession
: public std::enable_shared_from_this<ClxTcpServerSession>
{
public:
    ClxTcpServerSession(boost::asio::ip::tcp::socket socket);
    ~ClxTcpServerSession();
    
    
    void start();
    
    
    
private:
    
    
    
    void do_read();
    
    void do_write(std::size_t length);
    
    
    
    
    boost::asio::ip::tcp::socket socket_;
    //boost::asio::ip::tcp::socket *socket_self_;//自己
    //boost::asio::ip::tcp::socket *socket_peer_;//对等端socket
    //ClxSession * session_peer_;//对等端的session
    
    
    
    enum {max_length = 1024};
    char data_[max_length];
    char data_send_[max_length];//发送的数据
    boost::asio::streambuf outputstream_;
    boost::asio::streambuf inputstream_;
    
    
    
    bool inited_;//uuid是否验证完毕
    
    
    std::string uuid_;//该客户的UUID
    std::string uuid_peer_;//对等的UUID
    
    
};



#endif /* ClxTcpServerSession_hpp */
