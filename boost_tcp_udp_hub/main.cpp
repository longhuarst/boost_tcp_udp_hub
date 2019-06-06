//
//  main.cpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#include <iostream>


#include "ClxTcpClient.hpp"
#include "ClxTcpServer.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    
    std::cout << "Hello, World!"<<std::endl;
    
    
    
    boost::asio::io_service service_;
    
    
    //ClxTcpClient clxclient_(service_,18888);
    
    
    ClxTcpServer clxserver_(service_,18888);//创建服务器
    
    service_.run();
    
    
    
    
    
    
    
    
    
    
    return 0;
}







