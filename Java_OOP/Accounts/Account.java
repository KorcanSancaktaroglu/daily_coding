public class Account {
    protected String name, pin; // pin should be immutable string
    protected double balance; // no need to initialize

    public Account(String name, String pin, double balance) {
        this.name = name;
        this.pin = pin;
        this.balance = balance; // initial balance determined when account is opened
    }

    public boolean deposit(double amount) { // is deposit valid?
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }

    public boolean withdraw(double amount) {
        if (balance < amount) return false;
        balance -= amount;
        return true;
    }
    public double getBalance(){
        return balance;
    }

    @Override
    public String toString() {
        return "Name: " + name + " Balance: " + balance + " Pin: *******";
    }
}

public class VipAccount extends Account {
    private double limit;

    public VipAccount(String name, String pin, double balance, double limit) {
        super(name, pin, balance);
        this.limit = limit;
    }

    @Override
    public boolean withdraw(double amount) {
        if (amount > balance + limit) return false; // max amount balance + limit 
        balance -= amount;
        return true;
    }

    public boolean deposit(double amount, double bonus) {
        if (amount <= 0) return false;
        balance += bonus + amount;
        return true;
    }
}
