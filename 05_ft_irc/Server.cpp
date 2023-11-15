/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:10 by minjinki          #+#    #+#             */
/*   Updated: 2023/11/15 12:21:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() {}

Server::Server( const Server &s )
{
	(void)s;
}

Server::Server( int port, std::string password )
	: _port(port), _password(password)
{
	(void)_port;
	(void)_password;
}

Server::~Server() {}

Server	&Server::operator=( const Server &s )
{
	(void)s;
	return (*this);
}

void	Server::_init()
{
	this->_server_soc = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_server_soc == -1)
		throw socketException();

	int	opt = 1;
	if (setsockopt(this->_server_soc, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
		throw socketException();
	
	// close socket
	std::cout << close(this->_server_soc) << std::endl;
}

void	Server::run()
{
	this->_init();
}

const char*	Server::socketException::what() const throw()
{
	return ("Exception: socket error");
}