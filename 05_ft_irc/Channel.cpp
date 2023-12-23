/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:14:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/12/09 01:38:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

// 기본 생성자
Channel::Channel() : _isInviteOnly(false), _isTopicRestricted(false) {
    this->_accessLimit = 1000000;
}

// 복사 생성자
Channel::Channel(const Channel &c)
    : _isInviteOnly(c._isInviteOnly), _isTopicRestricted(c._isTopicRestricted),
      _channelName(c._channelName), _topic(c._topic), _password(c._password),
      _clients(c._clients) {}


// 대입 연산자 오버로딩
Channel &Channel::operator=(const Channel &c)
{
    if (this != &c)
    {
        _isInviteOnly = c._isInviteOnly;
        _isTopicRestricted = c._isTopicRestricted;
        _channelName = c._channelName;
        _topic = c._topic;
        _password = c._password;
        _clients = c._clients;
        _operators = c._operators;
    }
    return *this;
}

bool    Channel::operator<( const Channel &c ) const
{
    return (this->_channelName < c._channelName);
}

bool	Channel::operator<=( const Channel &c ) const
{
	return (this->_channelName <= c._channelName);
}

bool	Channel::operator>( const Channel &c ) const
{
	return (this->_channelName > c._channelName);
}

bool	Channel::operator>=( const Channel &c ) const
{
	return (this->_channelName >= c._channelName);
}


bool Channel::isOwner(Client& client)
{
	if (this->_clientAuth[client.getNick()] == "OWNER")
		return true;
	return false;
}

bool Channel::isOperator(Client& client)
{
    return _operators.find(&client) != _operators.end();
}

bool Channel::checkmode(char mode)
{
    std::string modeStr(1, mode);

    if (this->_mode.find(modeStr) != this->_mode.end())
	{
		return true;
	}

	return false;
}

Channel::Channel(const std::string &ChannelName, Client &client, std::string key)
    : _isInviteOnly(false), _isTopicRestricted(false), _channelName(ChannelName)
{
    char        buf[100];
    time_t      clock;
    struct tm*	tm_struct;

    if (key != "") {
        this->_password = key;
    }
    else{
        this->_password = "";
    }
    this->_topic = "";
    _clients.insert(&client);
    this->_owner = &client;
    this->_clientAuth[client.getNick()] = "OWNER";
    this->_accessLimit = 1000000;
    this->addOperator(client);
    clock = time(NULL);
    tm_struct = localtime(&clock);
    strftime(buf, 100, "%Y-%m-%d %H:%M:%S", tm_struct);
    std::cout << "time: " << buf << std::endl;
    this->_create_time = buf;
}

// 소멸자
Channel::~Channel() {}

// 클라이언트 추가
int Channel::addClient(Client &client)
{
    _clients.insert(&client);
    return 0;
}

// 오퍼레이터 추가
void Channel::addOperator(Client &client)
{
    _operators.insert(&client);
}

void Channel::dismissOperator(Client &client)
{
    _operators.erase(&client);
}

// 오퍼레이터 제거
int Channel::removeOperator(Client &client)
{
    _operators.erase(&client);
    return 0;
}

// 클라이언트 강퇴
int Channel::kickClient(Client &client)
{
    _clients.erase(&client);
    return 0;
}

std::string Channel::getWhoSetTopic(){
    return this->_topicSetUser;
}

std::string Channel::getTopicSetTime(){
    return this->_topicSetTime;
}

void Channel::setOwner(Client& client)
{
	this->_owner = &client;
}

void Channel::joinClient(Client& client, std::string auth)
{
	if (auth == "OWNER")
		this->setOwner(client);
	std::string name = client.getNick();
	this->_clients.insert(&client);
    this->_clientAuth[client.getNick()] = auth;
}

