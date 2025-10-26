class Bank {

    constructor(private balance: number[]) { }

    getAccoutId = (id: number) => {
        return id - 1;
    }

    transfer(account1: number, account2: number, money: number): boolean {
        if (account1 > this.balance.length || account2 > this.balance.length) {
            return false;
        }

        const account1Id = this.getAccoutId(account1);
        const account2Id = this.getAccoutId(account2);

        if (this.balance[account1Id] < money) {
            return false;
        }

        this.balance[account1Id] -= money;
        this.balance[account2Id] += money;

        return true;
    }

    deposit(account: number, money: number): boolean {

        if (account > this.balance.length) {
            return false;
        }

        const accountId = this.getAccoutId(account);
        this.balance[accountId] += money;
        return true;
    }

    withdraw(account: number, money: number): boolean {

        if (account > this.balance.length) {
            return false;
        }

        const accountId = this.getAccoutId(account);

        if (this.balance[accountId] < money) {
            return false;
        }

        this.balance[accountId] -= money;

        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */