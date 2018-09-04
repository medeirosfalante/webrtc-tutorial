#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>



using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;


typedef websocketpp::server<websocketpp::config:asio> WebSocketServer;

typedef WebSocketServer::message_ptr message_ptr;

WebSocketServer server;

void OnSockerMessage(WebSocketServer* s,websocketpp::connection_hd1 hd1, message_ptr msg){
    std::cout << msg->get_payload() << std::endl;
}



int main(){
    server.set_message_handler(bind(OnSockerMessage,&server,::_1,::_2));
    server.init_asio()
    server.set_reuse_addr(true);
    server.listen(8080);
    server.start_accept();
    server.run();
}