/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:10 by minjinki          #+#    #+#             */
/*   Updated: 2023/11/15 13:09:07 by minjinki         ###   ########.fr       */
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

void	Server::_kqueue()
{
	this->_kq = kqueue();
	if (this->_kq == -1)
	{
		close(this->_serverSoc);
		throw kqueueException();
	}

	struct kevent	kev;

	EV_SET(&kev, this->_serverSoc, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	this->_kev.push_back(kev);
}

void	Server::_init()
{
	this->_serverSoc = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_serverSoc == -1)
		throw socketException();

	int	opt = 1;
	if (setsockopt(this->_serverSoc, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
		throw socketException();

	struct	sockaddr_in	sockAddr;
	
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockAddr.sin_port = htons(this->_port);

	if (bind(this->_serverSoc, (struct sockaddr *)&sockAddr, sizeof(sockAddr)))
	{
		close(this->_serverSoc);
		throw bindException();
	}

	if (listen(this->_serverSoc, 10))
	{
		close(this->_serverSoc);
		throw listenException();
	}

	// set non-blocking
	fcntl(this->_serverSoc, F_SETFL, O_NONBLOCK);

	this->_kqueue();

	// close socket
	std::cout << close(this->_serverSoc) << std::endl;
}

void	Server::run()
{
	this->_init();
}

const char	*Server::socketException::what() const throw()
{
	return ("Exception: socket error");
}

const char	*Server::bindException::what() const throw()
{
	return ("Exception: bind error");
}

const char	*Server::listenException::what() const throw()
{
	return ("Exception: listen error");
}

const char	*Server::kqueueException::what() const throw()
{
	return ("Exception: kqueue error");
}
