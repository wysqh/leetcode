#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>
#include <ctime>
#include <deque>
#include <set>
#include <sstream>
using namespace std;

class DebugTool
{
public:
	virtual void debug_print() = 0;
};

struct NetInfo : public DebugTool
{
	int netNodeNumber;
	int netCircuitNumber;
	int consumeNodeNumber;

	NetInfo()
	{
	}

	NetInfo(string netInfo);

	void debug_print();
};

void NetInfo :: debug_print()
{
	cout << "==>网络信息==>" << endl;
	cout << "netNodeNumber: " << netNodeNumber << endl;
	cout << "netCircuitNumber: " << netCircuitNumber << endl;
	cout << "consumeNodeNumber: " << consumeNodeNumber << endl;
}

struct Server : public DebugTool
{
	int id;
	int capacity;
	int cost;
	Server(int _id, int _capacity, int _cost) : 
		id(_id), capacity(_capacity), cost(_cost)
	{
	}

	void debug_print();
};

void Server::debug_print()
{
	cout << "==>服务器信息==>" << endl;
	cout << "id: " << id << endl;
	cout << "capacity: " << capacity << endl;
	cout << "cost: " << cost << endl;
}

struct DeployNode : public DebugTool
{
	int id;
	int cost;
	DeployNode(int _id, int _cost) : id(_id), cost(_cost)
	{
	}

	void debug_print();
};

void DeployNode::debug_print()
{
	cout << "==>节点费用信息==>" << endl;
	cout << "id: " << id << endl;
	cout << "cost; " << cost << endl;
}

struct NetCircuit : public DebugTool
{
#define BLACK 1
#define WHITE 0
	int src;
	int dst;
	int totalCapacity;	//not used	//其实也可以用
	vector<int> bichannel;
	int cost;

	// for 残存网络
	int f;
	
	NetCircuit()
	{
	}

	NetCircuit(int _src, int _dst, int _total, int _cost, int _f = 0) 
		: src(_src), dst(_dst), totalCapacity(_total), cost(_cost), f(_f), bichannel(2, 0)
	{
		bichannel[0] = totalCapacity;
	}

	void debug_print();
};

void NetCircuit :: debug_print()
{
	cout << "==>链路信息==>" << endl;
	cout << "src: " << src << endl;
	cout << "dst; " << dst << endl;
	cout << "totalCapacity: " << totalCapacity << endl;
	cout << "cost; " << cost << endl;
}

struct ConsumeNode : DebugTool
{
	int id;
	int nodeId;
	int requirement;	
	int teamId;

	ConsumeNode(int _id, int _nodeId, int _requirement, int _teamId)
		: id(_id), nodeId(_nodeId), requirement(_requirement), teamId(_teamId)
	{
	}

	void debug_print();
};

void ConsumeNode::debug_print()
{
	cout << "==>消费节点信息==>" << endl;
	cout << "id: " << id << endl;
	cout << "nodeId; " << nodeId << endl;
	cout << "requirement: " << requirement << endl;
	//cout << "teamId; " << teamId << endl;
}

struct Info	: public DebugTool
{
	NetInfo netInfo;
	int teamId;
	int asset;

	Info()
	{
	}

	Info(string netInfo, string info);

	Info(const NetInfo _info, const int _teamId, int _asset)
		: netInfo(_info), teamId(_teamId), asset(_asset)
	{
	}

	void debug_print();
};

void Info::debug_print()
{
	netInfo.debug_print();
	cout << "==>个人信息==>" << endl;
	cout << "teamId: " << teamId << endl;
	cout << "asset: " << asset << endl;
}

struct ServerPostion
{
	int serverId;
	int nodeId;

	ServerPostion(int _serverid, int _nodeid) : serverId(_serverid), nodeId(_nodeid)
	{
	}
};

struct VectorEdge
{
	int src;
	int dst;
	int biedges;
	
	VectorEdge(int _src, int _dst) : src(_src), dst(_dst), biedges(0)
	{
	}

	VectorEdge(int _src, int _dst,int bi) : src(_src), dst(_dst), biedges(bi)
	{
	}
};

struct AugmentPath
{
	vector<int> vertex;
	vector<VectorEdge> linkage;

	AugmentPath()
	{
	}
};

struct Node
{
	// for BFS
	int id;
	int color;
	int dis;
	int parent;

	Node(int _id) : id(_id), color(WHITE), dis(0), parent(-1)
	{
	}
};

class MyNodeCompare
{
public:
	bool operator() (const Node& a, const Node& b)
	{
		return a.id < b.id;
	}
}myNodeComp;

struct Feasibles
{
	vector<vector<unordered_map<int, NetCircuit>>> fbSpaces;
	vector<int> NodeNumber;

	Feasibles()
	{
	}
};

struct MinInfo
{
	int minServer;
	int minCost;

	MinInfo(int _minServer = 0, int _minCost = 0) : minServer(_minServer), minCost(_minCost)
	{
	}
};

class Console : public DebugTool
{
public:
	NetInfo* info;	//配置信息
	vector<ConsumeNode> consumeNode;	//消费节点信息
	vector<unordered_map<int, NetCircuit>> circuits;	//网络链路信息
	vector<Node> nodes;	//网络链路节点
	int pay;	//用户支付费用

	Console(char* inLines[MAX_IN_NUM], int inLineNum) { init(inLines, inLineNum); };

	void debug_print();	//打印Console所有存储数据数据
	int getMinServerByDp(vector<int>& __list);	//通过动态规划获取最少部署服务器数量,__list返回__list[服务器id]租用的数量.
	int getTotalRequirement();	//获取总共链路需求
	void generate(vector<int> info, vector<ServerPostion>& __addresslist);	//随机生成给定服务器地址, __addresslist返回结果
	bool validate(vector<ServerPostion> serverNode, vector<vector<int>>& __paths); //验证给定服务器数量下网络拓扑图环境下,最小节点数量可行性, __path返回结果 
	void depth_first(int src, int dst);
	void Ford_Fulkerson(vector<int> serverNode, Feasibles&  __feasibles);	//最大网络流
	bool hasPath(int src, int dst, AugmentPath&  __path);	//返回残存网络中的一条增广路径__path
	void breadthFirstSearch(int src, int dst, AugmentPath& __path);	//广度优先搜索
	vector<Node>::iterator findNodeById(int id); //根据id返回一个Node的迭代器
	bool judge();	//判断某种选址是否应该放入解空间
	void restoreOriginbalState();	//恢复原链路状态
	int localOptimalSearch(MinInfo& __minInfo);	//局部最优搜索
	void findAlternativeNodes(vector<int>& __alternatives);	//获取备选服务器部署节点	
private:
	void init(char* inLines[MAX_IN_NUM], int inLineNum);
	void initServer(const char*);
	void initDeployNode(const char*);
	void initConsumeNode(const char*);
	void initCircuits(const char*);

	int getFigure(int number);	//获取位数

	vector<unordered_map<int, NetCircuit>> residual_circuits;	//残存网络
	vector<unordered_map<int, NetCircuit>> dylinkage;	//动态网络链路信息
	vector<Server> server;	//服务器相关信息
	vector<DeployNode> deployNode;	//网络节点部署费用
};

NetInfo::NetInfo(string info)
{
	stringstream ss(info);
	int netNodeNumber, netCircuitNumber, consumeNodeNumber;

	ss >> netNodeNumber >> netCircuitNumber >> consumeNodeNumber;

	this->netNodeNumber = netNodeNumber;
	this->netCircuitNumber = netCircuitNumber;
	this->consumeNodeNumber = consumeNodeNumber;
}

Info::Info(string netInfo, string info): netInfo(netInfo)
{
	stringstream ss(info);
	int asset, teamId;

	ss >> teamId >> asset;

	this->asset = asset;
	this->teamId = teamId;
}

void Console ::init(char* inLines[MAX_IN_NUM], int inLineNum)
{
	const char* src = inLines[0];

	info = new NetInfo(src);	

	//预留链路
	circuits.reserve(info->netNodeNumber + 2);	
	circuits.resize(info->netNodeNumber + 2);
	residual_circuits.reserve(info->netNodeNumber + 2);
	residual_circuits.reserve(info->netNodeNumber + 2);

	//动态变化值初始化
	dylinkage = circuits;

	int nbspN = 0;
	for (int i = 0; i < inLineNum; ++i)
	{
		const char* curline = inLines[i];
		if (string(curline).size() == 1)
		{
			++nbspN;
			continue;
		}

		switch (nbspN)
		{
		case 1: pay = atoi(curline); break;
		case 2:	initCircuits(curline);	break;
		case 3:	initConsumeNode(curline);	break;
		default:
			break;
		}
	}

	for (int i = 0; i < info->netNodeNumber+2; ++i)
		nodes.push_back(i);
}

void Console::initServer(const char* data)
{
	int id, capacity, cost;
	stringstream ss(data);
	ss >> id >> capacity >> cost;
	server.push_back(Server(id, capacity, cost));
}

void Console::initDeployNode(const char* data)
{
	int id, cost;
	stringstream ss(data);
	ss >> id >> cost;
	deployNode.push_back(DeployNode(id, cost));
}

void Console::initCircuits(const char* data)
{
	int src, dst, totalCapacity, rendCost;
	stringstream ss(data);
	ss >> src >> dst >> totalCapacity >> rendCost;
	circuits[src].insert(pair<int, NetCircuit>(dst, NetCircuit(src, dst, totalCapacity, rendCost)));
}

void Console::initConsumeNode(const char* data)
{
	int id, nodeId, requirement,teamId;
	stringstream ss(data);
	ss >> id >> nodeId >> requirement >> teamId;
	consumeNode.push_back(ConsumeNode(id, nodeId, requirement, teamId));
}

//打印Console所有存储数据数据
void Console::debug_print()
{
	info->debug_print();
	cout << "pay: " << pay << endl;

	for(auto& c: circuits)
		for(auto& m: c)
			m.second.debug_print();

	for(auto& c: consumeNode)
		c.debug_print();
}

//获取总共链路需求
int Console::getTotalRequirement()
{
	int reqWithoutLink = 0;
	for(const auto &c : consumeNode)
		reqWithoutLink += c.requirement;
	
	return reqWithoutLink;
}

//通过动态规划获取最少部署服务器数量
int Console::getMinServerByDp(vector<int>& __list)
{
	int sum = getTotalRequirement();
	int indice = server.size() - 1;
	int number = 0;

	__list.reserve(server.size());
	__list.resize(server.size());


	while (indice >= 0 && sum > 0)
	{
		while(sum - server[indice].capacity >= 0)
		{
			sum -= server[indice].capacity;
			number++;
		}
		__list[indice] = number;
		--indice;
	}

	for (int i = 0; i < __list.size() - 1; ++i)
		__list[i] = __list[i] - __list[i+1]; 
	
	if (sum != 0)
		__list[0]++;

	return sum == 0 ? number : (number + 1); 
}

//随机生成给定服务器地址, __addresslist返回结果
void Console :: generate(vector<int> server_info, vector<ServerPostion>& __addresslist)
{
	srand(time(NULL));
	for (int i = 0; i < server_info.size(); ++i)
	{
		while (server_info[i]-- > 0)
			__addresslist.push_back(ServerPostion(i, rand()%info->netNodeNumber));
	}

	//for (auto& e: __addresslist)
	//	cout << e.nodeId << " " << e.serverId << endl;
}

//获取位数
int Console :: getFigure(int number)
{
	int figure = 0;
	while (abs(number) > 0)
	{
		number /= 10;
		figure ++;
	}

	return figure;
}

//验证给定服务器数量下网络拓扑图环境下,最小节点数量可行性
bool Console::validate(vector<ServerPostion> serverNode, vector<vector<int>>& __paths)
{
	__paths.reserve(consumeNode.size());
	__paths.resize(consumeNode.size());

	random_shuffle(begin(serverNode), end(serverNode));
	
	int serverIndex = 0;
	for (int i = 0; i < consumeNode.size(); ++i)
	{
		
	}
	return true;
}

void Console::depth_first(int src, int dst)
{

}

void Console::Ford_Fulkerson(vector<int> serverNode, Feasibles& __feasibles)
{
	for(const auto& s : serverNode)
		circuits[info->netNodeNumber].insert(pair<int, NetCircuit>(s, NetCircuit(info->netNodeNumber, s, INT_MAX, 0)));

	for (const auto& c : consumeNode)
		circuits[c.nodeId].insert(pair<int, NetCircuit>(info->netNodeNumber+1, NetCircuit(c.nodeId, info->netNodeNumber+1, INT_MAX, 0)));

	int super_src = info->netNodeNumber;
	int super_dst = info->netNodeNumber + 1;

	for (auto& cirHashMap : circuits)
		for (auto& circuits : cirHashMap)
			circuits.second.f = 0;

	AugmentPath path;
	std::function<bool(const VectorEdge& a, const VectorEdge& b)>
		functor = [](const VectorEdge& a, const VectorEdge& b) -> bool {
						return a.biedges < b.biedges;
				  };

	while (hasPath(super_src, super_dst, path))
	{
		vector<VectorEdge>::iterator iter = min_element(begin(path.linkage), end(path.linkage), functor);
		int cf = iter->biedges;
		for (auto& e: path.linkage)
		{
			if (circuits[e.src][e.dst].bichannel[0] != 0)
				circuits[e.src][e.dst].f = circuits[e.src][e.dst].f + cf;
			else circuits[e.dst][e.src].f = circuits[e.dst][e.src].f - cf;
		}
	}

	if (judge())
	{
		__feasibles.fbSpaces.push_back(circuits);	//可行解的加入
		__feasibles.NodeNumber.push_back(serverNode.size());
	}

	//恢复原链路状态
	restoreOriginbalState();

	return;
};

