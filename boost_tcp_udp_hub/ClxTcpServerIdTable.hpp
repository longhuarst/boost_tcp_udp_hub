//
//  ClxTcpServerIdTable.hpp
//  boost_tcp_udp_hub
//
//  Created by 陆慧晨 on 2019/6/5.
//  Copyright © 2019 陆慧晨. All rights reserved.
//

#ifndef ClxTcpServerIdTable_hpp
#define ClxTcpServerIdTable_hpp

#include <stdio.h>





#include <set>
#include <string>
#include <boost/asio.hpp>



#include <boost/serialization/singleton.hpp>




class ClxTcpServerIdTable
{
public:
    ClxTcpServerIdTable();
    ~ClxTcpServerIdTable();
    
    
    void insert(std::string uuid, boost::asio::ip::tcp::socket& socket);
    
    void delete_by_id(std::string uuid);
    
    void delete_by_socket(boost::asio::ip::tcp::socket& socket);
    
    boost::asio::ip::tcp::socket* get_socket_by_id(std::string uuid);
    
    std::string get_id_by_socket(boost::asio::ip::tcp::socket& socket);
    
    
    
    
private:
    
    typedef std::map<std::string, boost::asio::ip::tcp::socket*> table_id_type;
    typedef std::map<boost::asio::ip::tcp::socket*, std::string> table_socket_type;
    
    table_id_type tables_id_; //ID¶ÔÕÕ±í
    table_socket_type tables_socket_; //ID¶ÔÕÕ±í
    
    
};


typedef boost::serialization::singleton<ClxTcpServerIdTable> ClxTcpServerIdTableInstance;




#endif /* ClxTcpServerIdTable_hpp */
