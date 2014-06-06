from os import listdir
from os.path import isfile, join

GRAPH_PATH = 'graphs'
TEAMS_PATH = 'teams'

class Graph:

	def __init__(self, n):
		self._n = n
		self._neighbours = [[] for i in xrange(n)]

	def add_edge(self, n1, n2):
		self._neighbours[n1].append(n2)
		self._neighbours[n2].append(n1)

	def neighbours(self, ni):
		return self._neighbours[ni]

	def num_nodes(self):
		return self._n

	def num_edges(self):
		return len(self._neighbours)

	def __str__(self):
		s = 'n: ' + str(self._n) + '\n'
		s += 'm: ' + str(len(self._neighbours)) + '\n'
		for i in xrange(len(self._neighbours)):
			s += str(i) + ': [ '
			for j in xrange(len(self._neighbours[i])):
				s += str(j) + ' '
			s += ']\n'
		return s


class Team:

	def __init__(self, name):
		self._name = name
		self._paths = {}

	def add_solution(self, graph_name, path):
		self._paths[graph_name] = path

	def path_for_graph(self, graph_name):
		if (graph_name not in self._paths.keys()):
			return []
		return self._paths[graph_name]

	def name(self):
		return self._name



def build_graph_set(graph_files):
	graph_set = {}
	for f in graph_files:
		gf = open(f)
		n = int(gf.readline().replace('\n', ''))
		m = int(gf.readline().replace('\n', ''))

		g = Graph(n)
		for i in range(m):
			tupl = gf.readline().replace('\n', '').strip().split(' ')
			n1 = int(tupl[0])
			n2 = int(tupl[1])
			g.add_edge(n1, n2)

		graph_set[f.split('/')[-1].lower()] = g

	return graph_set

def load_graph_set():
	graph_files = [ join(GRAPH_PATH,f) for f in listdir(GRAPH_PATH) if isfile(join(GRAPH_PATH,f)) ]
	graph_set = build_graph_set(graph_files)
	return graph_set


def is_valid(path, graph):
	# el camino es simple
	if (len(set(path)) != len(path)):
		return False
	# el camino posee al menos un nodo, el cual es un nodo valido
	if (len(path) < 1 or graph.num_nodes() < path[0]):
			return False

	# el camino es un camino valido
	ns = graph.neighbours(path[0]) 
	for n in path[1:]:
		if n not in ns:
			return False
		ns = graph.neighbours(n)

	return True
			
# CM_XW
# 2
# K_10 1 2 3 5 6 //separado por espacio
# P_5 6 3 1 4 2 			

def build_solutions(solution_files, graph_set):
	teams = {}
	for f in solution_files:
		sf = open(f)
		name = sf.readline().replace('\n','').strip().lower()
		team = Team(name)
		n = int(sf.readline().replace('\n', ''))
		for i in range(n):
			l = sf.readline().replace('\n', '').split(' ')
			graph_name = l[0].lower()
			path = [int(x) for x in l[1:]]
			if (is_valid(path, graph_set[graph_name])):
				team.add_solution(graph_name, path)
		teams[team] = team
		sf.close()

	return teams


def max_path_size(gname, teams):
	max = 1
	for tname in teams.keys():
		if (max < len(teams[tname].path_for_graph(gname))):
			max = len(teams[tname].path_for_graph(gname))
	return max


def teams_ranking(graph_set, teams):
	# mejores soluciones hasta el momento
	max_paths = {}
	for gname in graph_set.keys():
		max_paths[gname] = max_path_size(gname, teams)

	scores = {}
	for tname in teams.keys():
		team = teams[tname]
		score = 0
		for gname in graph_set.keys():
			if (max_paths[gname] == len(team.path_for_graph(gname))):
				score += 1
		scores[tname] = score

	ranking = sorted(teams.keys(), key = lambda team_name: scores[team_name])

	return ranking, scores


def load_teams(graph_set):
	team_files = [ join(TEAMS_PATH,f) for f in listdir(TEAMS_PATH) if isfile(join(TEAMS_PATH,f)) ]
	teams = build_solutions(team_files, graph_set)
	return teams

if __name__ == '__main__':

	graph_set = load_graph_set()
	teams = load_teams(graph_set)

	ranking, scores =	teams_ranking(graph_set, teams)

	ranking.reverse()

	for team in ranking:
		print 'Team:', team.name(), '- Score:', scores[team]
