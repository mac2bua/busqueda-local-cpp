#!/usr/bin/python
import os
import networkx as nx
import matplotlib.pyplot as plt

def printEdgeList(G, name):
    nx.write_edgelist(G, "temp.edgelist")
    temp = open("temp.edgelist", "r+")
    out = open(name, "w+")
    out.write(str(nx.number_of_nodes(G))+ "\n")
    out.write(str(nx.number_of_edges(G))+ "\n")
    for l in temp:
        out.write(l[0:-3] + "\n")
    temp.close()
    out.close()
    os.remove("temp.edgelist")


def discPaths(numberOfTwo, numberOfHundred, name):
    out = open(name, "w+")
    n = numberOfHundred * 100 + numberOfTwo * 2
    out.write(str(n) + "\n")
    m = numberOfTwo + numberOfHundred * 99
    out.write(str(m) + "\n")
    node = 0
    for i in range(0,numberOfTwo):
        out.write(str(node) + " " + str(node+1) + "\n")
        node = node + 2

    for j in range(0,numberOfHundred):
        for x in xrange(1,100):
            out.write(str(node) + " " + str(node+1) + "\n")
            node = node + 1
        node = node + 1


'''
#Paths from P10 to P100 
for i in range(10,110,10):
    P = nx.path_graph(i)
    name = "P_"+str(i)
    printEdgeList(P,name)

#Cycles from C10 to C100
for i in range(10,110,10):
    C = nx.cycle_graph(i)
    name = "C_"+str(i)
    printEdgeList(C,name)

#Complete graphs K10 to K100
for i in range(10,110,10):
    K = nx.complete_graph(i)
    name = "K_"+str(i)
    printEdgeList(K,name)

#Wheel graph W10 to W100
for i in range(10,110,10):
    W = nx.wheel_graph(i)
    name = "W_"+str(i)
    printEdgeList(W,name)

#Random graphs of size 10 to 100,
#generated with Erdos Renyi model G(n,p)
#(https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93R%C3%A9nyi_model)
for p in [x/10.0 for x in range(2, 9)]:
    print(p)
    for i in range(10,110,10):
        R = nx.fast_gnp_random_graph(i,p)
        name = "R("+str(i)+", "+str(p)+")"
        printEdgeList(R,name)
'''

for x in xrange(1,15):
    discPaths(50, x, "50P_2and"+str(x)+"P_100")
