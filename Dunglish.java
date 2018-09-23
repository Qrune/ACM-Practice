import java.util.*;

public class DUnglish {
    static void solution(){
        Scanner reader = new Scanner(System.in);
        long n = reader.nextInt();
        Map<String,List<String>> cor = new HashMap<>();
        Map<String,List<String>> inc = new HashMap<>();
        List<String> sen = new ArrayList<>();
        for (long i=0; i<n; i++){
            String cur = reader.next();
            sen.add(cur);
            cor.put(cur,new ArrayList<String>());
            inc.put(cur,new ArrayList<String>());
        }
        long m = reader.nextInt();

        Map<String, String> trans = new HashMap<>();
        for (long i=0; i<m; i++){
            String from = reader.next();
            String to = reader.next();
            String status = reader.next();
            Map<String,List<String>> curMap;
            trans.put(from,to);
            if (status.equals("correct")){
                curMap = cor;
            }
            else{
                curMap = inc;
            }
            if (curMap.containsKey(from)) {
                curMap.get(from).add(to);
            }else{
                List<String> cur = new ArrayList<>();
                cur.add(to);
                curMap.put(from,cur);
            }

        }
        long correct = 1;
        long total =1;
        for (String cur: sen){
            correct*= cor.get(cur).size();
            total *= (cor.get(cur).size() + inc.get(cur).size());
        }
        String result = "";
        if (total == 1){
            for (long i=0; i<n-1; i++){
                result += trans.get(sen.get((int)i)) + " ";
            }
            result += trans.get(sen.get((int)n-1));
            System.out.println(result);
            if (correct == 1){
                System.out.println("correct");
            }
            else{
                System.out.println("incorrect");
            }

        }else {

            System.out.println(correct + " correct");
            System.out.println(total - correct + " incorrect");
        }

    }
}
