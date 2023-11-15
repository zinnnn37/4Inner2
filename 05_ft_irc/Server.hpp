/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:53:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:59 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <exception>

// #include "Client.hpp"
// #include "Channal.hpp"
// #include "Command.hpp"

class	Channal;
class	Client;

class Server
{
	private:
		int							_port;
		int							_serverSoc;
		std::string					_password;

		int							_kq;
		std::list<struct kevent>	_kev;

		// std::map<int, Client *>		_clients;
		// std::list<Channal *>		_channals;

		Server();
		Server( const Server &s );

		Server &operator=( const Server &s );

		void	_init();
		void	_kqueue();

	public:
		Server( int port, std::string password );
		~Server();

		void	run();

		class	socketException : std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	bindException : std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	listenException : std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	kqueueException : std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif