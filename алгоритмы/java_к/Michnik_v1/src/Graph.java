import java.io.File;
import java.io.IOException;
import java.util.Scanner;
 
public class Graph {
    private int count;
    private int[][] matrix;
    private boolean[] marks;
 
    public Graph(int count){
        this.count=count;
        matrix=new int[count][count];
        marks=new boolean[count];
    }
 
    public void setEdge(int a,int b,int weight){
        matrix[a][b]=weight;
        matrix[b][a]=weight;
    }
 
    public int getEdge(int a,int b){
        return matrix[a][b];
    }
 
    public boolean hasEdge(int a,int b){
        return matrix[a][b]!=0;
    }
 
    public static Graph load(File file) throws IOException {
        Scanner sc=new Scanner(file);
 
        Graph graph=new Graph(sc.nextInt());
 
        while(sc.hasNext()){
            int a=sc.nextInt();
            int b=sc.nextInt();
            int weight=sc.nextInt();
 
            graph.setEdge(a,b,weight);
        }
        sc.close();
        return graph;
    }
 
    public static Graph load(String filename) throws IOException {
        return load(new File(filename));
    }
 
    public boolean enter(int pos){
        if(marks[pos]){
            return false;
        }else{
            marks[pos]=true;
            return true;
        }
    }
 
    public void leave(int pos){
        marks[pos]=false;
    }
 
    public int getCount(){
        return count;
    }
 
    public boolean allVisited(){
        for(int i=0;i<marks.length;i++){
            if(!marks[i])return false;
        }
        return true;
    }
}