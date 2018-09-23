import javafx.scene.layout.Priority;

import java.util.*;

public class Dup {
    void solution(){
        Scanner reader = new Scanner(System.in);
        int[] curLine ;
        while (reader.hasNextLine()){
            int n = reader.nextInt();
            if (n==0){
                return;
            }
            curLine = new int[n];
            for (int i=0; i<n; i++){
                curLine[i] = reader.nextInt();
            }
            int slow =0;
            for (int i=1; i<curLine.length; i++){
                if (curLine[i] != curLine[i-1]){
                    curLine[++slow] = curLine[i];
                }
            }
            curLine = Arrays.copyOf(curLine,slow+1);
            for (int cur: curLine){
                System.out.print(cur + " ");
            }
            System.out.println("$");
        }
    }
}
