/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:53:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/11/15 11:46:10 by minjinki         ###   ########.fr       */
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include "Client.hpp"
#include "Channal.hpp"
#include "Command.hpp"

class	Channal;
class	Client;

class Server
{
	private:
		int						_port;
		int						_server_soc;
		std::string				_password;

		std::map<int, Client *>	_clients;
		std::list<Channal *>	_channals;

		Server();
		Server( const Server &s );

		Server &operator=(const Server &ref);

		int		_init();

	public:
		Server( int port, std::string password );
		~Server();

		int		run();
};

#endif