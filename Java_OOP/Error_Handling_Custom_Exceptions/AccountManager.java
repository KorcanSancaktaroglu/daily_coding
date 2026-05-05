/**
 * Manages bank account operations like deposit and withdrawal.
 */
public class AccountManager {

    private double balance;

    public double getBalance() {
        return balance;
    }

    /**
     * Deposits a positive amount into the account.
     * @param amount The amount to deposit.
     * @throws Exception If the amount is negative.
     */
    public void deposit(double amount) throws Exception {
        if (amount >= 0) {
            balance += amount;
        } else {
            throw new Exception("Invalid amount: Deposit amount must be positive.");
        }
    }

    /**
     * Withdraws a specified amount from the account.
     * @param amount The amount to withdraw.
     * @throws InsufficientBalanceException If balance is less than the withdrawal amount.
     */
    public void withdraw(double amount) throws InsufficientBalanceException {
        if (balance >= amount) {
            balance -= amount;
        } else {
            throw new InsufficientBalanceException("Insufficient balance: Transaction declined.");
        }
    }
}
