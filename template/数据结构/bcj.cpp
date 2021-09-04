const int maxn=10010;
int f[maxn],rank[maxn]; 

void makeSet(int n){
    for(int i=0;i<=n;i++){
        f[i]=i;
        rank[i]=0;
    }
}

int find(int x){
    while(f[x]!=x)
    {
        f[x]=find(f[x]);    
    }
    return f[x];
}
void unionSet(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(rank[x]>rank[y]){
        f[y]=x;
    }
    else{
        if(rank[x]==rank[y]){
            rank[y]++;
        }
        f[x]=y;
    }
}