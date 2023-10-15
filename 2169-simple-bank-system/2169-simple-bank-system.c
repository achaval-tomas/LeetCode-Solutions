typedef struct {
    long long* balance;
    int size;
} Bank;


Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* bank = malloc(sizeof(Bank));
    bank->balance = malloc(balanceSize*sizeof(long long));
    bank->size = balanceSize;
    for (int i = 0; i<balanceSize; ++i){
        bank->balance[i] = balance[i];
    }
    return bank;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (account1 >= 1 && account1 <= obj->size && account2 >= 1 && account2 <= obj->size) {
        if (obj->balance[account1-1] >= money){
            obj->balance[account1-1] -= money;
            obj->balance[account2-1] += money;
            return true;
        }
    }
    return false;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account >= 1 && account <= obj->size) {
        obj->balance[account-1] += money;
        return true;
    }
    return false;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account >= 1 && account <= obj->size) {
        if (obj->balance[account-1] >= money){
            obj->balance[account-1] -= money;
            return true;
        }
    }
    return false;
}

void bankFree(Bank* obj) {
    free(obj->balance);
    free(obj);
}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);
 
 * bool param_2 = bankDeposit(obj, account, money);
 
 * bool param_3 = bankWithdraw(obj, account, money);
 
 * bankFree(obj);
*/