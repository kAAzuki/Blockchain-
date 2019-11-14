#include "Blockchain.h"
#include "sha256.h"

    Blockchain bChain = Blockchain();

    int p = 11, g = 2;

    bool findUser(string s){
        for(auto t:bChain.users){
            if(t==s)return true;
        }
        return false;
    }

int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

bool verify(int id, string user, int amount){
          int x1,x;
          x = id;
          for(auto t:bChain.users){
            if(t == user){
                x1 = bChain.adhar[t];
                if(bChain.balance[t]<amount){
                    cout << "Insufficient Amount" << endl;
                    return false;
                }
                break;
            }
          }
          int rounds = 100;
          while(rounds--){
          int y = modpow(g, x1, p);
          int r = rand()%11;
          int h = modpow(g, r, p);
          int b = rand()%2;
          int s = (r + b*x)%(p-1);
          int bob = modpow(g, s, p);
          int al = h*modpow(y, b, p)%p;
          if(al!=bob){
            cout << "Please Check ID and try again\n";
            return false;
          }
          }
        return true;
}

void update(string u1, string u2, int amt){
    for(int i=0;i<bChain.users.size();i++){
        if(bChain.users[i]==u1){
            bChain.balance[u1] -= amt;
        }
         if(bChain.users[i]==u2){
            bChain.balance[u2] += amt;
        }
    }
}

void display(string user){

    int cnt = 0;
    for(auto t:bChain._vChain){
        if(t.to==user){
            cout << "Amount " << t.amount << " From " << t.from << " To " << user << " At " <<  ctime(&t._tTime) << endl;
            cnt++;
        }
        else if(t.from == user){
            cout << "Amount " << t.amount << " From " << t.from << " To " << t.to << " At " <<  ctime(&t._tTime) << endl;
            cnt++;
        }
    }
    if(!cnt){
        cout << "No Transactions Found Against the given user\n";
    }
}

int main()
{

    cout << "Press 0 for exit \nPress 1 for transfer \nPress 2 to view transactions of a user \n" << endl;

    int x;
    while(true){
        cin >> x ;
        if(x==0)break;
        if(x==1){
            string u1,u2;
            int id,amt;
            cin >> u1 >> u2 >> id >> amt;
            if(u1==u2){
                cout << "Please Select Different Users\n";
                continue;
            }
            if(!findUser(u1)){
                    cout << "User1 not found" << endl;
                    continue;
            }
            if(!findUser(u2)){
                    cout << "User2 not found" << endl;
                    continue;
            }
            if(!verify(id, u1 , amt)){
                continue;
            }
            else {
                bChain.AddBlock(Block(1, u1, u2, amt));
                update(u1, u2, amt);
                cout << "Successful Transaction\n";
                //display();
            }
        }
        else if(x==2){
            string user;
            cin >> user;
            if(!findUser(user)){
                    cout << "User not found" << endl;
                    continue;
            }
            display(user);
        }
        else {
            cout << "Please Make a valid Choice\n";
        }
    }
    /*
    cout << "All Transactions\n";
    for(auto t:bChain._vChain){
        cout << t.to << " " << t.from << " " << t.amount << endl;
    }
    cout << "All Balance\n";
    for(auto t:bChain.users){
        cout <<  t << " " <<  bChain.balance[t] << " " << bChain.adhar[t] << endl;
    }
    */
    return 0;
}