bool Console::hasPath(int src, int dst, AugmentPath& __path)
{
	//增广路径初始化
	__path.linkage.clear();
	__path.vertex.clear();

	//残存网络初始化
	residual_circuits.clear();
	residual_circuits.reserve(info->netNodeNumber+2);
	residual_circuits.resize(info->netNodeNumber+2);

	for (const auto & eMap: circuits)
	{
		for (const auto & e: eMap)
		{
			residual_circuits[e.second.src].insert(
					pair<int, NetCircuit>(e.second.dst, NetCircuit(e.second.src, e.second.dst, e.second.totalCapacity, e.second.cost, e.second.totalCapacity - e.second.f)));
			residual_circuits[e.second.dst].insert(
				pair<int, NetCircuit>(e.second.src, NetCircuit(e.second.dst, e.second.src, circuits[e.second.src][e.second.dst].totalCapacity, 
					circuits[e.second.src][e.second.dst].cost, circuits[e.second.src][e.second.dst].f)));
		}
	}

	breadthFirstSearch(src, dst, __path);
	if (__path.vertex.size() == 1)
		return false;

	return true;
}

void Console::breadthFirstSearch(int src, int dst, AugmentPath& __path)
{
	deque<int> queues;
	queues.push_back(src);

	while (!queues.empty())
	{
		int u = queues.front();
		queues.pop_front();
		for(auto& v: circuits[u])
		{
			if (v.second.f == v.second.totalCapacity)
				continue; 

			vector<Node>::iterator it = findNodeById(v.second.dst);
			assert(it != nodes.end());
			if (it->color == WHITE)
			{
				assert(u == v.second.src);
				it->dis = it->dis + 1;
				it->parent = u;
				queues.push_back(v.second.dst);
			}
		}
		findNodeById(u)->color = BLACK;
	}


	vector<Node>::iterator iter = findNodeById(dst);
	while (iter->parent != -1)
	{
		/*vector<int> biedges(2, 0);
		if (circuits[iter->parent][iter->id].bichannel[0] == 0)
			biedges[1] = residual_circuits[iter->parent][iter->id].f;
		else biedges[0] = residual_circuits[iter->parent][iter->id].f;*/
		int biedges = residual_circuits[iter->parent][iter->id].f;

		__path.vertex.push_back(dst);
		__path.linkage.push_back(VectorEdge(iter->parent, iter->id, biedges));

		iter = findNodeById(iter->parent);
	}
	__path.vertex.push_back(src);

	reverse(begin(__path.vertex), end(__path.vertex));
}

vector<Node>::iterator Console::findNodeById(int id)
{
	vector<Node>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); it++)
		if (it->id == id)
			return it;

	return nodes.end();
}

bool Console :: judge()
{
	vector<unordered_map<int, NetCircuit>> reverseNetWork;
	assert(circuits.size() == info->netNodeNumber + 2);
	reverseNetWork.reserve(circuits.size());
	reverseNetWork.resize(circuits.size());

	bool usable = true;
	for (const auto& eMap: circuits)
		for (const auto& e : eMap)
			reverseNetWork[e.second.dst].insert(pair<int, NetCircuit>(e.second.src,
				NetCircuit(e.second.dst, e.second.src, e.second.totalCapacity, e.second.cost, e.second.f)));
	
	for (const auto& c : consumeNode)
	{
		int netflow_In = 0;
		for (const auto& relatived_nodes : reverseNetWork[c.nodeId])
			netflow_In += relatived_nodes.second.f;
		
		if (c.requirement > netflow_In)
		{
			usable = false;
			break;
		}
	}
			
	return usable;	
}

void Console::restoreOriginbalState()
{
	//restore
	circuits = dylinkage;
}

int Console::localOptimalSearch(MinInfo& __minInfo)
{
	vector<int> alternatives;
	findAlternativeNodes(alternatives);

	vector<int> possibles;	//备选部署节点位置
	Feasibles feasibles;	//解空间
	
	for (int i = 1; i < 3; i++)
	{
		possibles.clear();

		int loops = 5;
		while (loops-- >0)
		{
			random_shuffle(begin(alternatives), end(alternatives));
			
			for (int j = 0; j < i; ++j)
				possibles.push_back(alternatives[j]);

			Ford_Fulkerson(possibles, feasibles);

			if (feasibles.fbSpaces.size() > 0 && __minInfo.minServer == 0)
				__minInfo.minServer = i;
		}
	}

	//可行解解空间
	int min = INT_MAX;
	for (const auto& network : feasibles.fbSpaces)
	{
		int cost = 0;
		for (int i = 0; i < info->netNodeNumber; ++i)
			for (const auto& node : network[i])
				cost += node.second.f * node.second.cost;

		if (cost <  min)
			min = cost;
	}
	__minInfo.minCost = min;
#define OK 200
	return OK;
}

void Console::findAlternativeNodes(vector<int>& __alternatives)
{
	for (const auto& nearbys : consumeNode)
		for (const auto& element : circuits[nearbys.nodeId])
			__alternatives.push_back(element.second.dst);
}