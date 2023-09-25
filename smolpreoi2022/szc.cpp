#include <bits/stdc++.h>

using namespace std;

vector<int>graf[1000010];
vector<int>grafodwr[1000010];
bool visited[1000010];
vector<int>postorder;
vector<int>nieskonczonosc;
long long dp[1000010];
vector<int>najw;
int maks=0;
bool wcyklu[1000010];
vector<int>sortowany;

void DFS(int x){

    for(int i=0;i<grafodwr[x].size();i++){
        if(!visited[grafodwr[x].at(i)]){
            visited[grafodwr[x].at(i)]=1;
            DFS(grafodwr[x].at(i));
        }
    }
    postorder.push_back(x);
}

bool DFS2(int x){
    bool t=0;
    bool bezznaczenia;
    for(int i=0;i<graf[x].size();i++){
        if(!visited[graf[x].at(i)]){
            t=1;
            visited[graf[x].at(i)]=1;
            nieskonczonosc.push_back(graf[x].at(i));
            wcyklu[graf[x].at(i)]=1;
            bezznaczenia=DFS2(graf[x].at(i));
        }
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        grafodwr[b].push_back(a);
    }

    for(int i=0;i<=n+1;i++){
        visited[i]=0;
    }
    visited[n+1]=1;
    DFS(n+1);//post order

    //
    for(int i=0;i<=n+1;i++){
        visited[i]=0;
        wcyklu[i]=0;
    }
    
    int x;
    visited[n+1]=1;
    for(int i=postorder.size()-1;i>=0;i--){
        x=postorder.at(i);
        visited[x]=1;
        if(DFS2(x)){
            nieskonczonosc.push_back(x);
            wcyklu[x]=1;
        }
    }//sprawdzanie czy w cyklu i oznaczanie jak w cyklu

    for(int i=0;i<=n;i++){
        dp[i]=0;
    }


    dp[n+1]=1;
    for(int i=postorder.size()-1;i>=0;i--){
        for(int a=0;a<graf[postorder.at(i)].size();a++){
        dp[postorder.at(i)]+=dp[graf[postorder.at(i)].at(a)];
        }
    }//dla wszystkich po postorderze suma wszystkich ojcow

    for(int i=1;i<=n;i++){
        if(dp[i]>36500&&!wcyklu[i]){
            nieskonczonosc.push_back(i);
        }
        else if(dp[i]>maks){
            najw.clear();
            najw.push_back(i);
            maks=dp[i];
        }
        else if(dp[i]==maks){
            najw.push_back(i);
        }
    }//jesli wiecej niz 365000 to dodaje do nieskoczonosci jesli nie to maks ustala i dodaje do vectora najw


    if(!nieskonczonosc.empty()){
        sortowany=nieskonczonosc;
        sort(nieskonczonosc.begin(), nieskonczonosc.end());
        nieskonczonosc=sortowany;
        cout<<"nieskonczonosc"<<'\n'<<nieskonczonosc.size()<<'\n';
        for(int i=0;i<nieskonczonosc.size();i++){
            cout<<nieskonczonosc.at(i)<<" ";
        }
    }
    else{
        sortowany=najw;
        sort(najw.begin(), najw.end());
        najw=sortowany;
        cout<<maks<<'\n'<<najw.size()<<'\n';
        for(int i=0;i<najw.size();i++){
            cout<<najw.at(i)<<" ";
        }
    }//jak cos jest w nieskonczonosci to w wypisuje posortowane z nieskonczonosci jak nie to posortowane z maksu






    //cout<<nieskonczonosc.size();


}