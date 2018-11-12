public class Node{
     private String nameN;
     private boolean Q0,F;

     public Node(){
     }

     public Node(String nameN) {
         this.nameN = nameN;
     }

     public String toString() {
         return nameN;
     }

     public void setNameN(String name){
         this.nameN = name;
     }

    public boolean equals(String aux){
         if (aux.length() != nameN.length()) return false;
         for(int i=0;i<aux.length();i++){
             if(aux.charAt(i) != nameN.charAt(i)) return false;
         }
         return true;
    }
}
