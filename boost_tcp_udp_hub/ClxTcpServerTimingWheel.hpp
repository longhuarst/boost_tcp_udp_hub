//
//  ClxTcpServerTimingWheel.hpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#ifndef ClxTcpServerTimingWheel_hpp
#define ClxTcpServerTimingWheel_hpp



#include <boost/asio.hpp>

#include <stdio.h>

#include <boost/date_time/posix_time/posix_time.hpp>


class ClxTcpServerTimingWheel{
  

public:
    ClxTcpServerTimingWheel(boost::asio::io_service &service);
    ~ClxTcpServerTimingWheel();
    
private:
    
    boost::asio::io_service &service_;
    
};




#endif /* ClxTcpServerTimingWheel_hpp */
