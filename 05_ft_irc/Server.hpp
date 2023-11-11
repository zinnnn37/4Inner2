/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:53:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/11/11 13:17:43 by minjinki         ###   ########.fr       */
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
		int					port;
		int					server_soc;
		std::string			password;

		map<int, Client *>	_clients;
		list<Channal *>		_channals;

		Server();
		Server( const Server &s );

		Server &operator=(const Server &ref);

	public:
		Server( const char *port, const char *password );
		~Server();

		int		init();
};

#endif