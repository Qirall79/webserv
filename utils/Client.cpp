/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:12:11 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/11/13 12:29:17 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client( std::vector<ServerNode*>& servers):
servers(servers),
keepAlive(false) {
    this->response = new Response();
    this->request = new Request();
    this->response->setClient(this);
    this->parentServer = NULL;
    this->responseReady = false;
    this->timerStart = time(NULL);
};

Client::Client( std::vector<ServerNode*>& servers, std::string message, int fd):
servers(servers), message(message), fd(fd), keepAlive(false) {
    this->response = new Response();
    this->request = new Request();
    this->response->setClient(this);
    this->parentServer = NULL;
    this->responseReady = false;
    this->timerStart = time(NULL);
}

Client::~Client( void ) {
    delete this->response;
    delete this->request;
};

std::string& Client::getMessage( void ){
    return this->message;
}

void Client::setMessage( std::string message ) {
    this->message = message;
}

void Client::appendMessage( std::string message ) {
    this->message += message;
}

int Client::getFd( void )
{
    return this->fd;
}

void Client::setFd( int fd ) {
    this->fd = fd;
}

bool Client::isResponseReady( void ) {
    return this->responseReady;
}

Response& Client::getResponse( void ){
    return (*this->response);
}

void Client::resetResponse( void ) {
}

Request& Client::getRequest( void ){
    return (*this->request);
}

bool Client::isKeepAlive( void ) {
    return this->keepAlive;
}

std::vector<ServerNode*>& Client::getServers( void ) {
    return this->servers;
}

void Client::setListen( std::string listen ) {
    this->listen = listen;
}

std::string Client::getListen( void ) {
    return this->listen;
}

void Client::findParentServer( void ) {
    std::string host = this->getRequest().getValue("Host");
    std::vector<ServerNode*> &servers = this->servers;
    std::vector<std::string> serverNames;
    std::string serverListen;
    bool matched = false;

    for (int i = 0; i < (int) servers.size(); i++) {
        serverListen = servers[i]->getField("listen").getValues()[0];
        
        
        if (serverListen == this->listen) {
            if (this->parentServer == NULL) {
                this->parentServer = servers[i];
            }

            serverNames = servers[i]->getField("server_name").getValues();

            for (int j = 0; j < (int) serverNames.size(); j++) {
                if (host == serverNames[j]) {
                    this->parentServer = servers[i];
                    matched = true;
                    break ;
                }
            }
        }
        if (matched)
            break ;
    }
}

ServerNode& Client::getParentServer( void ) {
    return *(this->parentServer);
}
