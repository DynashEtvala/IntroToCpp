#include "ServerBrowserService.h"

void ServerBrowserService::sortPing()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = i; j > 0 && servers[j - 1].ping > servers[j].ping; j--)
		{
			ServerInfo hold = servers[j - 1];
			servers[j - 1] = servers[j];
			servers[j] = hold;
		}
	}
}

void ServerBrowserService::sortPlayers()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = i; j > 0 && servers[j - 1].currentPlayerCount > servers[j].currentPlayerCount; j--)
		{
			ServerInfo hold = servers[j - 1];
			servers[j - 1] = servers[j];
			servers[j] = hold;
		}
	}
}

ServerBrowserService::ServerBrowserService()
{}

bool ServerBrowserService::registerServer(ServerInfo newServer)
{
	if (serverCount < 50)
	{
		servers[serverCount] = newServer;
		serverCount++;
		return true;
	}
	return false;
}

int ServerBrowserService::getServers(ServerInfo * dstArray, size_t size)
{
	for (int i = 0; i < size && i < serverCount; i++)
	{
		dstArray[i] = servers[i];
	}
	return size < serverCount ? size : serverCount;
}

int ServerBrowserService::getServers(ServerInfo * dstArray, size_t size, int maxResults, int pingLimit, int region, bool allowEmpty, bool allowFull)
{
	for (int i = 0; i < size && i < serverCount && i < maxResults; i++)
	{
		if ((servers[i].ping < pingLimit && servers[i].regionID == region) && (!allowEmpty && servers[i].currentPlayerCount != 0) && (!allowFull && servers[i].currentPlayerCount < servers[i].maxPlayers))
		{
			dstArray[i] = servers[i];
		}
	}
	return (size < serverCount ? size : serverCount) < maxResults ? (size < serverCount ? size : serverCount) : maxResults;
}

int ServerBrowserService::getServers(ServerInfo * dstArray, size_t size, bool sortType)
{
	if (sortType)
	{
		sortPlayers();
	}
	else
	{
		sortPing();
	}
	for (int i = 0; i < size && i < serverCount; i++)
	{
		dstArray[i] = servers[i];
	}
	return size < serverCount ? size : serverCount;
}

int ServerBrowserService::getServers(ServerInfo * dstArray, size_t size, bool sortType, int maxResults, int pingLimit, int region, bool allowEmpty, bool allowFull)
{
	if (sortType)
	{
		sortPlayers();
	}
	else
	{
		sortPing();
	}
	for (int i = 0; i < size && i < serverCount && i < maxResults; i++)
	{
		if ((servers[i].ping < pingLimit && servers[i].regionID == region) && (!allowEmpty && servers[i].currentPlayerCount != 0) && (!allowFull && servers[i].currentPlayerCount < servers[i].maxPlayers))
		{
			dstArray[i] = servers[i];
		}
	}
	return (size < serverCount ? size : serverCount) < maxResults ? (size < serverCount ? size : serverCount) : maxResults;
}