// 토픽 설정
int Channel::setTopic(Client &client, const std::string &topic)
{
    char		buf[100];
	time_t		clock_timer;
    struct tm*	tm_struct;

	clock_timer = time(NULL);	// 현재 시간을 초 단위로 얻기
	tm_struct = localtime(&clock_timer);
	// 로컬 타임을 기준으로 tm 구조체를 만들어줌

    _topicSetUser = client.getNick();
	strftime(buf, 100, "%Y-%m-%d %H:%M:%S", tm_struct);
	_topicSetTime = buf;
    _topic = topic;
    return (0);
}

unsigned int Channel::getUserCountLimit(){
    return this->_accessLimit;
}

void Channel::setPassword(std::string password){
    this->_password = password;
}

// 모드 설정
void Channel::setMode(std::string mode)
{
    this->_mode.insert(mode);
}

void Channel::delMode(std::string mode)
{
    this->_mode.erase(mode);
}

void    Channel::setName( std::string name )
{
    this->_channelName = name;
}

// 채널에 속한 클라이언트들 반환
std::set<Client *> Channel::getClients()
{
    return _clients;
}

// 채널에 속한 클라이언트들 반환
Client* Channel::getClient(std::string nickname)
{
    for (std::set<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        Client* client = *it;
        if (client->getNick() == nickname)
        {
            return client;
        }
    }
    return NULL;
}

std::string Channel::getName(){
    return this->_channelName;
}

void removeChannel(Server *server, const std::string &channelName)
{
    Channel *channel = server->getChannel(channelName);

    if (channel)
        server->getChannels().erase(channel->getName());
	else
        std::cout << "Channel not found: " << channelName << std::endl;
}

void Channel::setUserNumberLimit(unsigned int limit)
{
    this->_accessLimit = limit;
}

std::string Channel::getPassword()
{
    return this->_password;
}

std::set<std::string> Channel::getMode()
{
    return this->_mode;
}

bool Channel::getInviteMode() const
{
	if (this->_mode.find("i") != this->_mode.end())
		return true;
	return false;
}

bool Channel::checkInvite(std::string nickname)
{
    if (this->_inviteName.find(nickname) == this->_inviteName.end()){
        return false;
    }
    else{
        this->_inviteName.erase(nickname);
        return true;
    }
}

std::string Channel::getTopic()
{
    return (this->_topic);
}

bool    Channel::isClient( std::string nick )
{
	ClientSet	clients = this->getClients();

	for (ClientSet::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (nick == (*it)->getNick())
            return (true);
	}

	return (false);
}

void	Channel::removeClient(std::string nick )
{
	ClientSet			clients = this->getClients();
	ClientSet::iterator	it = clients.begin();

	for (; it != clients.end(); it++)
	{
		if (nick == (*it)->getNick())
		{
			std::cout << "remove client " << (*it)->getNick() << " from " << this->getName() << std::endl;
			clients.erase(it);
            break;
		}
	}

	this->_clients = clients;
}


void	Channel::removeAuth( std::string nick )
{
    this->_clientAuth.erase(nick);
}

ClientSet	&Channel::getOperators()
{
    return (this->_operators);
}

// 클라이언트 제거
int Channel::removeClientinServer(Server *server, Client &client )
{
    _clients.erase(&client);
	_operators.erase(&client);
	_inviteName.erase(client.getNick());

    // 클라이언트가 채널에 남아 있는 유일한 클라이언트였다면 채널 삭제
    if (_clients.empty())
    {
        removeChannel(server, this->getName());
    }

    return 0;
}

std::string Channel::getChannelCreateTime()
{
    return this->_create_time;
}

bool Channel::isMode(std::string mode)
{
    if (this->_mode.find(mode) != this->_mode.end())
        return true;
    return false;
}

void   Channel::addInviteList(std::string name)
{
    this->_inviteName.insert(name);
}

std::string	Channel::getAuth(const std::string &nick )
{
	if (this->_clientAuth.find(nick) != this->_clientAuth.end())
		return (this->_clientAuth[nick]);
	else
		return ("");
}

