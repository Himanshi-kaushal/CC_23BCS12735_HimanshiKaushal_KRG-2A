import java.io.*;
import java.util.*;
 
public class Main {
    static final long mod1 = 1000000007;
    static final long mod2 = 1000000009;
    static final long base = 31;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
 
        Map<Integer, HashSet<Long>> map = new HashMap<>();
 
        long[] pow1 = new long[600005];
        long[] pow2 = new long[600005];
        pow1[0] = pow2[0] = 1;
 
        for(int i=1;i<pow1.length;i++){
            pow1[i] = (pow1[i-1]*base)%mod1;
            pow2[i] = (pow2[i-1]*base)%mod2;
        }
 
        for(int i=0;i<n;i++){
            String s = br.readLine();
            long h1=0,h2=0;
 
            for(int j=0;j<s.length();j++){
                int v = s.charAt(j)-'a'+1;
                h1 = (h1*base + v)%mod1;
                h2 = (h2*base + v)%mod2;
            }
 
            long key = (h1<<32) ^ h2;
            map.computeIfAbsent(s.length(),k->new HashSet<>()).add(key);
        }
 
        StringBuilder out = new StringBuilder();
 
        while(m-- > 0){
            String s = br.readLine();
            int len = s.length();
 
            if(!map.containsKey(len)){
                out.append("NO\n");
                continue;
            }
 
            long h1=0,h2=0;
 
            for(int i=0;i<len;i++){
                int v = s.charAt(i)-'a'+1;
                h1 = (h1*base + v)%mod1;
                h2 = (h2*base + v)%mod2;
            }
 
            boolean ok=false;
 
            for(int i=0;i<len && !ok;i++){
                int cur = s.charAt(i)-'a'+1;
 
                long rem1 = (cur*pow1[len-i-1])%mod1;
                long rem2 = (cur*pow2[len-i-1])%mod2;
 
                for(char c='a';c<='c';c++){
                    if(c==s.charAt(i)) continue;
 
                    int v = c-'a'+1;
 
                    long add1 = (v*pow1[len-i-1])%mod1;
                    long add2 = (v*pow2[len-i-1])%mod2;
 
                    long nh1 = (h1-rem1+mod1)%mod1;
                    nh1 = (nh1+add1)%mod1;
 
                    long nh2 = (h2-rem2+mod2)%mod2;
                    nh2 = (nh2+add2)%mod2;
 
                    long key = (nh1<<32) ^ nh2;
 
                    if(map.get(len).contains(key)){
                        ok=true;
                        break;
                    }
                }
            }
 
            out.append(ok?"YES\n":"NO\n");
        }
 
        System.out.print(out);
    }
}
