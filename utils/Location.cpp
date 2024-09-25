/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:31:10 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/09/24 11:18:51 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"

Location::Location( void ) {
};

Location::Location( ServerNode* server ) {
    this->server = server;
}

void Location::setServer( ServerNode* server ) {
    this->server = server;
}

std::map<std::string, Field > Location::getFields( void ) {
    return this->fields;
}

void Location::addField( std::string key, std::string value ) {
    this->fields[key].addValue(value);
}

Field Location::getField( std::string key ) {
    if (this->fields.find(key) != this->fields.end())
        return this->fields[key];
    return this->server->getField(key);
}