class Solution {
public:
    using int2=pair<int, int>;
    void print(auto& f){
        for(auto& [x, y]: f) cout<<"("<<x<<","<<y<<")";
        cout<<endl;
    }

    vector<int2> convert(string& expression){
        vector<int2> fraction;
        int sz=expression.size(), x=0, sgn=1;
        char c=expression[0];
        switch(c){
            case '+':break;
            case '-': sgn=-1; break;
            default: x=c-'0';
        }
        int prev=0;
        for(int i=1; i<sz; i++){
            c=expression[i];
            while(c>='0'){
                x=10*x+(c-'0');
                if (i==sz-1) break;
                c=expression[++i];
            //    cout<<x<<", ";
            }
            switch(c){
                case '+':
                    fraction.emplace_back(prev, x);
                    sgn=1; 
                    x=0;
                    break;
                case '-':
                    fraction.emplace_back(prev, x); 
                    sgn=-1; 
                    x=0;
                    break;
                case '/':
                    prev=x*sgn;
                    x=0;
            }  
        }
        // dealing with i=sz-1
        fraction.emplace_back(prev, x);
        return fraction;
    }
    int2 add(int2& x, int2& y){
        auto [xp, xq]=x;
        auto [yp, yq]=y;
        long long q=xq*yq;
        long long p=xp*yq+xq*yp;
        long long g=gcd(p, q);
        return {p/g, q/g};
    }
    
    string fractionAddition(string& expression) {
        auto fraction=convert(expression);
    //    print(fraction);
        int fz=fraction.size();
        int2 ans={0, 1};
        for(auto& f: fraction){
            ans=add(ans, f);
        }
        string s=to_string(ans.first)+"/"+to_string(ans.second);
        return s;
    }
};