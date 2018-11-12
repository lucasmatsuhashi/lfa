import edu.uci.ics.jung.graph.UndirectedSparseGraph;

public class Graph {

   public Graph(){
        edu.uci.ics.jung.graph.Graph<Node,Edge> g = new UndirectedSparseGraph<Node,Edge>();
        Node n1 = new Node("n1");
        Node n2 = new Node("n2");
        Node n3 = new Node("n3");
        Node n4 = new Node("n4");
        Node n5 = new Node("n5");
        Node n6 = new Node("n6");
        Node n7 = new Node("n7");
        Node n8 = new Node("n8");
        g.addEdge(new Edge("e1"), n1, n2);
        g.addEdge(new Edge("e2"), n2, n3);
        g.addEdge(new Edge("e3"), n3, n4);
        g.addEdge(new Edge("e4"), n4, n1);
        g.addEdge(new Edge("e5"), n5, n6);
        g.addEdge(new Edge("e6"), n6, n7);
        g.addEdge(new Edge("e7"), n7, n8);
        g.addEdge(new Edge("e8"), n8, n5);
        g.addEdge(new Edge("e9"), n1, n5);
        g.addEdge(new Edge("e10"), n2, n6);
        g.addEdge(new Edge("e11"), n3, n7);
        g.addEdge(new Edge("e12"), n4, n8);
    }
}
