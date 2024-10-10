/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:19:17 by mohilali          #+#    #+#             */
/*   Updated: 2024/10/10 10:29:00 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

void Response::setStatusMaps(){
	this->statusMaps[200] = "OK";
	this->statusMaps[201] = "Created";
	this->statusMaps[400] = "Bad Request";
	this->statusMaps[401] = "Unauthorized";
	this->statusMaps[403] = "Forbidden";
	this->statusMaps[404] = "Not Found";
	this->statusMaps[204] = "No Content";
	this->statusMaps[405] = "Method Not Allowed";
	this->statusMaps[413] = "Payload too Large";
	this->statusMaps[414] = "URI Too Long";
	this->statusMaps[415] = "Unsupported Media Type";
	this->statusMaps[416] = "Range Not Satisfiable";
	this->statusMaps[501] = "Not Implemented";
	this->statusMaps[505] = "HTTP Version Not Supported";
	this->statusMaps[422] = "Unprocessable Entity";
}


Response::Response(){
	this->statusCode = 200;
	this->statusLine = "";
	this->bodyResponse = "";
	this->setStatusMaps();
}
void    Response::setStatusLine(std::string _Status){
	this->statusLine = _Status;
}

std::string Response::getStatusLine(){
	return (this->statusLine);
}

int Response::GetStatusCode(){
	return (this->statusCode);
}

void Response::SetStatusCode(int _StatusCode){
	this->statusCode = _StatusCode;
}

Response::Response(const Response &Obj){
	this->MIMeType = Obj.MIMeType;
}

Response& Response::operator=(const Response &Obj){
	if (this != &Obj){
		this->MIMeType = Obj.MIMeType;
	}
	return (*this);
}

std::string Response::getMIMeType(std::string _Key){
		return (this->MIMeType.at(_Key));
}

std::string Response::createGetResponse( void ) {
	return "HTTP/1.1 404 Not Found\r\n\
Content-Length: 11\r\n\
Content-Type: text/html\r\n\
Last-Modified: Wed, 12 Aug 1998 15:03:50 GMT\r\n\
Accept-Ranges: bytes\r\n\
ETag: \"04f97692cbd1:377\"\r\n\
Date: Thu, 19 Jun 2008 19:29:07 GMT\r\n\
\r\n\
hello there";
}

Response::~Response(){
}