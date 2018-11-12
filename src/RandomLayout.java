import edu.uci.ics.jung.algorithms.layout.AbstractLayout;
import edu.uci.ics.jung.graph.Graph;

import java.awt.*;

//Se quiser criar um layout por vez:
public class RandomLayout<V,E> extends AbstractLayout<V,E>{

//Varios layout iterando:
//public class RandomLayout<V,E> extends AbstractLayout<V,E> implements IterativeContext {

    public RandomLayout(Graph<V, E> g) {
        super(g);
        }

    public RandomLayout(Graph<V, E> g, Dimension d) {
        super(g);
        setSize(d);
        }

    public void initialize() {
        layoutNodes();
        }

    public void reset() {
        }

    private void layoutNodes() {
        int clearance = 20;

        Dimension d = getSize();
        int width = d.width - clearance * 2;
        int height = d.height - clearance * 2;

        for (V v : getGraph().getVertices()) {
            if (isLocked(v)) continue;
            double x = Math.random() * width + clearance;
            double y = Math.random() * height + clearance;
            transform(v).setLocation(x, y);
            }
    }
    public void step(){
        layoutNodes();
    }

    public boolean done() {
        return false;
    }
}