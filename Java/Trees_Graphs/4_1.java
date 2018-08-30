package Trees_Graphs;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class Searching {
		
	private class Node{
		int data;
		ArrayList<Node> neighbour = new ArrayList<Node>();
	}
	private class Graph{
		//Implement a Adjacency list of nodes
		HashMap<Node, ArrayList<Node>> graph = new HashMap<Node, ArrayList<Node>>();
	}
	private ArrayList<Node> BFS_search(Graph graph, Node node1, Node node2){
		if(node1 == null || node2 == null){
			return null;
		}
		
		LinkedList<Node> queue = new LinkedList<Node>();
		ArrayList<Node> visited = new ArrayList<Node>();
		
		queue.add(node1);
		visited.add(node1);
		while (!queue.isEmpty()){
			Node currNode = queue.pop();
			for (Node n : graph.graph.get(currNode)){
				if(!visited.contains(n) && !n.equals(node2)){
					visited.add(n);
					queue.add(n);
					
				}
			}
		}
		return visited;
		
	}

}


