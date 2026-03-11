public class BankAccount {
    
    private String accountHolder;
    private double balance;

    public BankAccount(String name, double amount) {
        accountHolder = name;
        
        balance = (amount >= 0) ? amount : 0;
    }

    
    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Error: Deposit amount must be positive.");
            return; 
        }
        balance += amount;
        printTransaction(amount, "deposited");
    }

    
    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Error: Withdrawal amount must be positive.");
        } else if (amount > balance) {
            System.out.println("Error: Insufficient funds! Current balance: " + balance);
        } else {
            balance -= amount;
            printTransaction(amount, "withdrawn");
        }
    }

    public void showBalance() {
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Current Balance: " + balance + " TL");
    }

    
    private void printTransaction(double amount, String type) {
        System.out.println(amount + " TL " + type + ". New Balance: " + balance + " TL");
    }
}
