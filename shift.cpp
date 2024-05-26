#include <bits/stdc++.h>
using namespace std;
//se comecar lendo 0's, continua ate ler 1
//quando ler um 1, marca ele com o left. Entao, continua andando
//com o right ate ler um zero novamente
//entao marca o right na posição desse zero e faz o flip.
//Isso vai fazer a quantidade maxima de 1's andarem para a esquerda enquanto 
//a substring é pequena, minimizando o custo do sort: r - l + 1

long long int cost(int r, int l){
    return r - l + 1;
}

void switch_s(string& s, int l, int r, int& qnt){
    qnt++;
    int n = r-l+1;
    char lastOne = s[r];
    //0110 => 0011
    for(int i=r; i > l ; --i)
        s[i] = s[i-1];
    s[l] = lastOne;
}

void solve(string s){
    int qnt = 0;
    int r=0,l=0;
    int n = s.size();
    
    long long int sum=0;
    //missing input: "101011" -> ok,"01101001" -> :C

    //01234567
    //01101001
    //cout << "str: " << s << " ";

    for(; r < n; ){
        
        //11000
        //posiciono left e right
        while((s[l] != '1' || s[r] != '0') && l <= r && r < n){
            
            if(s[l] != '1') ++l;
            if(s[r] != '0' || l > r) ++r;

            //cout << "l: " << l << " r: " << r << endl;
        }
        //acumula sse deu certo
        if((s[l] == '1' && s[r] == '0')){
            //cout << "l: " << l << " r: " << r << endl;
            sum += cost(r,l);
            switch_s(s,l,r,qnt);
        }
        //next window
        if(r >= n)
            break;
        else
            ++r;
        ++l;
    }
    cout << "shift count: " << qnt << " - Final str: " << s << endl;
}

int main(){
    int qntTest;
    cin >> qntTest;
    
    string s;
    vector<string> str;
    
    while(qntTest){
        cin >> s;
        str.push_back(s);
        --qntTest;
    }

    for(int i=0;i<str.size();i++){
        solve(str[i]);
    }
}