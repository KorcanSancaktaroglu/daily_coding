public class App {
    public static void main(String[] args) {
        System.out.println("Banking System Initialized...");

        AccountManager manager = new AccountManager();

        try {
            System.out.println("Initial Balance: " + manager.getBalance());
            
            manager.deposit(100.0);
            System.out.println("Balance after deposit: " + manager.getBalance());

            manager.withdraw(90.0);
            System.out.println("Balance after withdrawal: " + manager.getBalance());

            // This will trigger the custom exception
            System.out.println("Attempting to withdraw 20.0...");
            manager.withdraw(20.0);
            
        } catch (InsufficientBalanceException e) {
            System.err.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Unexpected Error: " + e.getMessage());
        }

        System.out.println("Final Account State: " + manager.getBalance());
    }
}
