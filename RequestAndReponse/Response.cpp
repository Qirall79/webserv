/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:19:17 by mohilali          #+#    #+#             */
/*   Updated: 2024/09/30 14:36:10 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"


Response::Response(){
	this->MIMeType[".html"] = "text/html; charset=UTF-8";
	this->MIMeType[".css"] = "text/css";
	this->MIMeType[".js"] = "application/javascript";
	this->MIMeType[".jpg"] = "image/jpeg";
	this->MIMeType[".jpeg"] = "image/jpeg";
	this->MIMeType[".png"] = "image/png";
	this->MIMeType[".gif"] = "image/gif";
	this->MIMeType[".json"] = "application/json";
	this->MIMeType[".xml"] = "application/xml";
	this->MIMeType[".txt"] = "text/plain";
}



void    Response::setStatusLine(std::string _Status){
	this->StatusLine = _Status;
}

std::string Response::getStatusLine(){
	return (this->StatusLine);
}

const char *Response::ResponseException::what() const throw(){
	return error.c_str();
}

Response::ResponseException::ResponseException(const std::string &msg) : error(msg){};
Response::ResponseException::~ResponseException() throw(){};

void Response::setMap(std::string _name, std::string _Value){
	this->ResponseMeth[_name] = _Value;
}

Response::Response(const Response &Obj){
	this->MIMeType = Obj.MIMeType;
	this->ResponseMeth = Obj.ResponseMeth;
}

Response& Response::operator=(const Response &Obj){
	if (this != &Obj){
		this->ResponseMeth = Obj.ResponseMeth;
		this->MIMeType = Obj.MIMeType;
	}
	return (*this);
}

std::map<std::string, std::string> Response::getMap() const {
	return (this->ResponseMeth);
}

std::string Response::getMIMeType(std::string _Key){
	
	try{
		return (this->MIMeType.at(_Key));
	} catch (const std::out_of_range& e){
		std::cerr << "Expection: Key not found" << e.what() << std::endl;
		return "";
	}
}

Response::~Response(){
}