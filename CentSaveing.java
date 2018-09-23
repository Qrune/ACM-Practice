import java.util.Scanner;

public class CentSaveing {
    public void main(){
        Scanner reader = new Scanner(System.in);
        int n = reader.nextInt();
        int d = reader.nextInt();
        int result = Integer.MIN_VALUE;
        int[][] dp = new int[n+2][d+2];
        int[] prefix = new int[n];
        for (int i=0; i<=n; i++){
            for (int j=0; j<=d; j++){
                dp[i][j] = -1;
            }
        }
        for (int i=1; i<=n; i++){
            int cur = reader.nextInt();
            if (i==1) {
                prefix[1] = cur;
            }else{
                prefix[i] = prefix[i-1] + cur;
            }

            dp[i][0] = round(prefix[i]);
        }
        for (int i=0; i<d; i++){
            dp[0][i] = 0;
        }
        for (int i=1; i<=n; i++){
            for (int j = 0; j<i; j++){
                if (dp[i][j] == -1){
                    dp[i][j] = Integer.MAX_VALUE;
                }else {
                    dp[i][j] = Math.min(dp[i][j],dp[j][i]);
                }
            }
        }


        System.out.print(result);
    }
    int round(int val){
        int rem = val % 10;
        if (rem < 5){
            return val - rem;
        }
        return val+10-rem;
    }
}
