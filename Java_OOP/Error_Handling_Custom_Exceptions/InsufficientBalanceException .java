/**
 * Custom exception thrown when a withdrawal exceeds the current balance.
 */
public class InsufficientBalanceException extends Exception {
    
    public InsufficientBalanceException(String message) {
        super(message);
    }
}
