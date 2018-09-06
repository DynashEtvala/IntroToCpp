#pragma once
#include<iostream>
using namespace std;

struct ServerInfo
{
	int regionID;             // region
	int currentPlayerCount;   // current player count
	int maxPlayers;           // max player count
	int ping;                 // ping
};