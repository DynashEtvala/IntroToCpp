#pragma once
#include"Header.h"

class ServerBrowserService
{
private:
	// An array of all servers registered with the system.
	ServerInfo servers[50]; // note: this is hard-coded for 50 servers

	void sortPing();
	void sortPlayers();
							// A count of all servers currently registered.
	int serverCount;
public:

	ServerBrowserService();

	// Registers a server with the service
	bool registerServer(ServerInfo newServer);

	// Copies server entries into the given array.
	// Returns the total number of servers provided to the array.
	int getServers(ServerInfo * dstArray, size_t dstSize);
	int getServers(ServerInfo * dstArray, size_t size, int maxResults, int pingLimit, int region, bool allowEmpty, bool allowFull);
	int getServers(ServerInfo * dstArray, size_t dstSize, bool sortMode);
	int getServers(ServerInfo * dstArray, size_t size, bool sortMode, int maxResults, int pingLimit, int region, bool allowEmpty, bool allowFull);
};

